#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

template <typename T>
class BinarySearchTree {
private:
    struct Node {
        T data;
        Node* left;
        Node* right;
        Node(const T& d) : data(d), left(nullptr), right(nullptr) {}
    };
    
    Node* _root;
    int _size;
    
    Node* insert_recursive(Node* node, const T& value) {
        if (node == nullptr) {
            ++_size;
            return new Node(value);
        }
        if (value < node->data) {
            node->left = insert_recursive(node->left, value);
        } else if (node->data < value) {
            node->right = insert_recursive(node->right, value);
        }
        return node;
    }
    
    Node* remove_recursive(Node* node, const T& value) {
        if (node == nullptr) {
            return nullptr;
        }
        if (value < node->data) {
            node->left = remove_recursive(node->left, value);
        } else if (node->data < value) {
            node->right = remove_recursive(node->right, value);
        } else {
            if (node->left == nullptr) {
                Node* r = node->right;
                delete node;
                --_size;
                return r;
            }
            if (node->right == nullptr) {
                Node* l = node->left;
                delete node;
                --_size;
                return l;
            }
            Node* m = node->right;
            while (m->left != nullptr) {
                m = m->left;
            }
            node->data = m->data;
            node->right = remove_recursive(node->right, m->data);
        }
        return node;
    }
    
    Node* find_recursive(Node* node, const T& value) const {
        if (node == nullptr) {
            return nullptr;
        }
        if (value < node->data) {
            return find_recursive(node->left, value);
        }
        if (node->data < value) {
            return find_recursive(node->right, value);
        }
        return node;
    }
    
    void clear_recursive(Node* node) {
        if (node == nullptr) {
            return;
        }
        clear_recursive(node->left);
        clear_recursive(node->right);
        delete node;
    }
    
    int height_recursive(Node* node) const {
        if (node == nullptr) {
            return 0;
        }
        int l = height_recursive(node->left);
        int r = height_recursive(node->right);
        return 1 + (l > r ? l : r);
    }

public:
    /// 1. Конструктор по умолчанию
    BinarySearchTree() : _root(nullptr), _size(0) {
    }
    
    /// 2. Деструктор
    ~BinarySearchTree() {
        clear();
    }
    
    /// 3. Конструктор копирования
    BinarySearchTree(const BinarySearchTree& other) : _root(nullptr), _size(0) {
        struct Copier {
            static void run(Node* node, BinarySearchTree& tree) {
                if (node == nullptr) {
                    return;
                }
                tree.insert(node->data);
                run(node->left, tree);
                run(node->right, tree);
            }
        };
        Copier::run(other._root, *this);
    }
    
    /// 4. Оператор присваивания
    BinarySearchTree& operator=(const BinarySearchTree& other) {
        if (this == &other) {
            return *this;
        }
        clear();
        struct Copier {
            static void run(Node* node, BinarySearchTree& tree) {
                if (node == nullptr) {
                    return;
                }
                tree.insert(node->data);
                run(node->left, tree);
                run(node->right, tree);
            }
        };
        Copier::run(other._root, *this);
        return *this;
    }
    
    /// 5. insert(const T& value) - вставить
    void insert(const T& value) {
        _root = insert_recursive(_root, value);
    }
    
    /// 6. remove(const T& value) - удалить
    void remove(const T& value) {
        _root = remove_recursive(_root, value);
    }
    
    /// 7. find(const T& value) - найти элемент
    bool find(const T& value) const {
        return find_recursive(_root, value) != nullptr;
    }
    
    /// 8. inorder() - обход в порядке (выводит на консоль)
    void inorder() const {
        struct Walker {
            static void run(Node* node) {
                if (node == nullptr) {
                    return;
                }
                run(node->left);
                std::cout << node->data << ' ';
                run(node->right);
            }
        };
        Walker::run(_root);
        std::cout << '\n';
    }
    
    /// 9. preorder() - префиксный обход
    void preorder() const {
        struct Walker {
            static void run(Node* node) {
                if (node == nullptr) {
                    return;
                }
                std::cout << node->data << ' ';
                run(node->left);
                run(node->right);
            }
        };
        Walker::run(_root);
        std::cout << '\n';
    }
    
    /// 10. postorder() - постфиксный обход
    void postorder() const {
        struct Walker {
            static void run(Node* node) {
                if (node == nullptr) {
                    return;
                }
                run(node->left);
                run(node->right);
                std::cout << node->data << ' ';
            }
        };
        Walker::run(_root);
        std::cout << '\n';
    }
    
    /// 11. size() - количество элементов
    int size() const {
        return _size;
    }
    
    /// 12. height() - высота дерева
    int height() const {
        return height_recursive(_root);
    }
    
    /// 13. clear() - очистить
    void clear() {
        clear_recursive(_root);
        _root = nullptr;
        _size = 0;
    }
    
    /// 14. is_empty() - пусто ли
    bool is_empty() const {
        return _size == 0;
    }
};

#endif // BINARYSEARCHTREE_H
