#include "series.h"
#include <cmath>
#include <cassert>

int main() {
    Series series;
    double result = series.FuncA(3);
    double expected = 0.833333;
    assert(std::fabs(result - expected) < 1e-6);
    return 0;
}

