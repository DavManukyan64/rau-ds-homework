#include <iostream>
#include <vector>
#include <cassert>

std::vector<std::vector<int>> groupAdjacent(const std::vector<int>& v) {
	std::vector<std::vector<int>> groups;
	if (v.empty()) {
		return groups;
	}
	std::vector<int> currentGroup;
	currentGroup.push_back(v[0]);
	for (int i = 1; i < v.size(); i++) {
		if (v[i] == v[i - 1]) {
			currentGroup.push_back(v[i]);
		}
		else {
			groups.push_back(currentGroup);
			currentGroup.clear();
			currentGroup.push_back(v[i]);
		}
	}
	groups.push_back(currentGroup);
	return groups;
}

void test() {
	std::vector<int> v = { 1, 1, 2, 2, 2, 3, 1, 1 };

	std::vector<std::vector<int>> result = groupAdjacent(v);

	assert(result.size() == 4);
	assert(result[0].size() == 2);
	assert(result[1].size() == 3);
	assert(result[2].size() == 1);
	assert(result[3].size() == 2);

	std::cout << "Test Passed";
}

int main() {
	test();
	return 0;
}
