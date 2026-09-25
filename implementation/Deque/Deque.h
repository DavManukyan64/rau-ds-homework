#ifndef DEQUE_H
#define DEQUE_H

template <typename T>
class Deque {
private:
    T* _data;
    int _capacity;
    int _front;
    int _size;
    
    void expand();
    void shrink();

public:
    /// 1. Конструктор по умолчанию
    Deque();
    
    /// 2. Деструктор
    ~Deque();
    
    /// 3. Конструктор копирования
    Deque(const Deque& other);
    
    /// 4. Оператор присваивания
    Deque& operator=(const Deque& other);
    
    /// 5. push_back(const T& x) - добавить в конец
    void push_back(const T& x);
    
    /// 6. push_front(const T& x) - добавить в начало
    void push_front(const T& x);
    
    /// 7. pop_back() - удалить с конца
    void pop_back();
    
    /// 8. pop_front() - удалить с начала
    void pop_front();
    
    /// 9. operator[](int index) - доступ по индексу
    T& operator[](int index);
    const T& operator[](int index) const;
    
    /// 10. front() - первый элемент
    T& front();
    const T& front() const;
    
    /// 11. back() - последний элемент
    T& back();
    const T& back() const;
    
    /// 12. insert(int pos, const T& value) - вставить
    void insert(int pos, const T& value);
    
    /// 13. erase(int pos) - удалить
    void erase(int pos);
    
    /// 14. clear() - очистить
    void clear();
    
    int size() const;
    int capacity() const;
    bool empty() const;
};

#endif // DEQUE_H
