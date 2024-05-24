#include "Vector.h"
#include <gtest/gtest.h>

TEST(basic, create) {
  Vector<int> vec;
  EXPECT_EQ(vec.size(), 0);
  EXPECT_NE(vec.data(), nullptr);
}

TEST(basic, pushback) {
  Vector<int> vec;
  vec.push_back(1);
  vec.push_back(12);
  vec.push_back(123);

  EXPECT_EQ(vec.at(0), 1);
  EXPECT_EQ(vec.at(1), 12);
  EXPECT_EQ(vec.at(2), 123);
}

TEST(basic, pushbackStr) {
  Vector<std::string> vec;
  vec.push_back("1");
  vec.push_back("12");
  vec.push_back("123");

  EXPECT_EQ(vec.size(), 3);

  EXPECT_EQ(vec.at(0), std::string("1"));
  EXPECT_EQ(vec.at(1), std::string("12"));
  EXPECT_EQ(vec.at(2), std::string("123"));
}

TEST(basic, pushbackBig) {
  Vector<std::string> vec;
  {
    std::string acc = "a";
    vec.reserve(2048);
    vec.reserve(4096);
    vec.reserve(8192);

    for (int i = 0; i < 1024; i++) {
      acc += "b";
      vec.push_back(acc);
    }
  }

  EXPECT_EQ(vec.size(), 1024);

  {
    std::string acc = "a";
    for (int i = 0; i < 1024; i++) {
      acc += "b";
      EXPECT_EQ(vec.at(i), acc);
    }
  }
}

TEST(basic, reserve) {
  Vector<int> vec;
  EXPECT_EQ(vec.size(), 0);
  vec.reserve(100);
  EXPECT_NE(vec.data(), nullptr);
}

TEST(basic, clear) {
  Vector<int> vec;
  vec.push_back(1);
  vec.push_back(12);
  vec.push_back(123);
  vec.clear();
  EXPECT_EQ(vec.size(), 0);
}

TEST(basic, swap) {
  Vector<std::string> vec;
  vec.push_back("1");
  vec.push_back("12");
  vec.push_back("123");
  vec.push_back("1234");

  // EXPECT_EQ(vec.size(), 3);
  vec.swap(1, 3);

  EXPECT_EQ(vec.at(0), std::string("1"));
  EXPECT_EQ(vec.at(3), std::string("12"));
  EXPECT_EQ(vec.at(2), std::string("123"));
  EXPECT_EQ(vec.at(1), std::string("1234"));
}

TEST(basic, resize) {
  Vector<std::string> vec;
  vec.resize(5);

  EXPECT_EQ(vec.size(), 5);

  EXPECT_EQ(vec.at(0), std::string(""));
  EXPECT_EQ(vec.at(4), std::string(""));
  EXPECT_EQ(vec.at(2), std::string(""));
}

TEST(basic, popbackStr) {
  Vector<std::string> vec;
  vec.push_back("1");
  vec.push_back("12");
  vec.push_back("123");

  vec.pop_back();

  EXPECT_EQ(vec.size(), 2);
}

TEST(basic, insert) {
  Vector<std::string> vec;
  vec.push_back("1");
  vec.push_back("123");
  vec.push_back("1234");
  vec.insert(1, "12");

  EXPECT_EQ(vec.at(0), std::string("1"));
  EXPECT_EQ(vec.at(1), std::string("12"));
  EXPECT_EQ(vec.at(2), std::string("123"));
  EXPECT_EQ(vec.at(3), std::string("1234"));
}

TEST(basic, insertAsPush) {
  Vector<std::string> vec;
  vec.insert(0, "1");
  vec.insert(1, "12");
  vec.insert(2, "123");
  vec.insert(3, "1234");

  EXPECT_EQ(vec.at(0), std::string("1"));
  EXPECT_EQ(vec.at(1), std::string("12"));
  EXPECT_EQ(vec.at(2), std::string("123"));
  EXPECT_EQ(vec.at(3), std::string("1234"));
}


TEST(basic, erase) {
  Vector<std::string> vec;
  vec.push_back("1");
  vec.push_back("12");
  vec.push_back("aaaa");
  vec.push_back("123");
  vec.push_back("1234");

  vec.erase(2);

  EXPECT_EQ(vec.at(0), std::string("1"));
  EXPECT_EQ(vec.at(1), std::string("12"));
  EXPECT_EQ(vec.at(2), std::string("123"));
  EXPECT_EQ(vec.at(3), std::string("1234"));
}


TEST(basic, emplace) {
  Vector<std::string> vec;
  vec.push_back("1");
  vec.push_back("12");
  vec.push_back("123");
  vec.push_back("1234");
  vec.emplace(2);
  vec.emplace_back();

  EXPECT_EQ(vec.at(2), std::string(""));
  EXPECT_EQ(vec.at(5), std::string(""));

  EXPECT_EQ(vec.at(0), std::string("1"));
  EXPECT_EQ(vec.at(1), std::string("12"));
  EXPECT_EQ(vec.at(3), std::string("123"));
  EXPECT_EQ(vec.at(4), std::string("1234"));
}

TEST(iterator, simpleInt) {
  Vector<int> vec;
  vec.push_back(1);
  vec.push_back(2);
  vec.push_back(3);
  vec.push_back(4);

  int expected = 1;
  for(Vector<int>::Iterator cur = vec.begin(); cur != vec.end(); cur++) {
    EXPECT_EQ(*cur, expected);
    expected++;
  }

  EXPECT_EQ(expected, 5);
}


TEST(iterator, simpleRev) {
  Vector<int> vec;
  vec.push_back(1);
  vec.push_back(2);
  vec.push_back(3);
  vec.push_back(4);

  int expected = 4;
  for(Vector<int>::Iterator cur = vec.rbegin(); cur != vec.rend(); cur++) {
    EXPECT_EQ(*cur, expected);
    expected--;
  }

  EXPECT_EQ(expected, 0);
}



TEST(iterator, simpleInc) {
  Vector<int> vec;
  vec.push_back(1);
  vec.push_back(2);
  vec.push_back(3);
  vec.push_back(4);

  for(Vector<int>::Iterator cur = vec.rbegin(); cur != vec.rend(); cur++) {
    *cur = *cur + 10;
  }



  EXPECT_EQ(vec.at(0), 11);
  EXPECT_EQ(vec.at(1), 12);
  EXPECT_EQ(vec.at(2), 13);
  EXPECT_EQ(vec.at(3), 14);
}


TEST(iterator, const) {
  Vector<int> vec;
  vec.push_back(1);
  vec.push_back(2);
  vec.push_back(3);
  vec.push_back(4);

  int expected = 1;
  for(Vector<int>::ConstIterator cur = vec.cbegin(); cur != vec.cend(); cur++) {
    EXPECT_EQ(*cur, expected);
    expected++;
  }

  EXPECT_EQ(expected, 5);
}

TEST(brackets, read) {
  Vector<int> vec;
  vec.push_back(1);
  vec.push_back(12);
  vec.push_back(123);

  EXPECT_EQ(vec[0], 1);
  EXPECT_EQ(vec[1], 12);
  EXPECT_EQ(vec[2], 123);
}

TEST(brackets, write) {
  Vector<int> vec;
  vec.resize(3);
  vec[0] = 1;
  vec[1] = 12;
  vec[2] = 123;

  EXPECT_EQ(vec[0], 1);
  EXPECT_EQ(vec[1], 12);
  EXPECT_EQ(vec[2], 123);
}