#include <iostream>
#include <vector>
#include <cassert>

void manageCapacity(std::vector<int>& v) {
	std::cout << "Size before:" << v.size() << "\n";
	std::cout << "Capacity before:" << v.capacity() << "\n";
	v.reserve(v.capacity() + 500);
	for (int i = 1; i <= 500; i++) {
		v.push_back(i);
	}
	std::cout << "Size After " << v.size() << "\n";
	std::cout << "Capacity After " << v.capacity() << "\n";
}

void test() {
	std::vector<int> v;
	manageCapacity(v);
	assert(v.size() == 500);
	assert(v.capacity() >= v.size());
	std::cout << "Test Passed";
}

int main() {
	test();
	return 0;
}
