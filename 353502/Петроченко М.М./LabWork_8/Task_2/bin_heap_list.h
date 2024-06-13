#include <cstddef>
#include <memory>
#include <utility>

template <typename T>
class ListBinHeap {
   public:
    ListBinHeap();
    ~ListBinHeap();

   private:
    struct Node {
        std::shared_ptr<Node> left = nullptr;
        std::shared_ptr<Node> right = nullptr;
        std::weak_ptr<Node> parent = nullptr;
        std::pair<size_t, T> kv;
    };

    void heapify(std::shared_ptr<Node> root) {
        std::shared_ptr<Node> largest = root;
        if (root()->left()->kv.first > root()->kv.first) {
            largest = root()->left;
        }
        if (root()->right()->kv.first > root()->kv.first) {
            largest = root()->right;
        }
        if (largest != root) {
            std::swap(largest()->kv, root()->kv);
            this->heapify(largest);
        }
    }

    void heapify_up(std::shared_ptr<Node> node) {
        if (node->parent == nullptr) {
            return;
        }
        if (node->parent.lock()->kv.first >= node()->kv.first) {
            return;
        }
        std::swap(node->parent.lock()->kv, node->kv);
        heapify_up(node->parent.lock());
    }

    void insert(size_t key, const T& value) {
        if (this->last_layer == 0) {
            auto new_root = std::make_shared<Node>();
            new_root->kv = { key, value };
            this->last_layer += 1;
            this->free_place = 0;
            return;
        }
        auto current_node = this->root;
        for (int i = this->last_layer - 1; i >= 0; --i) {
            if ((free_place & (1 << i)) != 0) {
                if (current_node->right == nullptr) {
                    current_node->right = std::make_shared<Node>();
                    current_node->right->parent = current_node;
                }
                current_node = current_node->right;
            } else {
                if (current_node->left == nullptr) {
                    current_node->left = std::make_shared<Node>();
                    current_node->left->parent = current_node;
                }
                current_node = current_node->left;
            }
        }
        current_node->kv = { key, value };
        ++this->free_place;
        if (this->free_place == (1 << this->last_layer)) {
            this->last_layer++;
            this->free_place = 0;
        }
        this->heapify_up(current_node);
    }

    std::shared_ptr<Node> root;
    size_t last_layer = 0;
    size_t free_place = 0;
};
