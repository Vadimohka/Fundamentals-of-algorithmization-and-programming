#include "RBTree.h"
#include <gtest/gtest.h>

TEST(basic, creation) {
  RBTree<int, int> map;
}

TEST(basic, contains) {
  RBTree<int, int> map;
  EXPECT_FALSE(map.contains(10));
  map.insert(10, 1000);
  EXPECT_TRUE(map.contains(10));
}


TEST(basic, get) {
  RBTree<int, int> map;
  EXPECT_FALSE(map.contains(10));
  map.insert(10, 1000);
  EXPECT_EQ(map.get(10), 1000);
}


int mangle_key(long key) { return (key * 893923 + 1152931) % 10000007; }

TEST(filled, size16) {
  RBTree<int, int> map;
  for(int i = 0; i < 16; i++) {
    map.insert(mangle_key(i), 1000 + i);
    map.validateTree();
  }

  EXPECT_FALSE(map.contains(mangle_key(1000)));

  for(int i = 0; i < 16; i++) {
    EXPECT_TRUE(map.contains(mangle_key(i)));
    EXPECT_EQ(map.get(mangle_key(i)), 1000 + i);
  }
}


TEST(filled, size1024) {
  RBTree<int, int> map;
  for(int i = 0; i < 1024; i++) {
    map.insert(mangle_key(i), 1000 + i);
    map.validateTree();
  }

  EXPECT_FALSE(map.contains(mangle_key(10000)));

  for(int i = 0; i < 1024; i++) {
    EXPECT_TRUE(map.contains(mangle_key(i)));
    EXPECT_EQ(map.get(mangle_key(i)), 1000 + i);
  }

  EXPECT_LE(map.maxDepth(), 14);
}

TEST(remove, size16) {
  RBTree<int, int> map;
  for(int i = 0; i < 16; i++) {
    map.insert(mangle_key(i), 1000 + i);
    map.validateTree();
  }

  for(int i = 0; i < 16; i+=2) {
    map.erase(mangle_key(i));
    map.validateTree();
  }

  for(int i = 0; i < 16; i++) {
    if(i % 2 == 0) {
      EXPECT_FALSE(map.contains(mangle_key(i)));
    } else {
      EXPECT_TRUE(map.contains(mangle_key(i)));
      EXPECT_EQ(map.get(mangle_key(i)), 1000 + i);
    }
  }

  // EXPECT_LE(map.maxDepth(), 4);
}

TEST(remove, size1024) {
  RBTree<int, int> map;
  for(int i = 0; i < 1024; i++) {
    map.insert(mangle_key(i), 1000 + i);
    map.validateTree();
  }

  for(int i = 0; i < 1024; i+=4) {
    map.erase(mangle_key(i));
    map.erase(mangle_key(i+1));
    map.erase(mangle_key(i+2));
    map.validateTree();
  }

  for(int i = 0; i < 16; i++) {
    if(i % 4 != 3) {
      EXPECT_FALSE(map.contains(mangle_key(i)));
    } else {
      EXPECT_TRUE(map.contains(mangle_key(i)));
      EXPECT_EQ(map.get(mangle_key(i)), 1000 + i);
    }
  }

  EXPECT_LE(map.maxDepth(), 10);
}




// TEST(constr, copyAssign) {
//   RBTree<int, int> map(16);
//   for(int i = 0; i < 16; i++) {
//     map.insert(i, 1000 + i);
//   }

//   RBTree<int, int> map2(100);
//   map2 = map;
//   RBTree<int, int> map3(map2);

//   EXPECT_FALSE(map3.contains(1000));

//   for(int i = 0; i < 16; i++) {
//     EXPECT_TRUE(map3.contains(i));
//     EXPECT_EQ(map3.get(i), 1000 + i);
//   }
// }


// TEST(constr, moveAssign) {
//   RBTree<int, int> map(16);
//   for(int i = 0; i < 16; i++) {
//     map.insert(i, 1000 + i);
//   }

//   RBTree<int, int> map2(100);
//   map2 = std::move(map);
//   RBTree<int, int> map3(std::move(map2));

//   EXPECT_FALSE(map3.contains(1000));

//   for(int i = 0; i < 16; i++) {
//     EXPECT_TRUE(map3.contains(i));
//     EXPECT_EQ(map3.get(i), 1000 + i);
//   }
// }


// TEST(mem, strings) {
//   RBTree<int, std::string> map(16);

//   std::string vals[8] = {
//     "sdfdsf",
//     "s131ef",
//     "sdd342gfg",
//     "6u5ujtuytu",
//     "45hogfhifyt",
//     "y35thgfrytety",
//     "545gfhhgf",
//     "12313fpkff",
//   };

//   for(int i = 0; i < 8; i++) {
//     map.insert(i * 88 + 42, vals[i]);
//   }

//   RBTree<int, std::string> map2(100);
//   map2 = std::move(map);
//   RBTree<int, std::string> map3(std::move(map2));

//   EXPECT_FALSE(map3.contains(1000));

//   for(int i = 0; i < 8; i++) {
//     EXPECT_TRUE(map3.contains(i * 88 + 42));
//     EXPECT_EQ(map3.get(i * 88 + 42), vals[i]);
//   }
// }

// TEST(repeat, assign) {
//   RBTree<int, int> map(16);
//   for(int i = 0; i < 16; i++) {
//     map.insert(i, 1000 + i);
//   }

//   for(int i = 0; i < 16; i+=2) {
//     map.insert(i, 2000 + i);
//   }

//   for(int i = 0; i < 16; i++) {
//     int exp = i % 2 == 0 ? 2000 + i : 1000 + i;
//     EXPECT_EQ(map.get(i), exp);
//   }
// }

TEST(iter, forward) {
  RBTree<int, int> map;
  for(int i = 0; i < 1024; i++) {
    map.insert(i, 1000 + i);
  }

  int count = 0;
  for(auto g: map) {
    EXPECT_EQ(count, g.key);
    count++;
  }
  EXPECT_EQ(count, 1024);
}



TEST(map, simpl) {
  Map<int, int> map;
  
  EXPECT_EQ(map[123], 0);
  map[123] = 1230;
  EXPECT_EQ(map[123], 1230);


  map[1203] = 88;
  EXPECT_EQ(map[1203], 88);

  map[123] ++;
  EXPECT_EQ(map[123], 1231);
}
