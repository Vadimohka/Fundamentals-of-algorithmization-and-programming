#ifndef FILEFUNCTIONS_H
#define FILEFUNCTIONS_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class FileFunctions;
}
QT_END_NAMESPACE

class FileFunctions : public QWidget
{
    Q_OBJECT

public:
    FileFunctions(QWidget *parent = nullptr);
    ~FileFunctions();

private:
    Ui::FileFunctions *ui;
};
#endif // FILEFUNCTIONS_H
