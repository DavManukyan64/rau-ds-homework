#include <iostream>
#include <string>
#include <vector>

template <typename T, int N, int M>
class Matrix {
private:
	T arr[N][M];
public:
	void set(int row, int col, T value) {
		arr[row][col] = value;
	}
	T get(int row, int col) {
		return arr[row][col];
	}
	void print() {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				std::cout << arr[i][j] << " ";
			}
			std::cout << "\n";
		}
	}
	Matrix<T, N, M> operator+(const Matrix<T, N, M>& other) {
		Matrix<T, N, M> result;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				result.arr[i][j] = arr[i][j] + other.arr[i][j];
			}
		}
		return result;
	}
};

void test_Matrix() {
	std::cout << "Testing number 3 C-T" << "\n";
	Matrix<int, 2, 2> a;

	a.set(0, 0, 1);
	a.set(0, 1, 2);
	a.set(1, 0, 3);
	a.set(1, 1, 4);
	a.print();

	Matrix<std::string, 2, 2> b;

	b.set(0, 0, "Hello");
	b.set(0, 1, "World");
	b.set(1, 0, "Jamal");
	b.set(1, 1, "Madara");
	b.print();
}

int main() {
	test_Matrix();
	return 0;
}
