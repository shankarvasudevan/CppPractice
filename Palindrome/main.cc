#include <iostream>
#include <string>
#include <deque>

bool is_palindrome(const std::string& s)
{
    std::deque<char> d;

    for (char c : s)
    {
        d.push_back(std::toupper(c));
    }

    while (d.size() > 1)
    {
        char front = d.front();
        char back = d.back();

        d.pop_front();
        d.pop_back();

        if (front != back) 
        {
            return false;
        }
    }

    return true;
}

void CheckPalindrome(std::string word)
{
    std::cout << "Word: " << word << ", IsPalindrome: " << std::boolalpha << is_palindrome(word) << std::endl;
}

int main(int argc, char* argv[])
{
    CheckPalindrome("Hello");
    CheckPalindrome("Malayalam");
    CheckPalindrome("Deed");
    CheckPalindrome("Water");
    CheckPalindrome("A");

    return 0;
}