#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#include <array>
#include <iostream>
#include <string_view>

class MyPipe
{
    std::array<int, 2> m_handles; // Read handle and a write handle

public:
    MyPipe()
    {
        if (pipe(m_handles.data()) < 0)
        {
            exit(1);
        }
    }

    ~MyPipe()
    {
        close(m_handles.at(0));
        close(m_handles.at(1));
    }

    std::string read() 
    {
        std::array<char, 256> buf;
        std::size_t bytes = ::read(m_handles.at(0), buf.data(), buf.size()); // Blocking function and will not return until data is read from the pipe

        if (bytes > 0)
        {
            return {buf.data(), bytes};
        }

        return {};
    }

    void write(const std::string& msg)
    {
        ::write(m_handles.at(1), msg.data(), msg.size());
    }
};

int main(void)
{
    MyPipe p;

    if (fork() != 0) {
        sleep(1);
        std::cout << "parent\n"; 

        p.write("done");
        wait(nullptr);
    }
    else {
        auto msg = p.read(); // opens the pipe and waits until the parent process writes to the pipe

        std::cout << "child\n";
        std::cout << "msg: " << msg << std::endl;
    }
}

