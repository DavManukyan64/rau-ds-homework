#ifndef QUEUE_H
#define QUEUE_H

template <typename T>
class Queue {
private:
    T* _data;
    int _capacity;
    int _front;
    int _rear;
    int _size;
    
    void expand();

public:
    /// 1. Конструктор по умолчанию
    Queue();
    
    /// 2. Деструктор
    ~Queue();
    
    /// 3. Конструктор копирования
    Queue(const Queue& other);
    
    /// 4. Оператор присваивания
    Queue& operator=(const Queue& other);
    
    /// 5. enqueue(const T& x) - добавить в очередь
    void enqueue(const T& x);
    
    /// 6. dequeue() - удалить с начала очереди
    void dequeue();
    
    /// 7. front() - начало очереди
    T& front();
    const T& front() const;
    
    /// 8. rear() / back() - конец очереди
    T& rear();
    const T& rear() const;
    
    /// 9. size() - количество элементов
    int size() const;
    
    /// 10. capacity() - вместимость
    int capacity() const;
    
    /// 11. is_empty() - пуста ли
    bool is_empty() const;
    
    /// 12. is_full() - полна ли
    bool is_full() const;
    
    /// 13. clear() - очистить
    void clear();
};

#endif // QUEUE_H
