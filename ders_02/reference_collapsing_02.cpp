int main()
{
	using intrefref = int&&;
	int x{};

	intrefref& r1 = x;  //int& r1;
	intrefref&& r2 = 10;  //int&& r2;
}
