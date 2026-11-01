#include <iostream>
#include <forward_list>

void createAndFillList(int N) {
	std::forward_list<int> numbers;

	for (int i = 1; i <= N; i++) {
		numbers.push_front(i);
	}
	for (int x : numbers) {
		std::cout << x << " ";
	}
}

int main() {
	createAndFillList(5);
	return 0;
}
