#include <iostream>
#include <string>
#include <vector>


template <typename T, int N>
class FixedArray {
private:
	T arr[N];
public:
	void set(int index, T value) {
		arr[index] = value;
	}
	T get(int index) {
		return arr[index];
	}
	int size() {
		return N;
	}
};

void test_FixedArray() {
	std::cout << "Testing number 2 C-T" << "\n";
	FixedArray<int, 3> a;
	a.set(0, 10);
	a.set(1, 20);
	a.set(2, 30);
	std::cout << a.size() << "\n";

	FixedArray<std::string, 3> b;
	b.set(0, "Jamal");
	b.set(1, "Lewis");
	b.set(2, "Madara");

	std::cout << b.get(0) << "\n";
	std::cout << b.get(1) << "\n";
	std::cout << b.get(2) << "\n";

}

int main() {
	test_FixedArray();
	return 0;
}
