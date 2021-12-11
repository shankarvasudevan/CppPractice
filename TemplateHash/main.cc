#include <iostream>
#include <unordered_map>

class Foo
{
public:
    explicit Foo(int value) : mValue(value) {}

    int GetValue() const { return mValue; }
private:
    int mValue;
};

class FooHasher
{
    size_t operator()(const Foo& foo) const
    {
        std::cout << "FooHasher called" << std::endl;
        return foo.GetValue();
    }
}


int main(int argc, char* argv[])
{
    std::unordered_map<Foo, std::string> map1;

    map1.insert(new Foo(1), "AAA");
    map1.insert(new Foo(2), "BBB");

    std::unordered_map<Foo, std::string, FooHasher> map2;

    map2.insert(new Foo(3), "CCC");
    map2.insert(new Foo(4), "DDD");

    return 0;
}