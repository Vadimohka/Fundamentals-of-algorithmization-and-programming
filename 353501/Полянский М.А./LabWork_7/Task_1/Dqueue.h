

template<typename T>

class Node
{
public:
    T data;
    Node<T>* next;
    Node<T>* prev;
    Node(T value): data(value), prev(nullptr), next(nullptr){}
};


template <typename T>
class Deque{
private:
    Node<T>*front;
    Node<T>* rear;
    int size;
public:
    Deque() : front(nullptr), rear(nullptr), size(0) {}
    ~Deque(){
        while (!isEmpty())
        {
            PopFront();
        }
    }
    void clear(){
        while(!isEmpty()){
            PopFront();
        }
    }
    bool isEmpty(){
        return size ==0;
    } 

    T PopFront(){
        // if(isEmpty()){
        //     throw std::runtime_error("dqueue is empty");

        // }
        T value = front->data;
        Node<T>* temp = front;
        front = front->next;
        if (front) {
            front->prev = nullptr;
        } else {
            rear = nullptr;
        }
        delete temp;
        size--;
        return value;
    }

    T PopBack(){
        
        T value = rear->data;
        Node<T>* tmp = rear;
        rear = rear->prev;
        if(rear) rear->next = nullptr;
        else front = nullptr;
        delete tmp;
        size--;
        return value;
    }

    void pushFront(T value){
        Node<T>* newNode = new Node<T>(value);
        if(isEmpty()){
            rear = front = newNode;
        }
        else{
            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode;
        }
        ++size;
    }

    void pushBack(T value){
        Node<T>* newNode = new Node<T>(value);
        if(isEmpty()) rear = front = newNode;
        else{
            newNode->prev = rear;
            rear->next = newNode;
            rear = newNode;
        }
        ++size;

    }

    void deleteN(T data){
        Node<T>* tmp = front;
        Node<T>* preve= nullptr;
        while(tmp->data != data){
            preve = tmp;
            tmp = tmp->next;
        }
        if(preve  == nullptr){
            front = tmp->next;
            if(front) front->prev = nullptr;
            else rear = nullptr;
        }
        else{
            preve->next = tmp->next;
            if(tmp->next) tmp->next->prev = preve;
        }
        delete tmp;
        --size;

    }
    class Iterator {
    private:
        Node<T>* current;

    public:
        Iterator(Node<T>* node) : current(node) {}

        T& operator*() const {
            return current->data;
        }

        Iterator& operator++() {
            current = current->next;
            return *this;
        }

        Iterator operator++(int) {
            Iterator old = *this;
            ++(*this);
            return old;
        }

        bool operator==(const Iterator& other) const {
            return current == other.current;
        }

        bool operator!=(const Iterator& other) const {
            return !(*this == other);
        }
        bool operator<(const Iterator& other) const {
        return current->data < other.current->data;
        }

        bool operator>(const Iterator& other) const {
            return current->data > other.current->data;
        }
    };
    
    Iterator begin() const {
        return Iterator(front);
    }

    Iterator end() const {
        return Iterator(nullptr);
    }


};
