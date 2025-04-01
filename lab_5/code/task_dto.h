#ifndef BIS22U145_TASK_DTO_H
#define BIS22U145_TASK_DTO_H

#include <iostream>
#include <vector>

#define REDMINE "120232"

using namespace std;

class task_dto {
public:
    string uuid;
    static const string redmine_id;
    string url;
    string title;
    string ingredients_json;
    vector<string> steps;
    string image_url;
};


#endif //BIS22U145_TASK_DTO_H
