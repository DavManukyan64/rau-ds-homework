#pragma once
#ifndef FORWARDLIST_H
#define FORWARDLIST_H

#include <stdexcept>

template <typename T>
class ForwardList {
public:
    struct Node {
        T data;
        Node* next;
        Node(const T& d) : data(d), next(nullptr) {}
    };

private:
    Node* _head;
    int _size;

public:
    // 1
    ForwardList() : _head(nullptr), _size(0) {}

    // 2
    ~ForwardList() {
        clear();
    }

    // 3
    ForwardList(const ForwardList& other) : _head(nullptr), _size(0) {
        Node* current = other._head;
        while (current != nullptr) {
            Node* newNode = new Node(current->data);
            if (_head == nullptr) {
                _head = newNode;
            } else {
                Node* last = _head;
                while (last->next != nullptr) {
                    last = last->next;
                }
                last->next = newNode;
            }
            ++_size;
            current = current->next;
        }
    }

    // 4
    ForwardList& operator=(const ForwardList& other) {
        if (this != &other) {
            ForwardList temp(other);
            Node* tempHead = _head;
            int tempSize = _size;
            _head = temp._head;
            _size = temp._size;
            temp._head = tempHead;
            temp._size = tempSize;
        }
        return *this;
    }

    // 5
    void push_front(const T& x) {
        Node* newNode = new Node(x);
        newNode->next = _head;
        _head = newNode;
        ++_size;
    }

    // 6
    void pop_front() {
        if (_head == nullptr) {
            return;
        }
        Node* temp = _head;
        _head = _head->next;
        delete temp;
        --_size;
    }

    // 7
    T& front() {
        if (_head == nullptr) {
            throw std::out_of_range("ForwardList is empty");
        }
        return _head->data;
    }
    
    const T& front() const {
        if (_head == nullptr) {
            throw std::out_of_range("ForwardList is empty");
        }
        return _head->data;
    }

    // 8
    void insert_after(Node* node, const T& value) {
        if (node == nullptr) {
            return;
        }
        Node* newNode = new Node(value);
        newNode->next = node->next;
        node->next = newNode;
        ++_size;
    }

    // 9
    void erase_after(Node* node) {
        if (node == nullptr || node->next == nullptr) {
            return;
        }
        Node* temp = node->next;
        node->next = temp->next;
        delete temp;
        --_size;
    }

    // 10
    void clear() {
        while (_head != nullptr) {
            Node* temp = _head;
            _head = _head->next;
            delete temp;
        }
        _size = 0;
    }

    // 11
    void reverse() {
        Node* previous = nullptr;
        Node* current = _head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            current->next = previous;
            previous = current;
            current = nextNode;
        }
        _head = previous;
    }

    // 12
    int size() const {
        return _size;
    }

    // 13
    bool empty() const {
        return _size == 0;
    }

    // 14
    Node* begin() {
        return _head;
    }

    const Node* begin() const {
        return _head;
    }
};

#endif
