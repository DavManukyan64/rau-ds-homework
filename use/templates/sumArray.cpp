#include <iostream>
#include <string>
#include <vector>

template <typename B>
B sumArray(B* arr, int size) {
	B summ = B();
	for (int i = 0; i < size; i++) {
		summ += arr[i];
	}
	return summ;
}
void test_sumArray() {
	std::cout << "Testing number 3 F-T" << "\n";
	int a[5] = { 1, 2 ,3 ,4 , 5 };
	std::cout << sumArray(a, 5) << std::endl;
	double b[2] = { 2.5, 3.5 };
	std::cout << sumArray(b, 2) << std::endl;
	std::string c[2] = { "Jamal", "Lewis" };
	std::cout << sumArray(c, 2) << std::endl;
}

int main() {
	test_sumArray();
	return 0;
}
