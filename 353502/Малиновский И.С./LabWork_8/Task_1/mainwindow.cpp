#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    treeWidget = new QTreeWidget();
    insertButton = new QPushButton("Insert", this);
    insertLine = new QLineEdit();
    deleteButton = new QPushButton("Delete", this);
    eraseLine = new QLineEdit();
    findLCAButton = new QPushButton("Find LCA", this);
    val1Line = new QLineEdit();
    val2Line = new QLineEdit();

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(insertButton);
    layout->addWidget(insertLine);
    layout->addWidget(deleteButton);
    layout->addWidget(eraseLine);
    layout->addWidget(findLCAButton);
    layout->addWidget(val1Line);
    layout->addWidget(val2Line);

    QHBoxLayout *hLayout = new QHBoxLayout;
    hLayout->addWidget(treeWidget);
    hLayout->addLayout(layout);

    QWidget *widget = new QWidget;
    widget->setLayout(hLayout);
    setCentralWidget(widget);

    connect(insertButton, SIGNAL(clicked()), this, SLOT(on_insertButton_clicked()));
    connect(deleteButton, SIGNAL(clicked()), this, SLOT(on_deleteButton_clicked()));
    connect(findLCAButton, SIGNAL(clicked()), this, SLOT(on_findLCAButton_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_insertButton_clicked() {
    int key = insertLine->text().toInt();
    tree.insert(key);
    treeWidget->clear();
    tree.print(treeWidget);
}

void MainWindow::on_deleteButton_clicked() {
    int key = eraseLine->text().toInt();
    tree.erase(key);
    treeWidget->clear();
    tree.print(treeWidget);
}

void MainWindow::on_findLCAButton_clicked() {
    int val1 = val1Line->text().toInt();
    int val2 = val2Line->text().toInt();
    qDebug() << val1 << val2 << tree.contains(val1) << tree.contains(val2);
    if (!tree.contains(val1) || !tree.contains(val2)) {
        QMessageBox::warning(nullptr, "Ошибка", "Некорректные данные");
        return;
    }
    int lca=tree.lca(val1, val2);
    QMessageBox::information(nullptr, "LCA", QString::number(lca));
}
