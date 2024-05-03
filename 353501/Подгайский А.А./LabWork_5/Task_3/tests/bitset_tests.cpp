#include "bitset.h"
#include "gtest/gtest.h"



TEST(bset, basic){

    Bitset<16> small;
    ASSERT_EQ(small.to_string(), "0000000000000000");

    small.set(3);
    small.set(6);
    ASSERT_EQ(small.to_string(), "0001001000000000");

    Bitset<1076> big;
    ASSERT_EQ(big.to_string(), std::string(1076, '0'));

    Bitset<512512> very_big;
    ASSERT_EQ(very_big.to_string(), std::string(512512, '0'));
}


TEST(bset, flip){
    Bitset<512> b1;
    b1.flip();
    ASSERT_EQ(b1.to_string(), std::string(512, '1'));
    

    Bitset<16> b2;
    b2[3] = 1;
    b2[8] = 1;
    b2.flip();

    ASSERT_EQ(b2.to_string(), "1110111101111111");
}

TEST(bset, set){

    Bitset<100'000> b;

    b.set(124);
    b.set(986);
    b.set(986);
    b.set(99'987);

    std::string s (100'000, '0');
    s[124] = '1';
    s[986] = '1';
    s[99'987] = '1';

    ASSERT_EQ(b.to_string(), s);
    
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}