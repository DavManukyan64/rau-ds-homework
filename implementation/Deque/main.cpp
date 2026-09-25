#include "Deque.h"
#include <cassert>
#include <iostream>

// Реализуйте методы Deque<T>:
//
//   1. Deque()                         - конструктор по умолчанию
//   2. ~Deque()                        - деструктор
//   3. Deque(const Deque& other)       - конструктор копирования
//   4. operator=(const Deque& other)   - оператор присваивания
//   5. push_back(const T& x)           - добавить в конец
//   6. push_front(const T& x)          - добавить в начало
//   7. pop_back()                      - удалить с конца
//   8. pop_front()                     - удалить с начала
//   9. operator[](int)                 - доступ по индексу
//  10. front()                         - первый элемент
//  11. back()                          - последний элемент
//  12. insert(int, const T&)           - вставить
//  13. erase(int)                      - удалить
//  14. clear()                         - очистить
//
// Напишите для каждой функции один тест:
//   void test_<название_функции>() { ... }


void test_push_back() {
    Deque<int> d;
    
    d.push_back(10);
    assert(d.size() == 1);
    assert(d.back() == 10);
    
    d.push_back(20);
    d.push_back(30);
    assert(d.size() == 3);
    
    std::cout << "test_push_back passed" << std::endl;
}

// void test_push_front() { ... }
// void test_pop_back() { ... }
// void test_pop_front() { ... }


int main() {
    std::cout << "Running Deque tests" << std::endl;
    
    test_push_back();
    
    std::cout << "All tests passed" << std::endl;
    return 0;
}
