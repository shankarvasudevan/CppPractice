#include <iostream>
#include <memory>

class Test
{
private:
    int data;
public:
    Test() : data{0} { std::cout << "Test constructor (" << data << ")" << std::endl; }
    Test(int data) : data{data} { std::cout << "Test constructor (" << data << ")" << std::endl; }
    int get_data() const { return data; }
    ~Test() { std::cout << "Test destructor (" << data << ")" << std::endl; }
};

void my_deleter(Test* ptr)
{
    std::cout << "Using my_deleter" << std::endl;
    delete ptr;
}

// Function prototypes
std::unique_ptr<std::vector<std::shared_ptr<Test>>> make();
void fill(std::vector<std::shared_ptr<Test>>& vec, int num);
void display(const std::vector<std::shared_ptr<Test>>& vec);

std::unique_ptr<std::vector<std::shared_ptr<Test>>> make()
{
    return std::make_unique<std::vector<std::shared_ptr<Test>>>();
}

void fill(std::vector<std::shared_ptr<Test>>& vec, int num)
{
    for (int i=0; i < num; ++i)
    {
        std::cout << "Enter data point [" << i+1 << "]: " << std::endl;
        int dataPoint;
        std::cin >> dataPoint;
        vec.push_back(std::make_shared<Test>(dataPoint));
    }
}

void display(const std::vector<std::shared_ptr<Test>>& vec)
{   
    std::cout << "Displaying vector data" << std::endl;
    std::cout << "================" << std::endl;
    for (const auto& ptr : vec)
    {
        std::cout << ptr->get_data() << std::endl;
    }

    std::cout << "================" << std::endl;
}

int main(int argc, char* argv[])
{
    // Need to get this to compile
    std::unique_ptr<std::vector<std::shared_ptr<Test>>> vecPtr;
    vecPtr = make();
    std::cout << "How many data points do you want to enter: ";
    int num;
    std::cin >> num;
    fill(*vecPtr, num);
    display(*vecPtr);
    return 0;
}