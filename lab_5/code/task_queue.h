//
// Created by ivan on 03.02.25.
//

#ifndef BIS22U145_TASK_QUEUE_H
#define BIS22U145_TASK_QUEUE_H

#include <queue>
#include <mutex>
#include <condition_variable>

using namespace std;


template<typename T>
class task_queue {
public:
    void push(const T &elem) {
        tasks.push(elem);
    }

    T pop() {
        T top = tasks.front();
        tasks.pop();
        return top;
    }

    bool empty() {
        return tasks.empty();
    }

    condition_variable cv;
    bool pushed=false;
    mutex m;

private:
    queue<T> tasks;
};


#endif //BIS22U145_TASK_QUEUE_H
