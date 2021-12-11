#include <iostream>
#include "mystring.h"

int main(int argc, char* argv[])
{
    MyString s1{"Hello"};
    MyString s2{s1};
    MyString s3 = s1;
    MyString s4{MyString{"Hello"}};
}