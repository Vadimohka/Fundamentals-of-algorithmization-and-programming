#include <cstring>
#include <gtest/gtest.h>
#include "String.h"

TEST(basic, creation) {
  String s;
  EXPECT_EQ(strlen(s.c_str()), 0);
}

TEST(basic, fromCharPtr) {
  String s("testtest");
  EXPECT_STREQ(s.c_str(), "testtest");
}


TEST(basic, copyConstructor) {
  String s("testtest");
  String s1(s);
  String s2(s1);

  s1.c_str()[0] = 'a';

  EXPECT_STREQ(s.c_str(), "testtest");
  EXPECT_STREQ(s1.c_str(), "aesttest");
  EXPECT_STREQ(s2.c_str(), "testtest");
}


TEST(basic, assignConstructor) {
  String s("testtest");
  String s1 = s;
  String s2 = s1;

  s1.c_str()[0] = 'a';

  EXPECT_STREQ(s.c_str(), "testtest");
  EXPECT_STREQ(s1.c_str(), "aesttest");
  EXPECT_STREQ(s2.c_str(), "testtest");
}

TEST(basic, len) {
  String s("testtest");
  EXPECT_EQ(s.len(), 8);
}


TEST(memop, slice) {
  String s("testtest");
  String s1 = s.slice(2, 4);

  EXPECT_STREQ(s.c_str(), "testtest");
  EXPECT_STREQ(s1.c_str(), "stte");
}

TEST(memop, sliceEnd) {
  String s("testtest");
  String s1 = s.slice(2);

  EXPECT_STREQ(s1.c_str(), "sttest");
}

TEST(memop, concat) {
  String s1("test123");
  String s2("456testmore");
  String s = s1 + s2;

  EXPECT_STREQ(s1.c_str(), "test123");
  EXPECT_STREQ(s2.c_str(), "456testmore");

  EXPECT_STREQ(s.c_str(), "test123456testmore");
}

TEST(cmpop, eqstr) {
  String s1("test123");
  String s2("test123");
  EXPECT_EQ(s1.cmp(s2), 0);
  EXPECT_EQ(s2.cmp(s1), 0);
  EXPECT_TRUE(s1 == s2);
  EXPECT_FALSE(s1 != s2);
}

TEST(cmpop, dif) {
  String s1("aaa");
  String s2("ab");
  EXPECT_EQ(s1.cmp(s2), -1);
  EXPECT_EQ(s2.cmp(s1), 1);
  EXPECT_TRUE(s1 < s2);
  EXPECT_TRUE(s2 > s1);
  EXPECT_TRUE(s1 != s2);
}

TEST(tok, tokenize) {
  String s1("- This, a sample string.");
  std::vector<String> tokens = s1.tokenize(" ,.-");
  
  EXPECT_EQ(tokens.size(), 4);
  EXPECT_STREQ(tokens[0].c_str(), "This");
  EXPECT_STREQ(tokens[1].c_str(), "a");
  EXPECT_STREQ(tokens[2].c_str(), "sample");
  EXPECT_STREQ(tokens[3].c_str(), "string");
}


TEST(err, fromErr) {
  String s1 = String::fromErrno(ENOENT);

  EXPECT_STREQ(s1.c_str(), "No such file or directory");
}