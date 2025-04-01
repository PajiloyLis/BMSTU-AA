#include "tasks.h"

#define NANO 1e9

string to_json(const vector<map<string, string>> &obj) {
    string json = "[";
    for (auto &item: obj) {
        json += "{";
        for (auto &key_value: item) {
            json += "\"" + key_value.first + "\": \"" + key_value.second + "\",";
        }
        json = json.substr(0, json.size() - 1);
        json += "}";
        if (item != obj.back())
            json += ",";
    }
    json += "]";
    return json;
}

string to_json_2(const vector<string> &obj) {
    string json = "[";
    for (auto &item: obj) {
        json += "\"" + item + "\"";
        if (item != obj.back())
            json += ",";
    }
    json += "]";
    return json;
}

vector<string> read_task::process() {
    setlocale(LC_ALL, "Russian");
    cout << uuid << " " << "read_started\n";
    times["read_queue_start"]=clock();
    // Чтение HTML файла
    std::ifstream file;
    file.open(filename_1, ios_base::in);

    std::string html_content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();
    file.open(filename_2, ios_base::in);
    string url;
    file >> url;
    file.close();
    times["read_queue_pop"]=clock();
    cout << uuid << " " << "read ended\n";
    return {html_content, url};
}

task_dto parse_task::process() {
    cout << uuid << " " << "parse started\n";
    times["parse_queue_start"]=clock();
    task_dto result;
    result.uuid = uuid;
    result.url = content[1];
    GumboOutput *output = gumbo_parse(content[0].c_str());
    result.title = search_for_title(content[0]);
    result.ingredients_json = to_json(search_for_ingredients(output->root));
    result.steps = search_for_recipe_steps(output->root);
    result.image_url = search_for_recipe_detail_picture(output->root);
    if (result.title.empty() || result.ingredients_json == "[]" || result.steps.empty())
        complete = false;
    times["parse_queue_pop"]=clock();
    cout << uuid << " " << "parse ended\n";
    return result;
}

string parse_task::search_for_recipe_detail_picture(GumboNode *node) {
    string ans;
    // Проверяем, является ли узел элементом
    if (node->type == GUMBO_NODE_ELEMENT) {
        if (node->v.element.tag == GUMBO_TAG_DIV) {
            // Проверка наличия атрибута класса
            for (size_t i = 0; i < node->v.element.attributes.length; ++i) {
                auto *attr = static_cast<GumboAttribute *>(node->v.element.attributes.data[i]);
                if (attr->name == string("class") && attr->value == std::string("recipe_detail_picture")) {
                    // Если находим нужный элемент, выводим его содержимое
                    for (size_t j = 0; j < node->v.element.children.length; ++j) {
                        auto *child = static_cast<GumboNode *>(node->v.element.children.data[j]);
                        if (child->type == GUMBO_NODE_ELEMENT && child->v.element.tag == GUMBO_TAG_IMG) {
                            for (size_t k = 0; k < child->v.element.attributes.length; ++k) {
                                auto *child_attr = static_cast<GumboAttribute *>(child->v.element.attributes.data[k]);
                                if (child_attr->name == string("src"))
                                    return child_attr->value;
                            }
                        }
                    }
                }
            }
        }
        // Рекурсивный обход всех дочерних узлов
        for (size_t i = 0; i < node->v.element.children.length; ++i) {
            GumboNode *child = static_cast<GumboNode *>(node->v.element.children.data[i]);
            ans += search_for_recipe_detail_picture(child);
        }
    }
    return ans;
}

