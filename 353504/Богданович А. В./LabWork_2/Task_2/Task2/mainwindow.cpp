#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    deactivateEditBtns();
    ui->label_96->hide();
    ui->label_13->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::isGroupExist(QString group) {
    for (int i = 0; i < groupsCount; i++) {
        if (group == groups[i]) {
            return true;
        }
    }

    return false;
}

void MainWindow::deactivateEditBtns() {
    ui->fioEdit_line->setEnabled(false);
    ui->specEdit_line->setEnabled(false);
    ui->groupEdit_line->setEnabled(false);
    ui->oaipEdit_spinBox->setEnabled(false);
    ui->maEdit_spinBox->setEnabled(false);
    ui->agilaEdit_spinBox->setEnabled(false);
    ui->mlEdit_spinBOx->setEnabled(false);
    ui->historyEdit_spinBox->setEnabled(false);
    ui->edit_button->setEnabled(false);
    ui->delete_button->setEnabled(false);
}

void MainWindow::activateEditBtns() {
    ui->fioEdit_line->setEnabled(true);
    ui->specEdit_line->setEnabled(true);
    ui->groupEdit_line->setEnabled(true);
    ui->oaipEdit_spinBox->setEnabled(true);
    ui->maEdit_spinBox->setEnabled(true);
    ui->agilaEdit_spinBox->setEnabled(true);
    ui->mlEdit_spinBOx->setEnabled(true);
    ui->historyEdit_spinBox->setEnabled(true);
    ui->edit_button->setEnabled(true);
    ui->delete_button->setEnabled(true);
}

void MainWindow::addError(QString errorMessage) {
    QMessageBox::critical(nullptr, "Ошибка", errorMessage);

}

void MainWindow::clearForm() {
    ui->fioAdd_line->clear();
    ui->specAdd_line->clear();
    ui->groupAdd_line->clear();
    ui->oaipAdd_spinBox->setValue(0);
    ui->maAdd_spinBox->setValue(0);
    ui->agilaAdd_spinBox->setValue(0);
    ui->mlAdd_spinBox->setValue(0);
    ui->hisoryAdd_spinBox->setValue(0);
}

void MainWindow::clearEditForm() {
    ui->fioEdit_line->clear();
    ui->specEdit_line->clear();
    ui->groupEdit_line->clear();
    ui->oaipEdit_spinBox->setValue(0);
    ui->maEdit_spinBox->setValue(0);
    ui->agilaEdit_spinBox->setValue(0);
    ui->mlEdit_spinBOx->setValue(0);
    ui->historyEdit_spinBox->setValue(0);
}



void MainWindow::on_AddButton_clicked()
{
    QString errorMessage = "";

    bool isErr = false;
    QString name = ui->fioAdd_line->text();
    QString spec = ui->specAdd_line->text();
    QString group = ui->groupAdd_line->text();
    int oaip_mark = ui->oaipAdd_spinBox->value();
    int ma_mark = ui->maAdd_spinBox->value();
    int agila_mark = ui->agilaAdd_spinBox->value();
    int ml_mark = ui->mlAdd_spinBox->value();
    int hist_mark = ui->hisoryAdd_spinBox->value();

    int row = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(row);

    students[row] = Student(name, spec, group, oaip_mark, ma_mark, agila_mark, ml_mark, hist_mark);

    if (students[row].isNameCorrect()) {
        QTableWidgetItem *col1Item = new QTableWidgetItem(name);
        ui->tableWidget->setItem(row,0,col1Item);
    } else {
        errorMessage += "Оишбка в написании ФИО!\nФИО должно содержать только буквы\nВаше написание: "+name+"\nПример правильного написания: Богданович Андрей Валерьевич";
        isErr = true;
    }
    if (students[row].isSpecCorrect()) {
        QTableWidgetItem *col2Item = new QTableWidgetItem(spec);
        ui->tableWidget->setItem(row,1,col2Item);
    } else {
        if (!errorMessage.isEmpty()) {
            errorMessage += "\n\n";
        }
        errorMessage += "Ошибка в написании наименования специальности!\nНаименование специальности должно содержать только буквы\nВаше написание: "+spec+"\nПример правильного написания: ИиТП";
        isErr = true;
    }
    if (students[row].isGroupCorrect()){
        QTableWidgetItem *col3Item = new QTableWidgetItem(group);
        ui->tableWidget->setItem(row,2,col3Item);
    } else {
        if (!errorMessage.isEmpty()) {
            errorMessage += "\n\n";
        }
        errorMessage += "Ошибка в написании номера группы!\nНомер группы состоит из 6 цифр\nВаше написание: "+group+"\nПример правильного написания: 353504";
        isErr = true;
    }
    if (!isErr) {
        QTableWidgetItem *col4Item = new QTableWidgetItem(QString::number(students[row].averageMark(), 'f', 1));
        ui->tableWidget->setItem(row,3,col4Item);
    }

    if (isErr) {
        ui->tableWidget->removeRow(row);
        addError(errorMessage);
    } else {
        ui->studentSelect_comboBox->addItem(QString::number(row+1)+") "+students[row].getInitials());
        if (!isGroupExist(group)) {
            groups[groupsCount] = group;
            groupsCount++;
            ui->selectGroup_comboBox->addItem(group);
        }
        studentsCount++;
        clearForm();
    }
}


