struct pair
{
	int foo
	int bar;
};


#include "pair.h"

int compute(pair);

struct MyClass
{
	pair member;
};


#include "pair.h"
#include "MyClass.h"

int main()
{
	MyClass m;
	compute(m.member);
}
