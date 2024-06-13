#ifndef MAP_H
#define MAP_H

#include <memory>
#include <utility>
#include <QString>

template<class Key, class Value>
class Map
{
private:
    struct Node{
        std::pair<Key, Value> kv;
        bool Red;

        std::shared_ptr<Node> left;
        std::shared_ptr<Node> right;
        std::weak_ptr<Node> parent;


        Node() = default;
        Node(Key k, Value val) : kv(k, val){}
    };

    std::shared_ptr<Node> _root;
    std::shared_ptr<Node> _nil;
    size_t _size = 0;

    void CreateNil(){
        _nil = std::make_shared<Node>();
        _nil->Red = false;
        _nil->left = nullptr;
        _nil->right = nullptr;
    }

    std::shared_ptr<Node> leftRotate(std::shared_ptr<Node> node){
        auto tempNode = node->right;
        node->right = tempNode->left;
        node->right->parent = node;
        tempNode->left = node;
        tempNode->parent = tempNode->left->parent;
        tempNode->left->parent = tempNode;
        bindParent(tempNode, node);
        return tempNode;
    }

    std::shared_ptr<Node> rightRotate(std::shared_ptr<Node> node){
        auto tempNode = node->left;
        node->left = tempNode->right;
        node->left->parent = node;
        tempNode->right = node;
        tempNode->parent = tempNode->right->parent;
        tempNode->right->parent = tempNode;
        bindParent(tempNode, node);
        return tempNode;
    }

