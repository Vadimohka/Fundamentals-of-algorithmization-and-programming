template <typename Key, typename Value>
class RBTree {
public:
    struct Node {
        friend class RBTree;

        Key key;
        Value value;

    protected:
        Node *leftChild;
        Node *rightChild;
        Node *parentNode;
        bool nodeColor;

        Node(const Key &key, const Value &value);
    };

protected:
    Node *searchNode(const Key &key);
    void replaceNode(Node *oldNode, Node *newNode);
    void leftRotate(Node *x);
    void rightRotate(Node *x);
    long calculateMaxDepth(Node *node);
    void deleteSubTree(Node *node);

public:
    RBTree();
    ~RBTree();
    void clearTree();
    bool containsKey(const Key &key);
    Value &getValue(const Key &key);
    Node *addNode(const Key &key, const Value &value);
    void removeNode(const Key &key);
    long calculateMaxDepth();
    int calculateSize();

    class Iterator {
    protected:
        friend class RBTree<Key, Value>;
        Iterator(Node *rootNode);

    public:
        Node *operator->();
        Node &operator*();
        Iterator &operator++();
        bool operator==(const Iterator &other);
        bool operator!=(const Iterator &other);

    protected:
        Node *currentNode;
    };

    Iterator begin();
    Iterator end();

public:
    class Inspector {
    public:
        virtual ~Inspector() {}
        virtual void setValue(const Value& value) = 0;
        virtual void setKey(const Key& key) = 0;
        virtual void setMode(int mode) = 0;
        virtual Inspector * createChild() = 0;
    };

protected:
    void inspectTree(Inspector *ins, Node *node);

public:
    void inspectTree(Inspector *ins);

protected:
    Node *root;

    int calculateSubtreeSize(Node* n);
};

// Node constructor
template <typename Key, typename Value>
RBTree<Key, Value>::Node::Node(const Key &key, const Value &value)
    : key(key), value(value), leftChild(nullptr), rightChild(nullptr), parentNode(nullptr), nodeColor(0) {}

// Constructor for the RBTree
template <typename Key, typename Value>
RBTree<Key, Value>::RBTree() : root(nullptr) {}

// Destructor for the RBTree
template <typename Key, typename Value>
RBTree<Key, Value>::~RBTree() {
    clearTree();
}

// Clear the entire tree
template <typename Key, typename Value>
void RBTree<Key, Value>::clearTree() {
    deleteSubTree(root);
    root = nullptr;
}

// Delete the subtree rooted at the given node
template <typename Key, typename Value>
void RBTree<Key, Value>::deleteSubTree(Node *node) {
    if (node == nullptr)
        return;

    deleteSubTree(node->leftChild);
    deleteSubTree(node->rightChild);
    delete node;
}

// Check if the tree contains a given key
template <typename Key, typename Value>
bool RBTree<Key, Value>::containsKey(const Key &key) {
    return searchNode(key) != nullptr;
}

// Get the value associated with a given key
template <typename Key, typename Value>
Value &RBTree<Key, Value>::getValue(const Key &key) {
    Node *node = searchNode(key);
    if (node == nullptr)
        throw std::logic_error("Key not found");
    return node->value;
}

// Search for a node with the given key
template <typename Key, typename Value>
typename RBTree<Key, Value>::Node *RBTree<Key, Value>::searchNode(const Key &key) {
    Node *current = root;
    while (current != nullptr) {
        if (key == current->key)
            return current;
        if (key < current->key)
            current = current->leftChild;
        else
            current = current->rightChild;
    }
    return nullptr;
}

// Replace one node with another in the tree
template <typename Key, typename Value>
void RBTree<Key, Value>::replaceNode(Node *oldNode, Node *newNode) {
    Node *parent = oldNode->parentNode;
    if (newNode) {
        newNode->parentNode = parent;
    }

    if (parent == nullptr) {
        root = newNode;
    } else {
        if (parent->leftChild == oldNode) {
            parent->leftChild = newNode;
        } else {
            parent->rightChild = newNode;
        }
    }
}

// Perform a left rotation on a node
template <typename Key, typename Value>
void RBTree<Key, Value>::leftRotate(Node *x) {
    Node *y = x->rightChild;

    Node *b = y->leftChild;
    x->rightChild = b;
    if (b != nullptr)
        b->parentNode = x;

    replaceNode(x, y);

    y->leftChild = x;
    x->parentNode = y;
}

// Perform a right rotation on a node
template <typename Key, typename Value>
void RBTree<Key, Value>::rightRotate(Node *x) {
    Node *y = x->leftChild;

    Node *b = y->rightChild;
    x->leftChild = b;
    if (b != nullptr)
        b->parentNode = x;

    replaceNode(x, y);

    y->rightChild = x;
    x->parentNode = y;
}

