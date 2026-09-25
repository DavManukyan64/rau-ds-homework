#include "Queue.h"
#include <cassert>
#include <iostream>

// Реализуйте методы Queue<T>:
//   1. Queue()                         - конструктор
//   2. ~Queue()                        - деструктор
//   3. Queue(const &)                  - конструктор копирования
//   4. operator=(const &)              - оператор присваивания
//   5. enqueue(const T&)               - добавить
//   6. dequeue()                       - удалить
//   7. front()                         - начало очереди
//   8. rear()                          - конец очереди
//   9. size()                          - размер
//  10. capacity()                      - вместимость
//  11. is_empty()                      - пусто ли
//  12. is_full()                       - полна ли
//  13. clear()                         - очистить
//  14. ...

void test_enqueue() {
    Queue<int> q;
    
    q.enqueue(1);
    assert(q.size() == 1);
    assert(q.front() == 1);
    
    q.enqueue(2);
    q.enqueue(3);
    assert(q.size() == 3);
    
    std::cout << "test_enqueue passed" << std::endl;
}

// void test_dequeue() { ... }
// void test_front() { ... }

int main() {
    std::cout << "Running Queue tests" << std::endl;
    test_enqueue();
    std::cout << "All tests passed" << std::endl;
    return 0;
}
