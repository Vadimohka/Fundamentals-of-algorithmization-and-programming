
#include "RBTree.h"
#include <algorithm>
#include <climits>
#include <cstdlib>
#include <gtest/gtest.h>
#include <iostream>
#include <utility>

// TEST(rb_tree, insert_and_total_search) {
//   RBTree<long, long> bst;
//   std::vector<std::pair<long, long>> kvs;

//   for (int i = 0; i < 4096; ++i) {
//     long val = std::rand();
//     long key = std::rand() * ((std::rand() % 2) ? -1 : 1);

//     kvs.push_back({key, val});
//     bst.insert(key, val);
//     // std::cout << "passed " << i << '\n';
//     bst.validate_tree();

//     for (int j = 0; j < i; ++j) {
//       auto contains = bst.contains(kvs[j].first);
//       ASSERT_TRUE(contains);
//       ASSERT_EQ(bst.get(kvs[j].first), kvs[j].second);
//     }
//   }
// }

// TEST(bst, manual_remove){
//     BST<long> bst;

//     bst.insert(124, 163251);
//     bst.insert(121, 10);
//     bst.insert(126, 5);;
//     bst.remove(124);
//     bst.insert(125, 1231);

//     auto el = bst.search(121);
//     ASSERT_TRUE(el.is_valid());
//     ASSERT_EQ(*el, 10);

//     el = bst.search(126);
//     ASSERT_TRUE(el.is_valid());
//     ASSERT_EQ(*el, 5);

//     el = bst.search(124);
//     ASSERT_FALSE(el.is_valid());

// }

// TEST(bst, balance){
//     BSTWithDepth<long> bst;
//     for(int i = 0; i < 4096 * 8; ++i){
//         bst.insert(i, std::rand());
//     }

//     auto trav1 = bst.in_order_traverse();
//     std::cout << "before balance depth: " << bst.depth() << '\n';
//     bst.balance();
//     std::cout << "after balance depth: " << bst.depth() << '\n';
//     auto trav2 = bst.in_order_traverse();

//     ASSERT_EQ(trav1.size(), trav2.size());
//     for(int i = 0; i < trav1.size(); ++i){
//         ASSERT_EQ(trav1[i].val, trav2[i].   val);
//     }
// }

TEST(bst, insert_remove_insert) {
  RBTree<long, long> bst;

  std::set<long> keys;
  int arr_keys[32265];
  std::cout << "FIRST INSERTION STACK\n";
  for (int i = 0; i < 32265; ++i) {
    auto key = std::rand() * ((std::rand() % 2) ? -1 : 1) % 32265;
    bst.insert(key, std::rand());
    keys.insert(key);
    arr_keys[i] = key;
  }

  bst.validate_tree();

  std::cout << "REMOVING STACK\n";
  for (int i = 0; i < 2048; ++i) {
    auto rm_key = arr_keys[std::rand() % 32265];
    bst.remove(rm_key);

    ASSERT_FALSE(bst.contains(rm_key));
    bst.validate_tree();
    keys.erase(rm_key);
  }

  for (auto key : keys) {
    ASSERT_TRUE(bst.contains(key));
  }
}

TEST(bst, iterators){
  const int NUM = 16000;
  RBTree<long, long> rb;

  for(int i = 0; i < NUM; ++i ){
    auto kv = std::make_pair(std::rand(), std::rand());
    rb.insert(kv.first, kv.second);
  }

  long last_val = LONG_MIN;
  for(auto i = rb.begin(); i != rb.end(); ++i){
    ASSERT_TRUE(last_val <= i->first);
    last_val = i->first;
  }
}

// std::cout << "INSERTION AGAIN\n";
//   std::vector<std::pair<long, long>> kvs;
//   for (int i = 0; i < 4096; ++i) { 
//     long val = std::rand();
//     long key = std::rand() * ((std::rand() % 2) ? -1 : 1);

//     kvs.push_back({key, val});
//     bst.insert(key, val);

//     for (int j = 0; j < i; ++j) {
//       auto contains = bst.contains(kvs[j].first);
//       ASSERT_TRUE(contains);
//       ASSERT_EQ(bst.get(kvs[j].first), kvs[j].second);
//     }
//   }
// }

// TEST(bst, in_order){
//     BST<long> bst;
//     for(int i = 0; i < 4096 * 8; ++i){
//         bst.insert(std::rand() % 64000 - 32000, std::rand());
//     }

//     for(int i = 0; i < 2048; ++i){
//         bst.remove(std::rand() % 64000 - 32000);
//     }

//     bst.balance();

//     auto vect = bst.in_order_traverse();
//     ASSERT_TRUE(std::is_sorted(vect.begin(), vect.end(), [=](BST<long>::node&
//     n1,BST<long>::node& n2) {
//         return n1.key < n2.key;
//     }));
// }

int main(int argc, char **argv) {
  std::srand(time(nullptr));
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}