void MainWindow::on_studentSelect_comboBox_currentIndexChanged(int i)
{
    curInd = i - 1;

    if (i == 0) {
        clearEditForm();
        deactivateEditBtns();
    } else {
        activateEditBtns();
        if (ui->selectGroup_comboBox->currentIndex() != 0) {
            ui->fioEdit_line->setText(filtered[i-1].getName());
            ui->specEdit_line->setText(filtered[i-1].getSpec());
            ui->groupEdit_line->setText(filtered[i-1].getGroup());
            ui->oaipEdit_spinBox->setValue(filtered[i-1].getOaip());
            ui->maEdit_spinBox->setValue(filtered[i-1].getMa());
            ui->agilaEdit_spinBox->setValue(filtered[i-1].getAgila());
            ui->mlEdit_spinBOx->setValue(filtered[i-1].getMl());
            ui->historyEdit_spinBox->setValue(filtered[i-1].getHist());
        } else {
            ui->fioEdit_line->setText(students[i-1].getName());
            ui->specEdit_line->setText(students[i-1].getSpec());
            ui->groupEdit_line->setText(students[i-1].getGroup());
            ui->oaipEdit_spinBox->setValue(students[i-1].getOaip());
            ui->maEdit_spinBox->setValue(students[i-1].getMa());
            ui->agilaEdit_spinBox->setValue(students[i-1].getAgila());
            ui->mlEdit_spinBOx->setValue(students[i-1].getMl());
            ui->historyEdit_spinBox->setValue(students[i-1].getHist());
        }
    }
}


