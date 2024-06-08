#include "settings.h"
#include <iostream>

Settings::Settings(QWidget *parent) : QDialog(parent) {
    bgmLabel = new QLabel(tr("Music"));
    bgmSlider = new QSlider(Qt::Horizontal);
    bgmSpinBox = new QSpinBox;
    bgmSlider->setRange(0, 100);
    bgmSpinBox->setRange(0, 100);

    sfxLabel = new QLabel(tr("Sound Effects"));
    sfxSlider = new QSlider(Qt::Horizontal);
    sfxSpinBox = new QSpinBox;
    sfxSlider->setRange(0, 100);
    sfxSpinBox->setRange(0, 100);

    confirmButton = new QPushButton(tr("Confirm"));
    cancelButton = new QPushButton(tr("Cancel"));

    connect(bgmSpinBox, SIGNAL(valueChanged(int)), bgmSlider, SLOT(setValue(int)));
    connect(bgmSlider, SIGNAL(valueChanged(int)), bgmSpinBox, SLOT(setValue(int)));
    connect(bgmSlider, SIGNAL(valueChanged(int)), this, SLOT(bgmChanged()));
    connect(sfxSpinBox, SIGNAL(valueChanged(int)), sfxSlider, SLOT(setValue(int)));
    connect(sfxSlider, SIGNAL(valueChanged(int)), sfxSpinBox, SLOT(setValue(int)));
    connect(sfxSlider, SIGNAL(valueChanged(int)), this, SLOT(sfxChanged()));
    connect(confirmButton, SIGNAL(clicked(bool)), this, SLOT(confirm()));
    connect(cancelButton, SIGNAL(clicked(bool)), this, SLOT(reject()));

    QHBoxLayout *firstLayout = new QHBoxLayout;
    firstLayout->addWidget(bgmLabel);
    firstLayout->addWidget(bgmSlider);
    firstLayout->addWidget(bgmSpinBox);

    QHBoxLayout *secondLayout = new QHBoxLayout;
    secondLayout->addWidget(sfxLabel);
    secondLayout->addWidget(sfxSlider);
    secondLayout->addWidget(sfxSpinBox);

    QHBoxLayout *thirdLayout = new QHBoxLayout;
    thirdLayout->addWidget(confirmButton);
    thirdLayout->addWidget(cancelButton);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(firstLayout);
    mainLayout->addLayout(secondLayout);
    mainLayout->addLayout(thirdLayout);

    setLayout(mainLayout);
    setWindowModality(Qt::WindowModal);
    setWindowTitle("Settings");
}

void Settings::reject() {
    this->revertState();
    QDialog::reject();
}

void Settings::setState() {
    bgm = bgmSlider->value();
    sfx = sfxSlider->value();
}

void Settings::revertState() {
    bgmSlider->setValue(bgm);
    sfxSlider->setValue(sfx);
}

void Settings::readSettings() {
    QSettings settings("Super Tim Mario", "Mario Game");
    bgmSlider->setValue(settings.value("bgm", 50).toInt());
    sfxSlider->setValue(settings.value("sfx", 50).toInt());
    confirm();
}

void Settings::writeSettings() {
    QSettings settings("Super Tim Mario", "Mario Game");
    settings.setValue("bgm", bgmSlider->value());
    settings.setValue("sfx", sfxSlider->value());
}

void Settings::bgmChanged() {
    emit bgmAdjust(bgmSlider->value());
}

void Settings::sfxChanged() {
    emit sfxAdjust(sfxSlider->value());
}

void Settings::confirm() {
    emit bgmAdjust(bgmSlider->value());
    emit sfxAdjust(sfxSlider->value());
    this->setState();
    this->close();
}
