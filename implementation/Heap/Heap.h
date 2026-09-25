#ifndef HEAP_H
#define HEAP_H

template <typename T>
class Heap {
private:
    T* _data;
    int _capacity;
    int _size;
    
    void expand();
    void sift_up(int index);
    void sift_down(int index);

public:
    /// 1. Конструктор по умолчанию (min-heap)
    Heap();
    
    /// 2. Деструктор
    ~Heap();
    
    /// 3. Конструктор копирования
    Heap(const Heap& other);
    
    /// 4. Оператор присваивания
    Heap& operator=(const Heap& other);
    
    /// 5. insert(const T& x) - добавить элемент
    void insert(const T& x);
    
    /// 6. deleteMin() - удалить минимум (корень)
    void deleteMin();
    
    /// 7. getMin() - получить минимум
    T& getMin();
    const T& getMin() const;
    
    /// 8. size() - количество элементов
    int size() const;
    
    /// 9. capacity() - вместимость
    int capacity() const;
    
    /// 10. is_empty() - пуст ли
    bool is_empty() const;
    
    /// 11. clear() - очистить
    void clear();
    
    /// 12. heapify(T* array, int n) - построить кучу из массива
    void heapify(T* array, int n);
    
    /// 13. extract_min() - удалить и вернуть минимум
    T extract_min();
    
    /// 14. peek() - просмотреть минимум без удаления
    T& peek();
};

#endif // HEAP_H
