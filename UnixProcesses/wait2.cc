#include <unistd.h>
#include <iostream>
#include <sys/wait.h>

int main(void)
{
    int id;

    // Total 8 processes - 2^N, where N=number of times that fork is called
    auto id1 = fork(); // Parent->Child1
    auto id2 = fork(); // Parent->Child2, Child1->Child3
    auto id3 = fork(); // Parent->Child4, Child1->Child5, Child2->Child6, Child3->Child7

    while (1)
    {
        id = wait(nullptr);

        if (id == -1) break;

        if (id == id1) std::cout << "Child #1 finished" << std::endl;
        if (id == id2) std::cout << "Child #2 finished" << std::endl;
        if (id == id3) std::cout << "Child #3 finished" << std::endl;
    }

    if (id1 != 0 && id2 != 0 && id3 != 0) std::cout << "Parent done" << std::endl;
}