void MainWindow::on_edit_button_clicked()
{
    QString errorMessage = "";

    bool isErr = false;
    bool isDelete = false;

    Student st_backup = students[curInd];

    QString name = ui->fioEdit_line->text();
    QString spec = ui->specEdit_line->text();
    QString backupGroup = students[curInd].getGroup();
    QString group = ui->groupEdit_line->text();
    int oaip_mark = ui->oaipEdit_spinBox->value();
    int ma_mark = ui->maEdit_spinBox->value();
    int agila_mark = ui->agilaEdit_spinBox->value();
    int ml_mark = ui->mlEdit_spinBOx->value();
    int hist_mark = ui->historyEdit_spinBox->value();

    if (isGroupCorrect(group)) {
        if (!isGroupExist(group)) {
            groups[groupsCount] = group;
            groupsCount++;
            ui->selectGroup_comboBox->addItem(group);
        }

        if (ui->selectGroup_comboBox->currentIndex() == 0) {
            students[curInd] = Student(name, spec, group, oaip_mark, ma_mark, agila_mark, ml_mark, hist_mark);
            bool isStill = false;
            for (int i = 0; i < studentsCount; i++) {
                if (group == students[i].getGroup()) {
                    if (i == curInd) {
                        continue;
                    }
                    isStill = true;
                    break;
                }
            }

            int ind = 0;
            if (!isStill) {
                for (int i = 0; i < groupsCount; i++) {
                    if (backupGroup == groups[i]) {
                        ind = i;
                        for (int j = i; j < groupsCount - 1; j++) {
                            groups[i] = groups[i + 1];
                        }
                        groupsCount--;
                        break;
                    }
                }
                ui->selectGroup_comboBox->removeItem(ind+1);
            }
        } else {
            for (int i = 0; i < studentsCount; i++) {
                if (students[i] == filtered[curInd]) {
                    students[i] = Student(name, spec, group, oaip_mark, ma_mark, agila_mark, ml_mark, hist_mark);
                    break;
                }
            }
            if (group == ui->selectGroup_comboBox->currentText()) {
                filtered[curInd] = Student(name, spec, group, oaip_mark, ma_mark, agila_mark, ml_mark, hist_mark);
            } else {

                isDelete = true;

                for (int i = curInd; i < filteredCount - 1; i++) {
                    filtered[i] = filtered[i + 1];
                }
                filteredCount--;

                ui->studentSelect_comboBox->removeItem(curInd+1);

                for (int i = 1; i < filteredCount+1; i++) {
                    ui->studentSelect_comboBox->setItemText(i, QString::number(i)+") "+filtered[i-1].getInitials());
                }

                if (filteredCount == 0) {
                    int ind = ui->selectGroup_comboBox->currentIndex();
                    ui->selectGroup_comboBox->setCurrentIndex(0);
                    ui->selectGroup_comboBox->removeItem(ind);
                    return;
                }
            }

        }
    } else {
        students[curInd] = Student(name, spec, group, oaip_mark, ma_mark, agila_mark, ml_mark, hist_mark);
    }

    if (students[curInd].isNameCorrect()) {
        QTableWidgetItem *col1Item = new QTableWidgetItem(name);
        ui->tableWidget->setItem(curInd,0,col1Item);
    } else {
        errorMessage += "Оишбка в написании ФИО!\nФИО должно содержать только буквы\nВаше написание: "+name+"\nПример правильного написания: Богданович Андрей Валерьевич";
        isErr = true;
    }
    if (students[curInd].isSpecCorrect()) {
        QTableWidgetItem *col2Item = new QTableWidgetItem(spec);
        ui->tableWidget->setItem(curInd,1,col2Item);
    } else {
        if (!errorMessage.isEmpty()) {
            errorMessage += "\n\n";
        }
        errorMessage += "Ошибка в написании наименования специальности!\nНаименование специальности должно содержать только буквы\nВаше написание: "+spec+"\nПример правильного написания: ИиТП";
        isErr = true;
    }
    if (students[curInd].isGroupCorrect()){
        QTableWidgetItem *col3Item = new QTableWidgetItem(group);
        ui->tableWidget->setItem(curInd,2,col3Item);
    } else {
        if (!errorMessage.isEmpty()) {
            errorMessage += "\n\n";
        }
        errorMessage += "Ошибка в написании номера группы!\nНомер группы состоит из 6 цифр\nВаше написание: "+group+"\nПример правильного написания: 353504";
        isErr = true;
    }
    if (!isErr) {
        QTableWidgetItem *col4Item;
        if (ui->selectGroup_comboBox->currentIndex() == 0) {
            col4Item = new QTableWidgetItem(QString::number(students[curInd].averageMark(), 'f', 1));
        } else {
            col4Item = new QTableWidgetItem(QString::number(filtered[curInd].averageMark(), 'f', 1));
        }
        ui->tableWidget->setItem(curInd,3,col4Item);
    }

    if (isDelete) {
        ui->tableWidget->removeRow(curInd);
    }

    if (isErr) {
        students[curInd] = st_backup;
        addError(errorMessage);

    } else {
        ui->studentSelect_comboBox->setItemText(curInd+1, QString::number(curInd+1)+") "+students[curInd].getInitials());
        ui->studentSelect_comboBox->setCurrentIndex(0);
    }

}


