//
// Created by shosh on 5/29/24.
//

#include "MainWindow.h"

static const int TEXT_COLUMN = 0;

MainWindow::MainWindow(Node *node) {
    Root = node;
    this->addToolBar(Tools);
    Tools->addWidget(AddNode);
    AddNode->setText("Add node");
    auto Validator = new QIntValidator;
    Validator->setRange(-1000, 1000);
    connect(AddNode, &QPushButton::pressed, [=] {
        auto temp = new QTreeWidgetItem(Central);
        int key = EnterKey->text().toInt();
        Root = Root->insert(Root, key);
        Root->nodes_vector.clear();
        Root->preorderTraverse(Root);
        QVector<int> nodes_vect = Root->nodes_vector;
        int max;

        for (int i = 0; i < nodes_vect.size(); i++) {
            temp->insertChild(i, new QTreeWidgetItem(temp, QStringList(QString::number(nodes_vect[i]))));
            qDebug() << nodes_vect[i];
        }
    });
    EnterKey->setValidator(Validator);
    Tools->addWidget(EnterKey);
    this->setCentralWidget(Central);

    this->show();
}
