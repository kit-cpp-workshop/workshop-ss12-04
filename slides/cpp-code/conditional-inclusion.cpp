#ifdef WIN32
#include <winsock2.h>
#else
#include <sys/net.h> // and more headers
#endif

#include <iostream>

#define MY_ONE 1

int main()
{
#if 1 != MY_ONE
	std::cout << "MY_ONE is NOT equal to 1";
#else
	std::cout << "MY_ONE is equal to 1";
#endif
}