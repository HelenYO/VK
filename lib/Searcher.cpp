//
// Created by Елена on 2019-05-26.
//

#include <unordered_set>
#include "Searcher.h"

Searcher::Searcher(const std::vector<int> &a, const std::vector<int> &b) : a(a), b(b) {}

unsigned long Searcher::find_different_sizes() {
    unsigned long answer = 0;
    if(a.empty() || b.empty()) {
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

unsigned long Searcher::find_small_sizes() {
    std::unordered_set<int> set;
    for (int &i : a) {
        set.emplace(i);
    }
    for (int &i : b) {
        set.emplace(i);
    }

    unsigned long answer = a.size() - (set.size() - b.size());
    return answer;
}

unsigned long Searcher::find_sort() {
    unsigned long answer = 0;
    if (a.empty() || b.empty())
        return 0;
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    int index_a = 0, index_b = 0;
    unsigned long size = a.size() + b.size();
    for (unsigned long i = 0; i < size; ++i) {
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

unsigned long Searcher::find() {
    if (a.size() <= too_mall_size || b.size() <= too_mall_size) {
        return find_different_sizes();
    } else if (a.size() <= small_size & b.size() <= small_size) {
        return find_small_sizes();
    } else {
        return find_sort();
    }
}
