
#include "gtest/gtest.h"
#include <cstring>
#include <string>
#include "String.hpp"

TEST(string, ini){
    String s1("qwertyuiop[1234567890]");
    ASSERT_EQ(strcmp(s1.c_str(), "qwertyuiop[1234567890]"), 0);

    String s2("");
    ASSERT_EQ(strlen(s2.c_str()), 0);


    String s4(" ");
    ASSERT_STREQ(s4.c_str(), " ");

}

TEST(string, append){

    String s1("hello there");
    String s2(" here we go");
    s1.append(s2);

    ASSERT_STREQ( s1.c_str(), "hello there here we go");
}


TEST(string, resize){
    String s("aaa");
    s.resize(10, 'b');
    ASSERT_STREQ(s.c_str(), "aaabbbbbbb");

    String s2("");
    s2.resize(128, ' ');
    
    std::string check(128L, ' ');
    ASSERT_STREQ(check.c_str(), s2.c_str());
}

TEST(string, clear){
    String s("qoiwdoiqjoidnqnqionwoiwhoiwoqcoibqoic");
    s.clear();
    ASSERT_TRUE(s.empty());
}


int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}