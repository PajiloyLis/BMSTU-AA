#ifndef BIS22U145_TASKS_H
#define BIS22U145_TASKS_H

#include <iostream>
#include <utility>
#include <vector>
#include <fstream>
#include <sqlite3.h>
#include <gumbo.h>
#include <map>
#include <cerrno>
#include <cstring>
#include <regex>
#include <sqlite3.h>
#include <gumbo.h>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/lexical_cast.hpp>
#include "task_dto.h"
#include <ctime>

using namespace std;

class read_task {
public:
    explicit read_task(string &file_1, string &file_2) : filename_1(file_1), filename_2(file_2),
                                                         uuid(boost::lexical_cast<string>(
                                                                 boost::uuids::random_generator()())) {
        times["read_queue_push"]=clock();
        cout << uuid << " " << "created\n";
    }

    vector<string> process();

    string get_uuid() { return uuid; }


    map<string, clock_t> times;

private:

    string filename_1, filename_2;

    const string uuid;
};

class parse_task {
public:
    explicit parse_task(vector<string> &values, string uuid_, const map<string, clock_t> &old_times) : times(
            old_times), content(values), uuid(std::move(uuid_)), complete(true) {
        times["parse_queue_push"]=clock();
    }

    string get_uuid() { return uuid; }

    task_dto process(); //returns JSON

    bool is_complete() { return complete; };

    map<string, clock_t> times;
private:
    string search_for_recipe_detail_picture(GumboNode *node);

    vector<map<string, string>> search_for_ingredients(GumboNode *node);

    vector<string> search_for_recipe_steps(GumboNode *node);

    string search_for_title(const string &input);

    vector<string> content;

    const string uuid;

    bool complete;
};

class write_task {
public:
    explicit write_task(task_dto data, string uuid_, const map<string, clock_t> &old_times) : times(old_times),
                                                                                               uuid(std::move(uuid_)),
                                                                                               content(std::move(
                                                                                                       data)) {
        times["write_queue_push"]=clock();
    }

    string get_uuid() { return uuid; }

    bool process();

    map<string, clock_t> times;

private:
    const string uuid;

    task_dto content;
};

class log_task {
public:
    log_task(string uuid_, const map<string, clock_t> &old_times) : times(old_times), uuid(uuid_) {
        times["log_queue_push"]=clock();
    }

    void process();

    map<string, clock_t> times;
    const string uuid;
};

#endif //BIS22U145_TASKS_H
