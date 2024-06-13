#include "stack.h"

void Stack::push(const KeyValuePair &kv) {
    elements.push_back(kv);
}

void Stack::pop() {
    if (!elements.empty()) {
        elements.pop_back();
    }
}

KeyValuePair Stack::top() const {
    return elements.back();
}

bool Stack::isEmpty() const {
    return elements.empty();
}

std::vector<KeyValuePair> Stack::getElements() const {
    return elements;
}

