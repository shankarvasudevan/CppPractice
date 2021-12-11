#include <iostream>

class CopyOnly
{
public:
    CopyOnly()
    {
        std::cout << "CopyOnly: Default constructor" << std::endl;
    }

    CopyOnly(int value) : mValue(value)
    {
        std::cout << "CopyOnly: User-defined constructor" << std::endl;
    }

    CopyOnly(const CopyOnly& other)
    {
        mValue = other.mValue;
        std::cout << "CopyOnly: Copy constructor" << std::endl;
    }

    CopyOnly& operator=(const CopyOnly& other)
    {
        mValue = other.mValue;
        std::cout << "CopyOnly: Copy assignment" << std::endl;
        return *this;
    }

    // explicitly deleting the move only types
    CopyOnly(CopyOnly&&) = delete;
    CopyOnly& operator=(CopyOnly&&) = delete;

    int GetValue() const { return mValue; }

private:
    int mValue;
};

class MoveOnly
{
public:
    MoveOnly()
    {
        std::cout << "MoveOnly: Default constructor" << std::endl;
    }

    MoveOnly(int value) : mValue(value)
    {
        std::cout << "MoveOnly: User-defined constructor" << std::endl;
    }

    MoveOnly(const MoveOnly&) = delete;
    MoveOnly& operator=(const MoveOnly&) = delete;

    MoveOnly(MoveOnly&& other)
    {
        mValue = other.mValue;
        std::cout << "MoveOnly: Move constructor" << std::endl;
    }

    MoveOnly& operator=(MoveOnly&& other)
    {
        mValue = other.mValue;
        std::cout << "MoveOnly: Move assignment" << std::endl;
        return *this;
    }

    int GetValue() const { return mValue; }

private:
    int mValue;
};

template<typename T>
void PrintConstRef(const T& t)
{
    std::cout << t.GetValue() << std::endl;
}

template<typename T>
void PrintRValueRef(T&& t)
{
    std::cout << t.GetValue() << std::endl;
}

template<typename T>
void PrintCopy(T t)
{
    std::cout << t.GetValue() << std::endl;
}

int main(int argc, char* argv[])
{
    CopyOnly c{42};
    MoveOnly m{29};

    std::cout << "Printing with const ref" << std::endl;
    PrintConstRef<CopyOnly>(std::move(c));
    PrintConstRef<MoveOnly>(std::move(m));

    std::cout << "Printing with R-value ref" << std::endl;
    PrintRValueRef<CopyOnly>(std::move(c));
    PrintRValueRef<MoveOnly>(std::move(m));

    std::cout << "Printing with copy" << std::endl;
    //PrintCopy<CopyOnly>(std::move(c));
    PrintCopy<MoveOnly>(std::move(m));
}