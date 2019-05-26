//
// Created by Елена on 2019-05-26.
//

#ifndef VK_STUPID_SEARCHER_H
#define VK_STUPID_SEARCHER_H

#include <vector>
#include <iostream>


class Stupid_searcher {
    std::vector<int> a;
    std::vector<int> b;
public:
    Stupid_searcher(const std::vector<int> &a, const std::vector<int> &b);
    int find();
};


#endif //VK_STUPID_SEARCHER_H
