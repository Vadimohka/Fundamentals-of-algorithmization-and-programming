#include "mainwindow.h"
#include "ui_mainwindow.h"

int COUNTPROJECT = 0;
QMap <int, int> monthMap;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->listProjects->setSelectionMode(QAbstractItemView::SingleSelection);

    for (int i = 1; i <= 12; ++i) {
        if (i == 2) {
            monthMap[i] = 28;
        }
        else if (i == 4 || i == 6 || i == 9 || i == 11) {
            monthMap[i] = 30;
        }
        else {
            monthMap[i] = 31;
        }
    }
}

MainWindow::~MainWindow() {
    delete ui;
}

bool MainWindow::InputValidationNameHuman(QString InputDate) {
    int size = InputDate.size();
    int quanitySpace = 0;
    if (size == 0) {
        return false;
    }
    for (int i = 0; i < size; ++i) {
        if (InputDate.at(i) == ' ') {
            quanitySpace++;
        }
        else if (!((InputDate.at(i) >= 'A' && InputDate.at(i) <= 'Z') || (InputDate.at(i) >= 'a' && InputDate.at(i) <= 'z'))) {
            return false;
        }
    }
    if (quanitySpace != 2) {
        return false;
    }
    return true;
}

bool MainWindow::InputValidationDate(QString InputDate) {
    int size = InputDate.size();
    if (size != 10) {
        return false;
    }
    for (int i = 0; i < size; ++i) {
        if ((i == 2 || i == 5) && InputDate.at(i) != '.') {
            return false;
        }
        else if (!(InputDate.at(i) >= '0' && InputDate.at(i) <= '9') && i != 2 && i != 5) {
            return false;
        }
    }
    int day = InputDate.mid(0, 2).toInt();
    int month = InputDate.mid(3, 2).toInt();
    int year = InputDate.mid(6, 4).toInt();
    bool leapYear = false;
    if (month < 1 || month > 12) {
        return false;
    }
    if (year < 0 || year > 9999) {
        return false;
    }
    if (year % 4 == 0 && year % 100 != 0) {
        leapYear = true;
    }
    if (leapYear) {
        if (month == 2 && (day < 1 || day > 29)) {
            return false;
        }
    }
    else {
        if (month == 2 && (day < 1 || day > 28)) {
            return false;
        }
    }
    if ((month == 4 || month == 6 || month == 9 || month == 11) && (day < 1 || day > 30)) {
        return false;;
    }
    else if(day < 1 || day > 31) {
        return false;
    }
    return true;
}

bool MainWindow::InputValidationTerm(QString InputDate) {
    int size = InputDate.size();
    if (size == 0) {
        return false;
    }
    for (int i = 0; i < size; ++i) {
        if (InputDate.at(i) < '0' || InputDate.at(i) > '9') {
            return false;
        }
    }
    if (InputDate.size() >= 9) {
        return false;
    }
    if (InputDate.toInt() > 1000000) {
        return false;
    }
    return true;
}

void MainWindow::AddListData(QString NameProject, QString TaskProject, QString Executor, QString Supervisor,
                             QString DateIssuing, QString Term, QString DateHanding) {
    QString Input = NameProject + "/" + TaskProject + "/" + Executor + "/" +  Supervisor +
                    "/" + DateIssuing + "/" + Term + "/" + DateHanding;


    QListWidgetItem *ItemData = new QListWidgetItem(Input);
    AddTextOutput(Input);
    ui->listProjects->insertItem(ui->listProjects->count(), ItemData);
}


void MainWindow::AddTextOutput(QString TextOutput) {
    TextOutputFile += TextOutput + '\n';
}


