#include <iostream>
#include <byteswap.h>
#include <boost/endian/conversion.hpp>

struct Foo
{
	int32_t mDate;
};


int main(int argc, char* argv[])
{
	char msg[] = "20210611";

	Foo* foo = reinterpret_cast<Foo*>(&msg);

	std::cout << "Date = " << foo->mDate << std::endl;

	int32_t swappedDate = bswap_32(foo->mDate);
	std::cout << "Swapped Date = " << swappedDate << std::endl;

	int32_t reversed = boost::endian::endian_reverse(foo->mDate);
	std::cout << "Reversed Date = " << reversed << std::endl;

	int32_t reverseSwappedDate = bswap_32(reversed);
	std::cout << "Reverse Swapped Date = " << reverseSwappedDate << std::endl;


}