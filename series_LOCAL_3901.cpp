// series.cpp
#include "series.h"

double Series::FuncA() {
    double sum = 0.0;
    double x = 1.0;
    for (int i = 1; i <= 3; ++i) {
        sum += (i % 2 == 1 ? 1 : -1) * (pow(x, i) / i);
    }
    return sum;
}
