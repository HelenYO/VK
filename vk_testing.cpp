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
    std::vector<int> a, b;
    Searcher first(a, b);
    Stupid_searcher second(a,b);
    int right = second.find();
    EXPECT_EQ(right, first.find());
}

namespace {
    std::vector<int> generation(unsigned long n, int from, int to) {

        if(from > to) {
            std::swap(from, to);
        }

        std::vector<int> last_gen(n);

        for (int k = 0; k < n; ++k) {
            int q  = 1;
            while(q != 0) {
                srand(static_cast<unsigned int>(time(nullptr)));
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
    std::vector<int> a = generation(5, 5, 11);
    std::vector<int> b = generation(5, 5, 11);

    Searcher first(a, b);
    Stupid_searcher second(a,b);
    int right = second.find();
    EXPECT_EQ(right, first.find());

}

TEST(correctness, small) // NOLINT
{
    std::vector<int> a = generation(400, -10000, 1100000);
    std::vector<int> b = generation(550, -10000, 110000);

    Searcher first(a, b);
    Stupid_searcher second(a,b);
    int right = second.find();
    EXPECT_EQ(right, first.find());
}

TEST(correctness, big) // NOLINT
{
    std::vector<int> a = generation(3000, -4000, 1100000);
    std::vector<int> b = generation(1500, -4000, 110000);

    Searcher first(a, b);
    Stupid_searcher second(a,b);
    int right = second.find();
    EXPECT_EQ(right, first.find());
}

TEST(correctness, big_zero) // NOLINT
{
    std::vector<int> a = generation(3000, 0, 1100000);
    std::vector<int> b = generation(0, 0, 110000);

    Searcher first(a, b);
    Stupid_searcher second(a,b);
    int right = second.find();
    EXPECT_EQ(right, first.find());
}

TEST(correctness, zero) // NOLINT
{
    std::vector<int> a = generation(1100, -200, 2000);
    std::vector<int> b = generation(200, 40000, 50000);

    Searcher first(a, b);
    Stupid_searcher second(a,b);
    int right = second.find();
    EXPECT_EQ(right, first.find());
}

TEST(correctness, zero2) // NOLINT
{
    std::vector<int> a = generation(1100, -200, 2000);
    std::vector<int> b = generation(2000, 40000, 50000);

    Searcher first(a, b);
    Stupid_searcher second(a,b);
    int right = second.find();
    EXPECT_EQ(right, first.find());
}

TEST(correctness, zero3) // NOLINT
{
    std::vector<int> a = generation(1100, -20000, 2000);
    std::vector<int> b = generation(2, 40000, 50000);

    Searcher first(a, b);
    Stupid_searcher second(a,b);
    int right = second.find();
    EXPECT_EQ(right, first.find());
}

TEST(correctness, all_big) // NOLINT
{
    std::vector<int> a = generation(1100, 0, 1100);
    std::vector<int> b = generation(1100, 0, 1100);

    Searcher first(a, b);
    Stupid_searcher second(a,b);
    int right = second.find();
    EXPECT_EQ(right, first.find());
}

TEST(correctness, all_big2) // NOLINT
{
    std::vector<int> a = generation(1100, -1100, 0);
    std::vector<int> b = generation(1100, -1100, 0);

    Searcher first(a, b);
    Stupid_searcher second(a,b);
    int right = second.find();
    EXPECT_EQ(right, first.find());
}

TEST(correctness, all_small) // NOLINT
{
    std::vector<int> a = generation(900, 0, 900);
    std::vector<int> b = generation(900, 0, 900);

    Searcher first(a, b);
    Stupid_searcher second(a,b);
    int right = second.find();
    EXPECT_EQ(right, first.find());
}

TEST(correctness, all_small2) // NOLINT
{
    std::vector<int> a = generation(900, -900, 0);
    std::vector<int> b = generation(900, -900, 0);

    Searcher first(a, b);
    Stupid_searcher second(a,b);
    int right = second.find();
    EXPECT_EQ(right, first.find());
}

TEST(correctness, all_too_small) // NOLINT
{
    std::vector<int> a = generation(900, 0, 900);
    std::vector<int> b = generation(10, 0, 900);

    Searcher first(a, b);
    Stupid_searcher second(a,b);
    int right = second.find();
    EXPECT_EQ(right, first.find());
}

TEST(correctness, all_too_small2) // NOLINT
{
    std::vector<int> a = generation(900, -900, 0);
    std::vector<int> b = generation(10, -900, 0);

    Searcher first(a, b);
    Stupid_searcher second(a,b);
    int right = second.find();
    EXPECT_EQ(right, first.find());
}