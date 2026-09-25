# Data Structures Homework — RAU

Домашние задания по структурам данных на C++ для курса на 2-м курсе РАУ (~40 студентов).

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

### Требования

- **Методы 1-7**: 70%
- **Методы 8-11**: 85%
- **Методы 12-14**: 100%

Смотри в каждом `main.cpp`, что конкретно требуется.

### Структуры для реализации

1. Vector — динамический массив
2. Deque — двусторонняя очередь
3. CircularBuffer — циклический буфер
4. ForwardList — односвязный список
5. DoublyLinkedList — двусвязный список
6. Stack — стек
7. Queue — очередь
8. Heap — куча
9. BinarySearchTree — бинарное дерево поиска
10. HashTable — хеш-таблица
11. DisjointSets — система непересекающихся множеств

---

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
- Минимум 7+ тестов
- Проверяй граничные случаи
- Используй `assert()` для проверок
- Нет memory leaks!

---

## Оценка

| Компонент | Процент |
|-----------|---------|
| Implementation (7+ методов) | 70% |
| Implementation (все методы) | 100% |
| Use (решенные задачи) | +бонус |
| Устный экзамен | обязателен |

**Устный экзамен** (за неделю до модуля):
- Объясни свой код
- Напиши часть кода на бумаге
- Напиши тесты прямо на экзамене
- Отвечай на вопросы про алгоритм

---

## Как компилировать

### Linux / Mac
```bash
g++ -std=c++17 main.cpp -o test
./test
```

### Windows (MinGW)
```bash
g++ -std=c++17 main.cpp -o test.exe
test.exe
```

### IDE (VS Code / CLion)
Нажми **Run** (Ctrl+Shift+B)

---

## Частые проблемы

**Ошибка компиляции?**
- Проверь синтаксис в .h файле
- Убедись, что шаблоны объявлены правильно

**Segmentation fault?**
- Выход за границы массива
- Обращение к пустому контейнеру
- Утечка памяти (забыл `delete`)

**Тест не проходит?**
- Добавь `std::cout` для отладки
- Проверь граничные случаи
- Читай сообщение об ошибке в assert

---

## Как обновить submodule (use/)

```bash
cd use
git pull origin main
cd ..
```

---

## GitHub Classroom

Каждый студент получит:
- Свой форк: `github.com/rau-ds-homework/ds-homework-<ник>`
- CI проверяет компиляцию автоматически
- Преподаватель проверяет качество тестов

### Workflow студента
1. Клонируешь свой форк
2. Реализуешь структуру в `implementation/`
3. Решаешь задачи из `use/`
4. Пушишь в свой репо
5. GitHub Actions проверяет компиляцию

---

## Ссылки

- **ds-practice-problems**: https://github.com/Garnik645/ds-practice-problems
- **STL Reference**: https://en.cppreference.com/w/cpp/container
- **C++ Standard**: https://isocpp.org/

---

**Удачи! 🚀**
