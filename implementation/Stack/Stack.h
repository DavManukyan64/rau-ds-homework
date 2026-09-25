#ifndef STACK_H
#define STACK_H

template <typename T>
class Stack {
private:
    T* _data;
    int _capacity;
    int _size;
    
    void expand();

public:
    /// 1. Конструктор по умолчанию
    Stack();
    
    /// 2. Деструктор
    ~Stack();
    
    /// 3. Конструктор копирования
    Stack(const Stack& other);
    
    /// 4. Оператор присваивания
    Stack& operator=(const Stack& other);
    
    /// 5. push(const T& x) - добавить в стек
    void push(const T& x);
    
    /// 6. pop() - удалить с вершины
    void pop();
    
    /// 7. top() - вершина стека
    T& top();
    const T& top() const;
    
    /// 8. size() - количество элементов
    int size() const;
    
    /// 9. capacity() - вместимость
    int capacity() const;
    
    /// 10. is_empty() - пуст ли
    bool is_empty() const;
    
    /// 11. clear() - очистить
    void clear();
    
    /// 12. peek() - посмотреть вершину без удаления
    T& peek();
    const T& peek() const;
};

#endif // STACK_H
