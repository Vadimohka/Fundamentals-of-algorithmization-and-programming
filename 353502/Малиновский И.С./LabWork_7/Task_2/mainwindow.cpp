#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);

    keyLineEdit = new QLineEdit(this);
    keyLineEdit->setPlaceholderText("Key");

    dataLineEdit = new QLineEdit(this);
    dataLineEdit->setPlaceholderText("Data");

    QPushButton *insertButton = new QPushButton("Insert", this);
    QPushButton *searchButton = new QPushButton("Search", this);
    QPushButton *deleteButton = new QPushButton("Delete", this);
    QPushButton *balanceButton = new QPushButton("Balance", this);
    QPushButton *inorderButton = new QPushButton("Inorder", this);
    QPushButton *preorderButton = new QPushButton("Preorder", this);
    QPushButton *postorderButton = new QPushButton("Postorder", this);

    treeWidget = new QTreeWidget(this);
    treeWidget->setHeaderLabels({"Key", "Data"});

    textEdit = new QTextEdit(this);

    QHBoxLayout *inputLayout = new QHBoxLayout();
    inputLayout->addWidget(keyLineEdit);
    inputLayout->addWidget(dataLineEdit);

    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(insertButton);
    buttonLayout->addWidget(searchButton);
    buttonLayout->addWidget(deleteButton);
    buttonLayout->addWidget(balanceButton);
    buttonLayout->addWidget(inorderButton);
    buttonLayout->addWidget(preorderButton);
    buttonLayout->addWidget(postorderButton);

    mainLayout->addLayout(inputLayout);
    mainLayout->addLayout(buttonLayout);
    mainLayout->addWidget(treeWidget);
    mainLayout->addWidget(textEdit);

    setCentralWidget(centralWidget);

    connect(insertButton, &QPushButton::clicked, this, &MainWindow::on_insertButton_clicked);
    connect(searchButton, &QPushButton::clicked, this, &MainWindow::on_searchButton_clicked);
    connect(deleteButton, &QPushButton::clicked, this, &MainWindow::on_deleteButton_clicked);
    connect(balanceButton, &QPushButton::clicked, this, &MainWindow::on_balanceButton_clicked);
    connect(inorderButton, &QPushButton::clicked, this, &MainWindow::on_inorderButton_clicked);
    connect(preorderButton, &QPushButton::clicked, this, &MainWindow::on_preorderButton_clicked);
    connect(postorderButton, &QPushButton::clicked, this, &MainWindow::on_postorderButton_clicked);
}

MainWindow::~MainWindow()
{
}

void MainWindow::on_insertButton_clicked() {
    int key = keyLineEdit->text().toInt();
    std::string data = dataLineEdit->text().toStdString();
    bst.insert(key, data);
    updateTreeView();
}

void MainWindow::on_searchButton_clicked() {
    int key = keyLineEdit->text().toInt();
    std::string data;
    if (bst.search(key, data)) {
        textEdit->setText(QString::fromStdString("Found: " + data));
    } else {
        textEdit->setText("Not Found");
    }
}

void MainWindow::on_deleteButton_clicked() {
    int key = keyLineEdit->text().toInt();
    bst.remove(key);
    updateTreeView();
}

void MainWindow::on_balanceButton_clicked() {
    bst.balance();
    updateTreeView();
}

void MainWindow::on_inorderButton_clicked() {
    updateTextEdit(bst.inorder());
}

void MainWindow::on_preorderButton_clicked() {
    updateTextEdit(bst.preorder());
}

void MainWindow::on_postorderButton_clicked() {
    updateTextEdit(bst.postorder());
}

void MainWindow::updateTreeView() {
    treeWidget->clear();
    std::function<void(Node*, QTreeWidgetItem*)> addItems = [&](Node* node, QTreeWidgetItem* parentItem) {
        if (node == nullptr) return;

        QTreeWidgetItem* item = new QTreeWidgetItem(parentItem);
        item->setText(0, QString::number(node->key));
        item->setText(1, QString::fromStdString(node->data));
        parentItem->addChild(item);

        addItems(node->left, item);
        addItems(node->right, item);
    };

    Node* root = bst.getRoot(); // Получаем корневой узел
    if (root != nullptr) { // Проверяем, что корень не равен nullptr
        QTreeWidgetItem* rootItem = new QTreeWidgetItem(treeWidget);
        rootItem->setText(0, QString::number(root->key));
        rootItem->setText(1, QString::fromStdString(root->data));
        treeWidget->addTopLevelItem(rootItem);
        addItems(root->left, rootItem); // Добавляем левое поддерево
        addItems(root->right, rootItem); // Добавляем правое поддерево
    }
}

void MainWindow::updateTextEdit(const std::vector<std::string>& data) {
    textEdit->clear();
    for (const std::string& str : data) {
        textEdit->append(QString::fromStdString(str));
    }
}
