#ifndef SAVENEWIMAGETOLIBARYDIALOG_H
#define SAVENEWIMAGETOLIBARYDIALOG_H

#include <QDialog>
#include <QObject>
#include <QPushButton>
#include <QLabel>
#include <QCheckBox>
#include <QLineEdit>
#include <QFileDialog>
#include <QMessageBox>

#include "filenamevalidaror.h"
#include "foldernamevalidator.h"

class SaveNewImageToLibaryDialog: public QDialog
{
    Q_OBJECT
public:
    SaveNewImageToLibaryDialog(int x, int y, QPixmap pixMap);
    QCheckBox* UseOldLibary;
    QPushButton* ChangeAdress;
    QLineEdit* nameOfFile;
    QLineEdit* nameOfLibary;
    QPushButton* SavePushButton;



    bool ans;
    QString initialPath;
    QString FileName;
    QPixmap pixMap;

    void Save();
public slots:
    void on_UseOldLibary_clicked();
    void on_ChangeAdress_clicked();
    void on_SavePushButton_clicked();

};

#endif // SAVENEWIMAGETOLIBARYDIALOG_H
