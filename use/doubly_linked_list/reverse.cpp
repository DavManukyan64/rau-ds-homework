#include <iostream>

struct ListNode {
    int data;
    ListNode* next;
    ListNode* prev;

    explicit ListNode(int val) : data(val), next(nullptr), prev(nullptr) {}
};



ListNode* reverse(ListNode* head) {
    ListNode* current = head;
    ListNode* temp = nullptr;

    while (current != nullptr) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != nullptr) {
        head = temp->prev;
    }
    return head;
}



int main() {
    ListNode* head = new ListNode(1);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(3);

    head->next = second;
    second->prev = head;

    second->next = third;
    third->prev = second;

    head = reverse(head);

    return 0;
}
