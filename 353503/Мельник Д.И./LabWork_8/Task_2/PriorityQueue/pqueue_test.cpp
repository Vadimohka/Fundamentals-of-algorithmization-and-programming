#include "PriorityQueue.h"
#include "PriorityTree.cpp"
#include "gtest/gtest.h"
#include <algorithm>
#include <climits>
#include <cstdlib>

TEST(pqueue, BASIC) {
  auto NUM = 128000;
  PriorityQueue<long> pq;

  std::vector<long> sorted;
  for (int i = 0; i < NUM; ++i) {
    long val = std::rand();
    sorted.push_back(val);
    pq.push(val);
  }
  std::sort(sorted.begin(), sorted.end());

  for (int i = 0; i < NUM; ++i) {
    ASSERT_EQ(sorted[NUM - i - 1], pq.pop());
  }
}

TEST(pqueue, TREE) {
  auto NUM = 128000;
  PriorityTree<long> pt;
  std::vector<long> sorted;

  long max_val = LONG_MIN;

  for (int i = 0; i < NUM; ++i) {
    long val = std::rand();
    max_val = std::max(val, max_val);
    sorted.push_back(val);
    pt.push(val);

    ASSERT_EQ(pt.max(), max_val);
  }

  ASSERT_EQ(pt.size(), NUM);

  std::sort(sorted.begin(), sorted.end());

  for (int i = 0; i < NUM; ++i) {
    ASSERT_EQ(sorted[NUM - i - 1], pt.pop());
  }
}

int main(int argc, char **argv) {
  std::srand(time(nullptr));
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}