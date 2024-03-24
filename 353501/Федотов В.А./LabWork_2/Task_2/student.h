#pragma once

#include <QString>

class Student {
public:
  enum Subject {
    Logic,
    OAIP,
    History,
    MA,
    AGiLA,
    ML,
    SUBJECT_COUNT
  };

  Student(QString lastName, QString firstName, QString middleName,
          QString specialty, QString group, QString form, int marks[]);

  QString lastName() const;
  QString firstName() const;
  QString middleName() const;
  QString specialty() const;
  QString group() const;
  QString form() const;
  int mark(int SUBJECT);

  double averageMark() const;
  bool isBest() const;

  void setLastName(QString newValue);
  void setFirstName(QString newValue);
  void setMiddleName(QString newValue);
  void setSpecialty(QString newValue);
  void setGroup(QString newValue);
  void setForm(QString newValue);
  void setMark(int SUBJECT, int newValue);


private:
  QString lastName_;
  QString firstName_;
  QString middleName_;
  QString specialty_;
  QString group_;
  QString form_;
  int marks_[SUBJECT_COUNT]; // Array for subject marks
};