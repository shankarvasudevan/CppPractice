#include <iostream>
#include <numeric>
#include <vector>

struct Combo
{
	int mValue;
	bool mFlag;
	char mStatus;
};

int main(int argc, char* argv[])
{
	std::vector<Combo> vec;

	vec.push_back(Combo{1, true, 'A'});
	vec.push_back(Combo{20, false, 'B'});
	vec.push_back(Combo{30, false, 'C'});
	vec.push_back(Combo{4, true, 'D'});

	int sum = std::accumulate(vec.begin(), vec.end(), 0, [](int total, Combo c) { return total + c.mValue;  });

	int trueSum = 0;
	int falseSum = 0;

	std::for_each(vec.begin(), vec.end(), 
	[&](Combo& c) 
	{ 
		if (c.mFlag) 
		{
			trueSum += c.mValue;
		} 
		else
		{
			falseSum += c.mValue;
		}
	});

	std::cout << "Sum = " << sum << std::endl;

	std::cout << "TrueSum = " << trueSum << std::endl;
	std::cout << "FalseSum = " << falseSum << std::endl;
}
