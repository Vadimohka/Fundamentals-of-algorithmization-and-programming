#ifndef DIALOGINPUTSTUDENT_H
#define DIALOGINPUTSTUDENT_H

#include <QDialog>
#include <QTimer>
#include <student.h>

namespace Ui {
class DialogInputStudent;
}

class DialogInputStudent : public QDialog
{
    Q_OBJECT

public:
    explicit DialogInputStudent(QWidget *parent = nullptr);
    ~DialogInputStudent();

    void changeGroupCombo();
    void changeSpecialityCombo();
    Student getStudentInfo();
    void setStudentInfo(Student student);

private:
    Ui::DialogInputStudent *ui;

    QList<QString> FACULTIES, FKSIS, IEF, FRE;
    QList<QString> GROUPS_KI, GROUPS_PI, GROUPS_IITP, GROUPS_IPD, GROUPS_IIUSFU, GROUPS_MIN, GROUPS_NIN, GROUPS_RIR;
    QList<QString> GROUPS_EE, GROUPS_ISIT;
};

#endif // DIALOGINPUTSTUDENT_H
