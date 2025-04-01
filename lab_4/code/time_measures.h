#ifndef LAB_4_TIME_MEASURES_H
#define LAB_4_TIME_MEASURES_H

#include <fstream>
#include <iostream>
#include <vector>
#include <thread>
#include <pthread.h>
#include "algo.h"

using namespace std;


#define REPEATS 3
#define MIN_THREADS_COUNT 1
#define MAX_THREADS_COUNT (4 * thread::hardware_concurrency())
#define MULTIPLIER 2
#define MEASURES_CNT 6

void measure();

#endif //LAB_4_TIME_MEASURES_H
