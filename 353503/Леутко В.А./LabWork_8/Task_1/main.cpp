#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
// shared_ptr<::Node> insert(shared_ptr<Node> node, int key, str value) { // std::shared_ptr используется для управления памятью узлов дерева
//                                                                        //(память узлов будет автоматически освобождаться, когда на них не будет больше ссылок)
//     if (!node) // если корня нет (дерево пустое) -> добавляем новый узел, который и становиться корнем
//         return(newNode(key, value));

//     if (key < node->key) { // если новый добавляемый элемент являеться меньше текушего узла, на котором мы сейчас стоим, то мы рекурсивно идем налево
//         node->left = insert(node->left, key, value);
//         return node;
//     }
//     else if (key > node->key) { // больше текущего узла - рекурсивно идем направо
//         node->right = insert(node->right, key, value);
//         return node;
//     }
//     else { // Одинаковые ключи не допускаются
//         return node;
//     }
// }
