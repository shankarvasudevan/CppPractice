#include <iostream>
#include <unordered_set>

int main(int argc, char* argv[])
{
	std::unordered_set<int> s;
	s.insert(1);
	s.insert(2);
	s.insert(3);

	int x = s.erase(2);
	
	std::cout << x << std::endl;

	int y = s.erase(4);

	std::cout << y << std::endl;

	return 0;
}
