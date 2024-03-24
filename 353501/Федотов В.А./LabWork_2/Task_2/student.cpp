#include "student.h"

Student::Student(QString lastName, QString firstName, QString middleName,
                 QString specialty, QString group, QString form, int marks[])
    : lastName_(lastName), firstName_(firstName), middleName_(middleName),
      specialty_(specialty), group_(group), form_(form)
      {
        for (int i = 0; i < SUBJECT_COUNT; i++)
          marks_[i] = marks[i];
      }

      QString Student::lastName() const { return lastName_; }
      QString Student::firstName() const { return firstName_; }
      QString Student::middleName() const { return middleName_; }
      QString Student::specialty() const { return specialty_; }
      QString Student::group() const { return group_; }
      QString Student::form() const { return form_; }
      int Student::mark(int SUBJECT) { return marks_[SUBJECT]; }

      void Student::setLastName(QString newValue) { lastName_ = newValue; }
      void Student::setFirstName(QString newValue) { firstName_ = newValue; }
      void Student::setMiddleName(QString newValue) { middleName_ = newValue; }
      void Student::setSpecialty(QString newValue) { specialty_ = newValue; }
      void Student::setGroup(QString newValue) { group_ = newValue; }
      void Student::setForm(QString newValue) { form_ = newValue; }
      void Student::setMark(int SUBJECT, int newValue) { marks_[SUBJECT] = newValue; }

double Student::averageMark() const {
    double avg = 0;
    for (auto &mark : marks_)
      avg +=  double(mark) / SUBJECT_COUNT;
    return avg;
}

bool Student::isBest() const {
    for (auto &mark : marks_) {
      if (mark < 9) return false;
    }
    return true;
}
