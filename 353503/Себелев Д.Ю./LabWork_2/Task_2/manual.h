#ifndef MANUAL_H
#define MANUAL_H

#include <QDialog>
#include <QVector>
#include <QRegularExpression>

#include "manualtemplate.h"

namespace Ui {
class Manual;
}

class Manual : public QDialog
{
    Q_OBJECT

public:
    explicit Manual(QWidget *parent = nullptr);
    ~Manual() override;

    int GetFuelConsumption(QString typeOfAirplane);
    QString GetFileName() { return filename; }
    QStringList GetTypesOfAirplanes();

public slots:
    void ChooseManual();
    void ReadFromManual(QString fileName);
    void ShowInTable(ManualTemplate tmp);

signals:
    void FileHasBeenRead();

private:
    Ui::Manual *ui;
    QVector<ManualTemplate> info;
    QRegularExpression regex;
    QString filename{""};
};

#endif // MANUAL_H
