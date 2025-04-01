//#include "time_measures.h"
//
//void write_measures_file(const vector<double> &measures);
//
//void measure() {
//    max_handled_urls = 50;
//    vector<double> measures(MEASURES_CNT);
//    for (int i = MIN_THREADS_COUNT, num = 0; i <= MAX_THREADS_COUNT; i *= MULTIPLIER, num++) {
//        vector<thread> threads(i);
//        cout << "Measures with " << i << " threads\n";
//        timespec start, end;
//        for (int j = 0; j < REPEATS; ++j) {
//            cout << "Measure " << j << '\n';
//            handled_urls = 0;
//            all_urls.clear();
//            while (!urls_to_handle.empty())
//                urls_to_handle.pop();
//            clock_gettime(CLOCK_MONOTONIC, &start);
//            all_urls.insert(RECIPE_BASE_URL);
//            urls_to_handle.push(RECIPE_BASE_URL);
//            for (int k = 0; k < i; ++k)
//                threads[k] = thread(thread_func, ref(all_urls), ref(urls_to_handle));
//            for (auto &k: threads)
//                k.join();
//            clock_gettime(CLOCK_MONOTONIC, &end);
//            measures[num] += (end.tv_sec - start.tv_sec) * 1e9 + end.tv_nsec - start.tv_nsec;
//        }
//        cout << "Total time: " << measures[num] / 1e9 << '\n';
//        measures[num] = (REPEATS * max_handled_urls) / (measures[num] / 1e9);
//    }
//    write_measures_file(measures);
//}
//
//void write_measures_file(const vector<double> &measures) {
//    ofstream out;
//    out.open("./measures.json", ios_base::out);
//    out << "{\n";
//    for (int i = MIN_THREADS_COUNT, ind = 0; ind < measures.size(); i *= MULTIPLIER, ++ind) {
//        out << "\t\"" << i << "\": " << measures[ind] << (ind == measures.size() - 1 ? "\n" : ",\n");
//    }
//    out << "}\n";
//}