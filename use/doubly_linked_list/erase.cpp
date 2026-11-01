#include <iostream>

struct ListNode {
    int data;
    ListNode* next;
    ListNode* prev;

    explicit ListNode(int val) : data(val), next(nullptr), prev(nullptr) {}
};

void erase(ListNode* node) {
    if (node == nullptr) {
        return;
    }
    if (node->prev != nullptr) {
        node->prev->next = node->next;
    }
    if (node->next != nullptr) {
        node->next->prev = node->prev;
    }
    delete node;
}

int main() {
    ListNode* first = new ListNode(1);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(3);

    first->next = second;
    second->prev = first;

    second->next = third;
    third->prev = second;

    erase(second);

    return 0;
}
