#include <iostream>

using Combo = std::tuple<int, bool, char>;

int main(int argc, char* argv[])
{
	Combo c1 {42, true, 'A'};
	Combo c2 {42, false, 'B'};
	Combo c3 {42, false, 'A'};
	Combo c4 {42, true, 'B'};
	Combo c5 {50, true, 'A'};
	Combo c6 {50, true, 'B'};
	Combo c7 {42, true, 'A'};

	std::cout << "c1 == c7: " << (c1 == c7) << std::endl;
	std::cout << "c1 == c2 : " << (c1 == c2) << std::endl;

	return 0;
}
