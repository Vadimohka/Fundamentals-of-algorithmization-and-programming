#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

bool Widget::checkDateInput(QString text) {
    if (text[2] != '.' || text[5] != '.' || text.size() != 10) return false;
    if (text[0] > '9' || text[0] < '0') return false;
    if (text[1] > '9' || text[1] < '0') return false;
    if (text[3] > '9' || text[3] < '0') return false;
    if (text[4] > '9' || text[4] < '0') return false;
    if (text[6] > '9' || text[6] < '0') return false;
    if (text[7] > '9' || text[7] < '0') return false;
    if (text[8] > '9' || text[8] < '0') return false;
    if (text[9] > '9' || text[9] < '0') return false;
    for (int i = 10; i < text.size(); ++i) if (text[i] != ' ') return false;
    return true;
}

bool Widget::checkFIOInput(QString text) {
    int spaceCounter = 0;
    int lastLetterPosition = 0;
    for (int i = 0; i < text.size(); ++i) {
        if (spaceCounter == 2 && (text[i] == ' ' || i == text.size() - 1)) {
            lastLetterPosition = i;
            break;
        }
        if (text[i] == ' ') ++spaceCounter;
        else if (text[i] < 'A' || text[i] > 'Z' && text[i] < 'a' || text[i] > 'z') {
            return false;
        }
    }
    for (int i = lastLetterPosition + 1; i < text.size(); ++i) {
        if (text[i] != ' ') {
            return false;
        }
    }
    if (spaceCounter != 2) {
        return false;
    }
    return true;
}

bool Widget::checkFileInput(QString text) {
    int spaceCounter = 0;
    for (int i = 0; i < text.size(); ++i) {
        if (text[i] == ' ') ++spaceCounter;
    }
    if (spaceCounter < 10) { return false; }
    else { return true; }
}

bool Widget::checkLineNumberInput() {
    fromFileToVector();
    int lineNumber = ui->lineNumber_lineEdit->text().toInt();
    if (lineNumber <= 0 || lineNumber >= _workersVector.size()) {
        return false;
    }
    else {
        return true;
    }
}

bool Widget::fileIsEmpty(QString path) {
    bool isEmpty = true;
    if (!input.is_open()) {
        input.open(path.toUtf8());
    }
    std::string text;
    while (std::getline(input, text)) {
        isEmpty = false;
    }
    input.close();
    return isEmpty;
}


void Widget::fromFileToVector() {
    if (_path != nullptr && !input.is_open()) {
        input.open(_path.toUtf8(), std::ofstream::in);
    }
    if (input.is_open()) {
        qDebug() << "fromFileToVector started";
        _workersVector.clear();
        std::string text;
        int spaceCounter = 0;
        QString workerFIO, projectName, task, mentorFIO, dateGave, deadline, dateComplete;
        while (std::getline(input, text)) {
            if (checkFileInput(QString::fromStdString(text))) {
                for (int i = 0; i < text.size(); ++i) {
                    if (spaceCounter <= 2) {
                        workerFIO += QString(text[i]);
                    }
                    else if (spaceCounter == 3) {
                        projectName += QString(text[i]);
                    }
                    else if (spaceCounter == 4) {
                        task += QString(text[i]);
                    }
                    else if (spaceCounter > 4 && spaceCounter < 8) {
                        mentorFIO += QString(text[i]);
                    }
                    else if (spaceCounter == 8) {
                        dateGave += QString(text[i]);
                    }
                    else if (spaceCounter == 9) {
                        deadline += QString(text[i]);
                    }
                    else if (spaceCounter == 10) {
                        dateComplete += QString(text[i]);
                        if (dateComplete.size() == 10) break;
                    }
                    if (text[i] == ' ') ++spaceCounter;
                }

                workerFIO.remove(workerFIO.size() - 1, 1);
                projectName.remove(projectName.size() - 1, 1);
                task.remove(task.size() - 1, 1);
                mentorFIO.remove(mentorFIO.size() - 1, 1);
                dateGave.remove(dateGave.size() - 1, 1);
                deadline.remove(deadline.size() - 1, 1);

                checkDateInput(dateComplete);
                if (checkFIOInput(workerFIO) && checkFIOInput(mentorFIO) && checkDateInput(dateGave) && checkDateInput(deadline) &&
                    checkDateInput(dateComplete)) {
                    Worker temp(workerFIO);
                    temp.setProject(projectName);
                    temp.setTask(task);
                    temp.setMentorFIO(mentorFIO);
                    temp.setDateGave(dateGave);
                    temp.setDeadline(deadline);
                    temp.setDateComplete(dateComplete);
                    _workersVector.push_back(temp);
                }
                workerFIO.clear();
                projectName.clear();
                task.clear();
                mentorFIO.clear();
                dateGave.clear();
                deadline.clear();
                dateComplete.clear();
                spaceCounter = 0;
            }
        }
        input.close();
    }
}

