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
        std::stack<Node*> st;
        if (other._root != nullptr) {
            st.push(other._root);
        }
        while (!st.empty()) {
            Node* cur = st.top();
            st.pop();
            insert(cur->data);
            if (cur->right != nullptr) {
                st.push(cur->right);
            }
            if (cur->left != nullptr) {
                st.push(cur->left);
            }
        }
    }
    
    /// 4. Оператор присваивания
    BinarySearchTree& operator=(const BinarySearchTree& other) {
        if (this == &other) {
            return *this;
        }
        clear();
        std::stack<Node*> st;
        if (other._root != nullptr) {
            st.push(other._root);
        }
        while (!st.empty()) {
            Node* cur = st.top();
            st.pop();
            insert(cur->data);
            if (cur->right != nullptr) {
                st.push(cur->right);
            }
            if (cur->left != nullptr) {
                st.push(cur->left);
            }
        }
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
        std::stack<Node*> st;
        Node* cur = _root;
        while (cur != nullptr || !st.empty()) {
            while (cur != nullptr) {
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top();
            st.pop();
            std::cout << cur->data << ' ';
            cur = cur->right;
        }
        std::cout << '\n';
    }
    
    /// 9. preorder() - префиксный обход
    void preorder() const {
        std::stack<Node*> st;
        if (_root != nullptr) {
            st.push(_root);
        }
        while (!st.empty()) {
            Node* cur = st.top();
            st.pop();
            std::cout << cur->data << ' ';
            if (cur->right != nullptr) {
                st.push(cur->right);
            }
            if (cur->left != nullptr) {
                st.push(cur->left);
            }
        }
        std::cout << '\n';
    }
    
    /// 10. postorder() - постфиксный обход
    void postorder() const {
        std::stack<Node*> st1;
        std::stack<Node*> st2;
        if (_root != nullptr) {
            st1.push(_root);
        }
        while (!st1.empty()) {
            Node* cur = st1.top();
            st1.pop();
            st2.push(cur);
            if (cur->left != nullptr) {
                st1.push(cur->left);
            }
            if (cur->right != nullptr) {
                st1.push(cur->right);
            }
        }
        while (!st2.empty()) {
            std::cout << st2.top()->data << ' ';
            st2.pop();
        }
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
