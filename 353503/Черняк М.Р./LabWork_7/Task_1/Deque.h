#include <stdexcept>
#include <unordered_set>

template <typename T>
class Deque {
private:
    struct Node {
        T data;
        Node* next;
        Node* prev;

        Node(const T& value) : data(value), next(nullptr), prev(nullptr) {}
    };

    Node* front;
    Node* back;
    int size;

public:
    Deque() : front(nullptr), back(nullptr), size(0) {}

    ~Deque() {
        clear();
    }

    bool isEmpty() const {
        return size == 0;
    }

    int getSize() const {
        return size;
    }

    void pushFront(const T& value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            front = back = newNode;
        } else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
        size++;
    }

    void pushBack(const T& value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            front = back = newNode;
        } else {
            back->next = newNode;
            newNode->prev = back;
            back = newNode;
        }
        size++;
    }

    T popFront() {
        if (isEmpty()) {
            throw std::runtime_error("Deque is empty");
        }
        T value = front->data;
        Node* temp = front;
        if (front == back) {
            front = back = nullptr;
        } else {
            front = front->next;
            front->prev = nullptr;
        }
        delete temp;
        size--;
        return value;
    }

    T popBack() {
        if (isEmpty()) {
            throw std::runtime_error("Deque is empty");
        }
        T value = back->data;
        Node* temp = back;
        if (front == back) {
            front = back = nullptr;
        } else {
            back = back->prev;
            back->next = nullptr;
        }
        delete temp;
        size--;
        return value;
    }

    T peekFront() const {
        if (isEmpty()) {
            throw std::runtime_error("Deque is empty");
        }
        return front->data;
    }

    T peekBack() const {
        if (isEmpty()) {
            throw std::runtime_error("Deque is empty");
        }
        return back->data;
    }

    T at(int index) const {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }

        Node* current = front;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }

        return current->data;
    }

    void clear() {
        while (!isEmpty()) {
            popFront();
        }
    }

    void removeDuplicates() {
        if (isEmpty() || size == 1) {
            return; // Если деке пуста или содержит только один элемент, ничего не делаем
        }

        std::unordered_set<T> uniqueElements;
        Node* current = front;
        Node* prev = nullptr;

        while (current != nullptr) {
            if (uniqueElements.find(current->data) == uniqueElements.end()) {
                // Если элемент уникален, добавляем его в множество и перемещаемся к следующему
                uniqueElements.insert(current->data);
                prev = current;
                current = current->next;
            } else {
                // Если элемент повторяется, удаляем его из деки
                Node* temp = current;
                if (current == front) {
                    // Если удаляемый элемент - первый, обновляем front
                    front = current->next;
                    if (front != nullptr) {
                        front->prev = nullptr;
                    }
                } else {
                    prev->next = current->next;
                    if (current->next != nullptr) {
                        current->next->prev = prev;
                    } else {
                        // Если удаляемый элемент - последний, обновляем back
                        back = prev;
                    }
                }
                current = current->next;
                delete temp;
                size--;
            }
        }
    }
};
