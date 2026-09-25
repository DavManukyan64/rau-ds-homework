#ifndef FORWARDLIST_H
#define FORWARDLIST_H

template <typename T>
class ForwardList {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& d) : data(d), next(nullptr) {}
    };
    
    Node* _head;
    int _size;

public:
    /// 1. Конструктор по умолчанию
    ForwardList();
    
    /// 2. Деструктор
    ~ForwardList();
    
    /// 3. Конструктор копирования
    ForwardList(const ForwardList& other);
    
    /// 4. Оператор присваивания
    ForwardList& operator=(const ForwardList& other);
    
    /// 5. push_front(const T& x) - добавить в начало
    void push_front(const T& x);
    
    /// 6. pop_front() - удалить с начала
    void pop_front();
    
    /// 7. front() - первый элемент
    T& front();
    const T& front() const;
    
    /// 8. insert_after(Node* node, const T& value) - вставить после узла
    void insert_after(Node* node, const T& value);
    
    /// 9. erase_after(Node* node) - удалить после узла
    void erase_after(Node* node);
    
    /// 10. clear() - очистить
    void clear();
    
    /// 11. reverse() - развернуть
    void reverse();
    
    /// 12. size() - количество элементов
    int size() const;
    
    /// 13. empty() - пуст ли
    bool empty() const;
    
    /// 14. begin() - начало списка
    Node* begin();
    Node* begin() const;
};

#endif // FORWARDLIST_H
