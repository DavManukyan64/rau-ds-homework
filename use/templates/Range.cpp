#include <iostream>
#include <string>
#include <vector>

template <typename T>
class Range {
private:
	T start;
	T end;
public:
	Range(T _start, T _end) : start(_start), end(_end) {}
	bool contains(const T& value) {
		if (value <= end && value >= start) {
			return true;
		}
		else {
			return false;
		}
	}
	int length() {
		return end - start;
	}
	void print() {
		std::cout << start << " " << end << std::endl;
	}
};

void test_Range() {
	std::cout << "Testing number 4 C-T" << "\n";
	Range<int> a(3, 10);
	a.print();
	std::cout << a.length() << "\n";
	std::cout << a.contains(5) << "\n";
	Range<double> b(2.5, 7.5);
	b.print();
	std::cout << b.length() << "\n";
	std::cout << b.contains(10) << "\n";
	Range<char> c('a', 'f');
	c.print();
	std::cout << c.length() << "\n";
	std::cout << c.contains('z') << "\n";

}

int main() {
	test_Range();
	return 0;
}
