#include <iostream>
#include <queue>
#include <stack>

bool IsPalindrome(const std::string& word)
{
    std::queue<char> lettersQueue;
    std::stack<char> lettersStack;

    for (const char letter : word)
    {
        lettersQueue.push(letter);
        lettersStack.push(letter);
    }

    while (!lettersQueue.empty() && !lettersStack.empty() && (lettersQueue.front() == lettersStack.top()))
    {
        lettersQueue.pop();
        lettersStack.pop();
    }

    return lettersQueue.empty() && lettersStack.empty();
}

int main(int argc, char* argv[])
{
    std::cout << "Enter a word: " << std::endl;
    
    std::string word;
    std::cin >> word; 

    std::cout << "IsPalindrome: " << std::boolalpha << IsPalindrome(word) << std::endl;

    return 0;
}