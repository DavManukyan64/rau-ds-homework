#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

template <typename T>
class DoublyLinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node* prev;
        Node(const T& d) : data(d), next(nullptr), prev(nullptr) {}
    };
    
    Node* _head;
    Node* _tail;
    int _size;

public:
    /// 1. Конструктор по умолчанию
    DoublyLinkedList();
    
    /// 2. Деструктор
    ~DoublyLinkedList();
    
    /// 3. Конструктор копирования
    DoublyLinkedList(const DoublyLinkedList& other);
    
    /// 4. Оператор присваивания
    DoublyLinkedList& operator=(const DoublyLinkedList& other);
    
    /// 5. push_back(const T& x) - добавить в конец
    void push_back(const T& x);
    
    /// 6. push_front(const T& x) - добавить в начало
    void push_front(const T& x);
    
    /// 7. pop_back() - удалить с конца
    void pop_back();
    
    /// 8. pop_front() - удалить с начала
    void pop_front();
    
    /// 9. insert(int pos, const T& x) - вставить на позицию
    void insert(int pos, const T& x);
    
    /// 10. erase(int pos) - удалить с позиции
    void erase(int pos);
    
    /// 11. front() - первый элемент
    T& front();
    const T& front() const;
    
    /// 12. back() - последний элемент
    T& back();
    const T& back() const;
    
    /// 13. clear() - очистить
    void clear();
    
    /// 14. reverse() - развернуть
    void reverse();
    
    int size() const;
    bool empty() const;
};

#endif // DOUBLYLINKEDLIST_H
