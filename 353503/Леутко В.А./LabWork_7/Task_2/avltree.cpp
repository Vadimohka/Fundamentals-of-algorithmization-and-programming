#include "avltree.h"

int AVLTree::getHeight(shared_ptr<Node> node) {
    if (!node)
        return 0;
    return node->height;
}

int AVLTree::max(int a, int b) {
    return (a > b) ? a : b;
}

shared_ptr<Node> AVLTree::rightRotate(shared_ptr<Node> node) {
    shared_ptr<Node> x = node->left;
    shared_ptr<Node> T2 = x->right;

    // Выполняем поворот
    x->right = node;
    node->left = T2;

    // Обновляем высоту
    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    // Возвращаем новый корень
    return x;
}

shared_ptr<Node> AVLTree::leftRotate(shared_ptr<Node> node) {
    shared_ptr<Node> y = node->right;
    shared_ptr<Node> T2 = y->left;

    // Выполняем поворот
    y->left = node;
    node->right = T2;

    // Обновляем высоту
    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    // Возвращаем новый корень
    return y;
}

int AVLTree::getBalance(shared_ptr<Node> node) {
    if (!node)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}

shared_ptr<Node> AVLTree::insert(shared_ptr<Node> node, int key, string value) {
    // 1: Выполняем обычный поворот
    if (!node)
        return(make_shared<Node>(key, value));

    if (key < node->key) {
        node->left = insert(node->left, key, value);
    }
    else if (key > node->key) {
        node->right = insert(node->right, key, value);
    }
    // Одинаковые ключи не допускаются
    else {
        return node;
    }

    // 2: Обновляем высоту этого родительского узла
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    // 3: Получаем коэффициент баланса этого
    //    родительского узла, чтобы проверить,
    //    является ли этот узел сбалансированным
    int balance = getBalance(node);

    // Если этот узел не сбалансирован,
    // то есть 4 случая:

    // Left Left Case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // возвращаем (неизменный) указатель узла
    return node;
}

shared_ptr<Node> AVLTree::minValueNode(shared_ptr<Node> node) {
    shared_ptr<Node> current = node;

    // Получаем самый левый лист
    while (current->left)
        current = current->left;

    return current;
}

shared_ptr<Node> AVLTree::deleteNode(shared_ptr<Node> root, int key) {
    // 1: Выполняем стандартное удаление
    if (!root)
        return root;

    // Если ключ удаляемого элемента меньше
    // ключа корня, тогда он лежит
    // в левом поддереве
    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    }

    // Если ключ удаляемого элемента больше
    // ключа корня, тогда он лежит
    // в правом поддереве
    else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    }

    // Если ключ совпадает с ключем корня
    // то это удаляемый элемент
    else {
        // Узел имеет только одного потомка
        // Или не имеет ни одного
        if ((!root->left) || (!root->right)) {
            shared_ptr<Node> temp = root->left ?
                                        root->left :
                                        root->right;

            // Нет потомка
            if (!temp) {
                temp = root;
                root = shared_ptr<Node>();
            }
            // Один потомок
            else {
                *root = *temp; // Копируем содержимое
                    // непустого потомка
            }
        }
        else {
            // Узел с двумя потомками: Получим преемника
            // (минимальный в правом поддереве)
            shared_ptr<Node> temp = minValueNode(root->right);

            // Копируем данные прееемника в этот узел
            root->key = temp->key;

            // Удаляем преемника
            root->right = deleteNode(root->right, temp->key);
        }
    }

    // Если дерево имеет только один узел
    if (!root)
        return root;

    // 2: Обновляем высоту текущего узла
    root->height = 1 + max(getHeight(root->left),
                           getHeight(root->right));

    // 3: Получаем баланс-фактор этого узла
    // (чтобы проверить, стал ли этот узел несбалансированным)
    int balance = getBalance(root);

    // Если этот узел стал несбалансированным
    // То есть 4 случая

    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

shared_ptr<Node> AVLTree::findNode(shared_ptr<Node> root, int key)
{
    if (!root || root->key == key) {
        return root;
    }

    if (key < root->key) {
        return findNode(root->left, key);
    } else {
        return findNode(root->right, key);
    }
}

int AVLTree::countNodesInLeftSubtree(std::shared_ptr<Node> node)
{
    if (!node) {
        return 0;
    }

    int count = 0;
    std::shared_ptr<Node> current = node;

    // Спускаемся по левым узлам, считая их
    while (current) {
        count++;
        current = current->left;
    }

    return count;
}


