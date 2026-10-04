#include <iostream>
#include <string>
#include <vector>

template <typename T>
bool isEqual(const T a, const T b) {
	if (a == b) {
		return true;
	}
	return false;
}
template <>
bool isEqual(const char* a, const char* b) {
	if (strcmp(a, b) == 0) {
		return true;
	}
	return false;
}

void test_isEqual() {
	std::cout << "Testing number 2 T-S" << "\n";
	std::cout << isEqual(5, 10) << std::endl;
	const char* a = "Hello";
	const char* b = "Hello";
	const char* c = "World";
	std::cout << isEqual(a, b) << std::endl;
	std::cout << isEqual(a, c) << std::endl;

}

int main() {
	test_isEqual();
	return 0;
}