void MainWindow::on_ButtonAddProject_clicked() {
    QString NameProject = ui->lineNameProject->text();
    QString TaskProject = ui->lineTaskProject->text();
    QString Executor = ui->lineNameExecutor->text();
    QString Supervisor = ui->lineNameSupervisor->text();
    QString DateIssuing = ui->lineDateIssuingTask->text();
    QString Term = ui->lineTermTask->text();
    QString DateHanding = ui->lineDateHandingTask->text();

    if (NameProject.size() == 0) {
        QMessageBox::warning(this, "Ошибка!", "Введите корректное название проекта");
        return;
    }
    if (TaskProject.size() == 0) {
        QMessageBox::warning(this, "Ошибка!", "Введите корректное задание проекта");
        return;
    }
    if (!InputValidationNameHuman(Executor)) {
        QMessageBox::warning(this, "Ошибка!", "Введите корректное ФИО исполнителя:\n\"Фамилия Имя Отчество\", используйте буквы английского алфавита.");
        return;
    }
    if (!InputValidationNameHuman(Supervisor)) {
        QMessageBox::warning(this, "Ошибка!", "Введите корректное ФИО руководителя:\n\"Фамилия Имя Отчество\", используйте буквы английского алфавита.");
        return;
    }
    if (!InputValidationDate(DateIssuing)) {
        QMessageBox::warning(this, "Ошибка!", "Введите корректную дату выдачи задания:\n"
                                              "Первые 2 цифры означают день от 01 до 31 дня в зависимости от месяца,\n"
                                              "(Внимание 29 февраля можно ввести, когда год является високосным(кратен 4))\n"
                                              "далее необходимо ввести точку,\n"
                                              "после необходимо ввести 2 цифры месяца от 01 до 12,\n"
                                              "далее нужно ввести точку,\n"
                                              "после ввести 4 цифры года от 0000 да 9999");
        return;
    }
    if (!InputValidationTerm(Term)) {
        QMessageBox::warning(this, "Ошибка!", "Введите корректный срок: беззнаквое число, не превышающее 1000000");
        return;
    }
    if (!InputValidationDate(DateHanding)) {
        QMessageBox::warning(this, "Ошибка!", "Введите корректную дату cдачи задания:\n"
                                              "Первые 2 цифры означают день от 01 до 31 дня в зависимости от месяца,\n"
                                              "(Внимание 29 февраля можно ввести, когда год является високосным(кратен 4))\n"
                                              "далее необходимо ввести точку,\n"
                                              "после необходимо ввести 2 цифры месяца от 01 до 12,\n"
                                              "далее нужно ввести точку,\n"
                                              "после ввести 4 цифры года от 0000 да 9999");
        return;
    }



    project = new Project(NameProject, TaskProject, Executor, Supervisor, DateIssuing, Term, DateHanding);
    projects.append(project);
    COUNTPROJECT++;

    AddListData(NameProject, TaskProject, Executor, Supervisor, DateIssuing, Term, DateHanding);
}


void MainWindow::on_ButtonListSupervisor_clicked() {
    QString InputData = ui->lineListSupervisor->text();
    QString OutputData = "";
    QSet<QString> setProjects;
    if (!InputValidationNameHuman(InputData)) {
        QMessageBox::warning(this, "Ошибка!", "Введите корректное ФИО руководителя");
        return;
    }
    for (int i = 0; i < COUNTPROJECT; ++i) {
        if (projects[i]->SupervisorNameOutput() == InputData) {
            setProjects += projects[i]->NameProjectOutput();
        }
    }
    for (QString project : setProjects) {
        OutputData += project + '\n';
    }
    if (OutputData.size() == 0) {
        QMessageBox::information(this, "Внимание", InputData + " не числится в списке проектов");
        return;
    }
    QMessageBox::information(this, "Список проектов руководителя", OutputData);
}


void MainWindow::on_ButtonTaskExecutor_clicked() {
    QString InputData = ui->lineListTaskExecutor->text();
    QString OutputData = "";
    QSet<QString> setProjects;
    if (!InputValidationNameHuman(InputData)) {
        QMessageBox::warning(this, "Ошибка!", "Введите корректное ФИО исполнителя");
        return;
    }
    for (int i = 0; i < COUNTPROJECT; ++i) {
        if (projects[i]->ExecutorNameOutput() == InputData) {
            setProjects += projects[i]->TaskProjectOutput();
        }
    }
    for (QString project : setProjects) {
        OutputData += project + '\n';
    }
    if (OutputData.size() == 0) {
        QMessageBox::information(this, "Внимание", InputData + " не числится в списке проектов");
        return;
    }

    QMessageBox::information(this, "Список задач сотрудника", OutputData);
}


void MainWindow::on_ButtonExecutorsProject_clicked() {
    QString InputData = ui->lineListExecutorProject->text();
    QString OutputData = "";
    QSet<QString> setProjects;
    if (InputData.size() == 0) {
        QMessageBox::warning(this, "Ошибка!", "Введите корректное название проекта");
        return;
    }
    for (int i = 0; i < COUNTPROJECT; ++i) {
        if (projects[i]->NameProjectOutput() == InputData) {
            setProjects += projects[i]->ExecutorNameOutput();
        }
    }
    for (QString project : setProjects) {
        OutputData += project + '\n';
    }
    if (OutputData.size() == 0) {
        QMessageBox::information(this, "Внимание", InputData + " не является названием проекта");
        return;
    }

    QMessageBox::information(this, "Список сотрудников проекта", OutputData);
}


void MainWindow::on_ButtonOverdue_clicked()
{
    QString OutputData = "";
    for (int i = 0; i < COUNTPROJECT; ++i) {
        if (projects[i]->CheckTaskOverdue()) {
            OutputData += projects[i]->ExecutorNameOutput() + '\n';
        }
    }

    if (OutputData.size() == 0) {
        QMessageBox::information(this, "Внимание", "Сотрудники, просрочившие задание, отсутствуют");
        return;
    }
    QMessageBox::information(this, "Список сотрудников просрочивших задание", OutputData);
}