void Widget::addToFile(Worker added, QString path) {
    if (path != nullptr) {
        output.open(path.toUtf8(), std::ofstream::app);
        if (output.is_open()) {
            QString line = added.getWorkerFIOString() + ' ' + added.getProjectNameString() + ' ' + added.getTaskString() + ' ' +
                    added.getMentorFIOString() + ' ' + added.getDatesString();
            if (fileIsEmpty(path)) {
                output << line.toStdString();
            }
            else {
                output << '\n' << line.toStdString();
            }
            qDebug() << "data was recorded" << line;
            output.close();
        }
    }
}

void Widget::showTable() {
    ui->tableWidget->setRowCount(_workersVector.size());
    for (int i = 0; i < _workersVector.size(); ++i) {
        if (_workersVector[i].getDateGaveDate().getYear() != 0 && _workersVector[i].getDeadlineDate().getYear() != 0 && _workersVector[i].getDateCompleteDate().getYear() != 0) {
            ui->tableWidget->setItem(i, 0, new QTableWidgetItem(_workersVector[i].getWorkerFIOString()));
            ui->tableWidget->setItem(i, 1, new QTableWidgetItem(_workersVector[i].getProjectNameString()));
            ui->tableWidget->setItem(i, 2, new QTableWidgetItem(_workersVector[i].getTaskString()));
            ui->tableWidget->setItem(i, 3, new QTableWidgetItem(_workersVector[i].getMentorFIOString()));
            ui->tableWidget->setItem(i, 4, new QTableWidgetItem(_workersVector[i].getDateGaveString()));
            ui->tableWidget->setItem(i, 5, new QTableWidgetItem(_workersVector[i].getDeadlineString()));
            ui->tableWidget->setItem(i, 6, new QTableWidgetItem(_workersVector[i].getDateCompleteString()));
        }
        else {
            for (int j = 0; j < 7; ++j) {
                ui->tableWidget->setItem(i, j, new QTableWidgetItem(QString("Error!")));
            }
        }
    }
}


void Widget::on_open_file_clicked() {
    _path = QFileDialog::getOpenFileName(nullptr, "Open Files", "../Files", "txt file (*.txt);;");
}


void Widget::on_add_to_file_clicked() {
    if (_path == nullptr) {
        qDebug() << "File is not selected";
    }
    else {
        QString workerFIO = ui->workerFIO_lineEdit->text();
        QString projectName = ui->projectName_lineEdit->text();
        QString task = ui->task_lineEdit->text();
        QString mentorFIO = ui->mentorFIO_lineEdit->text();
        QString dateGave = ui->dateGave_lineEdit->text();
        QString deadline = ui->deadline_lineEdit->text();
        QString dateComplete = ui->dateComplete_lineEdit->text();
        Worker temp(workerFIO);
        temp.setDateGave(dateGave);
        temp.setDeadline(deadline);
        temp.setDateComplete(dateComplete);

        qDebug() << "date was read" << dateGave << deadline << dateComplete;
        //qDebug() << "date was read" << temp.getDateGaveDate().getYear() << temp.getDeadlineDate().getYear() << temp.getDateCompleteDate().getYear();
        if (checkFIOInput(workerFIO) && checkFIOInput(mentorFIO) && checkDateInput(dateGave) && checkDateInput(deadline) &&
            checkDateInput(dateComplete)) {

            temp.setProject(projectName);
            temp.setTask(task);
            temp.setMentorFIO(mentorFIO);

            if (temp.getDateGaveDate().getYear() != 0 && temp.getDeadlineDate().getYear() != 0 && temp.getDateCompleteDate().getYear() != 0) {
                _workersVector.push_back(temp);
                addToFile(temp, _path);
            }
        }
        else {
            if (!checkFIOInput(workerFIO)) {
                ui->workerFIO_lineEdit->setText("Error!");
                QTimer::singleShot(600, this, SLOT(clearErrorWorkerFIO()));
            }
            if (!checkFIOInput(mentorFIO)) {
                ui->mentorFIO_lineEdit->setText("Error!");
                QTimer::singleShot(600, this, SLOT(clearErrorMentorFIO()));
            }
            if (!checkDateInput(dateGave) || temp.getDateGaveDate().getYear() == 0) {
                ui->dateGave_lineEdit->setText("Error!");
                QTimer::singleShot(600, this, SLOT(clearErrorDateGave()));
            }
            if (!checkDateInput(deadline) || temp.getDeadlineDate().getYear() == 0) {
                ui->deadline_lineEdit->setText("Error!");
                QTimer::singleShot(600, this, SLOT(clearErrorDeadline()));
            }
            if (!checkDateInput(dateComplete) || temp.getDateCompleteDate().getYear() == 0) {
                ui->dateComplete_lineEdit->setText("Error!");
                QTimer::singleShot(600, this, SLOT(clearErrorDateComplete()));
            }
        }
    }
}


