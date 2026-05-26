#include <cstdlib>
#include <cstdio>


#include <chrono>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>


std::vector<std::string> load_sonnets(const std::string& filename) {
    std::ifstream iff(filename);
    if (!iff.is_open()) {
        std::cerr << "Failed to open file with sonnets: " << filename << std::endl;
        std::exit(EXIT_FAILURE);
    }

    std::vector<std::string> sonnets;
    while (iff) {
        std::string line;
        std::getline(iff, line);
        sonnets.emplace_back(std::move(line));
    }

    return std::move(sonnets);
}


int main(int argc, char** argv) {
    std::string filename = "sonnets.txt";
    if (argc > 1) {
        filename = argv[1];
    }

    auto&& sonnets = load_sonnets(filename);

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    for (int i = 0; i < 1000; ++i) {
        for (const auto& line: sonnets) {
            // std::cout << line << '\n';
            puts(line.c_str());
        }
    }
    std::cout.flush();
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    std::cerr << "Time difference = " << std::chrono::duration_cast<std::chrono::seconds>(end - begin).count() << "[s]" << std::endl;
    std::cerr << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;
    std::cerr << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << std::endl;

    return 0;
}
