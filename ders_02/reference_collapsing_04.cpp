int main()
{
	int x{};
	int&& r1{};

	decltype(r1)& r2 = x; //int& r2
	decltype(r1)&& r3 = 5; //int&& r3
	//..
}
