//
// Created by Елена on 2019-05-26.
//

#ifndef VK_SEARCHER_H
#define VK_SEARCHER_H

#include <vector>
#include <iostream>

typedef unsigned long long ull;

ull too_mall_size = 100;
ull small_size = 1000;



class Searcher {
std::vector<ull> a;
std::vector<ull> b;
public:
    Searcher(const std::vector<ull> &a, const std::vector<ull> &b);
    ull find();
private:
    ull find_sort();
    ull find_different_sizes();
    ull find_small_sizes();
};


#endif //VK_SEARCHER_H