// Calculate the maximum depth of the tree
template <typename Key, typename Value>
long RBTree<Key, Value>::calculateMaxDepth(Node *node) {
    if (node == nullptr)
        return 0;
    int leftDepth = calculateMaxDepth(node->leftChild);
    int rightDepth = calculateMaxDepth(node->rightChild);
    return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
}

// Return the maximum depth of the tree
template <typename Key, typename Value>
long RBTree<Key, Value>::calculateMaxDepth() {
    return calculateMaxDepth(root);
}

// Add a node to the tree
template <typename Key, typename Value>
typename RBTree<Key, Value>::Node *RBTree<Key, Value>::addNode(const Key &key, const Value &value) {
    if (root == nullptr) {
        root = new Node(key, value);
        root->nodeColor = 0; // Root is always black
        return root;
    }

    Node *parent = root;
    Node *node = nullptr;
    while (true) {
        if (key == parent->key) {
            parent->value = value; // Replace the value if key already exists
            return parent;
        }

        if (key < parent->key) {
            if (parent->leftChild == nullptr) {
                node = new Node(key, value);
                parent->leftChild = node;
                break;
            } else {
                parent = parent->leftChild;
            }
        } else {
            if (parent->rightChild == nullptr) {
                node = new Node(key, value);
                parent->rightChild = node;
                break;
            } else {
                parent = parent->rightChild;
            }
        }
    }
    Node *result = node;

    node->nodeColor = true; // New node is red
    node->parentNode = parent;

    // Fixup the tree
    while (node->parentNode != nullptr) {
        parent = node->parentNode;

        if (parent->nodeColor == 0)
            return result;

        Node *grandparent = parent->parentNode;
        if (grandparent == nullptr) {
            parent->nodeColor = 0;
            return result;
        }

        Node *uncle = grandparent->leftChild == parent ? grandparent->rightChild : grandparent->leftChild;
        if (uncle == nullptr || uncle->nodeColor == 0) {
            if (grandparent->leftChild == parent && parent->rightChild == node) {
                leftRotate(parent);
                std::swap(node, parent);
            }

            if (grandparent->rightChild == parent && parent->leftChild == node) {
                rightRotate(parent);
                std::swap(node, parent);
            }

            if (grandparent->leftChild == parent) {
                rightRotate(grandparent);
            } else {
                leftRotate(grandparent);
            }

            parent->nodeColor = 0;
            grandparent->nodeColor = 1;
            return result;
        }

        parent->nodeColor = 0;
        uncle->nodeColor = 0;
        grandparent->nodeColor = 1;

        node = grandparent;
    }

    return result;
}

// Remove a node with a given key from the tree
template <typename Key, typename Value>
void RBTree<Key, Value>::removeNode(const Key &key) {
  // Шаг 1: Найти узел с заданным ключом
    Node *node = searchNode(key);
    if (node == nullptr)
        return;// Если узел не найден, ничего не делаем

    if (node->leftChild != nullptr && node->rightChild != nullptr) { // Шаг 2: Если у узла есть два дочерних узла, находим преемника (наименьший узел в правом поддереве)
        Node *successor = node->rightChild;
        while (successor->leftChild != nullptr)
            successor = successor->leftChild;

        // Копируем ключ и значение преемника в текущий узел
        node->key = std::move(successor->key);
        node->value = std::move(successor->value);

        // Переключаемся на преемника для дальнейшего удаления
        node = successor;
    }


// Шаг 3: Если у узла есть только правый дочерний узел, заменяем узел на правого дочернего узла
    if (node->leftChild == nullptr && node->rightChild != nullptr) {
        node->rightChild->nodeColor = 0;
        replaceNode(node, node->rightChild);
        delete node;
        return;
    }

    if (node->leftChild != nullptr && node->rightChild == nullptr) {
        node->leftChild->nodeColor = 0;
        replaceNode(node, node->leftChild);
        delete node;
        return;
    }

    if (node->nodeColor == 1) {
        replaceNode(node, nullptr);
        delete node;
        return;
    }

    Node *sibling;
    Node *parent = node->parentNode;

    replaceNode(node, nullptr);
    delete node;

    while (true) {
        if (parent == nullptr)
            return;

        if (parent->leftChild == nullptr || parent->rightChild == nullptr)
            return;

        sibling = parent->leftChild == nullptr ? parent->rightChild : parent->leftChild;

        if (sibling->nodeColor == 1) {
            if (parent->leftChild == sibling) {
                rightRotate(parent);
            } else {
                leftRotate(parent);
            }

            parent->nodeColor = 1;
            sibling->nodeColor = 0;

            continue;
        }

        if ((sibling->leftChild == nullptr || sibling->leftChild->nodeColor == 0) &&
            (sibling->rightChild == nullptr || sibling->rightChild->nodeColor == 0)) {

            sibling->nodeColor = 1;

            if (parent->nodeColor == 1) {
                parent->nodeColor = 0;
                return;
            }

            node = parent;
            parent = node->parentNode;

            continue;
        }

        if (parent->leftChild == sibling &&
            (sibling->leftChild != nullptr && sibling->leftChild->nodeColor == 1) &&
            (sibling->rightChild == nullptr || sibling->rightChild->nodeColor == 0)) {
            sibling->leftChild->nodeColor = 0;
            sibling->nodeColor = 1;
            rightRotate(sibling);

            sibling = parent->rightChild;

            continue;
        }

        if (parent->rightChild == sibling &&
            (sibling->rightChild != nullptr && sibling->rightChild->nodeColor == 1) &&
            (sibling->leftChild == nullptr || sibling->leftChild->nodeColor == 0)) {
            sibling->rightChild->nodeColor = 0;
            sibling->nodeColor = 1;
            leftRotate(sibling);

            sibling = parent->leftChild;

            continue;
        }

        sibling->nodeColor = parent->nodeColor;
        parent->nodeColor = 0;

        if (parent->leftChild == sibling) {
            if (sibling->rightChild != nullptr) {
                sibling->rightChild->nodeColor = 0;
            }
            rightRotate(parent);
        } else {
            if (sibling->leftChild != nullptr) {
                sibling->leftChild->nodeColor = 0;
            }
            leftRotate(parent);
        }

        return;
    }
}

