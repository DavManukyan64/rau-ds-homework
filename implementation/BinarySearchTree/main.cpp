
#include "BinarySearchTree.h"
#include <cassert>
#include <iostream>

void test_constructor() {
    BinarySearchTree<int> bst;

    assert(bst.is_empty());
    assert(bst.size() == 0);
    assert(bst.height() == 0);

    std::cout << "test_constructor passed" << std::endl;
}

void test_destructor() {
    {
        BinarySearchTree<int> bst;

        bst.insert(50);
        bst.insert(30);
        bst.insert(70);
        bst.insert(20);
        bst.insert(40);
    }

    std::cout << "test_destructor passed" << std::endl;
}

void test_copy_constructor() {
    BinarySearchTree<int> bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);

    BinarySearchTree<int> copy(bst);

    assert(copy.size() == 5);
    assert(copy.find(50));
    assert(copy.find(30));
    assert(copy.find(70));
    assert(copy.find(20));
    assert(copy.find(40));

    copy.remove(30);

    assert(!copy.find(30));
    assert(bst.find(30));

    std::cout << "test_copy_constructor passed" << std::endl;
}

void test_assignment_operator() {
    BinarySearchTree<int> bst;
    BinarySearchTree<int> copy;

    bst.insert(50);
    bst.insert(30);
    bst.insert(70);

    copy.insert(100);
    copy = bst;

    assert(copy.size() == 3);
    assert(copy.find(50));
    assert(copy.find(30));
    assert(copy.find(70));
    assert(!copy.find(100));

    copy.remove(50);

    assert(!copy.find(50));
    assert(bst.find(50));

    std::cout << "test_assignment_operator passed" << std::endl;
}

void test_insert() {
    BinarySearchTree<int> bst;

    bst.insert(50);
    assert(bst.size() == 1);
    assert(bst.find(50));

    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);

    assert(bst.size() == 5);
    assert(bst.find(30));
    assert(bst.find(70));

    bst.insert(50);
    assert(bst.size() == 5);

    std::cout << "test_insert passed" << std::endl;
}

void test_remove() {
    BinarySearchTree<int> bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    bst.remove(20);
    assert(!bst.find(20));
    assert(bst.size() == 6);

    bst.remove(30);
    assert(!bst.find(30));
    assert(bst.size() == 5);

    bst.remove(50);
    assert(!bst.find(50));
    assert(bst.size() == 4);

    bst.remove(100);
    assert(bst.size() == 4);

    std::cout << "test_remove passed" << std::endl;
}

void test_find() {
    BinarySearchTree<int> bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(70);

    assert(bst.find(50));
    assert(bst.find(30));
    assert(bst.find(70));
    assert(!bst.find(100));

    std::cout << "test_find passed" << std::endl;
}

void test_size() {
    BinarySearchTree<int> bst;

    assert(bst.size() == 0);

    bst.insert(10);
    bst.insert(20);
    bst.insert(30);

    assert(bst.size() == 3);

    bst.remove(20);
    assert(bst.size() == 2);

    std::cout << "test_size passed" << std::endl;
}

void test_height() {
    BinarySearchTree<int> bst;

    assert(bst.height() == 0);

    bst.insert(50);
    assert(bst.height() == 1);

    bst.insert(30);
    bst.insert(70);
    assert(bst.height() == 2);

    bst.insert(20);
    assert(bst.height() == 3);

    std::cout << "test_height passed" << std::endl;
}

void test_clear() {
    BinarySearchTree<int> bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(70);

    bst.clear();

    assert(bst.size() == 0);
    assert(bst.is_empty());
    assert(bst.height() == 0);
    assert(!bst.find(50));

    std::cout << "test_clear passed" << std::endl;
}

void test_is_empty() {
    BinarySearchTree<int> bst;

    assert(bst.is_empty());

    bst.insert(10);
    assert(!bst.is_empty());

    bst.remove(10);
    assert(bst.is_empty());

    std::cout << "test_is_empty passed" << std::endl;
}

void test_traversals() {
    BinarySearchTree<int> bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);

    std::cout << "Inorder: ";
    bst.inorder();

    std::cout << "Preorder: ";
    bst.preorder();

    std::cout << "Postorder: ";
    bst.postorder();

    std::cout << "test_traversals passed" << std::endl;
}

int main() {
    std::cout << "Running BinarySearchTree tests" << std::endl;

    test_constructor();
    test_destructor();
    test_copy_constructor();
    test_assignment_operator();
    test_insert();
    test_remove();
    test_find();
    test_size();
    test_height();
    test_clear();
    test_is_empty();
    test_traversals();

    std::cout << "All tests passed" << std::endl;

    return 0;
}
