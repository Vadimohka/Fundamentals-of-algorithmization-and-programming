#include "cityinfowidget.h"

CityInfoWidget::CityInfoWidget(const QString &textLink, const QStringList photosLinks, QWidget *parent) : QWidget(parent), photosLinks(photosLinks) {
    // Создаем виджет-контейнер для всех компонентов
    QWidget *containerWidget = new QWidget();
    QVBoxLayout *containerLayout = new QVBoxLayout(containerWidget);

    QHBoxLayout *photoLayout = new QHBoxLayout();
    photoListWidget = new QListWidget(this);
    photoListWidget->setViewMode(QListView::IconMode);
    photoListWidget->setIconSize(QSize(300, 500));
    photoListWidget->setFlow(QListView::LeftToRight);
    photoListWidget->setWrapping(false);
    photoListWidget->setFixedSize(300, 500);
    photoLayout->addWidget(photoListWidget);

    fullImageLabel = new QLabel(this);
    containerLayout->addWidget(fullImageLabel);
    containerLayout->addLayout(photoLayout);

    text = readTextFromFile(textLink);
    textLabel = new QLabel(text);
    textLabel->setWordWrap(true);
    textLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    textLabel->setMaximumWidth(1920);

    containerLayout->addWidget(textLabel);
    containerLayout->addStretch();

    containerWidget->setLayout(containerLayout);

    // Создаем QScrollArea и добавляем в него контейнерный виджет
    QScrollArea *scrollArea = new QScrollArea(this);
    scrollArea->setWidget(containerWidget);
    scrollArea->setWidgetResizable(true);

    // Основной макет
    layout = new QVBoxLayout(this);
    layout->addWidget(scrollArea);
    setLayout(layout);

    loadPhotos();

    connect(photoListWidget, &QListWidget::itemClicked, this, &CityInfoWidget::showFullImage);
}

void CityInfoWidget::loadPhotos() {
    for (const QString &fileName : photosLinks) {
        QPixmap pixmap(fileName);
        if (!pixmap.isNull()) {
            images.append(pixmap);
            QListWidgetItem *item = new QListWidgetItem();
            item->setIcon(QIcon(pixmap));
            item->setData(Qt::UserRole, images.size() - 1);
            photoListWidget->addItem(item);
        }
    }
}

QString CityInfoWidget::readTextFromFile(const QString &filePath) {
    QString text;
    QFile file(filePath);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        text = in.readAll();
        file.close();
    }
    return text;
}

void CityInfoWidget::showFullImage(QListWidgetItem *item) {
    int index = item->data(Qt::UserRole).toInt();
    if (index >= 0 && index < images.size()) {
        QSize fixedSize(1600, 900);
        PhotoViewerDialog *dialog = new PhotoViewerDialog(images.toList(), index, fixedSize, this);
        dialog->show();
    }
}

void CityInfoWidget::showInfo() {
    setMinimumHeight(1080);
    QDesktopWidget desktop;
    QRect rect = desktop.availableGeometry(desktop.primaryScreen());
    QPoint center = rect.center();
    int x = center.x() - (width() / 2);
    int y = center.y() - (height() / 2);
    center.setX(x);
    center.setY(y);
    move(center);
    show();
}

CityInfoWidget::CityInfoWidget(const CityInfoWidget &other) : QWidget(other.parentWidget()), photosLinks(other.photosLinks) {
    for (const QPixmap &pixmap : other.images) {
        QPixmap copyPixmap(pixmap);
        images.append(copyPixmap);
    }

    text = other.text;

    // Создаем виджет-контейнер для всех компонентов
    QWidget *containerWidget = new QWidget();
    QVBoxLayout *containerLayout = new QVBoxLayout(containerWidget);

    photoListWidget = new QListWidget(this);
    photoListWidget->setViewMode(other.photoListWidget->viewMode());
    photoListWidget->setIconSize(other.photoListWidget->iconSize());
    photoListWidget->setFlow(other.photoListWidget->flow());
    photoListWidget->setWrapping(other.photoListWidget->isWrapping());
    for (int i = 0; i < other.photoListWidget->count(); ++i) {
        QListWidgetItem *item = other.photoListWidget->item(i);
        QListWidgetItem *copyItem = new QListWidgetItem(*item);
        photoListWidget->addItem(copyItem);
    }
    containerLayout->addWidget(photoListWidget);

    fullImageLabel = new QLabel(this);
    containerLayout->addWidget(fullImageLabel);

    textLabel = new QLabel(text);
    textLabel->setWordWrap(true);
    textLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    textLabel->setMaximumWidth(1000);
    containerLayout->addWidget(textLabel);
    containerLayout->addStretch();

    containerWidget->setLayout(containerLayout);

    // Создаем QScrollArea и добавляем в него контейнерный виджет
    QScrollArea *scrollArea = new QScrollArea(this);
    scrollArea->setWidget(containerWidget);
    scrollArea->setWidgetResizable(true);

    // Основной макет
    layout = new QVBoxLayout(this);
    layout->addWidget(scrollArea);
    setLayout(layout);

    connect(photoListWidget, &QListWidget::itemClicked, this, &CityInfoWidget::showFullImage);
}

CityInfoWidget& CityInfoWidget::operator=(const CityInfoWidget &other) {
    if (this == &other)
        return *this;

    delete layout;
    delete photoListWidget;
    delete fullImageLabel;
    delete textLabel;

    text = other.text;
    photosLinks = other.photosLinks;

    // Создаем виджет-контейнер для всех компонентов
    QWidget *containerWidget = new QWidget();
    QVBoxLayout *containerLayout = new QVBoxLayout(containerWidget);

    photoListWidget = new QListWidget(this);
    photoListWidget->setViewMode(other.photoListWidget->viewMode());
    photoListWidget->setIconSize(other.photoListWidget->iconSize());
    photoListWidget->setFlow(other.photoListWidget->flow());
    photoListWidget->setWrapping(other.photoListWidget->isWrapping());
    for (int i = 0; i < other.photoListWidget->count(); ++i) {
        QListWidgetItem *item = other.photoListWidget->item(i);
        QListWidgetItem *copyItem = new QListWidgetItem(*item);
        photoListWidget->addItem(copyItem);
    }
    photoListWidget->setFixedSize(300, 500);
    containerLayout->addWidget(photoListWidget);

    fullImageLabel = new QLabel(this);
    containerLayout->addWidget(fullImageLabel);

    textLabel = new QLabel(text);
    textLabel->setWordWrap(true);
    textLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    textLabel->setMaximumWidth(1000);
    containerLayout->addWidget(textLabel);
    containerLayout->addStretch();

    containerWidget->setLayout(containerLayout);

    // Создаем QScrollArea и добавляем в него контейнерный виджет
    QScrollArea *scrollArea = new QScrollArea(this);
    scrollArea->setWidget(containerWidget);
    scrollArea->setWidgetResizable(true);

    // Основной макет
    layout = new QVBoxLayout(this);
    layout->addWidget(scrollArea);
    setLayout(layout);

    connect(photoListWidget, &QListWidget::itemClicked, this, &CityInfoWidget::showFullImage);

    return *this;
}
