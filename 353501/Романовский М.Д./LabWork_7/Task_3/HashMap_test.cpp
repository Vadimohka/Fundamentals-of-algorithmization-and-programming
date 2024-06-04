#include "HashMap.h"
#include <gtest/gtest.h>

TEST(basic, creation) {
  HashMap<int> map(16);
}

TEST(basic, contains) {
  HashMap<int> map(16);
  EXPECT_FALSE(map.contains(10));
  map.insert(10, 1000);
  EXPECT_TRUE(map.contains(10));
}


TEST(basic, get) {
  HashMap<int> map(16);
  EXPECT_FALSE(map.contains(10));
  map.insert(10, 1000);
  EXPECT_EQ(map.get(10), 1000);
}


TEST(filled, size16) {
  HashMap<int> map(16);
  for(int i = 0; i < 30; i++) {
    map.insert(i, 1000 + i);
  }

  EXPECT_FALSE(map.contains(1000));

  for(int i = 0; i < 30; i++) {
    EXPECT_TRUE(map.contains(i));
    EXPECT_EQ(map.get(i), 1000 + i);
  }
}



TEST(constr, copyAssign) {
  HashMap<int> map(16);
  for(int i = 0; i < 16; i++) {
    map.insert(i, 1000 + i);
  }

  HashMap<int> map2(100);
  map2 = map;
  HashMap<int> map3(map2);

  EXPECT_FALSE(map3.contains(1000));

  for(int i = 0; i < 16; i++) {
    EXPECT_TRUE(map3.contains(i));
    EXPECT_EQ(map3.get(i), 1000 + i);
  }
}


TEST(constr, moveAssign) {
  HashMap<int> map(16);
  for(int i = 0; i < 16; i++) {
    map.insert(i, 1000 + i);
  }

  HashMap<int> map2(100);
  map2 = std::move(map);
  HashMap<int> map3(std::move(map2));

  EXPECT_FALSE(map3.contains(1000));

  for(int i = 0; i < 16; i++) {
    EXPECT_TRUE(map3.contains(i));
    EXPECT_EQ(map3.get(i), 1000 + i);
  }
}


TEST(mem, strings) {
  HashMap<std::string> map(16);

  std::string vals[8] = {
    "sdfdsf",
    "s131ef",
    "sdd342gfg",
    "6u5ujtuytu",
    "45hogfhifyt",
    "y35thgfrytety",
    "545gfhhgf",
    "12313fpkff",
  };

  for(int i = 0; i < 8; i++) {
    map.insert(i * 88 + 42, vals[i]);
  }

  HashMap<std::string> map2(100);
  map2 = std::move(map);
  HashMap<std::string> map3(std::move(map2));

  EXPECT_FALSE(map3.contains(1000));

  for(int i = 0; i < 8; i++) {
    EXPECT_TRUE(map3.contains(i * 88 + 42));
    EXPECT_EQ(map3.get(i * 88 + 42), vals[i]);
  }
}


TEST(repeat, assign) {
  HashMap<int> map(16);
  for(int i = 0; i < 16; i++) {
    map.insert(i, 1000 + i);
  }

  for(int i = 0; i < 16; i+=2) {
    map.insert(i, 2000 + i);
  }

  for(int i = 0; i < 16; i++) {
    int exp = i % 2 == 0 ? 2000 + i : 1000 + i;
    EXPECT_EQ(map.get(i), exp);
  }
}
