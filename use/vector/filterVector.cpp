#include <iostream>
#include <vector> 
#include <cassert>

template <typename T, typename Predicate>
std::vector<T> filterVector(const std::vector<T> v, Predicate Condition) {
	std::vector<T> result;
	for (int i = 0; i < v.size(); i++) {
		if (Condition(v[i])) {
			result.push_back(v[i]);
		}
	}
	return result;
}
bool isEven(int x) {
	return x % 2 == 0;
}
void test() {

	std::vector<int> v = { 1, 2, 3, 4, 5, 6 };
	std::vector<int> result = filterVector(v, isEven);
	assert(result.size() == 3);
	assert(result[0] == 2);
	assert(result[1] == 4);
	assert(result[2] == 6);
	std::cout << "Test Passed";
}
int main() {
	test();
	return 0;
}