// Calculate the size of the tree
template <typename Key, typename Value>
int RBTree<Key, Value>::calculateSize() {
    return calculateSubtreeSize(root);
}

// Calculate the size of a subtree
template <typename Key, typename Value>
int RBTree<Key, Value>::calculateSubtreeSize(Node *node) {
    if (node == nullptr)
        return 0;
    return 1 + calculateSubtreeSize(node->leftChild) + calculateSubtreeSize(node->rightChild);
}

// Inspect the tree
template <typename Key, typename Value>
void RBTree<Key, Value>::inspectTree(Inspector *ins, Node *node) {
    if (node == nullptr)
        return;

    ins->setKey(node->key);
    ins->setValue(node->value);

    if (node->leftChild != nullptr) {
        Inspector *child = ins->createChild();
        inspectTree(child, node->leftChild);
    }

    if (node->rightChild != nullptr) {
        Inspector *child = ins->createChild();
        inspectTree(child, node->rightChild);
    }
}

// Inspect the tree starting from the root
template <typename Key, typename Value>
void RBTree<Key, Value>::inspectTree(Inspector *ins) {
    inspectTree(ins, root);
}

// Iterator constructor
template <typename Key, typename Value>
RBTree<Key, Value>::Iterator::Iterator(Node *rootNode) : currentNode(rootNode) {
    if (!currentNode) return;
    while (currentNode->leftChild != nullptr)
        currentNode = currentNode->leftChild;
}

// Iterator dereference operator
template <typename Key, typename Value>
typename RBTree<Key, Value>::Node *RBTree<Key, Value>::Iterator::operator->() {
    return currentNode;
}

// Iterator dereference operator
template <typename Key, typename Value>
typename RBTree<Key, Value>::Node &RBTree<Key, Value>::Iterator::operator*() {
    return *currentNode;
}

// Iterator increment operator
template <typename Key, typename Value>
typename RBTree<Key, Value>::Iterator &RBTree<Key, Value>::Iterator::operator++() {
    if (currentNode == nullptr)
        return *this;

    if (currentNode->rightChild != nullptr) {
        currentNode = currentNode->rightChild;
        while (currentNode->leftChild != nullptr)
            currentNode = currentNode->leftChild;
    } else {
        Node *parent = currentNode->parentNode;
        while (parent != nullptr && currentNode == parent->rightChild) {
            currentNode = parent;
            parent = parent->parentNode;
        }
        currentNode = parent;
    }

    return *this;
}

// Iterator equality operator
template <typename Key, typename Value>
bool RBTree<Key, Value>::Iterator::operator==(const Iterator &other) {
    return currentNode == other.currentNode;
}

// Iterator inequality operator
template <typename Key, typename Value>
bool RBTree<Key, Value>::Iterator::operator!=(const Iterator &other) {
    return currentNode != other.currentNode;
}

// Return an iterator to the beginning of the tree
template <typename Key, typename Value>
typename RBTree<Key, Value>::Iterator RBTree<Key, Value>::begin() {
    return Iterator(root);
}

// Return an iterator to the end of the tree
template <typename Key, typename Value>
typename RBTree<Key, Value>::Iterator RBTree<Key, Value>::end() {
    return Iterator(nullptr);
}


//////////////
template <typename K, typename V> class Map: public RBTree<K, V> {
public:

  V& operator[](const K& key) {
    auto t = RBTree<K, V>::findNode(key);
    if(t != nullptr) {
      return t->val;
    };
    return RBTree<K, V>::insert(key, V())->val;
  };
};

template <typename K> class Set: public RBTree<K, char> {
public:
    void addNode(const K& val) {
        RBTree<K, char>::addNode(val, 'a');
    }
}; 