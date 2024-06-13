//
// Created by shosh on 5/22/24.
//

#include "MainWindow.h"

MainWindow::MainWindow() {
    MainLayout->addWidget(MainTypeScreen, 1, 1,1,2);
    auto timeElapsedPlaceholder = new QLabel;
    auto wordsPerMinutePlaceholder = new QLabel;
    timeElapsedPlaceholder->setText("Time elapsed");
    wordsPerMinutePlaceholder->setText("Accuracy");
    TimeElapsed->setText("0");
    AccuracyLabel->setText("0");
    TimeElapsed->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    AccuracyLabel->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    wordsPerMinutePlaceholder->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    timeElapsedPlaceholder->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    MainLayout->addWidget(timeElapsedPlaceholder,3,1, Qt::AlignLeft);
    MainLayout->addWidget(TimeElapsed,3, 0, Qt::AlignLeft);
    MainLayout->addWidget(wordsPerMinutePlaceholder,3,2);
    MainLayout->addWidget(AccuracyLabel, 3, 3);
    LanguagesSelector->addItem("English");
    LanguagesSelector->addItem("Belarusian");
    LanguagesSelector->addItem("French");
    LanguagesSelector->addItem("German");
    LanguagesSelector->addItem("Hebrew");
    LanguagesSelector->addItem("Arabic");
    connect(LanguagesSelector, &QComboBox::currentTextChanged, [=](const QString& index) {
        if (index == "English") {
            setKeyboardToEnglish();
        }
        if (index == "Belarusian") {
            setKeyboardToBelarusian();
        }
        if (index == "French") {
            setKeyboardToFrench();
        }
        if (index == "Arabic"){
            setKeyboardToArabic();
        }//TODO THIS HELL
        if (index == "Hebrew") {
            setKeyboardToHebrew();
        }
    });
    MainLayout->addWidget(LanguagesSelector,0,0, Qt::AlignTop);
    ChooseTxt->setText("Choose txt file to open");
    MainLayout->addWidget(ChooseTxt,0,0);
    connect(ChooseTxt, &QPushButton::pressed, [=] {
        ShownTypeScreen->clear();
        MainTypeScreen->clear();
        auto fileContentReady = [=](const QString &fileName, const QByteArray &fileContent) {
            ShownTypeScreen->textCursor().insertText(fileContent);
            QTextCursor textCursor = ShownTypeScreen->textCursor();
            textCursor.movePosition(QTextCursor::Start);
            ShownTypeScreen->setTextCursor(textCursor);
        };
        QFileDialog::getOpenFileContent("Text Files (*.txt)",  fileContentReady);
        GuiRefresh->start(10);
        connect(GuiRefresh, &QTimer::timeout, [=] {
            TimeElapsed->setText(QString::number(TimeElapsed->text().toFloat() + 0.01));
            AccuracyLabel->setText(QString::number((double)correct_symbols / all_symbols, 'g', 2) + "%");
        });
    });
    auto *VerticalKeyboardLayout = new QVBoxLayout;
    auto *KeyboardLayer1 = new QHBoxLayout;
    auto *KeyboardLayer2 = new QHBoxLayout;
    auto *KeyboardLayer3 = new QHBoxLayout;
    auto *KeyboardLayer4 = new QHBoxLayout;
    auto *KeyboardLayer5 = new QHBoxLayout;
    VerticalKeyboardLayout->addLayout(KeyboardLayer1);
    VerticalKeyboardLayout->addLayout(KeyboardLayer2);
    VerticalKeyboardLayout->addLayout(KeyboardLayer3);
    VerticalKeyboardLayout->addLayout(KeyboardLayer4);
    VerticalKeyboardLayout->addLayout(KeyboardLayer5);
    for (int i = 0; i < 14; i++) {
        auto *KeyButton = new QPushButton;
        keyboardButtons.append(KeyButton);
        KeyboardLayer1->addWidget(KeyButton);
        KeyButton->show();
        connect(KeyButton, &QPushButton::pressed, [=] {
            QTextCursor textCursor = ShownTypeScreen->textCursor();
            MainTypeScreen->setTextColor(QColor("#f38ba8"));
            textCursor.movePosition(QTextCursor::NextCharacter,QTextCursor::KeepAnchor);
            if (textCursor.selectedText() == KeyButton->text()) {
                qDebug() << "da nu";
                correct_symbols++;
                MainTypeScreen->setTextColor(QColor("#a6e3a1"));
            }
            all_symbols++;
            textCursor.clearSelection();
            ShownTypeScreen->setTextCursor(textCursor);
            MainTypeScreen->insertPlainText(KeyButton->text());
        });
    }
    for (int i = 0; i < 14; i++) {
        auto *KeyButton = new QPushButton;
        keyboardButtons.append(KeyButton);
        KeyboardLayer2->addWidget(KeyButton);
        KeyButton->show();
        connect(KeyButton, &QPushButton::pressed, [=] {
            QTextCursor textCursor = ShownTypeScreen->textCursor();
            textCursor.movePosition(QTextCursor::NextCharacter,QTextCursor::KeepAnchor);
            MainTypeScreen->setTextColor(QColor("#f38ba8"));
            if (textCursor.selectedText() == KeyButton->text()) {
                qDebug() << "da nu";
                correct_symbols++;
                MainTypeScreen->setTextColor(QColor("#a6e3a1"));
            }
            all_symbols++;
            textCursor.clearSelection();
            ShownTypeScreen->setTextCursor(textCursor);
            MainTypeScreen->insertPlainText(KeyButton->text());
        });
    }
    for (int i = 0; i < 12; i++) {
        auto *KeyButton = new QPushButton;
        keyboardButtons.append(KeyButton);
        KeyboardLayer3->addWidget(KeyButton);
        KeyButton->show();
        connect(KeyButton, &QPushButton::pressed, [=] {
            QTextCursor textCursor = ShownTypeScreen->textCursor();
            textCursor.movePosition(QTextCursor::NextCharacter,QTextCursor::KeepAnchor);
            MainTypeScreen->setTextColor(QColor("#f38ba8"));
            if (textCursor.selectedText() == KeyButton->text()) {
                qDebug() << "da nu";
                correct_symbols++;
                MainTypeScreen->setTextColor(QColor("#a6e3a1"));
            }
            all_symbols++;
            textCursor.clearSelection();
            ShownTypeScreen->setTextCursor(textCursor);
            MainTypeScreen->insertPlainText(KeyButton->text());
        });
    }
    for (int i = 0; i < 10; i++)  {
        auto *KeyButton = new QPushButton;
        keyboardButtons.append(KeyButton);
        KeyboardLayer4->addWidget(KeyButton);
        KeyButton->show();
        connect(KeyButton, &QPushButton::pressed, [=] {
            QTextCursor textCursor = ShownTypeScreen->textCursor();
            textCursor.movePosition(QTextCursor::NextCharacter,QTextCursor::KeepAnchor);
            MainTypeScreen->setTextColor(QColor("#f38ba8"));
            if (textCursor.selectedText() == KeyButton->text()) {
                qDebug() << "da nu";
                correct_symbols++;
                MainTypeScreen->setTextColor(QColor("#a6e3a1"));
            }
            all_symbols++;
            textCursor.clearSelection();
            ShownTypeScreen->setTextCursor(textCursor);
            MainTypeScreen->insertPlainText(KeyButton->text());
        });
    }
    auto *spaceBar = new QPushButton;
    keyboardButtons.append(spaceBar);
    KeyboardLayer5->addWidget(spaceBar);
    connect(spaceBar, &QPushButton::pressed, [=] {
        QTextCursor textCursor = ShownTypeScreen->textCursor();
        textCursor.movePosition(QTextCursor::NextCharacter,QTextCursor::KeepAnchor);
        MainTypeScreen->setTextColor(QColor("#f38ba8"));
        if (textCursor.selectedText() == spaceBar->text()) {
            qDebug() << "da nu";
            correct_symbols++;
            MainTypeScreen->setTextColor(QColor("#a6e3a1"));
        }
        all_symbols++;
        textCursor.clearSelection();
        ShownTypeScreen->setTextCursor(textCursor);
        MainTypeScreen->insertPlainText(spaceBar->text());
    });

    MainLayout->addWidget(ShownTypeScreen, 0,1,1,2);
    MainLayout->addLayout(VerticalKeyboardLayout, 2,0,1,3);

    this->CentralWidget->setLayout(MainLayout);
    this->setCentralWidget(CentralWidget);
    MainTypeScreen->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Maximum);
    LanguagesSelector->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    ChooseTxt->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);

    ShownTypeScreen->setTextInteractionFlags(Qt::NoTextInteraction);
    ShownTypeScreen->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Maximum);
    MainTypeScreen->setTextInteractionFlags(Qt::NoTextInteraction);
    this->setMinimumSize(700, 700);
    this->show();
    setKeyboardToEnglish();

}

