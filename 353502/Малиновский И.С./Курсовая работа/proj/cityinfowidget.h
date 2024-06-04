#ifndef CITYINFOWIDGET_H
#define CITYINFOWIDGET_H

#include <QWidget>
#include <QListWidget>
#include <QVBoxLayout>
#include "photoviewerdialog.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFile>
#include <QDebug>
#include <QScrollArea>

class CityInfoWidget : public QWidget {
    Q_OBJECT

public:
    CityInfoWidget(const QString &textLink, QStringList photosLinks, QWidget *parent = nullptr);
    CityInfoWidget(const CityInfoWidget &other);
    CityInfoWidget& operator=(const CityInfoWidget &other);

    void showInfo();

private:
    QVBoxLayout *layout;
    QListWidget *photoListWidget;
    QLabel *fullImageLabel, *textLabel;
    QVector<QPixmap> images;
    QString text;
    QStringList photosLinks;

private slots:
    void loadPhotos();
    QString readTextFromFile(const QString &filePath);
    void showFullImage(QListWidgetItem *item);
};

#endif // CITYINFOWIDGET_H
