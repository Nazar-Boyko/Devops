#include "series.h"
#include <cassert>
#include <chrono>
#include <iostream>
#include <cmath>

int main() {
    Series series;
    size_t size = 10000;
    int cycles = 10;

    auto start = std::chrono::high_resolution_clock::now();
    std::vector<double> values(size);
    for (int i = 0; i < cycles; ++i) {
        for (size_t j = 0; j < size; ++j) {
            values[j] = series.FuncA(j + 1);
        }
        std::sort(values.begin(), values.end());
    }
    auto end = std::chrono::high_resolution_clock::now();
    double elapsed = std::chrono::duration<double>(end - start).count();

    // Check that elapsed time is within the range
    assert(elapsed >= 5.0 && elapsed <= 20.0);
    std::cout << "Test passed! Elapsed time: " << elapsed << " seconds.\n";
    return 0;
}