void MainWindow::keyReleaseEvent(QKeyEvent *event) {
    if (event->key() == 16777252) {
        if (LanguagesSelector->currentText() == "English" && !is_uppercase) {
            setKeyboardToEnglishUppercase();
            is_uppercase = true;
        } else if (LanguagesSelector->currentText() == "English" && is_uppercase) {
            setKeyboardToEnglish();
            is_uppercase = false;
        }
    }
}

void MainWindow::setKeyboardToEnglish() {
    QString Language(QString("`1234567890-=") + QChar(0x7f) + QString("\tqwertyuiop[]") + QChar(92) + QString("asdfghjkl;'\rzxcvbnm,./ "));
    for (int i = 0; i < keyboardButtons.size(); i++) {
        keyboardButtons[i]->setText(Language.at(i));
        keyboardButtons[i]->setShortcut(QString(Language.at(i)));
        if (Language.at(i) == '\r') {
            keyboardButtons[i]->setShortcut(Qt::Key_Return);
        }
        if (Language.at(i) == '\t') {
            keyboardButtons[i]->setShortcut(Qt::Key_Tab);
        }
        if (Language.at(i) == 0x7f) {
            keyboardButtons[i]->setShortcut(Qt::Key_Backspace);
            keyboardButtons[i]->disconnect();
            connect(keyboardButtons[i], &QPushButton::pressed, [=] {
               MainTypeScreen->textCursor().deletePreviousChar();
            });
        }
        if (Language.at(i) == ' ') {
            keyboardButtons[i]->setShortcut(Qt::Key_Space);
        }
    }
}

