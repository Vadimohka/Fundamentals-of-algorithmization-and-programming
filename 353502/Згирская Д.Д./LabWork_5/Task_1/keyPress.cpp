#include "keyboard.h"
#include "ui_keyboard.h"

void Keyboard::on_extra_button_pressed() {
    ui->extra_button->setStyleSheet("background-color: rgb(0, 0, 0);");
    emit keyToPrint("ר");
}

void Keyboard::on_extra_button_released() {
    ui->extra_button->setStyleSheet("background-color: rgb(0, 0, 0);");
}

void Keyboard::on_number_button_1_pressed() {
    ui->number_button_1->setStyleSheet("background-color: rgb(0, 0, 0);");
    emit keyToPrint(ui->number_button_1->text());
}

void Keyboard::on_number_button_1_released() {
    ui->number_button_1->setStyleSheet("background-color: rgb(0, 0, 0);");
}

void Keyboard::on_number_button_2_pressed() {
    ui->number_button_2->setStyleSheet("background-color: rgb(0, 0, 0);");
    emit keyToPrint(ui->number_button_2->text());
}

void Keyboard::on_number_button_2_released() {
    ui->number_button_2->setStyleSheet("background-color: rgb(0, 0, 0);");
}


void Keyboard::on_number_button_3_pressed() {
    ui->number_button_3->setStyleSheet("background-color: rgb(0, 0, 0);");
    emit keyToPrint(ui->number_button_3->text());
}

void Keyboard::on_number_button_3_released() {
    ui->number_button_3->setStyleSheet("background-color: rgb(0, 0, 0);");
}


void Keyboard::on_number_button_4_pressed() {
    ui->number_button_4->setStyleSheet("background-color: rgb(0, 0, 0);");
    emit keyToPrint(ui->number_button_4->text());
}

void Keyboard::on_number_button_4_released() {
    ui->number_button_4->setStyleSheet("background-color: rgb(0, 0, 0);");
}


void Keyboard::on_number_button_5_pressed() {
    ui->number_button_5->setStyleSheet("background-color: rgb(0, 0, 0);");
    emit keyToPrint(ui->number_button_5->text());
}

void Keyboard::on_number_button_5_released() {
    ui->number_button_5->setStyleSheet("background-color: rgb(0, 0, 0);");
}


void Keyboard::on_number_button_6_pressed() {
    ui->number_button_6->setStyleSheet("background-color: rgb(0, 0, 0);");
    emit keyToPrint(ui->number_button_6->text());
}

void Keyboard::on_number_button_6_released() {
    ui->number_button_6->setStyleSheet("background-color: rgb(0, 0, 0);");
}


void Keyboard::on_number_button_7_pressed() {
    ui->number_button_7->setStyleSheet("background-color: rgb(0, 0, 0);");
    emit keyToPrint(ui->number_button_7->text());
}

void Keyboard::on_number_button_7_released() {
    ui->number_button_7->setStyleSheet("background-color: rgb(0, 0, 0);");
}


void Keyboard::on_number_button_8_pressed() {
    ui->number_button_8->setStyleSheet("background-color: rgb(0, 0, 0);");
    emit keyToPrint(ui->number_button_8->text());
}

void Keyboard::on_number_button_8_released() {
    ui->number_button_8->setStyleSheet("background-color: rgb(0, 0, 0);");
}


void Keyboard::on_number_button_9_pressed() {
    ui->number_button_9->setStyleSheet("background-color: rgb(0, 0, 0);");
    emit keyToPrint(ui->number_button_9->text());
}

void Keyboard::on_number_button_9_released() {
    ui->number_button_9->setStyleSheet("background-color: rgb(0, 0, 0);");
}


void Keyboard::on_number_button_10_pressed() {
    ui->number_button_10->setStyleSheet("background-color: rgb(0, 0, 0);");
    emit keyToPrint(ui->number_button_10->text());
}

void Keyboard::on_number_button_10_released() {
    ui->number_button_10->setStyleSheet("background-color: rgb(0, 0, 0);");
}


void Keyboard::on_number_button_11_pressed() {
    ui->number_button_11->setStyleSheet("background-color: rgb(0, 0, 0);");
    emit keyToPrint(ui->number_button_11->text());
}

void Keyboard::on_number_button_11_released() {
    ui->number_button_11->setStyleSheet("background-color: rgb(0, 0, 0);");
}