vector<map<string, string>> parse_task::search_for_ingredients(GumboNode *node) {
    vector<map<string, string>> res;
    // Проверяем, является ли узел элементом
    if (node->type == GUMBO_NODE_ELEMENT) {
        if (node->v.element.tag == GUMBO_TAG_DIV) {
            // Проверка наличия атрибута класса
            for (size_t i = 0; i < node->v.element.attributes.length; ++i) {
                auto *attr = static_cast<GumboAttribute *>(node->v.element.attributes.data[i]);
                if (attr->name == string("class") && attr->value == string("ingr_name")) {
                    // Если находим нужный элемент, выводим его содержимое
                    for (size_t j = 0; j < node->v.element.children.length; ++j) {
                        auto *child = static_cast<GumboNode *>(node->v.element.children.data[j]);
                        if (child->type == GUMBO_NODE_ELEMENT && child->v.element.tag == GUMBO_TAG_SPAN) {
                            auto child_with_fucking_text = static_cast<GumboNode *>(child->v.element.children.data[0]);
                            res.push_back({});
                            res.back()["name"] = child_with_fucking_text->v.text.text;
                        }
                    }
                    auto new_node = static_cast<GumboNode *>(node->parent->v.element.children.data[3]);
                    for (size_t i = 0; i < new_node->v.element.attributes.length; ++i) {
                        auto *attr = static_cast<GumboAttribute *>(new_node->v.element.attributes.data[i]);
                        if (attr->name == string("class") && attr->value == string("ingr_qt")) {
                            // Если находим нужный элемент, выводим его содержимое
                            if (new_node->v.element.children.length > 0) {
                                auto child_with_fucking_text = static_cast<GumboNode *>(new_node->v.element.children.data[0]);
                                string fucking_text = child_with_fucking_text->v.text.text;
//                    res.push_back({});
                                size_t whitespace = fucking_text.find(' ');
                                string count = fucking_text.substr(0, whitespace), unit = fucking_text.substr(
                                        whitespace + 1,
                                        fucking_text.size());
                                res.back()["unit"] = unit;
                                res.back()["quantity"] = count;
                            } else {
                                res.back()["unit"] = "";
                                res.back()["quantity"] = "";
                            }
                        }
                    }
                }
            }
        }
        // Рекурсивный обход всех дочерних узлов
        for (size_t i = 0; i < node->v.element.children.length; ++i) {
            auto child = static_cast<GumboNode *>(node->v.element.children.data[i]);
            auto temp = search_for_ingredients(child);
            res.insert(res.end(), temp.begin(), temp.end());
        }
    }

    return res;
}

vector<string> parse_task::search_for_recipe_steps(GumboNode *node) {
    vector<string> res;
    // Проверяем, является ли узел элементом
    if (node->type == GUMBO_NODE_ELEMENT) {
        if (node->v.element.tag == GUMBO_TAG_DIV) {
            // Проверка наличия атрибута класса
            for (size_t i = 0; i < node->v.element.attributes.length; ++i) {
                auto *attr = static_cast<GumboAttribute *>(node->v.element.attributes.data[i]);
                if (attr->name == string("class") && attr->value == std::string("numbered_list_content")) {
                    // Если находим нужный элемент, выводим его содержимое
                    for (size_t j = 0; j < node->v.element.children.length; ++j) {
                        auto *child = static_cast<GumboNode *>(node->v.element.children.data[j]);
                        if (child->type == GUMBO_NODE_TEXT) {
                            string fucking_text = child->v.text.text;
                            size_t ind;
                            while ((ind = fucking_text.find('\t')) != fucking_text.npos) {
                                fucking_text.replace(ind, 1, "");
                            }
                            while ((ind = fucking_text.find('\n')) != fucking_text.npos) {
                                fucking_text.replace(ind, 1, "");
                            }
                            res.push_back(fucking_text);
                        }
                    }
                }
            }
        }
        // Рекурсивный обход всех дочерних узлов
        for (size_t i = 0; i < node->v.element.children.length; ++i) {
            auto child = static_cast<GumboNode *>(node->v.element.children.data[i]);
            auto tmp = search_for_recipe_steps(child);
            res.insert(res.end(), tmp.begin(), tmp.end());
        }
    }
    return res;
}

string parse_task::search_for_title(const string &input) {
    std::regex h1_regex(R"(<h1 class="global_title">(.*?)<\/h1>)");
    std::smatch match;

    // Выполняем поиск
    if (std::regex_search(input, match, h1_regex)) {
        // Возвращаем содержимое тега
        return match[1].str();
    }

    // Если тег не найден, возвращаем пустую строку
    return "";
}


bool write_task::process() {
    cout << uuid << " " << "write started\n";
    times["write_queue_start"]=clock();
    sqlite3 *db;

    if (sqlite3_open("/home/ivan/lab.db", &db)) {
        times["write_queue_pop"]=clock();
        return false;
    }
    string sql_statement =
            "insert into lab values ('" + content.uuid + "', '" + content.redmine_id + "', '" + content.url + "', '" +
            content.title + "', '" + content.ingredients_json + "', '" +
            to_json_2(content.steps) + "', '" + content.image_url + "');";
    sqlite3_exec(db, sql_statement.c_str(), nullptr, nullptr, nullptr);
    sqlite3_close(db);
    times["write_queue_pop"]=clock();
    cout << uuid << " " << "write ended\n";
    return true;
}

void log_task::process() {
    cout << uuid << " " << "log started\n";
    times["log_queue_start"]=clock();
    times["log_queue_pop"]=clock();
    ofstream out;
    out.open("logs/" + uuid + ".json", ios_base::out);
    out << "{";
    for (auto it = times.begin(); it != times.end();) {
        out << "\"" << it->first << "\": " << it->second;
        if (++it != times.end())
            out << ",";
    }
    out << "}";
    out.close();
    cout << uuid << " " << "log ended\n";
}
