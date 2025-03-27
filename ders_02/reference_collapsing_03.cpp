int main()
{
	int x{};
	int& r1{ x };

	decltype(r1)& r2 = x; //int& r2
	decltype(r1)&& r3 = x; //int& r3
	//..
}