void Keyboard::on_number_button_12_pressed() {
    ui->number_button_12->setStyleSheet("background-color: rgb(0, 0, 0);");
    emit keyToPrint(ui->number_button_12->text());
}

void Keyboard::on_number_button_12_released() {
    ui->number_button_12->setStyleSheet("background-color: rgb(0, 0, 0);");
}

void Keyboard::on_shift_button_1_pressed() {
    ui->shift_button_1->setStyleSheet("background-color: grey;");
    isShift = true;
    updateKeyboard();
}

void Keyboard::on_shift_button_1_released() {
    ui->shift_button_1->setStyleSheet("");
    isShift = false;
    updateKeyboard();
}


void Keyboard::on_shift_button_2_pressed() {
    ui->shift_button_2->setStyleSheet("background-color: grey;");
    isShift = true;
    updateKeyboard();
}

void Keyboard::on_shift_button_2_released() {
    ui->shift_button_2->setStyleSheet("");
    isShift = false;
    updateKeyboard();
}


void Keyboard::on_space_button_pressed() {
    ui->space_button->setStyleSheet("background-color: grey;");
    emit keyToPrint(" ");
}

void Keyboard::on_space_button_released() {
    ui->space_button->setStyleSheet("");
}

void Keyboard::on_symbol_button_1_pressed() {
    ui->symbol_button_1->setStyleSheet("background-color: rgb(192, 192, 192);");
    emit keyToPrint(ui->symbol_button_1->text());
}

void Keyboard::on_symbol_button_1_released() {
    ui->symbol_button_1->setStyleSheet("background-color: rgb(0, 0, 0);");
}

void Keyboard::on_symbol_button_2_pressed() {
    ui->symbol_button_2->setStyleSheet("background-color: rgb(192, 192, 192);");
    emit keyToPrint(ui->symbol_button_2->text());
}

void Keyboard::on_symbol_button_2_released() {
    ui->symbol_button_2->setStyleSheet("background-color: rgb(0, 0, 0);");
}

void Keyboard::on_symbol_button_3_pressed() {
    ui->symbol_button_3->setStyleSheet("background-color: rgb(192, 192, 192);");
    emit keyToPrint(ui->symbol_button_3->text());
}

void Keyboard::on_symbol_button_3_released() {
    ui->symbol_button_3->setStyleSheet("background-color: rgb(0, 0, 0);");
}

void Keyboard::on_symbol_button_4_pressed() {
    ui->symbol_button_4->setStyleSheet("background-color: rgb(192, 192, 192);");
    emit keyToPrint(ui->symbol_button_4->text());
}

void Keyboard::on_symbol_button_4_released() {
    ui->symbol_button_4->setStyleSheet("background-color: rgb(0, 0, 0);");
}

void Keyboard::on_symbol_button_5_pressed() {
    ui->symbol_button_5->setStyleSheet("background-color: rgb(192, 192, 192);");
    emit keyToPrint(ui->symbol_button_5->text());
}

void Keyboard::on_symbol_button_5_released() {
    ui->symbol_button_5->setStyleSheet("background-color: rgb(0, 0, 0);");
}

void Keyboard::on_symbol_button_6_pressed() {
    ui->symbol_button_6->setStyleSheet("background-color: rgb(192, 192, 192);");
    emit keyToPrint(ui->symbol_button_6->text());
}

void Keyboard::on_symbol_button_6_released() {
    ui->symbol_button_6->setStyleSheet("background-color: rgb(0, 0, 0);");
}

void Keyboard::on_symbol_button_7_pressed() {
    ui->symbol_button_7->setStyleSheet("background-color: rgb(192, 192, 192);");
    emit keyToPrint(ui->symbol_button_7->text());
}

void Keyboard::on_symbol_button_7_released() {
    ui->symbol_button_7->setStyleSheet("background-color: rgb(0, 0, 0);");
}

void Keyboard::on_symbol_button_8_pressed() {
    ui->symbol_button_8->setStyleSheet("background-color: rgb(192, 192, 192);");
    emit keyToPrint(ui->symbol_button_8->text());
}

void Keyboard::on_symbol_button_8_released() {
    ui->symbol_button_8->setStyleSheet("background-color: rgb(0, 0, 0);");
}

void Keyboard::on_symbol_button_9_pressed() {
    ui->symbol_button_9->setStyleSheet("background-color: rgb(192, 192, 192);");
    emit keyToPrint(ui->symbol_button_9->text());
}

