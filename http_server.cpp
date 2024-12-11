#include <boost/asio.hpp>
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <cmath>
#include "series.h"

using boost::asio::ip::tcp;

std::vector<double> calculateAndSort(size_t size, int cycles, double& elapsed_time) {
    Series series;
    std::vector<double> values(size);
    auto start_time = std::chrono::high_resolution_clock::now();

    // Generate values using Series::FuncA and sort
    for (int cycle = 0; cycle < cycles; ++cycle) {
        for (size_t i = 0; i < size; ++i) {
            values[i] = series.FuncA(static_cast<int>(i + 1));
        }
        std::sort(values.begin(), values.end());
    }

    auto end_time = std::chrono::high_resolution_clock::now();
    elapsed_time = std::chrono::duration<double>(end_time - start_time).count();

    return values;
}

void handleRequest(tcp::socket& socket) {
    try {
        size_t size = 10000; // Number of elements in array
        int cycles = 10;     // Sorting cycles
        double elapsed_time;

        // Calculate and sort
        auto values = calculateAndSort(size, cycles, elapsed_time);

        // Prepare response
        std::string response_body = "Elapsed Time: " + std::to_string(elapsed_time) + " seconds\n";
        std::string http_response =
            "HTTP/1.1 200 OK\r\nContent-Length: " + std::to_string(response_body.size()) +
            "\r\nContent-Type: text/plain\r\n\r\n" + response_body;

        // Send response
        boost::asio::write(socket, boost::asio::buffer(http_response));
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void startServer(short port) {
    boost::asio::io_context io_context;
    tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(), port));

    while (true) {
        tcp::socket socket(io_context);
        acceptor.accept(socket);
        handleRequest(socket);
    }
}

int main() {
    try {
        startServer(8080);
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}


