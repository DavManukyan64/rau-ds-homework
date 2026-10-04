#include <iostream>
#include <vector>
#include <cassert>

template <typename T>
void resizeVector(std::vector<T>& v, int newSize, T defaultValue) {
	for (int i = 0; i < v.size(); i++) {
		std::cout << v[i] << " ";
	}
	std::cout << "\n";
	v.resize(newSize, defaultValue);
	for (int i = 0; i < v.size(); i++) {
		std::cout << v[i] << " ";
	}
}

void test() {
	std::vector<int> v = { 1, 2, 3 };
	resizeVector(v, 5, 42);
	assert(v.size() == 5);
	assert(v[3] == 42 && v[4] == 42);
	std::cout << "Test Passed";
}


int main() {
	test();
	return 0;
}
