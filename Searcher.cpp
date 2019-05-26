//
// Created by Елена on 2019-05-26.
//

#include <unordered_set>
#include "Searcher.h"

Searcher::Searcher(const std::vector<ull> &a, const std::vector<ull> &b) : a(a), b(b) {}

ull Searcher::find_different_sizes() {
    ull answer = 0;
    if (a.size() < b.size()) {
        for (int i = 0; i < b.size(); ++i) {
            for (int j = 0; j < a.size(); ++j) {
                if(a[j] == b[i]) {
                    ++answer;
                    break;
                }
            }
        }
    } else {
        for (int i = 0; i < a.size(); ++i) {
            for (int j = 0; j < b.size(); ++j) {
                if(a[i] == b[j]) {
                    ++answer;
                    break;
                }
            }
        }
    }
    return answer;
}

ull Searcher::find_small_sizes() {
    std::unordered_set<ull> set;
    for (int i = 0; i < a.size(); ++i) {
        set.emplace(a[i]);
    }
    for (int i = 0; i < b.size(); ++i) {
        set.emplace(b[i]);
    }

    ull answer = a.size() - (set.size() - b.size());
    return answer;
}

ull Searcher::find_sort() {
    ull answer = 0;
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    ull index_a = 0, index_b = 0;
    ull size = a.size() + b.size();
    for (int i = 0; i < size; ++i) {
        if(a[index_a] > b[index_b]) {
            if(index_b < b.size() - 1) {
                ++index_b;
            } else {
                break;
            }
        } else if(a[index_a] < b[index_b]) {
            if(index_a < a.size() - 1) {
                ++index_a;
            } else {
                break;
            }
        } else {
            ++answer;
            if(index_a == a.size() - 1 || index_b == b.size() - 1) {
                break;
            } else {
                ++index_a;
                ++index_b;
            }
        }
    }
    return answer;
}
