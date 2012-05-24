int square(int);            // global namespace  => external linkage

static int cube(int);       // static            => internal linkage

namespace bmp
{
	bool check(int, int);   // (named) namespace => external linkage
	
	namespace
	{
		void print();       // unnamed namespace => internal linkage
		static void test(); // static            => internal linkage
	}
}
