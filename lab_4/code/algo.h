#ifndef LAB_4_ALGO_H
#define LAB_4_ALGO_H

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <set>
#include <regex>
#include <fstream>
#include <mutex>
#include <queue>
#include <thread>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <iconv.h>

extern "C" {
#include <curl/curl.h>
#include <gumbo.h>
}

#define BASE_URL "https://sostra.ru/"
#define RECIPE_BASE_URL "https://sostra.ru/recipe-book/"
#define DIR "HTMLs/"
#define MAX_URLS_CNT 191
using namespace std;

extern set<string> all_urls;
extern queue<string> urls_to_handle;
extern int handled_urls;
extern int max_handled_urls;

void thread_func(set<string> &_all_urls, queue<string> &_urls_to_handle);
#endif //LAB_4_ALGO_H
