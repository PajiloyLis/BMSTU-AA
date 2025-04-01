#include "algo.h"

task_queue<read_task> read_task_queue;
task_queue<parse_task> parse_task_queue;
task_queue<write_task> write_task_queue;
task_queue<log_task> log_task_queue;

bool first_stage_filled, second_stage_filled, third_stage_filled, fourth_stage_filled;

void first_stage() {
    while (!first_stage_filled || !read_task_queue.empty()) {
        if (read_task_queue.empty()) {
            unique_lock lk(read_task_queue.m);
            read_task_queue.pushed = false;
            read_task_queue.cv.wait(lk, [] { return read_task_queue.pushed; });
        }
        read_task new_task = read_task_queue.pop();
        vector<string> result = new_task.process();
        unique_lock lk(parse_task_queue.m);
        parse_task_queue.push(parse_task(result, new_task.get_uuid(), new_task.times));
        parse_task_queue.pushed = true;
        lk.unlock();
        parse_task_queue.cv.notify_one();
    }
    second_stage_filled = true;
}

void second_stage() {
    while (!second_stage_filled||!parse_task_queue.empty()) {
        if (parse_task_queue.empty()) {
            unique_lock lk(parse_task_queue.m);
            parse_task_queue.pushed = false;
            parse_task_queue.cv.wait(lk, [] { return parse_task_queue.pushed; });
        }
        parse_task new_task = parse_task_queue.pop();
        task_dto new_dto = new_task.process();
        if (new_task.is_complete()) {
            unique_lock lk(write_task_queue.m);
            write_task_queue.push(write_task(new_dto, new_task.get_uuid(), new_task.times));
            write_task_queue.pushed = true;
            lk.unlock();
            write_task_queue.cv.notify_one();
        }
    }
    third_stage_filled = true;
}

void third_stage() {
    while (!third_stage_filled || !write_task_queue.empty()) {
        if (write_task_queue.empty()) {
            unique_lock lk(write_task_queue.m);
            write_task_queue.pushed = false;
            write_task_queue.cv.wait(lk, [] { return write_task_queue.pushed; });
        }
        write_task new_task = write_task_queue.pop();
        if (!new_task.process())
            cout << "Oooops\n";
        unique_lock lk(log_task_queue.m);
        log_task_queue.push(log_task(new_task.get_uuid(), new_task.times));
        log_task_queue.pushed = true;
        lk.unlock();
        log_task_queue.cv.notify_one();
    }
    fourth_stage_filled = true;
}

void log_stage() {
    while (!fourth_stage_filled|| !log_task_queue.empty()) {
        if (log_task_queue.empty()) {
            unique_lock lk(log_task_queue.m);
            log_task_queue.pushed = false;
            log_task_queue.cv.wait(lk, [] { return log_task_queue.pushed; });
        }
        log_task new_task = log_task_queue.pop();
        new_task.process();
    }
}