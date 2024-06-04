#include "SearchTree.h"
#include <gtest/gtest.h>

TEST(basic, creation) { SearchTree<int> tree; }

TEST(basic, contains) {
  SearchTree<int> tree;
  EXPECT_FALSE(tree.contains(10));
  tree.insert(10, 1000);
  EXPECT_TRUE(tree.contains(10));
}

TEST(basic, get) {
  SearchTree<int> tree;
  EXPECT_FALSE(tree.contains(10));
  tree.insert(10, 1000);
  EXPECT_EQ(tree.get(10), 1000);
}

int mangle_key(long key) { return (key * 893923 + 1152931) % 10000007; }

TEST(filled, size16) {
  SearchTree<int> tree;
  for (int i = 0; i < 30; i++) {
    tree.insert(mangle_key(i), 1000 + i);
  }

  EXPECT_FALSE(tree.contains(1000));

  for (int i = 0; i < 30; i++) {
    EXPECT_TRUE(tree.contains(mangle_key(i)));
    EXPECT_EQ(tree.get(mangle_key(i)), 1000 + i);
  }
}

TEST(constr, copyAssign) {
  SearchTree<int> tree;
  for (int i = 0; i < 16; i++) {
    tree.insert(mangle_key(i), 1000 + i);
  }

  SearchTree<int> tree2;
  tree2 = tree;
  SearchTree<int> tree3(tree2);

  EXPECT_FALSE(tree3.contains(mangle_key(1000)));

  for (int i = 0; i < 16; i++) {
    EXPECT_TRUE(tree3.contains(mangle_key(i)));
    EXPECT_EQ(tree3.get(mangle_key(i)), 1000 + i);
  }
}

TEST(constr, moveAssign) {
  SearchTree<int> tree;
  for (int i = 0; i < 16; i++) {
    tree.insert(i, 1000 + i);
  }

  SearchTree<int> tree2;
  tree2 = std::move(tree);
  SearchTree<int> map3(std::move(tree));

  EXPECT_FALSE(map3.contains(1000));

  for (int i = 0; i < 16; i++) {
    EXPECT_TRUE(map3.contains(i));
    EXPECT_EQ(map3.get(i), 1000 + i);
  }
}

TEST(mem, strings) {
  SearchTree<std::string> tree;

  std::string vals[8] = {
      "sdfdsf",      "s131ef",        "sdd342gfg", "6u5ujtuytu",
      "45hogfhifyt", "y35thgfrytety", "545gfhhgf", "12313fpkff",
  };

  for (int i = 0; i < 8; i++) {
    tree.insert(mangle_key(i) * 88 + 42, vals[i]);
  }

  SearchTree<std::string> tree2;
  tree2 = std::move(tree);
  SearchTree<std::string> tree3(std::move(tree2));

  EXPECT_FALSE(tree3.contains(1000));

  for (int i = 0; i < 8; i++) {
    EXPECT_TRUE(tree3.contains(mangle_key(i) * 88 + 42));
    EXPECT_EQ(tree3.get(mangle_key(i) * 88 + 42), vals[i]);
  }
}

TEST(repeat, assign) {
  SearchTree<int> tree;
  for(int i = 0; i < 16; i++) {
    tree.insert(mangle_key(i), 1000 + i);
  }

  for(int i = 0; i < 16; i+=2) {
    tree.insert(mangle_key(i), 2000 + i);
  }

  for(int i = 0; i < 16; i++) {
    int exp = i % 2 == 0 ? 2000 + i : 1000 + i;
    EXPECT_EQ(tree.get(mangle_key(i)), exp);
  }
}


TEST(remove, basic) {
  SearchTree<int> tree;
  for(int i = 0; i < 256; i++) {
    tree.insert(mangle_key(i), 1000 + i);
  }

  for(int i = 0; i < 256; i+=2) {
    tree.remove(mangle_key(i));
  }

  for(int i = 0; i < 256; i++) {
    if(i % 2 == 0) {
      EXPECT_FALSE(tree.contains(mangle_key(i)));
    } else {
      EXPECT_TRUE(tree.contains(mangle_key(i)));
    }
  }
}

TEST(balance, basic) {
  SearchTree<int> tree;
  for(int i = 0; i < 256; i++) {
    tree.insert(mangle_key(i), 1000 + i);
  }

  tree.balance();
  // for(int i = 0; i < 256; i+=2) {
  //   tree.remove(mangle_key(i));
  // }

  for(int i = 0; i < 256; i++) {
    EXPECT_EQ(tree.get(mangle_key(i)), 1000 + i);
  }
}


TEST(balance, removes) {
  SearchTree<int> tree;
  for(int i = 0; i < 1000; i++) {
    tree.insert(mangle_key(i), 1000 + i);
  }

  tree.balance();
  for(int i = 0; i < 1000; i+=2) {
    tree.remove(mangle_key(i));
  }

  for(int i = 0; i < 1000; i++) {
    if(i % 2 == 0) {
      EXPECT_FALSE(tree.contains(mangle_key(i)));
    } else {
      EXPECT_EQ(tree.get(mangle_key(i)), 1000 + i);
    }
  }
}




TEST(walk, incrementing) {
  SearchTree<int> tree;
  for(int i = 0; i < 1000; i++) {
    tree.insert(i, 1000 + i);
  }

  {
    int **v = tree.walk(WalkMode::Incrementing);
    for(int i = 0; i < 1000; i++) {
      EXPECT_EQ(*v[i], 1000 + i);
    }
    delete[] v;
  }

  {
    int **v = tree.walk(WalkMode::Incrementing);
    for(int i = 0; i < 1000; i++) {
      EXPECT_EQ(*v[i], 1000 + i);
    }
    delete[] v;
  }
}