void Keyboard::on_symbol_button_9_released() {
    ui->symbol_button_9->setStyleSheet("background-color: rgb(0, 0, 0);");
}

void Keyboard::on_symbol_button_10_pressed() {
    ui->symbol_button_10->setStyleSheet("background-color: rgb(192, 192, 192);");
    emit keyToPrint(ui->symbol_button_10->text());
}

void Keyboard::on_symbol_button_10_released() {
    ui->symbol_button_10->setStyleSheet("background-color: rgb(0, 0, 0);");
}

void Keyboard::on_symbol_button_11_pressed() {
    ui->symbol_button_11->setStyleSheet("background-color: rgb(192, 192, 192);");
    emit keyToPrint(ui->symbol_button_11->text());
}

void Keyboard::on_symbol_button_11_released() {
    ui->symbol_button_11->setStyleSheet("background-color: rgb(0, 0, 0);");
}

void Keyboard::on_symbol_button_12_pressed() {
    ui->symbol_button_12->setStyleSheet("background-color: rgb(192, 192, 192);");
    emit keyToPrint(ui->symbol_button_12->text());
}

void Keyboard::on_symbol_button_12_released() {
    ui->symbol_button_12->setStyleSheet("background-color: rgb(0, 0, 0);");
}

void Keyboard::on_symbol_button_13_pressed() {
    ui->symbol_button_13->setStyleSheet("background-color: rgb(192, 192, 192);");
    emit keyToPrint(ui->symbol_button_13->text());
}

void Keyboard::on_symbol_button_13_released() {
    ui->symbol_button_13->setStyleSheet("background-color: rgb(0, 0, 0);");
}

void Keyboard::on_symbol_button_14_pressed() {
    ui->symbol_button_14->setStyleSheet("background-color: rgb(192, 192, 192);");
    emit keyToPrint(ui->symbol_button_14->text());
}

void Keyboard::on_symbol_button_14_released() {
    ui->symbol_button_14->setStyleSheet("background-color: rgb(0, 0, 0);");
}

void Keyboard::on_symbol_button_15_pressed() {
    ui->symbol_button_15->setStyleSheet("background-color: rgb(192, 192, 192);");
    emit keyToPrint(ui->symbol_button_15->text());
}

void Keyboard::on_symbol_button_15_released() {
    ui->symbol_button_15->setStyleSheet("background-color: rgb(0, 0, 0);");
}

void Keyboard::on_symbol_button_16_pressed() {
    ui->symbol_button_16->setStyleSheet("background-color: rgb(192, 192, 192);");
    emit keyToPrint(ui->symbol_button_16->text());
}

void Keyboard::on_symbol_button_16_released() {
    ui->symbol_button_16->setStyleSheet("background-color: rgb(0, 0, 0);");
}

void Keyboard::on_symbol_button_17_pressed() {
    ui->symbol_button_17->setStyleSheet("background-color: rgb(192, 192, 192);");
    emit keyToPrint(ui->symbol_button_17->text());
}

void Keyboard::on_symbol_button_17_released() {
    ui->symbol_button_17->setStyleSheet("background-color: rgb(0, 0, 0);");
}

void Keyboard::on_symbol_button_18_pressed() {
    ui->symbol_button_18->setStyleSheet("background-color: rgb(192, 192, 192);");
    emit keyToPrint(ui->symbol_button_18->text());
}

void Keyboard::on_symbol_button_18_released() {
    ui->symbol_button_18->setStyleSheet("background-color: rgb(0, 0, 0);");
}

void Keyboard::on_symbol_button_19_pressed() {
    ui->symbol_button_19->setStyleSheet("background-color: rgb(192, 192, 192);");
    emit keyToPrint(ui->symbol_button_19->text());
}

void Keyboard::on_symbol_button_19_released() {
    ui->symbol_button_19->setStyleSheet("background-color: rgb(0, 0, 0);");
}

void Keyboard::on_symbol_button_20_pressed() {
    ui->symbol_button_20->setStyleSheet("background-color: rgb(192, 192, 192);");
    emit keyToPrint(ui->symbol_button_20->text());
}

void Keyboard::on_symbol_button_20_released() {
    ui->symbol_button_20->setStyleSheet("background-color: rgb(0, 0, 0);");
}

