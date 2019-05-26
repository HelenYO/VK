//
// Created by Елена on 2019-05-26.
//

#ifndef VK_SEARCHER_H
#define VK_SEARCHER_H

#include <vector>
#include <iostream>


int too_mall_size = 100;
int small_size = 1000;



class Searcher {
std::vector<int> a;
std::vector<int> b;
public:
    Searcher(const std::vector<int> &a, const std::vector<int> &b);
    unsigned long find();
private:
    unsigned long find_sort();
    unsigned long find_different_sizes();
    unsigned long find_small_sizes();
};


#endif //VK_SEARCHER_H
