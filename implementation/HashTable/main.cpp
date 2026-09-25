#include "HashTable.h"
#include <cassert>
#include <iostream>

// Реализуйте методы HashTable<K, V>:
//   1. HashTable()                     - конструктор
//   2. ~HashTable()                    - деструктор
//   3. HashTable(const &)              - конструктор копирования
//   4. operator=(const &)              - оператор присваивания
//   5. insert(const K&, const V&)      - вставить
//   6. remove(const K&)                - удалить
//   7. find(const K&)                  - найти значение
//   8. operator[](const K&)            - доступ как в map
//   9. size()                          - размер
//  10. capacity()                      - вместимость
//  11. is_empty()                      - пусто ли
//  12. clear()                         - очистить
//  13. contains(const K&)              - содержит ключ
//  14. load_factor()                   - коэффициент заполнения

void test_insert() {
    HashTable<int, int> ht;
    
    ht.insert(1, 10);
    assert(ht.size() == 1);
    assert(*ht.find(1) == 10);
    
    ht.insert(2, 20);
    ht.insert(3, 30);
    assert(ht.size() == 3);
    
    std::cout << "test_insert passed" << std::endl;
}

// void test_remove() { ... }
// void test_find() { ... }

int main() {
    std::cout << "Running HashTable tests" << std::endl;
    test_insert();
    std::cout << "All tests passed" << std::endl;
    return 0;
}
