#include <iostream>

enum Color : char
{
	UNKNOWN_COLOR = 0,
	RED = 'R',
	GREEN = 'G',
	YELLOW = 'Y'
};

enum Season : char
{
	UNKNOWN_SEASON = 0,
	SPRING = 'P',
	SUMMER = 'S',
	AUTUMN = 'A',
	WINTER = 'W'
};

struct Foo
{
	Color mColor = Color::UNKNOWN_COLOR;
	Season mSeason = Season::UNKNOWN_SEASON;
};

int main(int argc, char* argv[])
{

	Foo f;

	std::cout << static_cast<char>(f.mColor) << std::endl;
	std::cout << static_cast<char>(f.mSeason) << std::endl;

}
