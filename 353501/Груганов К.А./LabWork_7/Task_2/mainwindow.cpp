#include "mainwindow.h"
#include "avltree.h"
#include "treenode.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , avlTree(new AVLTree())
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    int keys[]{1, 8, 7, 5};
    string values[]{"A", "C", "D", "E"};

    int size = sizeof(keys) / sizeof(keys[0]);
    avlTree->insertFromArr(keys, values, size);
    on_preOrder_clicked();
    drawTree();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_preOrder_clicked()
{
    ui->orderBrowser->clear();
    avlTree->printPreOrder(ui->orderBrowser);
}

void MainWindow::on_postOrder_clicked()
{
    ui->orderBrowser->clear();
    avlTree->printPostOrder(ui->orderBrowser);
}

void MainWindow::on_inOrder_clicked()
{
    ui->orderBrowser->clear();
    avlTree->printInOrder(ui->orderBrowser);
}

void MainWindow::on_levelsButton_clicked()
{
    vector<int> levels = avlTree->nodesPerLevel();
    QString levelsText;
    for (size_t i = 0; i < levels.size(); i++) {
        levelsText += "Уровень " + QString::number(i) + ": " + QString::number(levels[i])
                      + " узлов\n";
    }
    ui->levelsBrowser->setText(levelsText);
}

void MainWindow::drawTree()
{
    scene->clear();
    if (avlTree->root != nullptr) {
        drawNode(avlTree->root, 0, 0, 100);
    }
}
void MainWindow::drawNode(AVLTree::Node *node, qreal x, qreal y, qreal offset)
{
    if (node == nullptr) {
        return;
    }

    TreeNode *treeNode = new TreeNode(node->key, QString::fromStdString(node->value));
    treeNode->setPosition(x, y);
    scene->addItem(treeNode);

    qreal nodeHeight = 40; // Высота узла, которую мы задали в TreeNode
    qreal verticalSpacing = 80; // Вертикальное расстояние между узлами

    if (node->left != nullptr) {
        QGraphicsLineItem *line = new QGraphicsLineItem(x,
                                                        y + nodeHeight / 2,
                                                        x - offset,
                                                        y + verticalSpacing - nodeHeight / 2);
        scene->addItem(line);
        drawNode(node->left, x - offset, y + verticalSpacing, offset / 1.5);
    }

    if (node->right != nullptr) {
        QGraphicsLineItem *line = new QGraphicsLineItem(x,
                                                        y + nodeHeight / 2,
                                                        x + offset,
                                                        y + verticalSpacing - nodeHeight / 2);
        scene->addItem(line);
        drawNode(node->right, x + offset, y + verticalSpacing, offset / 1.5);
    }
}

void MainWindow::on_insertNodButton_clicked()
{
    bool ok;
    int key = QInputDialog::getInt(this,
                                   tr("Вставка"),
                                   tr("Введите ключ:"),
                                   0,
                                   INT_MIN,
                                   INT_MAX,
                                   1,
                                   &ok);
    if (ok) {
        QString value = QInputDialog::getText(this, tr("Вставка"), tr("Введите значение:"));
        if (!value.isEmpty()) {
            avlTree->insert(key, value.toStdString());
            drawTree();
        }
    }
}

void MainWindow::on_findNodeButton_clicked()
{
    bool ok;
    int key = QInputDialog::getInt(this,
                                   tr("Поиск"),
                                   tr("Введите ключ для поиска:"),
                                   0,
                                   INT_MIN,
                                   INT_MAX,
                                   1,
                                   &ok);
    if (ok) {
        string value = avlTree->find(key);
        QMessageBox::information(this,
                                 tr("Поиск"),
                                 tr("Значение: ") + QString::fromStdString(value));
    }
}

void MainWindow::on_deleteNodeButton_clicked()
{
    bool ok;
    int key = QInputDialog::getInt(this,
                                   tr("Удаление"),
                                   tr("Введите ключ для удаления:"),
                                   0,
                                   INT_MIN,
                                   INT_MAX,
                                   1,
                                   &ok);
    if (ok) {
        bool wasRemoved = avlTree->remove(key);
        if (wasRemoved) {
            drawTree(); // Перерисовка дерева
        } else {
            QMessageBox::warning(this, tr("Ошибка"), tr("Ключ не найден в дереве."));
        }
    }
}
