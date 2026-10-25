#ifndef STACK_H
#define STACK_H

#include <stdexcept>

template <typename T>
class Stack {
private:
    T* _data;
    int _capacity;
    int _size;

    void expand() {
        int new_capacity = (_capacity == 0) ? 4 : _capacity * 2;
        T* new_data = new T[new_capacity];
        for (int i = 0; i < _size; ++i) {
            new_data[i] = _data[i];
        }
        delete[] _data;
        _data = new_data;
        _capacity = new_capacity;
    }

public:
    Stack() : _data(nullptr), _capacity(0), _size(0) {}

    ~Stack() {
        delete[] _data;
    }

    Stack(const Stack& other) : _data(nullptr), _capacity(other._capacity), _size(other._size) {
        if (_capacity > 0) {
            _data = new T[_capacity];
            for (int i = 0; i < _size; ++i) {
                _data[i] = other._data[i];
            }
        }
    }

    Stack& operator=(const Stack& other) {
        if (this != &other) {
            T* new_data = nullptr;
            if (other._capacity > 0) {
                new_data = new T[other._capacity];
                for (int i = 0; i < other._size; ++i) {
                    new_data[i] = other._data[i];
                }
            }
            delete[] _data;
            _data = new_data;
            _capacity = other._capacity;
            _size = other._size;
        }
        return *this;
    }

    void push(const T& x) {
        if (_size >= _capacity) {
            expand();
        }
        _data[_size++] = x;
    }

    void pop() {
        if (is_empty()) {
            throw std::underflow_error("Stack is empty");
        }
        --_size;
    }

    T& top() {
        if (is_empty()) {
            throw std::out_of_range("Stack is empty");
        }
        return _data[_size - 1];
    }

    const T& top() const {
        if (is_empty()) {
            throw std::out_of_range("Stack is empty");
        }
        return _data[_size - 1];
    }

    int size() const {
        return _size;
    }

    int capacity() const {
        return _capacity;
    }

    bool is_empty() const {
        return _size == 0;
    }

    void clear() {
        _size = 0;
    }

    T& peek() {
        return top();
    }

    const T& peek() const {
        return top();
    }
};

#endif // STACK_H
