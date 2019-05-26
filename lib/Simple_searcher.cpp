//
// Created by Елена on 2019-05-26.
//

#include "Simple_searcher.h"

Stupid_searcher::Stupid_searcher(const std::vector<ull> &a, const std::vector<ull> &b) : a(a), b(b) {}

ull Stupid_searcher::find() {
    ull answer = 0;
    if (a.size() == 0 || b.size() == 0) {
        return 0;
    }
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
