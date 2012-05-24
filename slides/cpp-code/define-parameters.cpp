#define MIN(x, y) (x < y) ? x : y
#define MIN2(x, y) ((x < y) ? x : y)

int main()
{
	int foo = MIN(23, 42) + 5;
	int bar = MIN2(23, 42) + 5;
	return 0;
}