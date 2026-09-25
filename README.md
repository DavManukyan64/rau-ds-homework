# Data Structures Homework — RAU

Домашние задания по структурам данных на C++.

## Быстрый старт

### 1. Клонируй репо со всеми submodules
```bash
git clone --recurse-submodules https://github.com/rau-ds-homework/ds-homework.git
cd ds-homework
```

### 2. Track 1: Implementation (реализуй структуры)
```bash
cd implementation/Vector
g++ -std=c++17 main.cpp -o test
./test
```

### 3. Track 2: Use (решай задачи на STL)
```bash
cd use
# Открой vector.md и решай задачи
cat vector.md
```

---

## Структура репо

```
ds-homework/
├── implementation/          # Реализуй свои структуры данных с нуля
│   ├── Vector/
│   │   ├── Vector.h         # Интерфейс (только сигнатуры)
│   │   └── main.cpp         # Требования + пример теста
│   ├── CircularBuffer/
│   ├── Deque/
│   ├── ForwardList/
│   ├── DoublyLinkedList/
│   ├── Stack/
│   ├── Queue/
│   ├── Heap/
│   ├── BinarySearchTree/
│   ├── HashTable/
│   └── DisjointSets/
│
├── use/                     # Submodule: задачи на STL
│   ├── README_TESTING.md    # Как решать задачи
│   ├── vector.md            # Задачи на std::vector
│   ├── deque.md             # Задачи на std::deque
│   ├── stack_and_queue.md   # Задачи на std::stack/queue
│   ├── set.md               # Задачи на std::set
│   ├── map.md               # Задачи на std::map
│   └── ... остальные файлы
│
└── README.md                # Этот файл

```

---

## Track 1: Implementation

**Реализуй структуры данных с нуля**

### Как начать

1. Выбери структуру: `implementation/Vector/`
2. Открой `Vector.h` — там интерфейс (сигнатуры методов)
3. Реализуй методы (заполни тело функций)
4. В `main.cpp` напиши тесты

### Пример

**Vector.h:**
```cpp
template<typename T>
class Vector {
public:
    void push_back(const T& x) {
        // РЕАЛИЗУЙ ЗДЕСЬ
    }
};
```

**main.cpp:**
```cpp
void test_push_back() {
    Vector<int> v;
    v.push_back(5);
    assert(v.size() == 1);
}

int main() {
    test_push_back();
    return 0;
}
```

### Запуск

```bash
cd implementation/Vector
g++ -std=c++17 main.cpp -o test
./test
```

## Track 2: Use

**Решай задачи, используя STL контейнеры**

### Как начать

1. Открой `use/README_TESTING.md`
2. Выбери файл задач: `use/vector.md`, `use/deque.md` и т.д.
3. Напиши решение в отдельном файле
4. Скомпилируй и протестируй

### Пример

**use/vector.md содержит:**
```
## Задача 1: Обратный вектор
Дан вектор. Выведи его в обратном порядке.
```

**Твое решение `vector_task1.cpp`:**
```cpp
#include <vector>
#include <iostream>
#include <algorithm>

int main() {
    std::vector<int> v = {1, 2, 3};
    std::reverse(v.begin(), v.end());
    
    for (int x : v) std::cout << x << " ";
    return 0;
}
```

### Запуск

```bash
g++ -std=c++17 vector_task1.cpp -o solution
./solution
```

---

## Требования к тестам (Implementation)

Напиши для **каждого метода один тест**:

```cpp
void test_push_back() {
    Vector<int> v;
    
    // Нормальный случай
    v.push_back(10);
    assert(v.size() == 1);
    
    v.push_back(20);
    assert(v.size() == 2);
    
    // Граничные случаи
    v.push_back(30);
    assert(v[2] == 30);
    
    std::cout << "test_push_back passed" << std::endl;
}
```

**Важно:**
- Проверяй граничные случаи
- Используй `assert()` для проверок

