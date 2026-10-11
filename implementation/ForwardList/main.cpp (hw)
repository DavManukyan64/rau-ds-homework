#include "ForwardList.h"
#include <cassert>
#include <iostream>

void test_default_constructor() {
    ForwardList<int> list;
    assert(list.size() == 0);
    assert(list.empty() == true);
    assert(list.begin() == nullptr);
    std::cout << "test_ForwardList passed" << std::endl;
}
void test_destructor() {
    {
        ForwardList<int> list;
        list.push_front(1);
        list.push_front(2);
    }
    std::cout << "test_~ForwardList passed" << std::endl;
}

void test_copy_constructor() {
    ForwardList<int> list1;
    list1.push_front(1);
    list1.push_front(2);
    ForwardList<int> list2(list1);
    assert(list2.size() == 2);
    assert(list2.front() == 2);
    std::cout << "test_operator= passed" << std::endl;
}

void test_assignment_operator() {
    ForwardList<int> list1;
    list1.push_front(5);
    list1.push_front(15);

    ForwardList<int> list2;
    list2 = list1;
    assert(list2.size() == 2);
    assert(list2.front() == 15);

    list2 = list2;
    assert(list2.size() == 2);
    assert(list2.front() == 15);
    std::cout << "test_operator= passed" << std::endl;
}

void test_push_front() {
    ForwardList<int> list;

    list.push_front(1);
    assert(list.size() == 1);
    assert(list.front() == 1);

    list.push_front(2);
    list.push_front(3);
    assert(list.size() == 3);
    assert(list.front() == 3);

    std::cout << "test_push_front passed" << std::endl;
}
void test_pop_front() {
    ForwardList<int> list;
    list.push_front(10);
    list.push_front(20);

    list.pop_front();
    assert(list.size() == 1);
    assert(list.front() == 10);

    list.pop_front();
    assert(list.size() == 0);
    assert(list.empty() == true);

    std::cout << "test_pop_front passed" << std::endl;
}

void test_front() {
    ForwardList<int> list;
    list.push_front(42);
    assert(list.front() == 42);

    list.front() = 100;
    assert(list.front() == 100);

    std::cout << "test_front passed" << std::endl;
}

void test_insert_after() {
    ForwardList<int> list;
    list.push_front(10);

    ForwardList<int>::Node* node = list.begin();
    list.insert_after(node, 20);
    assert(list.size() == 2);
    assert(node->next->data == 20);

    std::cout << "test_insert_after passed" << std::endl;
}

void test_erase_after() {
    ForwardList<int> list;
    list.push_front(30);
    list.push_front(20);
    list.push_front(10);

    ForwardList<int>::Node* node = list.begin();
    list.erase_after(node);
    assert(list.size() == 2);
    assert(node->next->data == 30);

    std::cout << "test_erase_after passed" << std::endl;
}

void test_clear() {
    ForwardList<int> list;
    list.push_front(1);
    list.push_front(2);

    list.clear();
    assert(list.size() == 0);
    assert(list.empty() == true);
    assert(list.begin() == nullptr);

    std::cout << "test_clear passed" << std::endl;
}

void test_reverse() {
    ForwardList<int> list;
    list.push_front(3);
    list.push_front(2);
    list.push_front(1);

    list.reverse();
    assert(list.front() == 3);
    assert(list.begin()->next->data == 2);
    assert(list.begin()->next->next->data == 1);

    std::cout << "test_reverse passed" << std::endl;
}
void test_size() {
    ForwardList<int> list;
    assert(list.size() == 0);
    list.push_front(5);
    assert(list.size() == 1);
    list.push_front(10);
    assert(list.size() == 2);

    std::cout << "test_size passed" << std::endl;
}
void test_empty() {
    ForwardList<int> list;
    assert(list.empty() == true);
    list.push_front(1);
    assert(list.empty() == false);

    std::cout << "test_empty passed" << std::endl;
}
void test_begin() {
    ForwardList<int> list;
    assert(list.begin() == nullptr);

    list.push_front(77);
    assert(list.begin() != nullptr);
    assert(list.begin()->data == 77);

    std::cout << "test_begin passed" << std::endl;
}

int main() {
    test_default_constructor();
    test_destructor();
    test_copy_constructor();
    test_assignment_operator();
    test_push_front();
    test_pop_front();
    test_front();
    test_insert_after();
    test_erase_after();
    test_clear();
    test_reverse();
    test_size();
    test_empty();
    test_begin();

    std::cout << "All tests passed successfully!" << std::endl;
    return 0;
}
