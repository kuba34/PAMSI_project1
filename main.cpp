#include <iostream>
#include <random>
#include <chrono>
#include <array>
#include <vector>
#include <algorithm> // std::is_sorted

#include "quicksort.hpp"
#include "mergesort.hpp"
//#include "introsort.hpp"

int main() {
    //TODO:
    //full random
    //25%, 50%, 75%, 95%, 99%, 99,7%
    //reverse sorted
    std::array<std::string, 8> desc = {"Full random",
        "25%", "50%", "75%", "95%", "99%", "99.7%", "Reverse sorted"};
    int sizes[] = {10000, 50000, 100000, 500000, 1000000};
    std::array<std::vector<int>, 40> arrays;

    for(int i = 0;i<5;++i) {
        for(int j = 0;j<8;++j) {
            arrays[i*8+j].reserve(sizes[i]);
        }
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution dis(0, 10);

    for(auto &vec:arrays) {
        for(unsigned i=0;i<vec.capacity();++i) {
            vec.push_back(dis(gen));
        }
    }


    using namespace std::chrono;

    std::vector<std::pair<microseconds, int>>
        stat, quicksort_stat, mergesort_stat, introsort_stat;

    time_point<steady_clock> start, end;
    microseconds duration;

    // Quicksort
    for(std::vector<int> &a:arrays) {
        //std::cout << "Pre:" << std::endl;
        //print_vec(a);
        start = steady_clock::now();
        introsort(a, 0, a.size());
        end = steady_clock::now();
        //std::cout << "Post:" << std::endl;
        //print_vec(a);

        duration = duration_cast<microseconds>(end-start);
        stat.emplace_back(duration, a.size());
        if(!std::is_sorted(a.begin(), a.end())) {
            std::cerr << "not sorted" << std::endl;
        }
        std::cout << "Time: " << duration.count() << "µs "
            << "size: " << a.size() << std::endl;
    }

    /*
    bool is = std::is_sorted(arrays[0].begin(), arrays[0].end());
    std::cout << std::boolalpha << "Is sorted: "  << is << std::endl;
    std::cout << "Elapsed:  "  <<
        ch::duration_cast<ch::microseconds>(end-start).count() << "µs" << std::endl;
    */
}
