#include <iostream>
#include "Searcher.h"

typedef unsigned long long ull;

int main() {
    std::vector<ull> a, b;
    ull size = 1000;
    for (ull i = 0; i < size; ++i) {
        a.push_back(1001 - i);
        b.push_back(i);
    }
    Searcher search(a, b);
    std::cout << search.find_small_sizes() << std::endl;
    std::cout << search.find_different_sizes() << std::endl;
    std::cout << search.find_sort() << std::endl;
    return 0;
}