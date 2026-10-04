#include <iostream>
#include <string>
#include <vector>

template <typename T>
void printValue(const T& value) {
	std::cout << value << std::endl;
}
template <>
void printValue(const bool& value) {
	if (value == true) {
		std::cout << true << std::endl;
	}
	else {
		std::cout << false << std::endl;
	}
}
void printValue(const char& value) {
	std::cout << "[" << value << "]" << std::endl;
}

void test_printValue() {
	std::cout << "Testing number 1 T-S" << "\n";
	printValue(12.5);
	bool a = true;
	printValue(a);
	char c[] = "Hello World";
	printValue(c);
}

int main() {
	test_printValue();
	return 0;
}
