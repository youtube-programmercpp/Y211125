void f(char* p)
{
}
int main()
{
	const int a = static_cast<int>(1.23);
	const auto b = static_cast<float>(a);

	const void* p = "ABC";
	const char* q = static_cast<const char*>(p);
	
	f(const_cast<char*>("ABC"));
}
