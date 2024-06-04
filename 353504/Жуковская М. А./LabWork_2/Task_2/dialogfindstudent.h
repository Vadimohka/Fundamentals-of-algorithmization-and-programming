#ifndef DIALOGFINDSTUDENT_H
#define DIALOGFINDSTUDENT_H

#include <QDialog>

namespace Ui {
class DialogFindStudent;
}

class DialogFindStudent : public QDialog
{
    Q_OBJECT

public:
    explicit DialogFindStudent(QWidget *parent = nullptr);
    ~DialogFindStudent();

    QString getStudentsName();

private:
    Ui::DialogFindStudent *ui;
};

#endif // DIALOGFINDSTUDENT_H