    void bindParent(std::shared_ptr<Node> node, std::shared_ptr<Node> child){
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

    std::shared_ptr<Node> findNode(const std::shared_ptr<Node>& curNode, const Key& key) const {
        if (curNode == nullptr) {
            return nullptr;
        }
        if (curNode == _nil) {
            return _nil;
        }
        if (key < curNode->kv.first) {
            return findNode(curNode->left, key);
        } else if (key > curNode->kv.first) {
            return findNode(curNode->right, key);
        } else {
            return curNode;
        }
    }

    bool UncleRed(const std::shared_ptr<Node>& node) {
        auto father = node->parent.lock();
        auto grandfather = father->parent.lock();
        if (grandfather->left == father) {
            return grandfather->right->Red;
        } else {
            return grandfather->left->Red;
        }
    }
    uint8_t countChildrens(const std::shared_ptr<Node>& node) {
        if (node == _nil) {
            return 0;
        }
        return (node->left != _nil) + (node->right != _nil);
    }


    void balanceInsert(std::shared_ptr<Node> node) {
        if (node == _root) {
            node->Red = false;
            return;
        }
        if (!node->parent.lock()->Red) {
            return;
        }
        if (UncleRed(node)) {
            auto grandfather = node->parent.lock()->parent.lock();
            grandfather->Red = true;
            grandfather->left->Red = false;
            grandfather->right->Red = false;
            balanceInsert(grandfather);
        } else { // the uncle is black
            father_Grandfather_Rotate(node);
        }
    }

    void father_Grandfather_Rotate(std::shared_ptr<Node> node) {
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

        grandfather->Red = false;
        grandfather->left->Red = true;
        grandfather->right->Red = true;
        if (bIsLeftFromGrandfather) {
            grandfather->right->right->Red = false;
        } else {
            grandfather->left->left->Red = false;
        }
    }


    void startDelete(std::shared_ptr<Node> node) {
        switch (countChildrens(node)) {
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
        if (!node->Red) {
            fixBlackDeleted(parent, !bIsSonLeft);
        }
    }

    void oneChDel(std::shared_ptr<Node> node) { // then node is black with red child
        if (node->right != _nil) {
            std::swap(node->kv, node->right->kv);
            node->right = _nil;
        } else {
            std::swap(node->kv, node->left->kv);
            node->left = _nil;
        }
    }

    void twoChDel(std::shared_ptr<Node> node) {
        auto minNode = node->left;
        while (minNode->right != _nil) {
            minNode = minNode->right;
        }
        std::swap(node->kv, minNode->kv);
        startDelete(minNode); // zero or one children
    }

    void fixBlackDeleted(std::shared_ptr<Node> node, bool bWasSonRight) { // deleted son is black
        if (node->Red) {
            redFix(node, bWasSonRight);
        } else {
            blackFix(node, bWasSonRight);
        }
    }

    void redFix(std::shared_ptr<Node> node, bool bWasSonRight) {
        auto other = (bWasSonRight ? node->left : node->right);
        if (!other->left->Red && !other->right->Red) {
            node->Red = false;
            other->Red = true;
        } else { // other does have some red son
            if ((bWasSonRight ? other->left : other->right)->Red) { // side son is red
                redSideSonSubFix(node, bWasSonRight);
            } else { // inner son is red, but we transform it to the case when side son is red
                other = (bWasSonRight ? leftRotate(other) : rightRotate(other));
                other->Red = false;
                (bWasSonRight ? other->left : other->right)->Red = true;
                redSideSonSubFix(node, bWasSonRight);
            }
        }
    }

    void redSideSonSubFix(std::shared_ptr<Node> node, bool bWasSonRight) {
        node = (bWasSonRight ? rightRotate(node) : leftRotate(node));
        node->Red = true;
        node->right->Red = false;
        node->left->Red = false;
    }

    void blackFix(std::shared_ptr<Node> node, bool bWasSonRight) {
        auto other = (bWasSonRight ? node->left : node->right);
        auto inner = (bWasSonRight ? other->right : other->left);
        if (other->Red && !inner->left->Red && !inner->right->Red) {
            node = (bWasSonRight ? rightRotate(node) : leftRotate(node));
            node->Red = false;
            (bWasSonRight ? node->right->left->Red : node->left->right->Red) = true;
        } else if (other->Red) { // there is red grandson
            if (other->Red && !(bWasSonRight ? inner->left : inner->right)->Red) { // transform to black brother
                node = (bWasSonRight ? rightRotate(node) : leftRotate(node));
                node->Red = false;
                (bWasSonRight ? node->right : node->left)->Red = true;
                redFix((bWasSonRight ? node->right : node->left), bWasSonRight); // it can cost three rotations
            } else {
                other = (bWasSonRight ? leftRotate(other) : rightRotate(other));
                node = (bWasSonRight ? rightRotate(node) : leftRotate(node));
                auto other = (bWasSonRight ? node->left : node->right); // they've become invalid
                auto inner = (bWasSonRight ? other->right : other->left);
                inner->Red = false;
            }
        } else { // other is black
            if ((bWasSonRight ? other->left : other->right)->Red && !inner->Red) { // transform for next if
                other = (bWasSonRight ? rightRotate(other) : leftRotate(other));
                other->Red = true;
                (bWasSonRight ? other->right : other->left)->Red = false; // changed inner is black
            }
            else if (inner->Red) {
                other = (bWasSonRight ? leftRotate(other) : rightRotate(other));
                other->Red = false;
                node = (bWasSonRight ? rightRotate(node) : leftRotate(node));
            } else { // all nodes are black
                other->Red = true;
                if (node == _root) {
                    return;
                }
                fixBlackDeleted(node->parent.lock(), node->parent.lock()->left == node);
            }
        }
    }

public:
    Map() {
        CreateNil();
        _root = _nil;
    }

    void insert(const Key& key, const Value& value) {
        auto newNode = std::make_shared<Node>(key, value);
        newNode->left = _nil;
        newNode->right = _nil;
        newNode->parent = _nil;
        newNode->Red = true;

        if (_root == _nil) {
            _root = newNode;
            _root->Red = false;
        } else {
            auto cur = _root;
            std::shared_ptr<Node> parent = nullptr;

            while (cur != _nil) {
                parent = cur;
                if (newNode->kv.first < cur->kv.first) {
                    cur = cur->left;
                } else {
                    cur = cur->right;
                }
            }

            newNode->parent = parent;
            if (newNode->kv.first < parent->kv.first) {
                parent->left = newNode;
            } else {
                parent->right = newNode;
            }
            balanceInsert(newNode);
        }
        ++_size;
    }

    void insert_or_assign(const Key& key, const Value& value) {
        auto node = findNode(_root, key);
        if (node == _nil) {
            insert(key, value);
        } else {
            node->kv.second = value;
        }
    }

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


    const Value* at(const Key& key) const{
        auto node = findNode(_root, key);
        if (node == _nil) {
            return nullptr;
        }
        return &(node->kv.second);
    }

    Value* at(const Key& key){
        auto node = findNode(_root, key);
        if (node == _nil) {
            return nullptr;
        }
        return &(node->kv.second);
    }

    Value& operator[](const Key& key) {
        auto node = findNode(_root, key);
        if (node == _nil) {
            insert(key, Value());
            node = findNode(_root, key);
        }
        return node->kv.second;
    }


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

        std::pair<const Key&, Value&> operator*() const {
            return std::make_pair(std::cref(current->kv.first), std::ref(current->kv.second));
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

    QString inorderTraversal() {
        QString str;
        inorderTraversal(_root, str, 0);
        return str;
    }

    void inorderTraversal(std::shared_ptr<Node> node, QString& str, int lvl) {
        if (node) {
            inorderTraversal(node->left, str, lvl + 1);
            auto tab = QString(lvl, '\t');
            if (node == _nil) {
                str += "\n" + tab + "nil";
            } else {
                str += "\n" + tab + (node->Red ? " Red " : " Black ") +
                       QString::number(node->kv.first) + "(key) " + (node->kv.second) + "(value)";
            }
            inorderTraversal(node->right, str, lvl + 1);
        }
    }

};

#endif // MAP_H
