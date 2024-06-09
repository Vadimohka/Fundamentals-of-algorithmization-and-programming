#ifndef SET_H
#define SET_H

#include <memory>
#include <stdexcept>

template <class Key>
class Set {
private:

    struct Node {
        const Key data;
        bool bIsRed;
        std::shared_ptr<Node> left;
        std::shared_ptr<Node> right;
        std::weak_ptr<Node> parent;

        Node() = default;
        Node(Key value) : data(value) {}
    };

    std::shared_ptr<Node> _root;
    std::shared_ptr<Node> _nil;
    size_t _size = 0;

    void initializeNIL() {
        _nil = std::make_shared<Node>();
        _nil->bIsRed = false;
        _nil->left = nullptr;
        _nil->right = nullptr;
    }

    //------------------------------------------------------------------------------------------------//

    std::shared_ptr<Node> leftRotate(std::shared_ptr<Node> node) {
        auto retNode = node->right;
        node->right = retNode->left;
        node->right->parent = node;
        retNode->left = node;
        retNode->parent = retNode->left->parent;
        retNode->left->parent = retNode;
        bindToParent(retNode, node);
        return retNode;
    }

    std::shared_ptr<Node> rightRotate(std::shared_ptr<Node> node) {
        auto retNode = node->left;
        node->left = retNode->right;
        node->left->parent = node;
        retNode->right = node;
        retNode->parent = retNode->right->parent;
        retNode->right->parent = retNode;
        bindToParent(retNode, node);
        return retNode;
    }

    // must be called after rotation
    void bindToParent(std::shared_ptr<Node> node, std::shared_ptr<Node> child) {
        if (child != _root) {
            if (node->parent.lock()->left == child) {
                node->parent.lock()->left = node;
            } else {
                node->parent.lock()->right = node;
            }
        } else {
            _root = node;
            node->parent.lock() = nullptr;
        }
    }

    //------------------------------------------------------------------------------------------------//

    std::shared_ptr<Node> findNode(const std::shared_ptr<Node>& curNode, const Key& key) const {
        if (curNode == nullptr) {
            return nullptr;
        }
        if (curNode == _nil) {
            return _nil;
        }
        if (key < curNode->data) {
            return findNode(curNode->left, key);
        } else if (key > curNode->data) {
            return findNode(curNode->right, key);
        } else {
            return curNode;
        }
    }

    bool isUncleRed(const std::shared_ptr<Node>& node) {
        auto father = node->parent.lock();
        auto grandfather = father->parent.lock();
        if (grandfather->left == father) {
            return grandfather->right->bIsRed;
        } else {
            return grandfather->left->bIsRed;
        }
    }

    uint8_t countChildren(const std::shared_ptr<Node>& node) {
        if (node == _nil) {
            return 0;
        }
        return (node->left != _nil) + (node->right != _nil);
    }

    //------------------------------------------------------------------------------------------------//

    void balanceInsert(std::shared_ptr<Node> node) {
        if (node == _root) {
            node->bIsRed = false;
            return;
        }
        if (!node->parent.lock()->bIsRed) {
            return;
        }
        if (isUncleRed(node)) {
            auto grandfather = node->parent.lock()->parent.lock();
            grandfather->bIsRed = true;
            grandfather->left->bIsRed = false;
            grandfather->right->bIsRed = false;
            balanceInsert(grandfather);
        } else { // the uncle is black
            fatherGrandfatherRotate(node);
        }
    }

    // make node-father-grandfather line straight, then rotate and fix colors
    void fatherGrandfatherRotate(std::shared_ptr<Node> node) {
        auto father = node->parent.lock();
        auto grandfather = father->parent.lock();
        bool bIsLeftFromFather = father->left == node;
        bool bIsLeftFromGrandfather = grandfather->left == father;
        if (bIsLeftFromFather != bIsLeftFromGrandfather) {
            if (bIsLeftFromFather) {
                father = rightRotate(father); // rightRotate(father);
            } else {
                father = leftRotate(father); // leftRotate(father);
            }
            //node = father;
            //father = node;
            grandfather = father->parent.lock();
        } // now they're on the straight line

        if (bIsLeftFromGrandfather) {
            grandfather =
                rightRotate(grandfather); //
        } else {
            grandfather =
                leftRotate(grandfather); //
        } // now they're on the right positions

        grandfather->bIsRed = false;
        grandfather->left->bIsRed = true;
        grandfather->right->bIsRed = true;
        if (bIsLeftFromGrandfather) {
            grandfather->right->right->bIsRed = false;
        } else {
            grandfather->left->left->bIsRed = false;
        }
    }

