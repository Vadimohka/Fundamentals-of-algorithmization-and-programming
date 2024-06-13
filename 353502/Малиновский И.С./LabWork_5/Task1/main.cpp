#include <QApplication>
#include "typingtrainer.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    TypingTrainer trainer;
    trainer.show();

    return a.exec();
}