void Widget::on_edit_file_clicked() {
    if (checkLineNumberInput()) {
        fromFileToVector();
        int lineNumber = ui->lineNumber_lineEdit->text().toInt();
        QString workerFIO = ui->workerFIO_lineEdit->text();
        QString projectName = ui->projectName_lineEdit->text();
        QString task = ui->task_lineEdit->text();
        QString mentorFIO = ui->mentorFIO_lineEdit->text();
        QString dateGave = ui->dateGave_lineEdit->text();
        QString deadline = ui->deadline_lineEdit->text();
        QString dateComplete = ui->dateComplete_lineEdit->text();
        if (workerFIO != "") {
            if (checkFIOInput(workerFIO)) {
                _workersVector[lineNumber - 1].setWorkerFIO(workerFIO);
            }
            else {
                ui->workerFIO_lineEdit->setText("Error!");
            }
        }
        if (projectName != "") {
            _workersVector[lineNumber - 1].setProject(projectName);
        }
        if (task != "") {
            _workersVector[lineNumber - 1].setTask(task);
        }
        if (mentorFIO != "") {
            if (checkFIOInput(workerFIO)) {
                _workersVector[lineNumber - 1].setMentorFIO(mentorFIO);
            }
            else {
                ui->mentorFIO_lineEdit->setText("Error!");

            }
        }
        Worker temp("A A A");
        temp.setDateGave(dateGave);
        temp.setDeadline(deadline);
        temp.setDateComplete(dateComplete);
        if (dateGave != "") {
            if (checkDateInput(dateGave) && temp.getDateGaveDate().getYear() != 0) {
                _workersVector[lineNumber - 1].setDateGave(dateGave);
            }
            else {
                ui->dateGave_lineEdit->setText("Error!");
            }
        }
        if (deadline != "") {
            if (checkDateInput(deadline) && temp.getDeadlineDate().getYear() != 0) {
                _workersVector[lineNumber - 1].setDateGave(deadline);
            }
            else {
                ui->deadline_lineEdit->setText("Error!");
            }
        }
        if (dateComplete != "") {
            if (checkDateInput(dateComplete) && temp.getDateCompleteDate().getYear() != 0) {
                _workersVector[lineNumber - 1].setDateGave(dateComplete);
            }
            else {
                ui->dateComplete_lineEdit->setText("Error!");
            }
        }
        clearFile(_path);
        for (int i = 0; i < _workersVector.size(); ++i) {
            addToFile(_workersVector[i], _path);
        }
    }
}


void Widget::on_delete_from_file_clicked() {
    if (checkLineNumberInput()) {
        fromFileToVector();
        int lineNumber = ui->lineNumber_lineEdit->text().toInt();
        clearFile(_path);
        for (int i = 0; i < _workersVector.size(); ++i) {
            if (i != lineNumber - 1) {
                addToFile(_workersVector[i], _path);
            }
        }
    }
}


void Widget::on_show_file_clicked() {
    fromFileToVector();
    showTable();
}

