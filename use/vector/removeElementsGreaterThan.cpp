#include <iostream>
#include <vector>
#include <cassert>

int removeElementsGreaterThan(std::vector<int>& v, int porog) {
	int count = 0;
	for (int i = v.size() - 1; i >=0; i--) {
		if (v[i] > porog) {
			v.pop_back();
			count++;
		}
		else {
			break;
		}
	}
	return count;
}

void test() {
	std::vector<int> result = { 1, 3, 5, 7, 10 };
	int removed = removeElementsGreaterThan(result, 5);
	assert(removed == 2);
	std::cout << "Test passed";
}

int main() {
	test();
	return 0;
}
