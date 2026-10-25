#ifndef STACK_CPP
#define STACK_CPP

#include "Stack.h"
#include <stdexcept>

template <typename T>
void Stack<T>::expand() {
    int new_capacity = (_capacity == 0) ? 4 : _capacity * 2;
    T* new_data = new T[new_capacity];
    for (int i = 0; i < _size; ++i) {
        new_data[i] = _data[i];
    }
    delete[] _data;
    _data = new_data;
    _capacity = new_capacity;
}

template <typename T>
Stack<T>::Stack() : _data(nullptr), _capacity(0), _size(0) {}

template <typename T>
Stack<T>::~Stack() {
    delete[] _data;
}

template <typename T>
Stack<T>::Stack(const Stack& other) : _data(nullptr), _capacity(other._capacity), _size(other._size) {
    if (_capacity > 0) {
        _data = new T[_capacity];
        for (int i = 0; i < _size; ++i) {
            _data[i] = other._data[i];
        }
    }
}

template <typename T>
Stack<T>& Stack<T>::operator=(const Stack& other) {
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

template <typename T>
void Stack<T>::push(const T& x) {
    if (_size >= _capacity) {
        expand();
    }
    _data[_size++] = x;
}

template <typename T>
void Stack<T>::pop() {
    if (is_empty()) {
        throw std::underflow_error("Stack is empty");
    }
    --_size;
}

template <typename T>
T& Stack<T>::top() {
    if (is_empty()) {
        throw std::out_of_range("Stack is empty");
    }
    return _data[_size - 1];
}

template <typename T>
const T& Stack<T>::top() const {
    if (is_empty()) {
        throw std::out_of_range("Stack is empty");
    }
    return _data[_size - 1];
}

template <typename T>
int Stack<T>::size() const {
    return _size;
}

template <typename T>
int Stack<T>::capacity() const {
    return _capacity;
}

template <typename T>
bool Stack<T>::is_empty() const {
    return _size == 0;
}

template <typename T>
void Stack<T>::clear() {
    _size = 0;
}

template <typename T>
T& Stack<T>::peek() {
    return top();
}

template <typename T>
const T& Stack<T>::peek() const {
    return top();
}

#endif
