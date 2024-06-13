#include <memory>
#include <QTreeWidget>

class TreeHeap {
private:
    struct TreeNode {
        int value;
        std::weak_ptr<TreeNode> parentNode;
        std::shared_ptr<TreeNode> leftChild;
        std::shared_ptr<TreeNode> rightChild;
    };

    void bubbleUp(std::shared_ptr<TreeNode> node);
    void bubbleDown(std::shared_ptr<TreeNode> node);

public:
    TreeHeap();
    ~TreeHeap();

    void insert(long value);
    long remove();
    bool isEmpty() const;
    void reset();
    int& top() const;

    QTreeWidgetItem* createGuiNode(std::shared_ptr<TreeNode> node);
    void display(QTreeWidget* widget);

private:
    std::shared_ptr<TreeNode> rootNode;
    int currentLevel;
    int indexAtLevel;
};
