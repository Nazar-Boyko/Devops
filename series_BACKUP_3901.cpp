// series.cpp
#include "series.h"

<<<<<<< HEAD
double Series::FuncA() {
    double sum = 0.0;
    double x = 1.0;
    for (int i = 1; i <= 3; ++i) {
=======
double Series::FuncA(int n) {
    double sum = 0.0;
    double x = 1.0;  
    for (int i = 1; i <= n; ++i) {
>>>>>>> branchA
        sum += (i % 2 == 1 ? 1 : -1) * (pow(x, i) / i);
    }
    return sum;
}

