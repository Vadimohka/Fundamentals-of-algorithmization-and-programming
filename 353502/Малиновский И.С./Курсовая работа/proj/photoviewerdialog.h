#ifndef PHOTOVIEWERDIALOG_H
#define PHOTOVIEWERDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QPixmap>
#include <QDesktopWidget>
#include <QApplication>

class PhotoViewerDialog : public QDialog {
    Q_OBJECT

public:
    explicit PhotoViewerDialog(const QList<QPixmap> &pixmaps, int curPos, QSize fixedSize, QWidget *parent = nullptr);
    PhotoViewerDialog(const PhotoViewerDialog &other);

protected:
    void showEvent(QShowEvent *event) override;

private:
    QLabel *imageLabel;
    QPushButton *prevButton;
    QPushButton *nextButton;
    QVBoxLayout *layout;
    QList<QPixmap> images;
    int currentIndex;

    bool centered = false;

private slots:
    void showPreviousImage();
    void showNextImage();
};

#endif // PHOTOVIEWERDIALOG_H
