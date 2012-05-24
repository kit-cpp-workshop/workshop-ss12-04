#include <iostream>

#define MYMACRO myInt

int main()
{
	int MYMACRO = 42;
	int MYMACRO_NOT = 3;
	
	if(42 == MYMACRO)
	{
		std::cout << myInt << "MYMACRO";
	}
}
