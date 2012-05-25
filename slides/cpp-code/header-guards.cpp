#ifndef PAIR_H
#define PAIR_H

struct pair
{
	int foo
	int bar;
};

#endif


#ifndef MYCLASS_H
#define MYCLASS_H

#include "pair.h"

int compute(pair);

struct MyClass
{
	pair member;
};

#endif


#include "pair.h"
#include "MyClass.h"

int main()
{
	MyClass m;
	compute(m.member);
}
