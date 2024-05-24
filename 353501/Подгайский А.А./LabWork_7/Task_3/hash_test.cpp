#include <gtest/gtest.h>
#include "HashTable.h"


TEST(bst, insert_search){
    HashTable<long> ht;

    for(int i = 0; i < 4096; ++i){
        long val = std::rand();
        long key = std::rand() * ( (std::rand() % 2) ? -1 : 1);
        ht.insert(key, val);

        ASSERT_TRUE(ht.contains(key));
        ASSERT_EQ(ht.get(key), val);
    }
}



TEST(bst, remove){
    HashTable<long> ht;

    std::set<long> keys;
    int arr_keys[32265];
    for(int i = 0; i < 32265; ++i){
        auto key = std::rand() * ( (std::rand() % 2) ? -1 : 1) % 32265;
        ht.insert(key, std::rand());
        //std::cout << "inserted " << key << '\n';
        keys.insert(key);
        arr_keys[i] = key;
    }

    for(int i = 0; i < 1024; ++i){
        auto rm_key =  arr_keys [ std::rand() % 32265 ];
        //std::cout << "removed " << rm_key << '\n';
        ht.remove(rm_key);
        ASSERT_FALSE(ht.contains(rm_key));
        keys.erase(rm_key);
    }

    for(auto key : keys){
        //std::cout << "checking " << key << '\n';
        ASSERT_TRUE(ht.contains(key));
    }
}

int main(int argc, char **argv) {
  std::srand(time(nullptr));
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}