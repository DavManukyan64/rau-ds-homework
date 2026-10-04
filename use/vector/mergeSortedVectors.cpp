#include <iostream>
#include <vector>
#include <cassert>

std::vector<int> mergeSortedVectors(const std::vector<int>& v1, const std::vector<int>& v2) {
	std::vector<int> result;
	int i = 0;
	int j = 0;
	while (i < v1.size() && j < v2.size()) {
		if (v1[i] < v2[j]) {
			result.push_back(v1[i]);
			i++;
		}
		else {
			result.push_back(v2[j]);
			j++;
		}
	}
	while (i < v1.size()) {
		result.push_back(v1[i]);
		i++;
	}
	while (j < v2.size()) {
		result.push_back(v2[j]);
		j++;
	}
	return result;
}

void test() {
	std::vector<int> v1 = { 1, 3, 5, 7 };
	std::vector<int> v2 = { 2, 4, 6, 8 };

	std::vector<int> result = mergeSortedVectors(v1, v2);

	assert(result.size() == v1.size() + v2.size());

	for (int i = 1; i < result.size(); i++) {
		assert(result[i - 1] <= result[i]);
	}

	std::cout << "Test Passed";
}


int main() {
	test();
	return 0;
}