void Widget::on_comboBox_activated(int index) {
    qDebug() << "Index =" << index;
    if (_path != nullptr) {
        fromFileToVector();
    }
    if (index == 0) {
        ui->workerFIO_lineEdit->isReadOnly();
        ui->projectName_lineEdit->isReadOnly();
        ui->task_lineEdit->isReadOnly();
        ui->dateGave_lineEdit->isReadOnly();
        ui->deadline_lineEdit->isReadOnly();
        ui->dateComplete_lineEdit->isReadOnly();
        QString text = ui->mentorFIO_lineEdit->text();
        _newPath = "/home/zgdarya/QTWORKS/LAB2_TASK2/Files/ProjectsOnMentor.txt";
        if (checkFIOInput(text)) {
            fillProjectsOnMentorFile(text);
        }
        else {
            ui->mentorFIO_lineEdit->setText("Error!");
        }
    }
    else if (index == 1) {
        ui->projectName_lineEdit->isReadOnly();
        ui->task_lineEdit->isReadOnly();
        ui->mentorFIO_lineEdit->isReadOnly();
        ui->dateGave_lineEdit->isReadOnly();
        ui->deadline_lineEdit->isReadOnly();
        ui->dateComplete_lineEdit->isReadOnly();
        QString text = ui->workerFIO_lineEdit->text();
        _newPath = "/home/zgdarya/QTWORKS/LAB2_TASK2/Files/TasksOnWorker.txt";
        fillTaskOnWorkerFile(text);
    }
    else if (index == 2) {
        ui->workerFIO_lineEdit->isReadOnly();
        ui->task_lineEdit->isReadOnly();
        ui->mentorFIO_lineEdit->isReadOnly();
        ui->dateGave_lineEdit->isReadOnly();
        ui->deadline_lineEdit->isReadOnly();
        ui->dateComplete_lineEdit->isReadOnly();
        QString text = ui->projectName_lineEdit->text();
        _newPath = "/home/zgdarya/QTWORKS/LAB2_TASK2/Files/WorkersOnProject.txt";
        fillWorkersOnProjectFile(text);
    }
    else {
        _newPath = "/home/zgdarya/QTWORKS/LAB2_TASK2/Files/WorkersFailedDeadline.txt";
        fillWorkersFailedDeadline();
    }
}

void Widget::fillProjectsOnMentorFile(QString text) {
    if (_path != nullptr) {
        clearFile(_newPath);
        output.open(_newPath.toUtf8(), std::ofstream::app);
        if (output.is_open()) {
            output << "Mentor's Name: " << text.toStdString() << '\n';
            output << "Mentor's Projects: ";
            for (int i = 0; i < _workersVector.size(); ++i) {
                if (_workersVector[i].getMentorFIOString() == text) {
                    output << '\n' << _workersVector[i].getProjectNameString().toStdString();
                }
            }
            output.close();
        }
    }
}

void Widget::fillTaskOnWorkerFile(QString text) {
    if (_path != nullptr) {
        clearFile(_newPath);
        output.open(_newPath.toUtf8(), std::ofstream::app);
        if (output.is_open()) {
            output << "Worker's Name: " << text.toStdString() << '\n';
            output << "Worker's Tasks: ";
            for (int i = 0; i < _workersVector.size(); ++i) {
                if (_workersVector[i].getWorkerFIOString() == text) {
                    output << '\n' << _workersVector[i].getTaskString().toStdString();
                }
            }
            output.close();
        }
    }
}

void Widget::fillWorkersOnProjectFile(QString text) {
    if (_path != nullptr) {
        clearFile(_newPath);
        output.open(_newPath.toUtf8(), std::ofstream::app);
        if (output.is_open()) {
            output << "Project's Name: " << text.toStdString() << '\n';
            output << "Project's Workers: ";
            for (int i = 0; i < _workersVector.size(); ++i) {
                if (_workersVector[i].getProjectNameString() == text) {
                    output << '\n' << _workersVector[i].getWorkerFIOString().toStdString();
                }
            }
            output.close();
        }
    }
}

void Widget::clearFile(QString path) {
    output.open(path.toUtf8(), std::ofstream::out | std::ofstream::trunc);
    output.close();
}

void Widget::fillWorkersFailedDeadline() {
    if (_path != nullptr) {
        clearFile(_newPath);
        output.open(_newPath.toUtf8(), std::ofstream::app);
        if (output.is_open()) {
            output << "Deadlines Failed: " << '\n';
            output << "Worker's Names: ";
            int delta;
            for (int i = 0; i < _workersVector.size(); ++i) {
                delta = _workersVector[i].getDeadlineDate().Duration(_workersVector[i].getDateCompleteDate());
                if (delta < 0) {
                    output << '\n' << _workersVector[i].getWorkerFIOString().toStdString();
                }
            }
            output.close();
        }
    }
}

void Widget::clearErrorWorkerFIO() {
    ui->workerFIO_lineEdit->setText("");
}

void Widget::clearErrorMentorFIO() {
    ui->mentorFIO_lineEdit->setText("");
}

void Widget::clearErrorDateGave() {
    ui->dateGave_lineEdit->setText("");
}

void Widget::clearErrorDeadline() {
    ui->deadline_lineEdit->setText("");
}

void Widget::clearErrorDateComplete() {
    ui->dateComplete_lineEdit->setText("");
}

