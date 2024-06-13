#pragma once
static std::string ch_hor = "-", ch_ver = "|", ch_ddia = "/", ch_rddia = "\\", ch_udia = "\\", ch_ver_hor = "|-", ch_udia_hor = "\\-", ch_ddia_hor = "/-", ch_ver_spa = "| ";
template <typename T>
class BinarySearchTree {
    

    public:
        struct Node {
            public:
                long key;
                T value;
                Node* left;
                Node* right;

                int height;

                Node(long k, T v) : key(k), value(v), left(nullptr), right(nullptr) {

                }

        };

        Node* getRoot() {
            return root;
        }
    public:
        Node* root;
    public:
        BinarySearchTree() : root(nullptr) {}

        Node* newNode(long k, T v)
        {
            Node* temp  = new Node(k, v);
            temp->height = 1;
            return temp;
        }
        
        int height(Node *N)  
        {  
            if (N == nullptr)  
                return 0;  
            return N->height;  
        } 

        int max(int a, int b)  
        {  
            return (a > b)? a : b;  
        } 

        int getBalance(Node *N)  
        {  
            if (N == NULL)  
                return 0;  
            return height(N->left) - height(N->right);  
        }  

        void updateHeight(Node* node){
            node->height = std::max(height(node->left), 
                    height(node->right)) + 1;  
        }

        void swap(Node* a, Node* b){
            long tempKey = a->key;
            a->key = b->key;
            b->key = tempKey;

            T tempVal = a->value;
            a->value = b->value;
            b->value = tempVal; 
        }

        Node* rightRotate(Node* root){
            swap(root, root->left);
            Node* tempRootRight = root->right;
            Node* tempRootLeft = root->left;

            root->right = tempRootLeft;
            root->left = tempRootLeft->left;
            tempRootLeft->left = tempRootLeft->right;
            tempRootLeft->right = tempRootRight;
            updateHeight(root->right);
            updateHeight(root);
            return root;
        }

        Node* leftRotate(Node* root){
            swap(root, root->right);
            Node* tempLeft = root->left;
            Node* tempRight = root->right;

            root->left = tempRight;
            root->right = tempRight->right;
            tempRight->right = tempRight->left;
            tempRight->left = tempLeft;
            updateHeight(root->left);
            updateHeight(root);
            return root;
        }

        Node* insert(Node* node, long key, const T &value) {
            if (node == nullptr)
                return newNode(key, value);
            if (key < node->key)
                node->left = insert(node->left, key, value);
            else if (key > node->key)
                node->right = insert(node->right, key, value);

            node->height = 1 + max(height(node->left),  
                        height(node->right));  
  
            /* 3. Get the balance factor of this ancestor  
                node to check whether this node became  
                unbalanced */
            int balance = getBalance(node);  
        
            // If this node becomes unbalanced, then  
            // there are 4 cases  
        
            // Left Left Case  
            if (balance > 1 && key < node->left->key)  
                return rightRotate(node);  
        
            // Right Right Case  
            if (balance < -1 && key > node->right->key)  
                return leftRotate(node);  
        
            // Left Right Case  
            if (balance > 1 && key > node->left->key)  
            {  
                node->left = leftRotate(node->left);  
                return rightRotate(node);  
            }  
        
            // Right Left Case  
            if (balance < -1 && key < node->right->key)  
            {  
                node->right = rightRotate(node->right);  
                return leftRotate(node);  
            }  

            return node;
        }

        Node* search(Node* root, long key)
        {
            if (root == nullptr || root->key == key)
                return root;

            if (root->key < key)
                return search(root->right, key);

            return search(root->left, key);
        }

        Node* findMin(Node *node) {
            while (node->left != nullptr) {
                node = node->left;
            }
            return node;
        }

        Node* findMax(Node *node) {
            while (node->right != nullptr) {
                node = node->right;
            }
            return node;
        }

        Node* deleteNode(Node* root, long k) {
            if (root == nullptr)
                return root;

            // If the key to be deleted is smaller than the root's key, then it lies in the left subtree
            if (k < root->key) {
                root->left = deleteNode(root->left, k);
            }
            // If the key to be deleted is greater than the root's key, then it lies in the right subtree
            else if (k > root->key) {
                root->right = deleteNode(root->right, k);
            }
            else{
                if (root->left == nullptr) {
                    Node* temp = root->right;
                    delete root;
                    return temp;
                }
                else if (root->right == nullptr) {
                    Node* temp = root->left;
                    delete root;
                    return temp;
                }

                Node* tmp = findMin(root->right);
                root->key = tmp->key;
                root->value = tmp->value;
                root->right = deleteNode(root->right, tmp->key);
            }

            updateHeight(root);

                int balance = getBalance(root); 
 
                // If this node becomes unbalanced, 
                // then there are 4 cases 
            
                // Left Left Case 
                if (balance > 1 && 
                    getBalance(root->left) >= 0) 
                    return rightRotate(root); 
            
                // Left Right Case 
                if (balance > 1 && 
                    getBalance(root->left) < 0) 
                { 
                    root->left = leftRotate(root->left); 
                    return rightRotate(root); 
                } 
            
                // Right Right Case 
                if (balance < -1 && 
                    getBalance(root->right) <= 0) 
                    return leftRotate(root); 
            
                // Right Left Case 
                if (balance < -1 && 
                    getBalance(root->right) > 0) 
                { 
                    root->right = rightRotate(root->right); 
                    return leftRotate(root); 
                } 

            return root;
        }


