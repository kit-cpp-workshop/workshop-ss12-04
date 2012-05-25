#define SQUARE(x) (x*x)
#define CUBE(VAR) (VAR*VAR*VAR)
#define DIST(x, y) std::sqrt(SQUARE(x) + SQUARE(y))

int main()
{
	int foo = SQUARE(42);
	
	int myX = 5;
	int myY = 3;
	int myDist = DIST(myX, myY);
}


#define MIN(x, y) (x < y) ? x : y
#define MIN2(x, y) ((x < y) ? x : y)

int main()
{
	int foo = MIN(23, 42) + 5;
	int bar = MIN2(23, 42) + 5;
	return 0;
}