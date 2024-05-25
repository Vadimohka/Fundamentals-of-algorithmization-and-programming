#include <QApplication>

#include "app/shortcuts.h"
#include "view/mainwindow.h"

using std::vector;

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    auto model = model::make_shared<model::GameModel>();

    view::MainWindow window(model);


    window.show();
    return a.exec();
}
