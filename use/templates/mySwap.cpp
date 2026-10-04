#include <iostream>
#include <string>
#include <vector>

template <typename A>
void mySwap(A& a, A& b) {
	A temp = a;
	a = b;
	b = temp;
}
void test_mySwap() {
	std::cout << "Testing number 2 F-T" << "\n";
	int a = 5;
	int b = 1;
	mySwap(a, b);
	std::cout << a << "\n" << b << "\n";
	double c = 3.14;
	double d = 6.28;
	mySwap(c, d);
	std::cout << c << "\n" << d << "\n";
	std::string e = "Jamal";
	std::string f = "Lewis";
	mySwap(e, f);
	std::cout << e << "\n" << f << "\n";
}
int main() {
	test_mySwap();
	return 0;
}
