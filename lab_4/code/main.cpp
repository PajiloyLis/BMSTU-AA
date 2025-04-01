#include <iostream>
#include <set>
#include <mutex>
#include <thread>
#include <ctime>
#include <vector>
#include "algo.h"
#include "time_measures.h"

using namespace std;


void solve() {
    all_urls.insert(RECIPE_BASE_URL);
    urls_to_handle.push(RECIPE_BASE_URL);
    int temp;
    cout << "Enter the number of recipe pages to download:\n";
    cin >> temp;
    max_handled_urls = min(MAX_URLS_CNT, temp);
    cout << "Enter number of threads (1 for no parallel):\n";
    int max_threads_cnt;
    cin >> max_threads_cnt;
    vector<thread> threads(max_threads_cnt);
    time_t start = clock();
    for (int i = 0; i < threads.size(); ++i)
        threads[i] = thread(thread_func, ref(all_urls), ref(urls_to_handle));
    for (auto &i: threads)
        i.join();
    time_t end = clock();
    cout << "Execution_time_with " << max_threads_cnt << " threads is " << double(end - start) / CLOCKS_PER_SEC << '\n';
}

int main(int argc, char **argv) {
    if (argc == 1)
        solve();
    else if (argc == 2 && argv[1] == string("-t")) {
        measure();
    } else {
        cout << "Error: unexpected args: ";
        for (int i = 1; i < argc; ++i)
            cout << argv[i] << " ";
        cout << '\n';
        return 1;
    }
}
