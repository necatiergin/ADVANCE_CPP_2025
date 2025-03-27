int main()
{
	using intref = int&;
	int x{};

	intref& r1 = x;  //int& r1;
	intref&& r2 = x;  //int& r2;
}
