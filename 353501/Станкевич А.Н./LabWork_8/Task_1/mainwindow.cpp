#include "mainwindow.h"
#include "treenode.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , bst(new BST())
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    int keys[]{5, 9, 7, 6};
    string values[]{"A", "C", "D", "E"};

    int size = sizeof(keys) / sizeof(keys[0]);
    bst->insertFromArr(keys, values, size);
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
    bst->printPreOrder(ui->orderBrowser);
}

void MainWindow::on_postOrder_clicked()
{
    ui->orderBrowser->clear();
    bst->printPostOrder(ui->orderBrowser);
}

void MainWindow::on_inOrder_clicked()
{
    ui->orderBrowser->clear();
    bst->printInOrder(ui->orderBrowser);
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
            bst->insert(key, value.toStdString());
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
        string value = bst->find(key);
        QMessageBox::information(this,
                                 tr("Поиск"),
                                 tr("Значение: ") + QString::fromStdString(value));
    }
}

void MainWindow::drawTree()
{
    scene->clear();
    if (bst->root != nullptr) {
        drawNode(bst->root, 0, 0, 100);
    }
}

void MainWindow::drawNode(BST::Node *node, qreal x, qreal y, qreal offset)
{
    if (node == nullptr) {
        return;
    }

    // Создаем TreeNode для текущего узла и добавляем его на сцену
    TreeNode *treeNode = new TreeNode(node->key, QString::fromStdString(node->value));
    treeNode->setPosition(x, y);
    scene->addItem(treeNode);

    // Задаем высоту узла и вертикальное расстояние между узлами
    qreal nodeHeight = 40;
    qreal verticalSpacing = 80;

    // Рекурсивно рисуем левое поддерево
    if (node->left != nullptr) {
        QGraphicsLineItem *line = new QGraphicsLineItem(x,
                                                        y + nodeHeight / 2,
                                                        x - offset,
                                                        y + verticalSpacing - nodeHeight / 2);
        scene->addItem(line);
        drawNode(node->left, x - offset, y + verticalSpacing, offset / 1.5);
    }

    // Рекурсивно рисуем правое поддерево
    if (node->right != nullptr) {
        QGraphicsLineItem *line = new QGraphicsLineItem(x,
                                                        y + nodeHeight / 2,
                                                        x + offset,
                                                        y + verticalSpacing - nodeHeight / 2);
        scene->addItem(line);
        drawNode(node->right, x + offset, y + verticalSpacing, offset / 1.5);
    }
}

void MainWindow::on_levelsButton_clicked()
{
    vector<int> levels = bst->nodesPerLevel();
    QString levelsText;
    for (size_t i = 0; i < levels.size(); i++) {
        levelsText += "Уровень " + QString::number(i) + ": " + QString::number(levels[i])
                      + " узлов\n";
    }
    ui->levelsBrowser->setText(levelsText);
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
        bool wasRemoved = bst->remove(key);
        if (wasRemoved) {
            drawTree(); // Перерисовка дерева
        } else {
            QMessageBox::warning(this, tr("Ошибка"), tr("Ключ не найден в дереве."));
        }
    }
}
