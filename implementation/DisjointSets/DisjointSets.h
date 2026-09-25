#ifndef DISJOINTSETS_H
#define DISJOINTSETS_H

#include <map>

template <typename T>
class DisjointSets {
private:
    struct Element {
        T value;
        Element* parent;
        int rank;
        Element(const T& v) : value(v), parent(this), rank(0) {}
    };
    
    std::map<T, Element*> _elements;
    int _num_sets;

public:
    /// 1. Конструктор по умолчанию
    DisjointSets();
    
    /// 2. Деструктор
    ~DisjointSets();
    
    /// 3. Конструктор копирования
    DisjointSets(const DisjointSets& other);
    
    /// 4. Оператор присваивания
    DisjointSets& operator=(const DisjointSets& other);
    
    /// 5. make_set(const T& value) - создать множество из одного элемента
    void make_set(const T& value);
    
    /// 6. find(const T& value) - найти представителя множества
    T find(const T& value);
    
    /// 7. unite(const T& x, const T& y) - объединить два множества
    void unite(const T& x, const T& y);
    
    /// 8. same_set(const T& x, const T& y) - проверить в одном ли множестве
    bool same_set(const T& x, const T& y);
    
    /// 9. size() - количество элементов
    int size() const;
    
    /// 10. num_sets() - количество множеств
    int num_sets() const;
    
    /// 11. clear() - очистить
    void clear();
    
    /// 12. is_empty() - пусто ли
    bool is_empty() const;
    
    /// 13. contains(const T& value) - содержит ли элемент
    bool contains(const T& value) const;
    
    /// 14. get_all_sets() - получить все множества
    std::vector<std::vector<T>> get_all_sets();
};

#endif // DISJOINTSETS_H
