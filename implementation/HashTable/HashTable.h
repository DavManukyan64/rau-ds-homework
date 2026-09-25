#ifndef HASHTABLE_H
#define HASHTABLE_H

template <typename K, typename V>
class HashTable {
private:
    struct Pair {
        K key;
        V value;
        Pair(const K& k, const V& v) : key(k), value(v) {}
    };
    
    Pair** _table;
    int _capacity;
    int _size;
    
    int hash(const K& key) const;
    void rehash();

public:
    /// 1. Конструктор по умолчанию (capacity = 16)
    HashTable();
    
    /// 2. Деструктор
    ~HashTable();
    
    /// 3. Конструктор копирования
    HashTable(const HashTable& other);
    
    /// 4. Оператор присваивания
    HashTable& operator=(const HashTable& other);
    
    /// 5. insert(const K& key, const V& value) - вставить
    void insert(const K& key, const V& value);
    
    /// 6. remove(const K& key) - удалить
    bool remove(const K& key);
    
    /// 7. find(const K& key) - найти значение
    V* find(const K& key);
    const V* find(const K& key) const;
    
    /// 8. operator[](const K& key) - доступ как в map
    V& operator[](const K& key);
    
    /// 9. size() - количество пар
    int size() const;
    
    /// 10. capacity() - размер таблицы
    int capacity() const;
    
    /// 11. is_empty() - пусто ли
    bool is_empty() const;
    
    /// 12. clear() - очистить
    void clear();
    
    /// 13. contains(const K& key) - проверить наличие ключа
    bool contains(const K& key) const;
    
    /// 14. load_factor() - коэффициент заполнения
    double load_factor() const;
};

#endif // HASHTABLE_H