void MainWindow::setKeyboardToEnglishUppercase() {
    QString Language(QString("`!@#$%^") +QString("&") + QString("*()_+") + QChar(0x7f) + QString("\tQWERTYUIOP{}") + QChar('|') + QString("ASDFGHJKL:") + QString("'") + QString("\rZXCVBNM<>? "));
    for (int i = 0; i < keyboardButtons.size(); i++) {
        keyboardButtons[i]->setText(Language.at(i));
        keyboardButtons[i]->setShortcut(QString(Language.at(i)));
        if (Language.at(i) == '\r') {
            keyboardButtons[i]->setShortcut(Qt::Key_Return);
        }
        if (Language.at(i) == '\t') {
            keyboardButtons[i]->setShortcut(Qt::Key_Tab);
        }
        if (Language.at(i) == 0x7f) {
            keyboardButtons[i]->setShortcut(Qt::Key_Backspace);
            keyboardButtons[i]->disconnect();
            connect(keyboardButtons[i], &QPushButton::pressed, [=] {
                MainTypeScreen->textCursor().deletePreviousChar();
            });
        }
        if (Language.at(i) == ' ') {
            keyboardButtons[i]->setShortcut(Qt::Key_Space);
        }
    }
}

void MainWindow::setKeyboardToBelarusian() {
    QString Language(QString("ё1234567890-=") + QChar('\b') + QString("\tйцукенгшўзх'") + QChar(92) + QString("фывапролджэ\rячсмітьбю. "));
        for (int i = 0; i < keyboardButtons.size(); i++) {
            keyboardButtons[i]->setText(Language.at(i));
            keyboardButtons[i]->setShortcut(QString(Language.at(i)));
            if (Language.at(i) == '\r') {
                keyboardButtons[i]->setShortcut(Qt::Key_Return);
            }
            if (Language.at(i) == '\t') {
                keyboardButtons[i]->setShortcut(Qt::Key_Tab);
            }
            if (Language.at(i) == 0x7f) {
                keyboardButtons[i]->setShortcut(Qt::Key_Backspace);
                keyboardButtons[i]->disconnect();
                connect(keyboardButtons[i], &QPushButton::pressed, [=] {
                    MainTypeScreen->textCursor().deletePreviousChar();
                });
            }
            if (Language.at(i) == ' ') {
                keyboardButtons[i]->setShortcut(Qt::Key_Space);
            }
        }
}