void Keyboard::on_symbol_button_21_pressed() {
    ui->symbol_button_21->setStyleSheet("background-color: rgb(192, 192, 192);");
    emit keyToPrint(ui->symbol_button_21->text());
}

void Keyboard::on_symbol_button_21_released() {
    ui->symbol_button_21->setStyleSheet("background-color: rgb(0, 0, 0);");
}

void Keyboard::on_symbol_button_22_pressed() {
    ui->symbol_button_22->setStyleSheet("background-color: rgb(192, 192, 192);");
    emit keyToPrint(ui->symbol_button_22->text());
}

void Keyboard::on_symbol_button_22_released() {
    ui->symbol_button_22->setStyleSheet("background-color: rgb(0, 0, 0);");
}

void Keyboard::on_symbol_button_23_pressed() {
    ui->symbol_button_23->setStyleSheet("background-color: rgb(192, 192, 192);");
    emit keyToPrint(ui->symbol_button_23->text());
}

void Keyboard::on_symbol_button_23_released() {
    ui->symbol_button_23->setStyleSheet("background-color: rgb(0, 0, 0);");
}

void Keyboard::on_symbol_button_24_pressed() {
    ui->symbol_button_24->setStyleSheet("background-color: rgb(192, 192, 192);");
    emit keyToPrint(ui->symbol_button_24->text());
}

void Keyboard::on_symbol_button_24_released() {
    ui->symbol_button_24->setStyleSheet("background-color: rgb(0, 0, 0);");
}

void Keyboard::on_symbol_button_25_pressed() {
    ui->symbol_button_25->setStyleSheet("background-color: rgb(192, 192, 192);");
    emit keyToPrint(ui->symbol_button_25->text());
}

void Keyboard::on_symbol_button_25_released() {
    ui->symbol_button_25->setStyleSheet("background-color: rgb(0, 0, 0);");
}

void Keyboard::on_symbol_button_26_pressed() {
    ui->symbol_button_26->setStyleSheet("background-color: rgb(192, 192, 192);");
    emit keyToPrint(ui->symbol_button_26->text());
}

void Keyboard::on_symbol_button_26_released() {
    ui->symbol_button_26->setStyleSheet("background-color: rgb(0, 0, 0);");
}

void Keyboard::on_symbol_button_27_pressed() {
    ui->symbol_button_27->setStyleSheet("background-color: rgb(192, 192, 192);");
    emit keyToPrint(ui->symbol_button_27->text());
}

void Keyboard::on_symbol_button_27_released() {
    ui->symbol_button_27->setStyleSheet("background-color: rgb(0, 0, 0);");
}

void Keyboard::on_symbol_button_28_pressed() {
    ui->symbol_button_28->setStyleSheet("background-color: rgb(192, 192, 192);");
    emit keyToPrint(ui->symbol_button_28->text());
}

void Keyboard::on_symbol_button_28_released() {
    ui->symbol_button_28->setStyleSheet("background-color: rgb(0, 0, 0);");
}

void Keyboard::on_symbol_button_29_pressed() {
    ui->symbol_button_29->setStyleSheet("background-color: rgb(192, 192, 192);");
    emit keyToPrint(ui->symbol_button_29->text());
}

void Keyboard::on_symbol_button_29_released() {
    ui->symbol_button_29->setStyleSheet("background-color: rgb(0, 0, 0);");
}

void Keyboard::on_symbol_button_30_pressed() {
    ui->symbol_button_30->setStyleSheet("background-color: rgb(192, 192, 192);");
    emit keyToPrint(ui->symbol_button_30->text());
}

void Keyboard::on_symbol_button_30_released() {
    ui->symbol_button_30->setStyleSheet("background-color: rgb(0, 0, 0);");
}

void Keyboard::on_symbol_button_31_pressed() {
    ui->symbol_button_31->setStyleSheet("background-color: rgb(192, 192, 192);");
    emit keyToPrint(ui->symbol_button_31->text());
}

void Keyboard::on_symbol_button_31_released() {
    ui->symbol_button_31->setStyleSheet("background-color: rgb(0, 0, 0);");
}

void Keyboard::on_symbol_button_32_pressed() {
    ui->symbol_button_32->setStyleSheet("background-color: rgb(192, 192, 192);");
    emit keyToPrint(ui->symbol_button_32->text());
}

void Keyboard::on_symbol_button_32_released() {
    ui->symbol_button_32->setStyleSheet("background-color: rgb(0, 0, 0);");
}

