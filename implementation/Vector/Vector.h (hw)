#ifndef VECTOR_H
#define VECTOR_H
#include <cstddef>
#include <stdexcept>

template <typename T>
class Vector {
private:
	T* _data;
	std::size_t _size;
	std::size_t _capacity; 
	void _resize_capacity(size_t new_capacity) {
		T* new_data = new T[new_capacity];
		for (std::size_t i = 0; i < _size; i++) {
			new_data[i] = _data[i];
		}
		delete[] _data;
		_data = new_data;
		_capacity = new_capacity;
	}

public:
	//1
	Vector() : _data(nullptr), _size(0), _capacity(0) {}

	//2
	Vector(size_t initial_size) : _data(nullptr), _size(initial_size), _capacity(initial_size) {
		if (initial_size != 0) {
			_data = new T[initial_size]{};
		}
	}

	//3
	~Vector() {
		delete[] _data;
	}




	//4
	Vector(const Vector& other) : _data(nullptr), _size(other._size), _capacity(other._capacity) {
		if (_capacity != 0) {
			_data = new T[_capacity];
		}
		for (std::size_t i = 0; i < _size; i++) {
			_data[i] = other._data[i];
		}
	}


	//5
	Vector& operator=(const Vector& other) {
		if (this == &other) {
			return *this;
		}
		T* new_data = nullptr;
		if (other._capacity > 0) {
			new_data = new T[other._capacity];
			for (std::size_t i = 0; i < other._size; i++) {
				new_data[i] = other._data[i];
			}
		}
		delete[] _data;
		_data = new_data;
		_size = other._size;
		_capacity = other._capacity;
		return *this;
	}

	//6

	void push_back(const T& value) {
		T copy = value;
		if (_size == _capacity) {
			if (_capacity == 0) {
				_resize_capacity(1);
			}
			else{
				_resize_capacity(_capacity * 2);
			}
		}
		_data[_size] = copy;
		_size++;
	}

	//7
	void pop_back() {
		if (empty()) {
			throw std::out_of_range("Vector is empty");
		}
		_size--;
	}
	//8
	T& operator[](std::size_t index) {
		return _data[index];
	}
	const T& operator[](std::size_t index) const {
		return _data[index];
	}


	//9

	T& at(std::size_t index)  {
		if (index >= _size) {
			throw std::out_of_range("Index out of range");
		}
		return _data[index];
	}

	const T& at(std::size_t index) const {
		if (index >= _size) {
			throw std::out_of_range("Index out of range");
		}
		return _data[index];
	}

	//10
	T& front() {
		if (empty()) {
			throw std::out_of_range("Vector is Empty");
		}
		return _data[0];
	}

	const T& front() const {
		if (empty()) {
			throw std::out_of_range("Vector is Empty");
		}
		return _data[0];
	}
	
	//11
	T& back() {
		if (empty()) {
			throw std::out_of_range("Vector is Empty");
		}
		return _data[_size-1];
	}
	const T& back() const {
		if (empty()) {
			throw std::out_of_range("Vector is Empty");
		}
		return _data[_size-1];
	}
	//12
	std::size_t size() const {
		return _size;
	}
	//13
	std::size_t capacity() const {
		return _capacity;
	}
	//14
	bool empty() const {
		if (_size == 0) {
			return true;
		}
		return false;
	}

	//15
	void reserve(size_t new_capacity) {
		if (new_capacity > _capacity) {
			_resize_capacity(new_capacity);
		}
	}
	//16
	void clear() {
		_size = 0;
	}

	//17
	T* begin() {
		return _data;
	}
	const T* begin() const {
		return _data;
	}
	//18
	T* end() {
		if (_data == nullptr) {
			return nullptr;
		}
		return _data + _size;
	}
	const T* end() const {
		if (_data == nullptr) {
			return nullptr;
		}
		return _data + _size;
	}
};


#endif
