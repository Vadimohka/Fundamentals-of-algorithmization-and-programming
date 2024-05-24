#include "BST.h"
#include "BSTWithDepth.h"
#include <algorithm>
#include <cstdlib>
#include <gtest/gtest.h>
#include <iostream>
#include <sys/types.h>



TEST(bst, insert_search){
    BST<long> bst;

    for(int i = 0; i < 4096; ++i){
        long val = std::rand();
        long key = std::rand() * ( (std::rand() % 2) ? -1 : 1);
        bst.insert(key, val);

        auto el = bst.search(key);
        ASSERT_TRUE(el.is_valid());
        ASSERT_EQ(*el, val);
    }
}


TEST(bst, manual_remove){
    BST<long> bst;

    bst.insert(124, 163251);
    bst.insert(121, 10);
    bst.insert(126, 5);;
    bst.remove(124);
    bst.insert(125, 1231);

    auto el = bst.search(121);
    ASSERT_TRUE(el.is_valid());
    ASSERT_EQ(*el, 10);

    el = bst.search(126);
    ASSERT_TRUE(el.is_valid());
    ASSERT_EQ(*el, 5);


    el = bst.search(124);
    ASSERT_FALSE(el.is_valid());

}

TEST(bst, balance){
    BSTWithDepth<long> bst;
    for(int i = 0; i < 4096 * 8; ++i){
        bst.insert(i, std::rand());
    }

    auto trav1 = bst.in_order_traverse();
    std::cout << "before balance depth: " << bst.depth() << '\n';
    bst.balance();
    std::cout << "after balance depth: " << bst.depth() << '\n';
    auto trav2 = bst.in_order_traverse();


    ASSERT_EQ(trav1.size(), trav2.size());
    for(int i = 0; i < trav1.size(); ++i){
        ASSERT_EQ(trav1[i].val, trav2[i].   val);
    }
}



TEST(bst, remove){
    BST<long> bst;
    std::set<long> keys;
    int arr_keys[32265];
    for(int i = 0; i < 32265; ++i){
        auto key = std::rand() * ( (std::rand() % 2) ? -1 : 1) % 32265;
        bst.insert(key, std::rand());
        //std::cout << "inserted " << key << '\n';
        keys.insert(key);
        arr_keys[i] = key;
    }

    for(int i = 0; i < 1024; ++i){
        auto rm_key =  arr_keys [ std::rand() % 32265 ];
        //std::cout << "removed " << rm_key << '\n';
        bst.remove(rm_key);
        ASSERT_FALSE(bst.search(rm_key).is_valid());
        keys.erase(rm_key);
    }

    bst.balance();

    for(auto key : keys){
        //std::cout << "checking " << key << '\n';
        ASSERT_TRUE(bst.search(key).is_valid());
    }
}

TEST(bst, in_order){
    BST<long> bst;
    for(int i = 0; i < 4096 * 8; ++i){
        bst.insert(std::rand() % 64000 - 32000, std::rand());
    }

    for(int i = 0; i < 2048; ++i){
        bst.remove(std::rand() % 64000 - 32000);
    }

    bst.balance();

    auto vect = bst.in_order_traverse();
    ASSERT_TRUE(std::is_sorted(vect.begin(), vect.end(), [=](BST<long>::node& n1,BST<long>::node& n2) {
        return n1.key < n2.key;
    }));
}


int main(int argc, char **argv) {
  std::srand(time(nullptr));
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}