void MainWindow::on_delete_button_clicked()
{
    int rowCount = ui->tableWidget->rowCount();

    QString currentGroup = students[curInd].getGroup();

    if (ui->selectGroup_comboBox->currentIndex() == 0) {
        ui->tableWidget->removeRow(curInd);

        for (int i = curInd; i < rowCount; i++) {
            students[i] = students[i+1];
        }

        ui->studentSelect_comboBox->removeItem(curInd+1);
        ui->studentSelect_comboBox->setCurrentIndex(0);

        for (int i = 1; i < rowCount; i++) {
            ui->studentSelect_comboBox->setItemText(i, QString::number(i)+") "+students[i-1].getInitials());
        }

        studentsCount--;
    } else {
        ui->tableWidget->removeRow(curInd);

        qDebug() << curInd;


        for (int i = 0; i < studentsCount; i++) {
            if (students[i] == filtered[curInd]) {
                for (int j = i; j < studentsCount; j++) {
                    students[j] = students[j+1];
                }
                break;
            }
        }

        studentsCount--;

        for (int i = curInd; i < filteredCount; i++) {
            filtered[i] = filtered[i+1];
        }

        ui->studentSelect_comboBox->removeItem(curInd+1);
        ui->studentSelect_comboBox->setCurrentIndex(0);

        for (int i = 1; i < filteredCount; i++) {
            ui->studentSelect_comboBox->setItemText(i, QString::number(i)+") "+filtered[i-1].getInitials());
        }

        filteredCount--;



        if (filteredCount == 0) {
            for(int i = 0; i < groupsCount; i++) {
                if (groups[i] == currentGroup) {
                    for (int j = i; j < groupsCount - 1; j++) {
                        groups[j] = groups[j + 1];
                    }
                    groupsCount--;

                    int ind = ui->selectGroup_comboBox->currentIndex();
                    ui->selectGroup_comboBox->setCurrentIndex(0);
                    ui->selectGroup_comboBox->removeItem(ind);
                    break;
                }
            }
        }
    }



    bool isStillExist = false;
    for (int i = 0; i < studentsCount - 1; i++) {
        if (students[i].getGroup() == currentGroup) {
            isStillExist = true;
        }
    }

    if (!isStillExist) {
        for(int i = 0; i < groupsCount; i++) {
            if (groups[i] == currentGroup) {
                for (int j = i; j < groupsCount - 1; j++) {
                    groups[j] = groups[j + 1];
                }

                ui->selectGroup_comboBox->setCurrentIndex(0);
                ui->selectGroup_comboBox->removeItem(i+1);
                groupsCount--;


                break;
            }
        }
    }
}


void MainWindow::on_saveFile_button_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Сохранить файл"), "../Task2/Files", tr("Все файлы (*)"));
    int count = ui->tableWidget->rowCount();


    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (file.open(QIODevice::WriteOnly)) {
            QTextStream out(&file);
            for (int i = 0; i < count; i ++) {
                out << students[i].getName() << ";"
                    << students[i].getSpec() << ";"
                    << students[i].getGroup() << ";"
                    << QString::number(students[i].getMa()) << ";"
                    << QString::number(students[i].getOaip()) << ";"
                    << QString::number(students[i].getAgila()) << ";"
                    << QString::number(students[i].getMl()) << ";"
                    << QString::number(students[i].getHist()) << ";\n";
            }
            file.close();
        }
    }

}


void MainWindow::on_openFile_button_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Открыть файл"), "../Task2/Files", tr("Все файлы (*)"));


    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (file.open(QIODevice::ReadOnly)) {
            ui->studentSelect_comboBox->setCurrentIndex(0);
            ui->selectGroup_comboBox->setCurrentIndex(0);
            delete[] students;
            students = new Student[100];
            delete[] groups;
            groups = new QString[50];

            int sz = ui->tableWidget->rowCount();
            ui->tableWidget->setRowCount(0);

            for (int i = 0; i < sz; i++) {
                ui->studentSelect_comboBox->removeItem(1);
            }

            for (int i = 0; i < groupsCount; i++) {
                ui->selectGroup_comboBox->removeItem(1);
            }
            groupsCount = 0;
            int c = 0;

            QTextStream in(&file);
            while (!in.atEnd()) {
                QString name = "", spec = "", group = "", oaip_mark = "", ma_mark = "", agila_mark = "", ml_mark = "", hist_mark = "";
                QString line = in.readLine();
                int i = 0;

                while (line[i] != ';') {
                    name += line[i];
                    i++;
                }

                i++;
                while (line[i] != ';') {
                    spec += line[i];
                    i++;
                }

                i++;
                while(line[i] != ';') {
                    group += line[i];
                    i++;
                }

                i++;
                while(line[i] != ';') {
                    oaip_mark += line[i];
                    i++;
                }

                i++;
                while(line[i] != ';') {
                    ma_mark += line[i];
                    i++;
                }

                i++;
                while(line[i] != ';') {
                    agila_mark += line[i];
                    i++;
                }

                i++;
                while(line[i] != ';') {
                    ml_mark += line[i];
                    i++;
                }

                i++;
                while(line[i] != ';') {
                    hist_mark += line[i];
                    i++;
                }

                students[c] = Student(name, spec, group, oaip_mark.toInt(), ma_mark.toInt(), agila_mark.toInt(), ml_mark.toInt(), hist_mark.toInt());

                ui->tableWidget->insertRow(c);
                QTableWidgetItem *col1Item = new QTableWidgetItem(name);
                ui->tableWidget->setItem(c,0,col1Item);
                QTableWidgetItem *col2Item = new QTableWidgetItem(spec);
                ui->tableWidget->setItem(c,1,col2Item);
                QTableWidgetItem *col3Item = new QTableWidgetItem(group);
                ui->tableWidget->setItem(c,2,col3Item);
                QTableWidgetItem *col4Item = new QTableWidgetItem(QString::number(students[c].averageMark(), 'f', 1));
                ui->tableWidget->setItem(c,3,col4Item);

                ui->studentSelect_comboBox->addItem(QString::number(c+1)+") "+students[c].getInitials());
                c++;

                if (!isGroupExist(group)) {
                    groups[groupsCount] = group;
                    groupsCount++;
                    ui->selectGroup_comboBox->addItem(group);
                }

                studentsCount++;
            }
        }
    }
}


