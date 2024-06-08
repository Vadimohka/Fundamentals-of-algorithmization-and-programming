// #include "Stack.h"

// Stack::Stack() : top(-1) {}

// bool Stack::isEmpty() {
//     return top == -1;
// }

// bool Stack::isFull()  {
//     return top == MAX_SIZE - 1;
// }

// void Stack::push(int newItem) {
//     if (isFull()) {
//         throw "Stack overflow";
//     }
//     ++top;
//     items[top] = newItem;
// }

// int Stack::pop() {
//     if (isEmpty()) {
//         throw "Stack underflow";
//     }
//     int removedItem = items[top];
//     --top;
//     return removedItem;
// }

// QVector<int> Stack::toQVector() {
//     QVector<int> vec;
//     for (int i = top; i >= 0; --i) {
//         vec.append(items[i]);
//     }
//     return vec;
// }

// int Stack::peek() {
//     if (!isEmpty()) {
//         return items[top];
//     }
//     throw "Stack underflow";
// }

// void Stack::clear() {
//     top = -1;
// }