    //------------------------------------------------------------------------------------------------//

    void startDelete(std::shared_ptr<Node> node) {
        switch (countChildren(node)) {
        case 0 :
            zeroChDel(node);
            break;
        case 1:
            oneChDel(node);
            break;
        case 2:
            twoChDel(node);
            break;
        }
    }

    void zeroChDel(std::shared_ptr<Node> node) {
        if (node == _root) {
            return clear();
        }
        auto parent = node->parent.lock();
        bool bIsSonLeft = parent->left == node;
        (bIsSonLeft ? parent->left : parent->right) = _nil;
        if (!node->bIsRed) {
            fixBlackDeleted(parent, !bIsSonLeft);
        }
    }

    void oneChDel(std::shared_ptr<Node> node) { // then node is black with red child
        if (node->right != _nil) {
            std::swap(node->data, node->right->data);
            node->right = _nil;
        } else {
            std::swap(node->data, node->left->data);
            node->left = _nil;
        }
    }

    void twoChDel(std::shared_ptr<Node> node) {
        auto minNode = node->left;
        while (minNode->right != _nil) {
            minNode = minNode->right;
        }
        std::swap(node->data, minNode->data);
        startDelete(minNode); // zero or two children
    }

    void fixBlackDeleted(std::shared_ptr<Node> node, bool bWasSonRight) { // deleted son is black
        if (node->bIsRed) {
            redFix(node, bWasSonRight);
        } else {
            blackFix(node, bWasSonRight);
        }
    }

    void redFix(std::shared_ptr<Node> node, bool bWasSonRight) {
        auto other = (bWasSonRight ? node->left : node->right);
        if (!other->left->bIsRed && !other->right->bIsRed) {
            node->bIsRed = false;
            other->bIsRed = true;
        } else { // other does have some red son
            if ((bWasSonRight ? other->left : other->right)->bIsRed) { // side son is red
                redSideSonSubFix(node, bWasSonRight);
            } else { // inner son is red, but we transform it to the case when side son is red
                other = (bWasSonRight ? leftRotate(other) : rightRotate(other));
                other->bIsRed = false;
                (bWasSonRight ? other->left : other->right)->bIsRed = true;
                redSideSonSubFix(node, bWasSonRight);
            }
        }
    }

    void redSideSonSubFix(std::shared_ptr<Node> node, bool bWasSonRight) {
        node = (bWasSonRight ? rightRotate(node) : leftRotate(node));
        node->bIsRed = true;
        node->right->bIsRed = false;
        node->left->bIsRed = false;
    }

    void blackFix(std::shared_ptr<Node> node, bool bWasSonRight) {
        auto other = (bWasSonRight ? node->left : node->right);
        auto inner = (bWasSonRight ? other->right : other->left);
        if (other->bIsRed && !inner->left->bIsRed && !inner->right->bIsRed) {
            node = (bWasSonRight ? rightRotate(node) : leftRotate(node));
            node->bIsRed = false;
            (bWasSonRight ? node->right->left->bIsRed : node->left->right->bIsRed) = true;
        } else if (other->bIsRed) { // there is red grandson
            if (other->bIsRed && !(bWasSonRight ? inner->left : inner->right)->bIsRed) { // transform to black brother
                node = (bWasSonRight ? rightRotate(node) : leftRotate(node));
                node->bIsRed = false;
                (bWasSonRight ? node->right : node->left)->bIsRed = true;
                redFix((bWasSonRight ? node->right : node->left), bWasSonRight); // it can cost three rotations
            } else {
                other = (bWasSonRight ? leftRotate(other) : rightRotate(other));
                node = (bWasSonRight ? rightRotate(node) : leftRotate(node));
                auto other = (bWasSonRight ? node->left : node->right); // they've become invalid
                auto inner = (bWasSonRight ? other->right : other->left);
                inner->bIsRed = false;
            }
        } else { // other is black
            if ((bWasSonRight ? other->left : other->right)->bIsRed && !inner->bIsRed) { // transform for next if
                other = (bWasSonRight ? rightRotate(other) : leftRotate(other));
                other->bIsRed = true;
                (bWasSonRight ? other->right : other->left)->bIsRed = false; // changed inner is black
            }
            else if (inner->bIsRed) {
                other = (bWasSonRight ? leftRotate(other) : rightRotate(other));
                other->bIsRed = false;
                node = (bWasSonRight ? rightRotate(node) : leftRotate(node));
            } else { // all nodes are black
                other->bIsRed = true;
                if (node == _root) {
                    return;
                }
                fixBlackDeleted(node->parent.lock(), node->parent.lock()->left == node);
            }
        }
    }

