#include "DisjointSets.h"
#include <cassert>
#include <iostream>

// Реализуйте методы DisjointSets<T>:
//   1. DisjointSets()                  - конструктор
//   2. ~DisjointSets()                 - деструктор
//   3. DisjointSets(const &)           - конструктор копирования
//   4. operator=(const &)              - оператор присваивания
//   5. make_set(const T&)              - создать множество
//   6. find(const T&)                  - найти представителя
//   7. unite(const T&, const T&)       - объединить множества
//   8. same_set(const T&, const T&)    - проверить в одном множестве
//   9. size()                          - размер
//  10. num_sets()                      - количество множеств
//  11. clear()                         - очистить
//  12. is_empty()                      - пусто ли
//  13. contains(const T&)              - содержит элемент
//  14. get_all_sets()                  - получить все множества

void test_make_set() {
    DisjointSets<int> ds;
    
    ds.make_set(1);
    assert(ds.size() == 1);
    assert(ds.contains(1));
    assert(ds.num_sets() == 1);
    
    ds.make_set(2);
    ds.make_set(3);
    assert(ds.size() == 3);
    assert(ds.num_sets() == 3);
    
    std::cout << "test_make_set passed" << std::endl;
}

// void test_find() { ... }
// void test_unite() { ... }

int main() {
    std::cout << "Running DisjointSets tests" << std::endl;
    test_make_set();
    std::cout << "All tests passed" << std::endl;
    return 0;
}