void MainWindow::on_selectGroup_comboBox_currentIndexChanged(int index)
{
    ui->tableWidget->setRowCount(0);
    ui->studentSelect_comboBox->setCurrentIndex(0);
    for (int i = 0; i < studentsCount; i++) {
        ui->studentSelect_comboBox->removeItem(1);
    }

    if (index == 0) {
        for (int i = 0; i < studentsCount; i++) {
            ui->tableWidget->insertRow(i);
            QTableWidgetItem *col1Item = new QTableWidgetItem(students[i].getName());
            ui->tableWidget->setItem(i,0,col1Item);
            QTableWidgetItem *col2Item = new QTableWidgetItem(students[i].getSpec());
            ui->tableWidget->setItem(i,1,col2Item);
            QTableWidgetItem *col3Item = new QTableWidgetItem(students[i].getGroup());
            ui->tableWidget->setItem(i,2,col3Item);
            QTableWidgetItem *col4Item = new QTableWidgetItem(QString::number(students[i].averageMark(), 'f', 1));
            ui->tableWidget->setItem(i,3,col4Item);

            ui->studentSelect_comboBox->addItem(QString::number(i+1)+") "+students[i].getInitials());
        }
    } else {
        filteredCount = 0;
        for (int i = 0; i < studentsCount; i++) {
            if (students[i].getGroup() == ui->selectGroup_comboBox->currentText()) {
                filtered[filteredCount] = students[i];
                ui->tableWidget->insertRow(filteredCount);
                QTableWidgetItem *col1Item = new QTableWidgetItem(students[i].getName());
                ui->tableWidget->setItem(filteredCount,0,col1Item);
                QTableWidgetItem *col2Item = new QTableWidgetItem(students[i].getSpec());
                ui->tableWidget->setItem(filteredCount,1,col2Item);
                QTableWidgetItem *col3Item = new QTableWidgetItem(students[i].getGroup());
                ui->tableWidget->setItem(filteredCount,2,col3Item);
                QTableWidgetItem *col4Item = new QTableWidgetItem(QString::number(students[i].averageMark(), 'f', 1));
                ui->tableWidget->setItem(filteredCount,3,col4Item);

                ui->studentSelect_comboBox->addItem(QString::number(filteredCount+1)+") "+students[i].getInitials());
                filteredCount++;
            }
        }
    }
}


