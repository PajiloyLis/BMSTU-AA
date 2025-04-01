#include "algo.h"

set<string> all_urls;
queue<string> urls_to_handle;

int max_handled_urls = MAX_URLS_CNT;
int handled_urls = 0;

mutex set_urls_mutex, counter_mutex, queue_urls_mutex;

std::string
convert_encoding(const std::string &input, const std::string &from_encoding, const std::string &to_encoding) {
    iconv_t cd = iconv_open(to_encoding.c_str(), from_encoding.c_str());
    if (cd == (iconv_t) (-1)) {
        throw std::runtime_error("iconv_open failed: " + std::string(strerror(errno)));
    }

    const char *inbuf = input.c_str();
    size_t inbytesleft = strlen(inbuf);
    size_t outbytesleft = inbytesleft * 4; // Размер выходного буфера
    char *outbuf = new char[outbytesleft];
    char *outptr = outbuf;

    size_t result = iconv(cd, const_cast<char **>(&inbuf), &inbytesleft, &outptr, &outbytesleft);
    if (result == (size_t) (-1)) {
        delete[] outbuf;
        iconv_close(cd);
        throw std::runtime_error("iconv failed: " + std::string(strerror(errno)));
    }

    std::string output(outbuf, outptr - outbuf);
    delete[] outbuf;
    iconv_close(cd);

    return output;
}

size_t curl_write(char *contents, size_t size, size_t nmemb, string *data) {
    size_t new_size = size * nmemb;
    if (data == nullptr)
        return 0;
    data->append(contents, new_size);
    return new_size;
}

set<string> extract_hyperlinks(const string &text) {
    static const std::regex hl_regex("href=\"/(.*?)\"", std::regex_constants::icase);
    return {std::sregex_token_iterator(text.begin(), text.end(), hl_regex, 1), std::sregex_token_iterator{}};
}

void prepare_hyperlinks(const string &text, set<string> &urls, queue<string> &_urls_to_handle) {
    set<string> links = extract_hyperlinks(text);
    for (auto it = links.begin(); it != links.end();) {
        if (it->find(".ru") == string::npos && it->find(".com") == string::npos && it->find(".org") == string::npos &&
            it->substr(0, 12) == string("recipe-book/")) {
            string new_url = string(BASE_URL) + (*it);
            set_urls_mutex.lock();
            if (urls.find(new_url) == urls.end()) {
                set_urls_mutex.unlock();
                urls.insert(new_url);
                queue_urls_mutex.lock();
                _urls_to_handle.push(new_url);
                queue_urls_mutex.unlock();
            } else
                set_urls_mutex.unlock();
        }
        ++it;
    }
}

string load_page(const string &url, set<string> &urls, queue<string> &_urls_to_handle) {
    CURL *curl = curl_easy_init();
    string result;
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, curl_write);
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &result);
        CURLcode res_code = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        prepare_hyperlinks(result, urls, _urls_to_handle);
    }
    return result;
}

void write_html_file(const string &filename, const string &content) {
    ofstream out;
    out.open(filename, ios_base::out);
    out << content;
    out.close();
}

void thread_func(set<string> &_all_urls, queue<string> &_urls_to_handle) {
    while (handled_urls < max_handled_urls) {
        queue_urls_mutex.lock();
        if (!_urls_to_handle.empty()) {
            string new_url = _urls_to_handle.front();
            _urls_to_handle.pop();
            queue_urls_mutex.unlock();
            string content = load_page(new_url, _all_urls, _urls_to_handle);
            if (new_url.find("/recipe-book/meal/") != std::string::npos &&
                count(new_url.begin(), new_url.end(), '/') > 6) {
                write_html_file(string(DIR) + to_string(handled_urls) + ".html", convert_encoding(content, "CP1251", "UTF-8"));
                write_html_file(string(DIR)+ to_string(handled_urls)+".txt", new_url);
                counter_mutex.lock();
                ++handled_urls;
                counter_mutex.unlock();
            }
        } else
            queue_urls_mutex.unlock();
    }
}
