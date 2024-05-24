#include "Deque.h"
// #include "List.h"
#include <cstdlib>
#include <deque>
#include <gtest/gtest.h>
TEST(deque, BASIC_PUSH_BACK) {
  Deque<int> d;
  for (int i = 0; i < 32768 * 2; ++i) {
    auto l = std::rand();
    d.push_back(l);
    ASSERT_EQ(d.back(), l);

    auto q = std::rand();
    d.push_front(q);
    ASSERT_EQ(d.front(), q);
  }
}

TEST(deque, BASIC_POP_BACK) {
  Deque<int> d;

  for (int i = 0; i < 1337; ++i) {

    auto l = std::rand();
    d.push_back(l);

    auto push_pop_cnt = std::rand() % 3123;
    for (int j = 0; j < push_pop_cnt; ++j) {
      d.push_back(std::rand());
    }
    for (int j = 0; j < push_pop_cnt; ++j) {
      d.pop_back();
    }

    ASSERT_EQ(d.back(), l);
  }
}

TEST(deque, POP_FRONT_BACK) {
  Deque<int> d;
  for (int i = 0; i < 4096; ++i) {

    auto a = 4372;
    auto b = 2734;
    auto val = std::rand();

    d.push_front(val);

    for (int j = 0; j < a; ++j) {
      d.push_back(std::rand());
    }
    for (int j = 0; j < b; ++j) {
      d.push_front(std::rand());
    }
    for (int j = 0; j < a; ++j) {
      d.pop_back();
    }
    for (int j = 0; j < b; ++j) {
      d.pop_front();
    }

    ASSERT_EQ(d.front(), val);
  }
}

TEST(deque, ITERATOR) {
  Deque<int> d;
  int vals[8092];
  for (int i = 0; i < 8092; ++i) {
    vals[i] = std::rand();
    d.push_back(vals[i]);
  }

  int cnt = 0;
  for (auto i = d.begin(); i != d.end(); ++i) {
    ASSERT_EQ(vals[cnt], *i);
    ++cnt;
  }
}

// for fun
TEST(std_deque, POP_FRONT_BACK) {
  std::deque<int> d;
  for (int i = 0; i < 4096; ++i) {

    auto a = 4372;
    auto b = 2734;
    auto val = std::rand();

    d.push_front(val);

    for (int j = 0; j < a; ++j) {
      d.push_back(std::rand());
    }
    for (int j = 0; j < b; ++j) {
      d.push_front(std::rand());
    }
    for (int j = 0; j < a; ++j) {
      d.pop_back();
    }
    for (int j = 0; j < b; ++j) {
      d.pop_front();
    }

    ASSERT_EQ(d.front(), val);
  }
}

// TEST(list, BASIC){
//   List<int> l;
//   auto val = std::rand();
//   l.push_back(val);
//   for(int i = 0; i < 2048; ++i){
//     l.push_back(std::rand());
//   }
//   for(int i = 0; i < 2048; ++i){
//     l.pop_back();
//   }
//   ASSERT_EQ(l.back(), val);
// }

int main(int argc, char **argv) {
  std::srand(time(nullptr));
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}