#include <iostream>

#define MY_ONE 1

int main()
{
#if 2 == 1 + 1
	std::cout << "2 is equal to 1 + 1";
#endif

#if 1 != MY_ONE
	std::cout << "MY_ONE is NOT equal to 1";
#else
	std::cout << "MY_ONE is equal to 1";
#endif
}