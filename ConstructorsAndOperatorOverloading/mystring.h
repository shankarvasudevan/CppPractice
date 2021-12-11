#pragma once
#include <iostream>
#include <string>

class MyString
{
public:
    MyString(MyString&& other) : mValue{std::move(other.mValue)}
    {
        other.mValue = nullptr;
        std::cout << "Move constructor" << std::endl;
    }

    MyString(const MyString& other) : mValue{other.mValue}
    {
        std::cout << "Copy constructor" << std::endl;
    }

    MyString(const std::string& value) : mValue{value}
    {
        std::cout << "Regular constructor" << std::endl;
    }

    MyString() 
    {
        std::cout << "Default constructor" << std::endl;
    }

    const std::string& GetValue() const { return mValue; }

private:
    std::string mValue;
};