#ifndef ARRAYTABLE_H
#define ARRAYTABLE_H

#include <QTableWidget>
#include <QElapsedTimer>
#include <QWidget>
#include <QRandomGenerator>
#include <QVector>

QT_BEGIN_NAMESPACE
namespace Ui {
class ArrayTable;
}
QT_END_NAMESPACE

const int RAND_PRECISION = 1000;

class ArrayTable : public QWidget
{
    Q_OBJECT

    const int MAX_SIZE = 100000;

    QVector<float> _data;
    bool _isReadOnly = false;
    bool _isTableOnly = false;
    Ui::ArrayTable *ui;

public:
    explicit ArrayTable(QWidget *parent = nullptr);
    ~ArrayTable() override;

    QVector<float> vector() const;
    void setVector(const QVector<float> &newVector);
    int vectSize() const;
    void setReadOnly(bool status);
    bool readOnly() const;
    void setTableOnly(bool status);
    bool tableOnly() const;

protected:
    void resizeEvent(QResizeEvent *event) override;

private:
    void showVect();

signals:
    void vectorChanged();

private slots:
    void slotResizeArray(int newSize);
    void slotChangeElement(double newValue);
    void slotRandomiseValues();
};

#endif // ARRAYTABLE_H
