#include "Vector.h"
#include <cassert>
#include <iostream>

void test_Vector() {
    Vector<int> v;

    assert(v.size() == 0);
    assert(v.capacity() == 0);
    assert(v.empty() == true);

    std::cout << "test_Vector passed!\n";
}

void test_DestVector() {
    {
        Vector<int> v(10);
        assert(v.size() == 10);
    }
    {
        Vector<int> v;
    }
    std::cout << "test_~Vector passed!\n";
}

void test_Vector_copy() {
    Vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    Vector<int> v2(v1);
    assert(v2.size() == 2);
    assert(v2[0] == 10);
    assert(v2[1] == 20);

    Vector<int> v3;
    Vector<int> v4(v3);
    assert(v4.empty() == true);

    std::cout << "test_Vector_copy passed!\n";
}

void test_operator_assignment() {
    Vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);

    Vector<int> v2;
    v2 = v1;
    assert(v2.size() == 2);
    assert(v2[0] == 1);
    assert(v2[1] == 2);

    v1 = v1;
    assert(v1.size() == 2);
    assert(v1[0] == 1);

    std::cout << "test_operator_assignment passed!\n";
}
void test_push_back() {
    Vector<int> v;
    v.push_back(5);
    assert(v.size() == 1);
    assert(v.capacity() >= 1);
    assert(v[0] == 5);

    v.push_back(10);
    v.push_back(15);
    assert(v.size() == 3);
    assert(v[1] == 10);
    assert(v[2] == 15);

    std::cout << "test_push_back passed!\n";
}

void test_pop_back() {
    Vector<int> v;
    v.push_back(100);
    v.push_back(200);
    v.pop_back();
    assert(v.size() == 1);
    assert(v[0] == 100);

    v.pop_back();
    assert(v.empty() == true);

    bool exception_thrown = false;
    try {
        v.pop_back();
    }
    catch (const std::out_of_range&) {
        exception_thrown = true;
    }
    assert(exception_thrown);

    std::cout << "test_pop_back passed!\n";
}

void test_operator_bracket() {
    Vector<int> v(2);
    v[0] = 42;
    v[1] = 84;
    assert(v[0] == 42);
    assert(v[1] == 84);

    const Vector<int>& cv = v;
    assert(cv[0] == 42);

    std::cout << "test_operator_bracket passed!\n";
}

void test_back() {
    Vector<int> v;
    v.push_back(10);
    v.push_back(99);
    assert(v.back() == 99);


    Vector<int> empty_v;
    bool exception_thrown = false;
    try {
        empty_v.back();
    }
    catch (const std::out_of_range&) {
        exception_thrown = true;
    }
    assert(exception_thrown);

    std::cout << "test_back passed!\n";
}

void test_clear() {
    Vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.clear();
    assert(v.size() == 0);
    assert(v.empty() == true);

    v.clear();
    assert(v.empty() == true);
    std::cout << "test_clear passed!\n";
}

void test_front() {
    Vector<int> v;
    v.push_back(11);
    v.push_back(22);
    assert(v.front() == 11);

    Vector<int> empty_v;
    bool exception_thrown = false;
    try {
        empty_v.front();
    }
    catch (const std::out_of_range&) {
        exception_thrown = true;
    }
    assert(exception_thrown);
    std::cout << "test_front passed!\n";
}


int main() {
    test_Vector();
    test_DestVector();
    test_Vector_copy();
    test_operator_assignment();
    test_push_back();
    test_pop_back();
    test_operator_bracket();
    test_back();
    test_clear();
    test_front();
    std::cout << "All tests passed successfully!\n";
    return 0;
}
