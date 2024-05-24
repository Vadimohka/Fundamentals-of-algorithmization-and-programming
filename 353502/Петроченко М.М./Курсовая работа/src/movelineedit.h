//
// Created by acryoz on 5/4/24.
//

#ifndef COURSEWORK_LIB_MOVELINEEDIT_H_
#define COURSEWORK_LIB_MOVELINEEDIT_H_

#include <QLineEdit>


QT_BEGIN_NAMESPACE

namespace Ui {
class MoveLineEdit;
}

QT_END_NAMESPACE

class MoveLineEdit : public QLineEdit {
    Q_OBJECT

   public:
    explicit MoveLineEdit(QWidget* parent = nullptr);
    ~MoveLineEdit() override;
    void mousePressEvent(QMouseEvent* ev) override;

   private:
    Ui::MoveLineEdit* ui;
};


#endif  //COURSEWORK_LIB_MOVELINEEDIT_H_