void Keyboard::on_symbol_button_33_pressed() {
    ui->symbol_button_33->setStyleSheet("background-color: rgb(192, 192, 192);");
    emit keyToPrint(ui->symbol_button_33->text());
}

void Keyboard::on_symbol_button_33_released() {
    ui->symbol_button_33->setStyleSheet("background-color: rgb(0, 0, 0);");
}

void Keyboard::destroyAllFocuses() {
    ui->extra_button->setFocusPolicy(Qt::NoFocus);
    ui->number_button_1->setFocusPolicy(Qt::NoFocus);
    ui->number_button_2->setFocusPolicy(Qt::NoFocus);
    ui->number_button_3->setFocusPolicy(Qt::NoFocus);
    ui->number_button_4->setFocusPolicy(Qt::NoFocus);
    ui->number_button_5->setFocusPolicy(Qt::NoFocus);
    ui->number_button_6->setFocusPolicy(Qt::NoFocus);
    ui->number_button_7->setFocusPolicy(Qt::NoFocus);
    ui->number_button_8->setFocusPolicy(Qt::NoFocus);
    ui->number_button_9->setFocusPolicy(Qt::NoFocus);
    ui->number_button_10->setFocusPolicy(Qt::NoFocus);
    ui->number_button_11->setFocusPolicy(Qt::NoFocus);
    ui->number_button_12->setFocusPolicy(Qt::NoFocus);
    ui->symbol_button_1->setFocusPolicy(Qt::NoFocus);
    ui->symbol_button_2->setFocusPolicy(Qt::NoFocus);
    ui->symbol_button_3->setFocusPolicy(Qt::NoFocus);
    ui->symbol_button_4->setFocusPolicy(Qt::NoFocus);
    ui->symbol_button_5->setFocusPolicy(Qt::NoFocus);
    ui->symbol_button_6->setFocusPolicy(Qt::NoFocus);
    ui->symbol_button_7->setFocusPolicy(Qt::NoFocus);
    ui->symbol_button_8->setFocusPolicy(Qt::NoFocus);
    ui->symbol_button_9->setFocusPolicy(Qt::NoFocus);
    ui->symbol_button_10->setFocusPolicy(Qt::NoFocus);
    ui->symbol_button_11->setFocusPolicy(Qt::NoFocus);
    ui->symbol_button_12->setFocusPolicy(Qt::NoFocus);
    ui->symbol_button_13->setFocusPolicy(Qt::NoFocus);
    ui->symbol_button_14->setFocusPolicy(Qt::NoFocus);
    ui->symbol_button_15->setFocusPolicy(Qt::NoFocus);
    ui->symbol_button_16->setFocusPolicy(Qt::NoFocus);
    ui->symbol_button_17->setFocusPolicy(Qt::NoFocus);
    ui->symbol_button_18->setFocusPolicy(Qt::NoFocus);
    ui->symbol_button_19->setFocusPolicy(Qt::NoFocus);
    ui->symbol_button_20->setFocusPolicy(Qt::NoFocus);
    ui->symbol_button_21->setFocusPolicy(Qt::NoFocus);
    ui->symbol_button_22->setFocusPolicy(Qt::NoFocus);
    ui->symbol_button_23->setFocusPolicy(Qt::NoFocus);
    ui->symbol_button_24->setFocusPolicy(Qt::NoFocus);
    ui->symbol_button_25->setFocusPolicy(Qt::NoFocus);
    ui->symbol_button_26->setFocusPolicy(Qt::NoFocus);
    ui->symbol_button_27->setFocusPolicy(Qt::NoFocus);
    ui->symbol_button_28->setFocusPolicy(Qt::NoFocus);
    ui->symbol_button_29->setFocusPolicy(Qt::NoFocus);
    ui->symbol_button_30->setFocusPolicy(Qt::NoFocus);
    ui->symbol_button_31->setFocusPolicy(Qt::NoFocus);
    ui->symbol_button_32->setFocusPolicy(Qt::NoFocus);
    ui->symbol_button_33->setFocusPolicy(Qt::NoFocus);
    ui->shift_button_1->setFocusPolicy(Qt::NoFocus);
    ui->shift_button_2->setFocusPolicy(Qt::NoFocus);
    ui->space_button->setFocusPolicy(Qt::NoFocus);
}

void Keyboard::updateSelf(int index) {
    language = Language(index);
    updateKeyboard();
}
