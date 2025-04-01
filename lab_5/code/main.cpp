#include <iostream>
#include <set>
#include <mutex>
#include <thread>
#include <ctime>
#include <vector>
#include "algo.h"
#include "time_measures.h"
#include "task_queue.h"
#include "tasks.h"

using namespace std;

extern task_queue<read_task> read_task_queue;
extern task_queue<parse_task> parse_task_queue;
extern task_queue<write_task> write_task_queue;
extern task_queue<log_task> log_task_queue;

extern bool first_stage_filled, second_stage_filled, third_stage_filled, fourth_stage_filled;

void solve() {
    first_stage_filled = second_stage_filled = third_stage_filled = false;
    thread first_stage_thread(first_stage), second_stage_thread(second_stage), third_stage_thread(third_stage), log_stage_thread(log_stage);
    for (int i = 0; i < 191; ++i) {
        cout << i << '\n';
        string file_name_1 = "/home/ivan/Study/AA/lab_5/bis22u145/HTMLs/" + to_string(i) + ".html",
                file_name_2 = "/home/ivan/Study/AA/lab_5/bis22u145/HTMLs/" + to_string(i) + ".txt";
        unique_lock lk(read_task_queue.m);
        read_task_queue.push(read_task(file_name_1, file_name_2));
        read_task_queue.pushed = true;
        lk.unlock();
        read_task_queue.cv.notify_one();
    }
    first_stage_filled=true;
//    first_stage();
//    second_stage();
//    third_stage();
//    log_stage();
    first_stage_thread.join(), second_stage_thread.join(), third_stage_thread.join(), log_stage_thread.join();
}

int main(int argc, char **argv) {
    if (argc == 1)
        solve();
    else if (argc == 2 && argv[1] == string("-t")) {
//        measure();
    } else {
        cout << "Error: unexpected args: ";
        for (int i = 1; i < argc; ++i)
            cout << argv[i] << " ";
        cout << '\n';
        return 1;
    }
}
