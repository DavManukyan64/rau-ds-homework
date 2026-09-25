#include "Stack.h"
#include <cassert>
#include <iostream>

// Реализуйте методы Stack<T>:
//   1. Stack()                         - конструктор
//   2. ~Stack()                        - деструктор
//   3. Stack(const &)                  - конструктор копирования
//   4. operator=(const &)              - оператор присваивания
//   5. push(const T&)                  - добавить
//   6. pop()                           - удалить
//   7. top()                           - вершина
//   8. size()                          - размер
//   9. capacity()                      - вместимость
//  10. is_empty()                      - пусто ли
//  11. clear()                         - очистить
//  12. peek()                          - просмотреть вершину
//  13. ...
//  14. ...

void test_push() {
    Stack<int> s;
    
    s.push(5);
    assert(s.size() == 1);
    assert(s.top() == 5);
    
    s.push(10);
    s.push(15);
    assert(s.size() == 3);
    assert(s.top() == 15);
    
    std::cout << "test_push passed" << std::endl;
}

// void test_pop() { ... }
// void test_top() { ... }

int main() {
    std::cout << "Running Stack tests" << std::endl;
    test_push();
    std::cout << "All tests passed" << std::endl;
    return 0;
}
