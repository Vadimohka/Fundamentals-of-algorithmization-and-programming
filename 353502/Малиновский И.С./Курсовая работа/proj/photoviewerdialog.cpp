// photoviewerdialog.cpp

#include "photoviewerdialog.h"

PhotoViewerDialog::PhotoViewerDialog(const QList<QPixmap> &pixmaps, int curPos, QSize fixedSize, QWidget *parent)
    : QDialog(parent), currentIndex(0) {
    layout = new QVBoxLayout(this);

    imageLabel = new QLabel(this);
    imageLabel->setPixmap(pixmaps[curPos]);
    imageLabel->setAlignment(Qt::AlignCenter);
    imageLabel->setFixedSize(fixedSize);
    layout->addWidget(imageLabel, 0, Qt::AlignCenter);

    prevButton = new QPushButton("Previous", this);
    nextButton = new QPushButton("Next", this);

    connect(prevButton, &QPushButton::clicked, this, &PhotoViewerDialog::showPreviousImage);
    connect(nextButton, &QPushButton::clicked, this, &PhotoViewerDialog::showNextImage);

    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(prevButton);
    buttonLayout->addWidget(nextButton);

    layout->addLayout(buttonLayout);

    setLayout(layout);

    currentIndex = curPos;
    images = pixmaps;
}

PhotoViewerDialog::PhotoViewerDialog(const PhotoViewerDialog &other)
    : QDialog(other.parentWidget()), currentIndex(other.currentIndex), centered(other.centered)
{
    layout = new QVBoxLayout(this);

    images = other.images;

    imageLabel = new QLabel(this);
    imageLabel->setPixmap(images[currentIndex]);
    layout->addWidget(imageLabel);

    prevButton = new QPushButton("Previous", this);
    nextButton = new QPushButton("Next", this);

    connect(prevButton, &QPushButton::clicked, this, &PhotoViewerDialog::showPreviousImage);
    connect(nextButton, &QPushButton::clicked, this, &PhotoViewerDialog::showNextImage);

    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(prevButton);
    buttonLayout->addWidget(nextButton);
    layout->addLayout(buttonLayout);

    setLayout(layout);
}


void PhotoViewerDialog::showEvent(QShowEvent *event) {
    QDialog::showEvent(event);
    if (!centered) {
        QRect screenGeometry = QApplication::desktop()->screenGeometry();
        int x = screenGeometry.center().x() - width() / 2;
        int y = screenGeometry.center().y() - height() / 2;
        move(x, y);
        centered = true;
    }
}

void PhotoViewerDialog::showPreviousImage() {
    if (currentIndex > 0) {
        currentIndex--;
        imageLabel->setPixmap(images[currentIndex]);
    }
}

void PhotoViewerDialog::showNextImage() {
    if (currentIndex < images.size() - 1) {
        currentIndex++;
        imageLabel->setPixmap(images[currentIndex]);
    }
}
