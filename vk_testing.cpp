//
// Created by Елена on 2019-05-26.
//

#include <sstream>
#include <random>
#include "gtest/gtest.h"

#include "lib/Searcher.h"
#include "lib/Simple_searcher.h"


TEST(correctness, blank) // NOLINT
{
    std::vector<ull> a, b;
    Searcher first(a, b);
    Stupid_searcher second(a,b);
    ull right = second.find();
    EXPECT_EQ(right, first.find());
}

namespace {
    std::vector<ull> generation(ull n, ull from, ull to) {

        if(from > to) {
            std::swap(from, to);
        }

        std::vector<ull> last_gen(n);

        for (int k = 0; k < n; ++k) {
            int q  = 1;
            while(q != 0) {
                srand(time(NULL));
                while (q) {
                    q = 0;
                    last_gen[k] = rand() % (to - from) + 1 + from;
                    if (k != 0) {
                        for (int i = 0; i < k; i++) {
                            if (last_gen[k] == last_gen[i]) {
                                q = 1;
                                break;
                            }
                        }
                    }
                }
            }
        }
        return last_gen;
    }
}

TEST(correctness, too_small) // NOLINT
{
    std::vector<ull> a = generation(5, 5, 11);
    std::vector<ull> b = generation(5, 5, 11);

    Searcher first(a, b);
    Stupid_searcher second(a,b);
    ull right = second.find();
    EXPECT_EQ(right, first.find());

}

TEST(correctness, small) // NOLINT
{
    std::vector<ull> a = generation(400, 0, 1100000);
    std::vector<ull> b = generation(550, 0, 110000);

    Searcher first(a, b);
    Stupid_searcher second(a,b);
    ull right = second.find();
    EXPECT_EQ(right, first.find());
}

TEST(correctness, big) // NOLINT
{
    std::vector<ull> a = generation(3000, 0, 1100000);
    std::vector<ull> b = generation(1500, 0, 110000);

    Searcher first(a, b);
    Stupid_searcher second(a,b);
    ull right = second.find();
    EXPECT_EQ(right, first.find());
}

TEST(correctness, big_zero) // NOLINT
{
    std::vector<ull> a = generation(3000, 0, 1100000);
    std::vector<ull> b = generation(0, 0, 110000);

    Searcher first(a, b);
    Stupid_searcher second(a,b);
    ull right = second.find();
    EXPECT_EQ(right, first.find());
}

TEST(correctness, zero) // NOLINT
{
    std::vector<ull> a = generation(1100, 0, 2000);
    std::vector<ull> b = generation(200, 40000, 50000);

    Searcher first(a, b);
    Stupid_searcher second(a,b);
    ull right = second.find();
    EXPECT_EQ(right, first.find());
}

TEST(correctness, zero2) // NOLINT
{
    std::vector<ull> a = generation(1100, 0, 2000);
    std::vector<ull> b = generation(2000, 40000, 50000);

    Searcher first(a, b);
    Stupid_searcher second(a,b);
    ull right = second.find();
    EXPECT_EQ(right, first.find());
}

TEST(correctness, zero3) // NOLINT
{
    std::vector<ull> a = generation(1100, 0, 2000);
    std::vector<ull> b = generation(2, 40000, 50000);

    Searcher first(a, b);
    Stupid_searcher second(a,b);
    ull right = second.find();
    EXPECT_EQ(right, first.find());
}

TEST(correctness, all_big) // NOLINT
{
    std::vector<ull> a = generation(1100, 0, 1100);
    std::vector<ull> b = generation(1100, 0, 1100);

    Searcher first(a, b);
    Stupid_searcher second(a,b);
    ull right = second.find();
    EXPECT_EQ(right, first.find());
}

TEST(correctness, all_small) // NOLINT
{
    std::vector<ull> a = generation(900, 0, 900);
    std::vector<ull> b = generation(900, 0, 900);

    Searcher first(a, b);
    Stupid_searcher second(a,b);
    ull right = second.find();
    EXPECT_EQ(right, first.find());
}

TEST(correctness, all_too_small) // NOLINT
{
    std::vector<ull> a = generation(900, 0, 900);
    std::vector<ull> b = generation(10, 0, 900);

    Searcher first(a, b);
    Stupid_searcher second(a,b);
    ull right = second.find();
    EXPECT_EQ(right, first.find());
}