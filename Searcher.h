//
// Created by Елена on 2019-05-26.
//

#ifndef VK_SEARCHER_H
#define VK_SEARCHER_H

#include <vector>
#include <iostream>

typedef unsigned long long ull;


class Searcher {
std::vector<ull> a;
std::vector<ull> b;
public:
    Searcher(const std::vector<ull> &a, const std::vector<ull> &b);
    ull find_sort();
    ull find_different_sizes();
    ull find_small_sizes();
private:

};


#endif //VK_SEARCHER_H
