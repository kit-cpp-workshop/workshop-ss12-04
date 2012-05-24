int square(int p)
{
	return p*p;
}


int square(int);

int main()
{
	int i = square(42);
}


struct Square
{
	int compute(int);
};

int Square::compute(int p)
{
	return p*p;
}


int main()
{
	Square s;
	int i = s.compute(42);
}