void MainWindow::on_sort_button_clicked()
{
    Student temp;
    ui->tableWidget->setRowCount(0);
    ui->studentSelect_comboBox->setCurrentIndex(0);
    for (int i = 0; i < studentsCount; i++) {
        ui->studentSelect_comboBox->removeItem(1);
    }

    if (ui->selectGroup_comboBox->currentIndex() == 0) {
        for (int i = 1; i < studentsCount; i++) {
            for (int j = i; j > 0 && students[j - 1].averageMark() < students[j].averageMark(); j--) {
                temp = students[j - 1];
                students[j - 1] = students[j];
                students[j] = temp;
            }
        }

        for (int i = 0; i < studentsCount; i++) {
            ui->tableWidget->insertRow(i);
            QTableWidgetItem *col1Item = new QTableWidgetItem(students[i].getName());
            ui->tableWidget->setItem(i,0,col1Item);
            QTableWidgetItem *col2Item = new QTableWidgetItem(students[i].getSpec());
            ui->tableWidget->setItem(i,1,col2Item);
            QTableWidgetItem *col3Item = new QTableWidgetItem(students[i].getGroup());
            ui->tableWidget->setItem(i,2,col3Item);
            QTableWidgetItem *col4Item = new QTableWidgetItem(QString::number(students[i].averageMark(), 'f', 1));
            ui->tableWidget->setItem(i,3,col4Item);

            ui->studentSelect_comboBox->addItem(QString::number(i+1)+") "+students[i].getInitials());
        }
    } else {
        for (int i = 0; i < filteredCount; i++) {
            for (int j = i; j > 0 && filtered[j - 1].averageMark() < filtered[j].averageMark(); j--) {
                temp = filtered[j - 1];
                filtered[j - 1] = filtered[j];
                filtered[j] = temp;
            }
        }

        for (int i = 0; i < filteredCount; i++) {
            ui->tableWidget->insertRow(i);
            QTableWidgetItem *col1Item = new QTableWidgetItem(filtered[i].getName());
            ui->tableWidget->setItem(i,0,col1Item);
            QTableWidgetItem *col2Item = new QTableWidgetItem(filtered[i].getSpec());
            ui->tableWidget->setItem(i,1,col2Item);
            QTableWidgetItem *col3Item = new QTableWidgetItem(filtered[i].getGroup());
            ui->tableWidget->setItem(i,2,col3Item);
            QTableWidgetItem *col4Item = new QTableWidgetItem(QString::number(filtered[i].averageMark(), 'f', 1));
            ui->tableWidget->setItem(i,3,col4Item);

            ui->studentSelect_comboBox->addItem(QString::number(i+1)+") "+filtered[i].getInitials());
        }
    }
}


void MainWindow::on__createVed_button_clicked()
{
    ui->studentSelect_comboBox->setCurrentIndex(0);
    ui->selectGroup_comboBox->setCurrentIndex(0);
    delete[] students;
    students = new Student[100];
    delete[] groups;
    groups = new QString[50];

    int sz = ui->tableWidget->rowCount();
    ui->tableWidget->setRowCount(0);

    for (int i = 0; i < sz; i++) {
        ui->studentSelect_comboBox->removeItem(1);
    }

    for (int i = 0; i < groupsCount; i++) {
        ui->selectGroup_comboBox->removeItem(1);
    }
}


void MainWindow::on_find_button_clicked()
{
    QString line = ui->lineEdit->text();
    if (line.isEmpty()) {
        QMessageBox::critical(nullptr, "Ошибка", "Введите ФИО, чтобы найти студента");
        return;
    }

    ui->lineEdit->clear();

    for (int i = 0; i < studentsCount; i++) {
        if (students[i].getName().indexOf(line) != -1) {
            ui->label_13->hide();
            ui->Fio_Label->setText("ФИО: " + students[i].getName());
            ui->Spec_Label->setText("Специальность: " + students[i].getSpec());
            ui->Group_Label->setText("Номер группы: " + students[i].getGroup());
            ui->AvMark_Label->setText("Средний балл: " + QString::number(students[i].averageMark()));
            ui->label_96->show();
            ui->oaipLabel->setText("ОАиП: " + QString::number(students[i].getOaip()));
            ui->maLabel->setText("Мат анализ: " + QString::number(students[i].getMa()));
            ui->agilaLabel->setText("АГиЛА: " + QString::number(students[i].getAgila()));
            ui->mlLabel->setText("Мат логика: " + QString::number(students[i].getMl()));
            ui->historyLabel->setText("История: " + QString::number(students[i].getHist()));
            return;
        }
    }

    ui->Fio_Label->setText("");
    ui->Spec_Label->setText("");
    ui->Group_Label->setText("");
    ui->AvMark_Label->setText("");
    ui->label_96->hide();
    ui->oaipLabel->setText("");
    ui->maLabel->setText("");
    ui->agilaLabel->setText("");
    ui->mlLabel->setText("");
    ui->historyLabel->setText("");
    ui->label_13->show();

}

bool MainWindow::isGroupCorrect(QString group) {
    if (group.isEmpty()) {
        return false;
    }

    if (group.length() != 6) {
        return false;
    }

    for (int i = 0; i < group.length(); i++) {
        if (!group[i].isNumber()) {
            return false;
        }
    }

    return true;
}

