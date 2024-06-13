#include "list.h"

void List::append(int value)
{
    std::shared_ptr<Node> newNode = std::make_shared<Node>(value);
    if (!head) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    size++;
}

QStringList List::printList() const
{
    QStringList list{};
    std::shared_ptr<Node> current = head;
    while (current) {
        list.push_back(QString::number(current->data));
        current = current->next;
    }
    return list;
}

int& List::operator[](int i)
{
    if (i < size) {
        int index = 0;
        std::shared_ptr<Node> current = head;
        while (index != i && current && current->next) {
            current = current->next;
            index++;
        }
        return current->data;
    }
    throw QException();
}