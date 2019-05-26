//
// Created by Елена on 2019-05-26.
//

#ifndef VK_STUPID_SEARCHER_H
#define VK_STUPID_SEARCHER_H

#include <vector>
#include <iostream>

typedef unsigned long long ull;


class Stupid_searcher {
    std::vector<ull> a;
    std::vector<ull> b;
public:
    Stupid_searcher(const std::vector<ull> &a, const std::vector<ull> &b);
    ull find();
};


#endif //VK_STUPID_SEARCHER_H
