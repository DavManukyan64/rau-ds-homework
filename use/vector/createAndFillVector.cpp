#include <iostream>
#include <vector>
#include <cassert>

std::vector<int> createAndFillVector(int size) {
	std::vector<int> vectron(size);
	for (int i = 0; i < size; i++) {
		vectron[i] = i + 1;

	}

	for (int i = 0; i < size; i++) {
		std::cout << vectron[i] << "\n";
	}
	std::cout << vectron.size() << std::endl;
	std::cout << vectron.capacity() << std::endl;
	return vectron;
}

void test_createAndFillVector() {
	std::vector<int> result = createAndFillVector(5);
	assert(result.size() == 5);
	assert(result[0] == 1);
	assert(result[1] == 2);
	assert(result[2] == 3);
	assert(result[3] == 4);
	assert(result[4] == 5);
	std::cout << "Test passed" << std::endl;
}

int main() {
	test_createAndFillVector();
	return 0;
}
