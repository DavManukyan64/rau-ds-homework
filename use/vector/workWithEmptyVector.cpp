#include <iostream>
#include <vector>
#include <cassert>


std::vector<int> workWithEmptyVector() {
	std::vector<int> v;
	for (int i = 1; i <= 10; i++) {
		v.push_back(i);
		std::cout << v.size() << std::endl;
		std::cout << v.capacity() << std::endl;
	}
	for (int i = 0; i < v.size(); i++) {
		std::cout << v[i] << " ";
	}
	return v;
}


void test() {
	std::vector<int> result = workWithEmptyVector();
	assert(result.size() == 10);
	for (int i = 0; i < 10; i++) {
		assert(result[i] == i + 1);
	}
	std::cout << "Test passed";
}

int main() {
	test();
	return 0;
}
