//
// Created by Елена on 2019-05-26.
//

#include "Simple_searcher.h"

Stupid_searcher::Stupid_searcher(const std::vector<int> &a, const std::vector<int> &b) : a(a), b(b) {}

int Stupid_searcher::find() {
    int answer = 0;
    if (a.empty() || b.empty()) {
        return 0;
    }
    if (a.size() < b.size()) {
        for (int i : b) {
            for (int j : a) {
                if(j == i) {
                    ++answer;
                    break;
                }
            }
        }
    } else {
        for (int i : a) {
            for (int j : b) {
                if(i == j) {
                    ++answer;
                    break;
                }
            }
        }
    }
    return answer;
}
