#ifndef ARRAYTABLE_H
#define ARRAYTABLE_H

#include <QTableWidget>
#include <QElapsedTimer>
#include <QWidget>
#include <QRandomGenerator>

QT_BEGIN_NAMESPACE
namespace Ui {
class ArrayTable;
}
QT_END_NAMESPACE

class ArrayTable : public QWidget
{
    Q_OBJECT

    const int MAX_SIZE = 1000;
    int *_array = new int[1];
    int _arrSize = 1;
    int _capacity = 1;
    bool _isReadOnly = false;
    Ui::ArrayTable *ui;

public:
    explicit ArrayTable(QWidget *parent = nullptr);
    ~ArrayTable() override;

    int *array() const;
    void setArray(int *newArray, int newArrSize);
    int arrSize() const;
    void setReadOnly(bool status);
    bool readOnle() const;

protected:
    void resizeEvent(QResizeEvent *event) override;

private:
    void showArray();

signals:
    void arrayChanged();

private slots:
    void slotResizeArray(int newSize);
    void slotChangeElement(int newValue);
    void slotRandomiseValues();
};

#endif // ARRAYTABLE_H
