#ifndef LAB5TASK1_KEYBOARD_H
#define LAB5TASK1_KEYBOARD_H

#include <QWidget>
#include <vector>
#include "QKeyEvent"
#include "QDebug"
#include "QString"
#include "QPushButton"
#include "QCoreApplication"


QT_BEGIN_NAMESPACE
namespace Ui { class Keyboard; }
QT_END_NAMESPACE

class Keyboard : public QWidget {
Q_OBJECT

    enum Language {
        German = 0,
        French = 1,
        Arabic = 2,
        Chinese = 3,
        Belorussian = 4,
        Hebrew = 5
    };

    void destroyAllFocuses();

    void updateKeyboard();

    void keyPressed(QPushButton *button, int key);

    bool isShift;

    Language language;

    std::vector<std::vector<QString>> languages;

public:
    explicit Keyboard(QWidget *parent = nullptr);

    ~Keyboard() override;

    void keyPressEvent(QKeyEvent *event) override;

    void keyReleaseEvent(QKeyEvent *event) override;

    void updateSelf(int index);

private slots:

    void on_extra_button_pressed();

    void on_extra_button_released();

    void on_number_button_1_pressed();

    void on_number_button_1_released();

    void on_number_button_2_pressed();

    void on_number_button_2_released();

    void on_number_button_3_pressed();

    void on_number_button_3_released();

    void on_number_button_4_pressed();

    void on_number_button_4_released();

    void on_number_button_5_pressed();

    void on_number_button_5_released();

    void on_number_button_6_pressed();

    void on_number_button_6_released();

    void on_number_button_7_pressed();

    void on_number_button_7_released();

    void on_number_button_8_pressed();

    void on_number_button_8_released();

    void on_number_button_9_pressed();

    void on_number_button_9_released();

    void on_number_button_10_pressed();

    void on_number_button_10_released();

    void on_number_button_11_pressed();

    void on_number_button_11_released();

    void on_number_button_12_pressed();

    void on_number_button_12_released();

    void on_shift_button_1_pressed();

    void on_shift_button_1_released();

    void on_shift_button_2_pressed();

    void on_shift_button_2_released();

    void on_space_button_pressed();

    void on_space_button_released();

    void on_symbol_button_1_pressed();

    void on_symbol_button_1_released();

    void on_symbol_button_2_pressed();

    void on_symbol_button_2_released();

    void on_symbol_button_3_pressed();

    void on_symbol_button_3_released();

    void on_symbol_button_4_pressed();

    void on_symbol_button_4_released();

    void on_symbol_button_5_pressed();

    void on_symbol_button_5_released();

    void on_symbol_button_6_pressed();

    void on_symbol_button_6_released();

    void on_symbol_button_7_pressed();

    void on_symbol_button_7_released();

    void on_symbol_button_8_pressed();

    void on_symbol_button_8_released();

    void on_symbol_button_9_pressed();

    void on_symbol_button_9_released();

    void on_symbol_button_10_pressed();

    void on_symbol_button_10_released();

    void on_symbol_button_11_pressed();

    void on_symbol_button_11_released();

    void on_symbol_button_12_pressed();

    void on_symbol_button_12_released();

    void on_symbol_button_13_pressed();

    void on_symbol_button_13_released();

    void on_symbol_button_14_pressed();

    void on_symbol_button_14_released();

    void on_symbol_button_15_pressed();

    void on_symbol_button_15_released();

    void on_symbol_button_16_pressed();

    void on_symbol_button_16_released();

    void on_symbol_button_17_pressed();

    void on_symbol_button_17_released();

    void on_symbol_button_18_pressed();

    void on_symbol_button_18_released();

    void on_symbol_button_19_pressed();

    void on_symbol_button_19_released();

    void on_symbol_button_20_pressed();

    void on_symbol_button_20_released();

    void on_symbol_button_21_pressed();

    void on_symbol_button_21_released();

    void on_symbol_button_22_pressed();

    void on_symbol_button_22_released();

    void on_symbol_button_23_pressed();

    void on_symbol_button_23_released();

    void on_symbol_button_24_pressed();

    void on_symbol_button_24_released();

    void on_symbol_button_25_pressed();

    void on_symbol_button_25_released();

    void on_symbol_button_26_pressed();

    void on_symbol_button_26_released();

    void on_symbol_button_27_pressed();

    void on_symbol_button_27_released();

    void on_symbol_button_28_pressed();

    void on_symbol_button_28_released();

    void on_symbol_button_29_pressed();

    void on_symbol_button_29_released();

    void on_symbol_button_30_pressed();

    void on_symbol_button_30_released();

    void on_symbol_button_31_pressed();

    void on_symbol_button_31_released();

    void on_symbol_button_32_pressed();

    void on_symbol_button_32_released();

    void on_symbol_button_33_pressed();

    void on_symbol_button_33_released();

signals:

    void keyToPrint(QString);

private:
    Ui::Keyboard *ui;
};


#endif //LAB5TASK1_KEYBOARD_H
