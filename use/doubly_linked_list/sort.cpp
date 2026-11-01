#include <iostream>

struct ListNode {
    int data;
    ListNode* next;
    ListNode* prev;

    explicit ListNode(int val) : data(val), next(nullptr), prev(nullptr) {}
};


void sort(ListNode* head) {
    if (head == nullptr) {
        return;
    }
    bool swapped = true;
    while (swapped) {
        swapped = false;
        ListNode* current = head;
        while (current->next != nullptr) {
            if (current->data > current->next->data) {
                std::swap(current->data, current->next->data);
                swapped = true;
            }
            current = current->next;
        }
    }
}



int main() {
    ListNode* head = new ListNode(4);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(5);
    ListNode* fourth = new ListNode(1);
    ListNode* fifth = new ListNode(3);

    head->next = second;
    second->prev = head;

    second->next = third;
    third->prev = second;

    third->next = fourth;
    fourth->prev = third;

    fourth->next = fifth;
    fifth->prev = fourth;

    sort(head);

    return 0;
}
