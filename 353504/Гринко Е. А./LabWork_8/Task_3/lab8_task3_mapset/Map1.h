#include <memory>

template <typename Key, typename Value>
class Map {
private:
    enum class Color { RED, BLACK };

    struct Node {
        Key key;
        Value value;
        Color color;
        std::shared_ptr<Node> left;
        std::shared_ptr<Node> right;
        std::shared_ptr<Node> parent;

        Node(const Key& k, const Value& v, Color c = Color::RED)
                : key(k), value(v), color(c), left(nullptr), right(nullptr), parent(nullptr) {}
    };

    std::shared_ptr<Node> root;

    void rotateLeft(std::shared_ptr<Node> x) {
        auto y = x->right;
        x->right = y->left;
        if (y->left != nullptr) {
            y->left->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == nullptr) {
            root = y;
        } else if (x == x->parent->left) {
            x->parent->left = y;
        } else {
            x->parent->right = y;
        }
        y->left = x;
        x->parent = y;
    }

    void rotateRight(std::shared_ptr<Node> y) {
        auto x = y->left;
        y->left = x->right;
        if (x->right != nullptr) {
            x->right->parent = y;
        }
        x->parent = y->parent;
        if (y->parent == nullptr) {
            root = x;
        } else if (y == y->parent->right) {
            y->parent->right = x;
        } else {
            y->parent->left = x;
        }
        x->right = y;
        y->parent = x;
    }

    void fixInsert(std::shared_ptr<Node> z) {
        while (z->parent != nullptr && z->parent->color == Color::RED) {
            if (z->parent == z->parent->parent->left) {
                auto y = z->parent->parent->right;
                if (y != nullptr && y->color == Color::RED) {
                    z->parent->color = Color::BLACK;
                    y->color = Color::BLACK;
                    z->parent->parent->color = Color::RED;
                    z = z->parent->parent;
                } else {
                    if (z == z->parent->right) {
                        z = z->parent;
                        rotateLeft(z);
                    }
                    z->parent->color = Color::BLACK;
                    z->parent->parent->color = Color::RED;
                    rotateRight(z->parent->parent);
                }
            } else {
                auto y = z->parent->parent->left;
                if (y != nullptr && y->color == Color::RED) {
                    z->parent->color = Color::BLACK;
                    y->color = Color::BLACK;
                    z->parent->parent->color = Color::RED;
                    z = z->parent->parent;
                } else {
                    if (z == z->parent->left) {
                        z = z->parent;
                        rotateRight(z);
                    }
                    z->parent->color = Color::BLACK;
                    z->parent->parent->color = Color::RED;
                    rotateLeft(z->parent->parent);
                }
            }
        }
        root->color = Color::BLACK;
    }

    void transplant(std::shared_ptr<Node> u, std::shared_ptr<Node> v) {
        if (u->parent == nullptr) {
            root = v;
        } else if (u == u->parent->left) {
            u->parent->left = v;
        } else {
            u->parent->right = v;
        }
        if (v != nullptr) {
            v->parent = u->parent;
        }
    }

    void fixDelete(std::shared_ptr<Node> x) {
        while (x != root && (x == nullptr || x->color == Color::BLACK)) {
            if (x == x->parent->left) {
                auto w = x->parent->right;
                if (w->color == Color::RED) {
                    w->color = Color::BLACK;
                    x->parent->color = Color::RED;
                    rotateLeft(x->parent);
                    w = x->parent->right;
                }
                if ((w->left == nullptr || w->left->color == Color::BLACK) &&
                    (w->right == nullptr || w->right->color == Color::BLACK)) {
                    w->color = Color::RED;
                    x = x->parent;
                } else {
                    if (w->right == nullptr || w->right->color == Color::BLACK) {
                        w->left->color = Color::BLACK;
                        w->color = Color::RED;
                        rotateRight(w);
                        w = x->parent->right;
                    }
                    w->color = x->parent->color;
                    x->parent->color = Color::BLACK;
                    w->right->color = Color::BLACK;
                    rotateLeft(x->parent);
                    x = root;
                }
            } else {
                auto w = x->parent->left;
                if (w->color == Color::RED) {
                    w->color = Color::BLACK;
                    x->parent->color = Color::RED;
                    rotateRight(x->parent);
                    w = x->parent->left;
                }
                if ((w->right == nullptr || w->right->color == Color::BLACK) &&
                    (w->left == nullptr || w->left->color == Color::BLACK)) {
                    w->color = Color::RED;
                    x = x->parent;
                } else {
                    if (w->left == nullptr || w->left->color == Color::BLACK) {
                        w->right->color = Color::BLACK;
                        w->color = Color::RED;
                        rotateLeft(w);
                        w = x->parent->left;
                    }
                    w->color = x->parent->color;
                    x->parent->color = Color::BLACK;
                    w->left->color = Color::BLACK;
                    rotateRight(x->parent);
                    x = root;
                }
            }
        }
        if (x != nullptr) {
            x->color = Color::BLACK;
        }
    }


public:
    Map() : root(nullptr) {}

    void insert(const Key& key, const Value& value) {
        auto z = std::make_shared<Node>(key, value);
        std::shared_ptr<Node> y = nullptr;
        auto x = root;
        while (x != nullptr) {
            y = x;
            if (z->key < x->key) {
                x = x->left;
            } else {
                x = x->right;
            }
        }
        z->parent = y;
        if (y == nullptr) {
            root = z;
        } else if (z->key < y->key) {
            y->left = z;
        } else {
            y->right = z;
        }
        z->left = nullptr;
        z->right = nullptr;
        z->color = Color::RED;
        fixInsert(z);
    }

    void erase(const Key& key) {
        auto z = root;
        while (z != nullptr) {
            if (key == z->key) {
                break;
            } else if (key < z->key) {
                z = z->left;
            } else {
                z = z->right;
            }
        }
        if (z == nullptr) {
            return;
        }

        auto y = z;
        auto yOriginalColor = y->color;
        std::shared_ptr<Node> x;
        if (z->left == nullptr) {
            x = z->right;
            transplant(z, z->right);
        } else if (z->right == nullptr) {
            x = z->left;
            transplant(z, z->left);
        } else {
            y = z->right;
            while (y->left != nullptr) {
                y = y->left;
            }
            yOriginalColor = y->color;
            x = y->right;
            if (y->parent == z) {
                x->parent = y;
            } else {
                transplant(y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }
            transplant(z, y);
            y->left = z->left;
            y->left->parent = y;
            y->color = z->color;
        }
        if (yOriginalColor == Color::BLACK) {
            fixDelete(x);
        }
    }

    Value* get(const Key& key) {
        auto current = root;
        while (current != nullptr) {
            if (key == current->key) {
                return &current->value;
            } else if (key < current->key) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        return nullptr;
    }
};
