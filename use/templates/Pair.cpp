#include <iostream>
#include <string>
#include <vector>

template <typename T1, typename T2>
class Pair {
private:
	T1 first;
	T2 second;
public:
	Pair(T1 a, T2 b) : first(a), second(b) {}
	void printPair() {
		std::cout << first << " " << second << std::endl;
	}
};

void test_Pair() {
	std::cout << "Testing number 1 C-T" << "\n";
	Pair<int, double> p1(10, 3.14);
	p1.printPair();
}

int main() {
	test_Pair();
	return 0;
}
