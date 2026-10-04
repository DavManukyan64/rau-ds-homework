#include <iostream>
#include <string>
#include <vector>

template <typename C>
int linearSearch(std::vector<C>& arr, C element) {
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] == element) {
			return i;
		}
	}
	return -1;
}
void test_linearSearch() {
	std::cout << "Testing number 5 F-T" << "\n";
	std::vector<int> a = { 5, 2, 8, 2, 10 };
	std::cout << linearSearch(a, 2) << std::endl;
	std::vector<double> b = { 3.14, 2.71, 6.28 };
	std::cout << linearSearch(b, 6.28) << std::endl;
	std::vector<std::string> c = { "Jamal", "Lewis", "Madara" };
	std::cout << linearSearch(c, std::string("Lewis")) << std::endl;
}

int main() {
	test_linearSearch();
	return 0;
}