        // Прямой обход (Preorder) - посещаем корень, затем левое поддерево, затем правое поддерево.
        // Симметричный обход (Inorder) - посещаем левое поддерево, затем корень, затем правое поддерево.
        // Обратный обход (Postorder) - посещаем левое поддерево, затем правое поддерево, затем корень.
        void printInorderTree(Node* node, QString& InorderOrder){
            if (node == nullptr){
                return;
            }
            printInorderTree(node->left, InorderOrder);
            InorderOrder += ("key: " + QString::number(node->key) + "value: " + node->value + " ");
            printInorderTree(node->right, InorderOrder);
        }

        void printPostOrder(Node* node, QString& postOrder)
        {
            if (node == nullptr){
                return;
            }
            printPostOrder(node->left, postOrder);
            printPostOrder(node->right, postOrder);
            postOrder += ("key: " + QString::number(node->key) + "value: " + node->value + " ");
        }

        void printPreOrder(Node* node, QString& preOrder)
        {
            if (node == nullptr){
                return;
            }
            preOrder += ("key: " + QString::number(node->key) + "value: " + node->value + " ");
            printPreOrder(node->left, preOrder);
            printPreOrder(node->right, preOrder);
        }

        void destroyTree(Node *node) {
            if (node != nullptr) {
                qDebug() << "recuresion" << "\n";
                destroyTree(node->left);
                destroyTree(node->right);
                delete node;
            }
        }

        void balanceTree() {
            QVector<QPair<long, T>> sortedPairs;
            inOrderToVec(root, sortedPairs);
            root = buildBalancedTree(sortedPairs, 0, sortedPairs.size() - 1);
        }

        void inOrderToVec(Node *node, QVector<QPair<long, T>>& vec) {
            if (node != nullptr) {
                inOrderToVec(node->left, vec);
                vec.emplace_back(node->key, node->value);
                inOrderToVec(node->right, vec);
            }
        }

        Node* buildBalancedTree(QVector<QPair<long, T>>& sortedPairs, long start, long end) {
            if (start > end){
                return nullptr;
            }
            long mid = (start + end) / 2;
            Node* newNode = new Node(sortedPairs[mid].first, sortedPairs[mid].second);
            newNode->left = buildBalancedTree(sortedPairs, start, mid - 1);
            newNode->right = buildBalancedTree(sortedPairs, mid + 1, end);
            return newNode;
        }

        void treeStruct(Node const *node, bool high = true, std::vector<std::string> const &lpref = std::vector<std::string>(), std::vector<std::string> const &cpref = std::vector<std::string>(), std::vector<std::string> const &rpref = std::vector<std::string>(), bool root = true, bool left = true, std::shared_ptr<std::vector<std::vector<std::string>>> lines = nullptr)
        {
            if (!node)
                return;
            typedef std::vector<std::string> VS;
            auto VSCat = [](VS const &a, VS const &b)
            { auto r = a; r.insert(r.end(), b.begin(), b.end()); return r; };
            if (root)
                lines = std::make_shared<std::vector<VS>>();
            if (node->left)
                treeStruct(node->left, high, VSCat(lpref, high ? VS({" ", " "}) : VS({" "})), VSCat(lpref, high ? VS({ch_ddia, ch_ver}) : VS({ch_ddia})), VSCat(lpref, high ? VS({ch_hor, " "}) : VS({ch_hor})), false, true, lines);
            auto sval = std::to_string(node->key);
            size_t sm = left || sval.empty() ? sval.size() / 2 : ((sval.size() + 1) / 2 - 1);
            for (size_t i = 0; i < sval.size(); ++i)
                lines->push_back(VSCat(i < sm ? lpref : i == sm ? cpref
                                                                : rpref,
                                    {std::string(1, sval[i])}));
            if (node->right)
                treeStruct(node->right, high, VSCat(rpref, high ? VS({ch_hor, " "}) : VS({ch_hor})), VSCat(rpref, high ? VS({ch_rddia, ch_ver}) : VS({ch_rddia})), VSCat(rpref, high ? VS({" ", " "}) : VS({" "})), false, false, lines);
            if (root)
            {
                VS out;
                for (size_t l = 0;; ++l)
                {
                    bool last = true;
                    std::string line;
                    for (size_t i = 0; i < lines->size(); ++i)
                        if (l < (*lines).at(i).size())
                        {
                            line += lines->at(i)[l];
                            last = false;
                        }
                        else
                            line += " ";
                    if (last)
                        break;
                    out.push_back(line);
                }

                for (size_t i = 0; i < out.size(); ++i)
                {
                    qDebug() << out[i];
                }
            }
            else 
            {
                return;
            }
        }

        void drawTree() {
            treeStruct(root);
        }

};
