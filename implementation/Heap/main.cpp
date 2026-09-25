#include "Heap.h"
#include <cassert>
#include <iostream>

// Реализуйте методы Heap<T>:
//   1. Heap()                          - конструктор
//   2. ~Heap()                         - деструктор
//   3. Heap(const &)                   - конструктор копирования
//   4. operator=(const &)              - оператор присваивания
//   5. insert(const T&)                - добавить
//   6. deleteMin()                     - удалить минимум
//   7. getMin()                        - получить минимум
//   8. size()                          - размер
//   9. capacity()                      - вместимость
//  10. is_empty()                      - пусто ли
//  11. clear()                         - очистить
//  12. heapify(T*, int)                - построить кучу
//  13. extract_min()                   - удалить и вернуть минимум
//  14. peek()                          - просмотреть минимум

void test_insert() {
    Heap<int> h;
    
    h.insert(5);
    assert(h.size() == 1);
    assert(h.getMin() == 5);
    
    h.insert(3);
    h.insert(7);
    h.insert(1);
    assert(h.size() == 4);
    assert(h.getMin() == 1);
    
    std::cout << "test_insert passed" << std::endl;
}

// void test_deleteMin() { ... }
// void test_getMin() { ... }

int main() {
    std::cout << "Running Heap tests" << std::endl;
    test_insert();
    std::cout << "All tests passed" << std::endl;
    return 0;
}
