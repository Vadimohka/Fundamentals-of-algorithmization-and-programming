#include "mycstring.h"
#include "gtest/gtest.h"
#include <cstring>

TEST(cstr, strcpy){
    char* ch = new char[16];
    const char* l = "abcdefgquhdqi";

    my_strcpy(ch, l);
     ASSERT_EQ(strcmp(ch, l), 0);
     delete[] ch;
}


TEST(cstr, strlen){
    const char* l1 = "abcdefgqpfqqonjniewbdeioqdjioqwijoqjioqdjioqdijo";
    const char* l2 = "";

     ASSERT_EQ(my_strlen(l1), strlen(l1));
     ASSERT_EQ(my_strlen(l2), strlen(l2));
}


TEST(cstr, strcat){
    char* s1 = new char[32];
    my_strcpy(s1, "hello there");
    my_strcat(s1, " here we go");

    ASSERT_EQ(strcmp(s1, "hello there here we go"), 0);
    delete[] s1;
}


TEST(cstr, strcpy_2){
    char* c = new char[64];
    my_strcpy(c, "qwertyuiop[asdfghjkl;'zxcvbnm,./]");
    ASSERT_STREQ(c, "qwertyuiop[asdfghjkl;'zxcvbnm,./]");
}

TEST(cstrm, strtok){
    char* s = new char[64];
    const char* delims = "-, ";
    my_strcpy(s, "  Hello --, guys, here-we, go   !!!");

    char* token = my_strtok(s, delims);
    ASSERT_STREQ(token, "Hello");

    token = my_strtok(NULL, delims);
    ASSERT_STREQ(token, "guys");

    token = my_strtok(NULL, delims);
    ASSERT_STREQ(token, "here");

    token = my_strtok(NULL, delims);
    ASSERT_STREQ(token, "we");

    token = my_strtok(NULL, delims);
    ASSERT_STREQ(token, "go");

    token = my_strtok(NULL, delims);
    ASSERT_STREQ(token, "!!!");
    
    token = my_strtok(NULL, delims);
    ASSERT_EQ(token, (char*)0);

    delete[] s;

}


int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}