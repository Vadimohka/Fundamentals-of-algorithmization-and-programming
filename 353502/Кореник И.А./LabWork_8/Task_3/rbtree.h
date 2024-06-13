#include <stdexcept>
#include <utility>



template <typename K, typename V> class RBTree {
public:
    struct Node {
        friend class RBTree;

        K key;
        V val;

    public:
        Node *left;
        Node *right;
        Node *parent;
        bool color;

        Node(const K &key, const V &val)
            : key(key), val(val), left(nullptr), right(nullptr), parent(nullptr),
            color(0) {}
    };

public:
    Node *findNode(const K &key) {
        Node *cur = root;
        while (cur != nullptr) {
            if (key == cur->key)
                return cur;

            if (key < cur->key)
                cur = cur->left;
            else
                cur = cur->right;
        }

        return nullptr;
    }

    void replaceWith(Node *from, Node *to) {
        Node *parent = from->parent;

        if (to) {
            to->parent = parent;
        }

        if (parent == nullptr) {
            root = to;
        } else {
            if (parent->left == from) {
                parent->left = to;
            } else {
                parent->right = to;
            }
        }
    }

    void rotateLeft(Node *x) {
        //    x           y    )
        //   / \         / \   )
        //  a   y   =>  x   c  )
        //     / \     / \     )
        //    b   c   a   b    )

        // Take node that will become new parent
        Node *y = x->right;

        // Move child(b) that will be moved during rotation
        Node *b = y->left;
        x->right = b;
        if (b != nullptr)
            b->parent = x;

        // Make y point to the super parent
        replaceWith(x, y);

        // Put x as a child of y
        y->left = x;
        x->parent = y;
    }

    void rotateRight(Node *x) {
        //     x          y      )
        //    / \        / \     )
        //   y   c  =>  a   x    )
        //  / \            / \   )
        // a   b          b   c  )

        // Take node that will become new parent
        Node *y = x->left;

        // Move child(b) that will be moved during rotation
        Node *b = y->right;
        x->left = b;
        if (b != nullptr)
            b->parent = x;

        // Make y point to the super parent
        replaceWith(x, y);

        // Put x as a child of y
        y->right = x;
        x->parent = y;
    }

    long maxDepth(Node *node) {
        if (node == nullptr)
            return 0;
        int lnodes = maxDepth(node->left);
        int rnodes = maxDepth(node->right);
        return lnodes > rnodes ? lnodes + 1 : rnodes + 1;
    }

    int validateTree(Node *node) {
        if (node == nullptr)
            return 0;

        if (node->color == 1) {
            if (node->left && node->left->color == 1) {
                throw std::logic_error("Invalid tree left color");
            }

            if (node->right && node->right->color == 1) {
                throw std::logic_error("Invalid tree right color");
            }
        }

        if (node->left == nullptr && node->right != nullptr) {
            if (node->right->color != 1) {
                throw std::logic_error("Invalid tree single left color");
            }
        }

        if (node->right == nullptr && node->left != nullptr) {
            if (node->left->color != 1) {
                throw std::logic_error("Invalid tree single right color");
            }
        }

        int blackLenLeft = validateTree(node->left);
        int blackLenRight = validateTree(node->right);

        if (blackLenLeft != blackLenRight) {
            throw std::logic_error("Invalid tree black length");
        }

        return blackLenLeft + (node->color == 0 ? 1 : 0);
    }

    void clear(Node *node) {
        if (node == nullptr)
            return;

        clear(node->left);
        clear(node->right);
        delete node;
    }

public:
    RBTree() : root(nullptr) {}
    ~RBTree() { clear(); }

    void clear() {
        clear(root);
        root = nullptr;
    }

    bool contains(const K &key) { return findNode(key) != nullptr; }

    V &get(const K &key) {
        Node *node = findNode(key);
        return node->val;
    }

    Node *insert(const K &key, const V &val) {
        // If tree is empty insert node as new root
        if (root == nullptr) {
            root = new Node(key, val);
            root->color = 0;
            return root;
        }

        // Insert node as we would in BST
        Node *parent = root;
        Node *node = nullptr;
        while (true) {
            // If there is already node, update it
            if (key == parent->key) {
                parent->val = val;
                return parent;
            }

            if (key < parent->key) {
                if (parent->left == nullptr) {
                    node = new Node(key, val);
                    parent->left = node;
                    break;
                } else {
                    parent = parent->left;
                }
            } else {
                if (parent->right == nullptr) {
                    node = new Node(key, val);
                    parent->right = node;
                    break;
                } else {
                    parent = parent->right;
                }
            }
        }
        Node *res = node;

        // Newly inserted node is RED
        node->color = true;
        node->parent = parent;

        // Rebalance RB Tree by fixing possible Red-Red child
        // On start of each loop node is always red
        // Ref: https://en.wikipedia.org/wiki/Red%E2%80%93black_tree#Insertion
        while (node->parent != nullptr) {
            parent = node->parent;

            // Parent is black, so current node doesn't cause
            // longer paths and conditions are satisfied
            if (parent->color == 0)
                return res;

            Node *grand = parent->parent;
            // Parent is the RED root and  we can
            // safely mark it as black as no longer
            // paths will appear
            if (grand == nullptr) {
                parent->color = 0;
                return res;
            }

            // Determine N's uncle, also known as P brother
            Node *uncle = grand->left == parent ? grand->right : grand->left;
            // If there is no uncle or uncle is black
            if (uncle == nullptr || uncle->color == 0) {
                // Detect cases where N is inner child of P
                if (grand->left == parent && parent->right == node) {
                    rotateLeft(parent);
                    std::swap(node, parent);
                }

                if (grand->right == parent && parent->left == node) {
                    rotateRight(parent);
                    std::swap(node, parent);
                }

                // Move red-red case one up
                if (grand->left == parent) {
                    rotateRight(grand);
                } else {
                    rotateLeft(grand);
                }

                // We can now recolor without braking rules
                parent->color = 0; // grandparent after rotation
                grand->color = 1;  // uncle after rotation
                return res;
            }

            // Recoulor current subtree and move up
            parent->color = 0;
            uncle->color = 0;
            grand->color = 1;

            // May have introduced new red-red situation
            // Continue loop to fix it
            node = grand;
        }

        return res;
    }

    void erase(const K &key) {
        Node *node = findNode(key);
        if (node == nullptr)
            return;

        if (node->left != nullptr && node->right != nullptr) {
            Node *toRepl = node->right;
            while (toRepl->left != nullptr)
                toRepl = toRepl->left;

            node->key = std::move(toRepl->key);
            node->val = std::move(toRepl->val);

            node = toRepl;
        }

        // One child
        if (node->left == nullptr && node->right != nullptr) {
            node->right->color = 0;
            replaceWith(node, node->right);
            delete node;
            return;
        }

        if (node->right == nullptr && node->left != nullptr) {
            node->left->color = 0;
            replaceWith(node, node->left);
            delete node;
            return;
        }

        // No children there
        if (node == root) {
            delete root;
            root = nullptr;
            return;
        }

        // We can simply remove red nodes
        if (node->color == 1) {
            replaceWith(node, nullptr);
            delete node;
            return;
        }

        Node *nodeToClean = node;

        // At this point we should now have a black node
        // With no children, just to be sure let's check
        if (node->left != nullptr || node->right != nullptr) {
            throw new std::logic_error("Invalid attempt to remove");
        }

        // To the start of pain ((
        // If such node is removed, we have to apply some fixes
        // to keep the tree in valid state
        // Ref:
        // https://ru.wikipedia.org/wiki/%D0%9A%D1%80%D0%B0%D1%81%D0%BD%D0%BE-%D1%87%D1%91%D1%80%D0%BD%D0%BE%D0%B5_%D0%B4%D0%B5%D1%80%D0%B5%D0%B2%D0%BE#%D0%A3%D0%B4%D0%B0%D0%BB%D0%B5%D0%BD%D0%B8%D0%B5
        while (node->parent != nullptr) {
            // Case 2:
            {
                Node *parent = node->parent;
                bool atLeft = parent->left == node;
                Node *sibling = atLeft ? parent->right : parent->left;
                if (sibling->color == 1) {
                    parent->color = 1;
                    sibling->color = 0;

                    if (atLeft)
                        rotateLeft(parent);
                    else
                        rotateRight(parent);
                }
            }

            // Case 3 and 4:
            {
                Node *parent = node->parent;
                bool atLeft = parent->left == node;
                Node *sibling = atLeft ? parent->right : parent->left;

                bool blackSiblings =
                    (sibling->color == 0) &&
                    (sibling->left == nullptr || sibling->left->color == 0) &&
                    (sibling->right == nullptr || sibling->right->color == 0);

                if ((parent->color == 0) && blackSiblings) {
                    sibling->color = 1;
                    node = node->parent;
                    continue;
                }

                if ((parent->color == 1) && blackSiblings) {
                    sibling->color = 1;
                    parent->color = 0;
                    break;
                }
            }

            // Case 5:
            {
                Node *parent = node->parent;
                bool atLeft = parent->left == node;
                Node *sibling = atLeft ? parent->right : parent->left;

                if (sibling->color == 0) {
                    if (atLeft &&
                        (sibling->right == nullptr || sibling->right->color == 0) &&
                        (sibling->left && sibling->left->color == 1)) {
                        sibling->color = 1;
                        sibling->left->color = 0;
                        rotateRight(sibling);
                    } else if (!atLeft &&
                               (sibling->left == nullptr || sibling->left->color == 0) &&
                               (sibling->right && sibling->right->color == 1)) {
                        sibling->color = 1;
                        sibling->right->color = 0;
                        rotateLeft(sibling);
                    }
                }
            }

            // Case 6:
            {
                Node *parent = node->parent;
                bool atLeft = parent->left == node;
                Node *sibling = atLeft ? parent->right : parent->left;

                parent = node->parent;
                atLeft = parent->left == node;
                sibling = atLeft ? parent->right : parent->left;
                sibling->color = parent->color;
                parent->color = 0;

                if (atLeft) {
                    if (sibling->right)
                        sibling->right->color = 0;
                    rotateLeft(parent);
                } else {
                    if (sibling->left)
                        sibling->left->color = 0;
                    rotateRight(parent);
                }
            }

            break;
        }

        // Actually remove node from tree
        {
            Node *parent = nodeToClean->parent;
            if (parent) {
                if (parent->left == nodeToClean) {
                    parent->left = nullptr;
                } else {
                    parent->right = nullptr;
                }
            }
        }
        delete nodeToClean;
    }

    long maxDepth() { return maxDepth(root); }

    void validateTree() { validateTree(root); }

public:
    class Iterator {
    public:
        friend class RBTree<K, V>;
        Iterator(Node *root) : cur(root) {
            if(!cur) return;
            while (cur->left != nullptr)
                cur = cur->left;
        }

    public:
        Node *operator->() { return cur; }

        Node &operator*() { return *cur; }

        Iterator &operator++() {
            if (!cur)
                return *this;

            if (cur->right != nullptr) {
                cur = cur->right;

                while (cur->left != nullptr)
                    cur = cur->left;
            } else {
                while (cur->parent != nullptr && cur->parent->right == cur) {
                    cur = cur->parent;
                }
                cur = cur->parent;
            }


            return *this;
        }

        bool operator==(const Iterator &other) {
            // if (cur == nullptr && other.cur == nullptr)
            //   return true;
            return cur == other.cur;
        }

        bool operator!=(const Iterator &other) { return !(*this == other); }

    protected:
        Node *cur;
    };

    Iterator begin() { return Iterator(root); }
    Iterator end() { return Iterator(nullptr); }

public:
    Node *root;

public:
    class Inspector {
    public:
        virtual ~Inspector() {}
        virtual void setVal(const V& val) = 0;
        virtual void setKey(const K& key) = 0;
        virtual void setMode(int mode) = 0;
        virtual Inspector * createChild() = 0;
    };

protected:

    void inspect(Inspector *ins, Node *node) {
        if (node == nullptr) {
            ins->setMode(-1);
        } else {
            ins->setMode(node->color);
            ins->setKey(node->key);
            ins->setVal(node->val);
            inspect(ins->createChild(), node->left);
            inspect(ins->createChild(), node->right);
        }
    }

public:
    void inspect(Inspector *ins) {
        inspect(ins, root);
    }
};


template <typename K, typename V> class Map: public RBTree<K, V> {
    using RBTree = RBTree<K, V>;

public:
    V& operator[](const K& key) {
        auto t = RBTree::findNode(key);
        if(t != nullptr) {
            return t->val;
        };
        return RBTree::insert(key, V())->val;
    }
};