void MainWindow::setKeyboardToFrench() {
    QString Language(QString("²") + QString("&") + QString("é") + QChar(34) + QString("'(-è_çà)=") + QChar('\b') + QString("\tazertyuiop^$*") + QString("qsdfghjklmù\rwxcvbn,;:! "));
    for (int i = 0; i < keyboardButtons.size(); i++) {
        keyboardButtons[i]->setText(Language.at(i));
        keyboardButtons[i]->setShortcut(QString(Language.at(i)));
        if (Language.at(i) == '\r') {
            keyboardButtons[i]->setShortcut(Qt::Key_Return);
        }
        if (Language.at(i) == '\t') {
            keyboardButtons[i]->setShortcut(Qt::Key_Tab);
        }
        if (Language.at(i) == '\b') {
            keyboardButtons[i]->setShortcut(Qt::Key_Backspace);
            keyboardButtons[i]->disconnect();
            connect(keyboardButtons[i], &QPushButton::pressed, [=] {
                MainTypeScreen->textCursor().deletePreviousChar();
            });
        }
        if (Language.at(i) == ' ') {
            keyboardButtons[i]->setShortcut(Qt::Key_Space);
            connect(keyboardButtons[i], &QPushButton::pressed, [=] {
                words_per_minute++;
            });
        }
    }
}

void MainWindow::setKeyboardToArabic() {
    QString Language (QString("ذ1234567890-=\b\tضصثقفغعهخح" ) + QString("جد") + QChar(92) + QString("شسيبلاتنمكطئءؤرلاىةوزظ") + QString(" "));
    for (int i = 0; i < keyboardButtons.size(); i++) {
        keyboardButtons[i]->setText(Language.at(i));
        keyboardButtons[i]->setShortcut(QString(Language.at(i)));
        if (Language.at(i) == '\r') {
            keyboardButtons[i]->setShortcut(Qt::Key_Return);
        }
        if (Language.at(i) == '\t') {
            keyboardButtons[i]->setShortcut(Qt::Key_Tab);
        }
        if (Language.at(i) == '\b') {
            keyboardButtons[i]->setShortcut(Qt::Key_Backspace);
            keyboardButtons[i]->disconnect();
            connect(keyboardButtons[i], &QPushButton::pressed, [=] {
                MainTypeScreen->textCursor().deletePreviousChar();
            });
        }
        if (Language.at(i) == ' ') {
            keyboardButtons[i]->setShortcut(Qt::Key_Space);
            connect(keyboardButtons[i], &QPushButton::pressed, [=] {
                words_per_minute++;
            });
        }
    }
}

void MainWindow::setKeyboardToHebrew() {
    QString Language(QString(";123456890-=") + QString("\t") + QString("/") + QString("'קראטוןםפ]") + QChar(92) + QString("שדגכעיחלךף,זסבהנמצתץ.גךדזגדץתצ "));
    for (int i = 0; i < keyboardButtons.size(); i++) {
        keyboardButtons[i]->setText(Language.at(i));
        keyboardButtons[i]->setShortcut(QString(Language.at(i)));
        if (Language.at(i) == '\r') {
            keyboardButtons[i]->setShortcut(Qt::Key_Return);
        }
        if (Language.at(i) == '\t') {
            keyboardButtons[i]->setShortcut(Qt::Key_Tab);
        }
        if (Language.at(i) == '\b') {
            keyboardButtons[i]->setShortcut(Qt::Key_Backspace);
            keyboardButtons[i]->disconnect();
            connect(keyboardButtons[i], &QPushButton::pressed, [=] {
                MainTypeScreen->textCursor().deletePreviousChar();
            });
        }
        if (Language.at(i) == ' ') {
            keyboardButtons[i]->setShortcut(Qt::Key_Space);
            connect(keyboardButtons[i], &QPushButton::pressed, [=] {
                words_per_minute++;
            });
        }
    }
}