void MainWindow::InputValidationEnter(QString text) {
    QString string = "";
    int size = text.size();
    for (int i = 0; i < size; ++i) {
        if (text.at(i) == '\n') {
            InputOpenedFile(string);
            string = "";
        }
        else {
            string += text.at(i);
        }
    }
}

void MainWindow::InputOpenedFile(QString InputData) {
    InputData += "/";
    int size = InputData.size();
    int countSlash = 0;
    QString strChecked = "";
    QString NameProject = "";
    QString TaskProject = "";
    QString Executor = "";
    QString Supervisor = "";
    QString DateIssuing = "";
    QString Term = "";
    QString DateHanding = "";



    for (int i = 0; i < size; ++i) {

        if (InputData.at(i) == '/') {
            countSlash++;

            switch (countSlash) {
            case 1:
              //  ui->plainTextEdit->insertPlainText(strChecked + "\n");
                NameProject = strChecked;
                break;
            case 2:
              // ui->plainTextEdit->insertPlainText(strChecked + "\n");
                TaskProject = strChecked;
                break;
            case 3:
              //  ui->plainTextEdit->insertPlainText(strChecked + "\n");
                if (InputValidationNameHuman(strChecked)) {
                    Executor = strChecked;
                }
                else {
                    return;
                }
                break;
            case 4:
              //  ui->plainTextEdit->insertPlainText(strChecked + "\n");
                if (InputValidationNameHuman(strChecked)) {
                    Supervisor = strChecked;
                }
                else {
                    return;
                }
                break;
            case 5:
               // ui->plainTextEdit->insertPlainText(strChecked + "\n");
                if (InputValidationDate(strChecked)) {
                    DateIssuing = strChecked;
                }
                else {
                    return;
                }
                break;
            case 6:
               // ui->plainTextEdit->insertPlainText(strChecked + "\n");
                if (InputValidationTerm(strChecked)) {
                    Term = strChecked;
                }
                else {
                    return;
                }
                break;
            case 7:
               // ui->plainTextEdit->insertPlainText(strChecked + "\n");
                if (InputValidationDate(strChecked)) {
                    DateHanding = strChecked;
                }
                else {
                    return;
                }
                break;
            default:
                break;
            }
            strChecked = "";
        }
        else {
            strChecked += InputData.at(i);
        }
    }
    if (countSlash != 7) {
        return;
    }
    project = new Project(NameProject, TaskProject, Executor, Supervisor, DateIssuing, Term, DateHanding);
    projects.append(project);
    COUNTPROJECT++;
    AddListData(NameProject, TaskProject, Executor, Supervisor, DateIssuing, Term, DateHanding);
}

void MainWindow::CheckedTable(int CountOld) {
    if (ui->listProjects->count() < CountOld) {
        QMessageBox::information(this,"Обратите внмание","В данном текстовом файле нет корректных дынных");
    }
}

void MainWindow::on_ButtonOpenFile_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Открытие файла", "/home/lklls1/Документы/", tr("TXT Files (*.txt)"));
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Не удалось открыть файл";
        return;
    }
    QTextStream in(&file);
    QString text = in.readAll();
    //ui->plainTextEdit->insertPlainText(text);
    int CountOld = COUNTPROJECT + 1;
    InputValidationEnter(text);
    CheckedTable(CountOld);
    file.close();
}


void MainWindow::on_ButtonSaveFile_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Открытие файла", "/home/lklls1/Документы/", tr("TXT Files (*.txt)"));
    //QString filename = "/home/lklls1/Документы/proverka.txt";
    QFile file("/home/lklls1/Документы/kaka.txt");
    if(file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        // We're going to streaming text to the file
        QTextStream stream(&file);

        stream << TextOutputFile;

        file.close();
        qDebug() << "Writing finished";
    }
   //  QString filename = "/home/lklls1/Документы/proverka.txt";
   //  QFile file(filename);
   //  if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
   //      qDebug() << "Не удалось открыть файл";
   //      return;
   //  }
   // // if (file.open(QIODevice::ReadWrite)) {
   //      QTextStream stream(&file);
   //      stream << "something";
    //}
    // QString fileName = QFileDialog::getSaveFileName(this, "Открытие файла", "/home/");
    // QFile file(fileName);
    // if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
    //v     qDebug() << "Не удалось открыть файл";
    //     return;
    // }
    //QString saveFile = saveProjectDlg.getSaveFileName(this, tr("Project Save As"), temp, tr("System Files (*.txt)"));
    // QTextStream in(&file);
    // QString text = in.readAll();
    // //ui->plainTextEdit->insertPlainText(text);

    // InputValidationEnter(text);

}

