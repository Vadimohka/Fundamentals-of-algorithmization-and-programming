#include <QVector>
#include <climits>
#include <stdexcept>

template<typename T>
class SearchTree {
public:
    struct TreeNode {
        T data;
        TreeNode* right;
        TreeNode* left;
        long key;
        TreeNode(long key,const T& val) : key(key), data(val){
            right = nullptr;
            left = nullptr;
        }

        ~TreeNode() {
            if (left != nullptr) {
                delete left;
            }
            if (right != nullptr) {
                delete right;
            }
        }
    };  
protected:
    TreeNode* root;

public:
    SearchTree() { this->root = nullptr; }

  SearchTree(const SearchTree &another) { fronAnother(another); }

  SearchTree &operator=(const SearchTree &another) {
    delete root;
    this->root = nullptr;

    fronAnother(another);
    return *this;
  }

  SearchTree(SearchTree &&another) {
    this->root = another.root;
    another.root = nullptr;
  }

  ~SearchTree() {
    if (this->root)
      delete this->root;
  }

  void clear() {
    delete this->root;
    this->root = nullptr;
  }
    // balancee SeatchTree 

    void balance() {
    if (!root) {
        return;
    }

    QVector<TreeNode*> nodes;
    StoreBSTNodes(nodes, root);
    root = buildTreeUtil(nodes, 0, nodes.size() - 1);
}

void StoreBSTNodes(QVector<TreeNode*>& nodes, TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    StoreBSTNodes(nodes, root->left);
    nodes.push_back(root);
    StoreBSTNodes(nodes, root->right);
}

TreeNode* buildTreeUtil(QVector<TreeNode*>& nodes, int start, int end) {
    if (start > end) {
        return nullptr;
    }

    int mid = (start + end) / 2;
    TreeNode* root = nodes[mid];

    root->left = buildTreeUtil(nodes, start, mid - 1);
    root->right = buildTreeUtil(nodes, mid + 1, end);

    return root;
}

    // insert 
    void insert(long key, const T &data) {
        TreeNode **target = &this->root;
        while (*target != nullptr) {
          long targkey = (*target)->key;
          if (targkey == key) {
            (*target)->data = data;
            return;
          } else if (key < (*target)->key) {
            target = &(*target)->left;
          } else {
            target = &(*target)->right;
          }
        }

        *target = new TreeNode(key, data);
    }
    void removeByKey(long key) {
        TreeNode* s = this->root;
        remove(s, key);
    }


    void remove(TreeNode*& root, long key) {
    if (!root) {
        return;
    }

    if (key < root->key) {
        remove(root->left, key);
    } else if (key > root->key) {
        remove(root->right, key);
    } else {
        if (root->left == nullptr) {
            TreeNode* tmp = root->right;
            delete root;
            root = tmp;
        } else if (root->right == nullptr) {
            TreeNode* tmp = root->left;
            delete root;
            root = tmp;
        } else {
            TreeNode* successorParent = root;
            TreeNode* successor = root->right;
            while (successor->left != nullptr) {
                successorParent = successor;
                successor = successor->left;
            }
            root->data = successor->data;
            root->key = successor->key;
            remove(successorParent->right, successor->key);
        }
    }
}


   
    
    void preorder(TreeNode* node, QVector<T>& result) {
        if (node == nullptr)
            return;
        
        result.push_back(node->data); 
        preorder(node->left, result); 
        preorder(node->right, result);
    }

   
    void postorder(TreeNode* node, QVector<T>& result) {
        if (node == nullptr)
            return;
        
        postorder(node->left, result); 
        postorder(node->right, result); 
        result.push_back(node->data); 
    }

   
    QVector<T> getPreorder() {
        QVector<T> result;
        preorder(root, result);
        return result;
    }

    
    QVector<T> getPostorder() {
        QVector<T> result;
        postorder(root, result);
        return result;
    }

    T& get(long key) {
        TreeNode* current = this->root;
        while (current != nullptr) {
            if (current->key == key) {
                return current->data; 
            } else if (key < current->key) {
                current = current->left; 
            } else {
                current = current->right; 
            }
        }

        throw std::invalid_argument("Key not found"); 
    }

    bool findByKey(long key){
        TreeNode* s = this->root;
        while (s!= nullptr)
        {
            /* code */
            if(s->key == key)
                return true;
            
            if(key< s->key){
                s = s->left;
            }else{
                s = s->right;
            }
        }
        return false;
    }

};
