#include <iostream>
#include <vector>
#include <cassert>

int findSubsequence(const std::vector<int>& mainVec, const std::vector<int>& subVec) {
	for (int i = 0; i <= mainVec.size() - subVec.size(); i++) {
		bool found = true;

		for (int j = 0; j < subVec.size(); j++) {
			if (mainVec[i + j] != subVec[j]) {
				found = false;
				break;
			}
		}
		if (found) {
			return i;
		}
	}
	return -1;
}

void test() {
	std::vector<int> mainVec = { 1, 2, 3, 4, 5, 6 };
	std::vector<int> subVec = { 3, 4, 5 };

	int result = findSubsequence(mainVec, subVec);
	assert(mainVec.size() - subVec.size() >= 0);
	assert(result == 2);
	std::cout << "Test Passed";
}

int main() {
	test();
	return 0;
}
