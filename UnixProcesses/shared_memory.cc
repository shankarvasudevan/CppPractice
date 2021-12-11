#include <string.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/wait.h>

#include <iostream>

char *
get_shared_memory()
{
    auto key = ftok("myfile", 42);
    auto shm = shmget(key, 0x1000, 0666 | IPC_CREAT);

    return static_cast<char *>(shmat(shm, nullptr, 0));
}

int main(void)
{
    if (fork() != 0) {
        sleep(1);
        std::cout << "parent\n";

        auto msg = get_shared_memory();
        msg[0] = 42; // writing to shared mem

        wait(nullptr);
    }
    else {
        auto msg = get_shared_memory();
        while(msg[0] != 42); // reading from shared mem
        std::cout << "child\n";
    }
}

// > g++ scratchpad.cpp; ./a.out
// parent
// child