    //------------------------------------------------------------------------------------------------//

public:

    //------------------------------------------------------------------------------------------------//

    Set() {
        initializeNIL();
        _root = _nil;
    }
    //------------------------------------------------------------------------------------------------//

    void insert(const Key& key) {
        auto newNode = std::make_shared<Node>(key);
        newNode->left = _nil;
        newNode->right = _nil;
        newNode->parent = _nil;
        newNode->bIsRed = true;

        if (_root == _nil) {
            _root = newNode;
            _root->bIsRed = false;
        } else {
            auto cur = _root;
            std::shared_ptr<Node> parent = nullptr;

            while (cur != _nil) {
                parent = cur;
                if (newNode->data.first < cur->data.first) {
                    cur = cur->left;
                } else {
                    cur = cur->right;
                }
            }

            newNode->parent = parent;
            if (newNode->data.first < parent->data.first) {
                parent->left = newNode;
            } else {
                parent->right = newNode;
            }
            balanceInsert(newNode);
        }
        ++_size;
    }

    void insert_or_assign(const Key& key) {
        auto node = findNode(_root, key);
        if (node == _nil) {
            insert(key);
        } else {
            node->data = key;
        }
    }

    //------------------------------------------------------------------------------------------------//

    void erase(const Key& key) {
        auto node = findNode(_root, key);
        if (node == _nil) {
            return;
        }
        startDelete(node);
        --_size;
    }

    void clear() {
        _root = nullptr;
        _root = _nil;
        _size = 0;
    }

    //------------------------------------------------------------------------------------------------//

    // returns pntr
    Key* get(const Key& key) {
        auto node = findNode(_root, key);
        if (node == _nil) {
            return nullptr;
        }
        return &(node->data);
    }

    Key& operator[](const Key& key) {
        auto node = findNode(_root, key);
        if (node == _nil) {
            insert(key);
            node = findNode(_root, key);
        }
        return node->data.second;
    }

    const Key& operator[](const Key& key) const {
        auto node = findNode(_root, key);
        if (node == _nil) {
            throw std::out_of_range("no such key");
            insert(key);
            node = findNode(_root, key);
        }
        return node->data.second;
    }

    //------------------------------------------------------------------------------------------------//

    class MapIterator {
    private:
        std::shared_ptr<Node> current;
        std::shared_ptr<Node> root;

    public:
        MapIterator(std::shared_ptr<Node> current, std::shared_ptr<Node> root)
            : current(current), root(root) {}

        MapIterator& operator++() {
            if (current == nullptr || current == root) {
                return *this;
            }

            if (current->right != nullptr) {
                current = current->right;
                while (current->left != nullptr) {
                    current = current->left;
                }
            } else {
                auto parent = current->parent.lock();
                while (parent != nullptr && current == parent->right) {
                    current = parent;
                    parent = parent->parent.lock();
                }
                current = parent;
            }

            return *this;
        }

        const Key& operator*() const {
            return std::make_pair(std::cref(current->data.first), std::ref(current->data.second));
        }

        bool operator==(const MapIterator& other) const {
            return current == other.current;
        }

        bool operator!=(const MapIterator& other) const {
            return !(*this == other);
        }
    };

    MapIterator begin() const {
        if (_root == nullptr) {
            return MapIterator(nullptr, nullptr);
        }
        auto current = _root;
        while (current->left != nullptr) {
            current = current->left;
        }
        return MapIterator(current, _root);
    }

    MapIterator end() const {
        return MapIterator(nullptr, _root);
    }
};

#endif // SET_H


