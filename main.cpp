#include <iostream>
#include "Searcher.h"

int main() {
    std::vector<int> a, b;
    int size = 1000;
    for (int i = 0; i < size; ++i) {
        a.push_back(1001 - i);
        b.push_back(i);
    }
    Searcher search(a, b);
    std::cout << search.find() << std::endl;
    return 0;
}