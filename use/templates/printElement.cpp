#include <iostream>
#include <string>
#include <vector>

template <typename T>
void printElement(T value) {
	std::cout << value << std::endl;
}
void test_printElement() {
	std::cout << "Testing number 1 F-T" << "\n";
	int a = 5;
	double b = 3.14;
	std::string c = "Hi!";
	printElement(a);
	printElement(b);
	printElement(c);
}
int main(){
	test_printElement();
	return 0;
}
