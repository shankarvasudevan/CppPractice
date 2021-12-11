#include <iostream>
#include <unordered_map>

struct Foo
{
	std::string mValue;
};

struct Bar
{
	std::string mValue;
};

template<typename MapType>
void PrintMap(std::unordered_map<int, MapType> map)
{
	for (const auto& [key, val] : map)
	{
		std::cout << "{" << key << "," << val.mValue << "}" << std::endl;
	}
}

int main(int argc, char* argv[])
{
	std::unordered_map<int, Foo> mFooMap;
	mFooMap[1] = Foo{"One"};
	mFooMap[2] = Foo{"Two"};
	mFooMap[3] = Foo{"Three"};

	std::unordered_map<int, Bar> mBarMap;
	mBarMap[4] = Bar{"Four"};
	mBarMap[5] = Bar{"Five"};
	mBarMap[6] = Bar{"Six"};

	PrintMap(mFooMap);
	PrintMap(mBarMap);

	return 0;
}
