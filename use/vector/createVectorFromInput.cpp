#include <iostream>
#include <vector>
#include <cassert>

std::vector<int> createVectorFromInput() {
	std::vector<int> v;
	int n;
	while (true) {
		std::cin >> n;
		if (n == 0) {
			break;
		}
		v.push_back(n);
	}
	return v;
}

void test() {
	std::vector<int> result = createVectorFromInput();
	for (int i = 0; i < result.size(); i++) {
		assert(result[i] != 0);
	}
	std::cout << "Test Passed";
}

int main() {
	test();
	return 0;
}
