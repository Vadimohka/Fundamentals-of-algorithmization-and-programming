#include <QApplication>
#include <QPushButton>
#include <QTextToSpeech>
#include <QVBoxLayout>
#include <QWidget>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget window;
    QVBoxLayout layout(&window);
    QPushButton button("Play Text");
    layout.addWidget(&button);

    QTextToSpeech *speech = new QTextToSpeech(&window);

    QObject::connect(&button, &QPushButton::clicked, [=]() {
        QString text = "Hello, this is a voiceover example.";
        speech->say(text);
    });

    window.setLayout(&layout);
    window.setWindowTitle("Text to Speech Example");
    window.show();

    return app.exec();
}