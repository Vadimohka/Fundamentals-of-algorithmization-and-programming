#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "task.h"

#include <QFileDialog>
#include <QMessageBox>
#include <QFile>
#include <QDate>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    file(nullptr)
{
    ui->setupUi(this);
    connect(ui->openFileButton, &QPushButton::clicked, this, &MainWindow::openFile);
    connect(ui->addButton, &QPushButton::clicked, this, &MainWindow::onAddButtonClicked);
    connect(ui->deleteButton, &QPushButton::clicked, this, &MainWindow::onDeleteButtonClicked);
    connect(ui->editButton, &QPushButton::clicked, this, &MainWindow::onEditButtonClicked);
    connect(ui->sortButton, &QPushButton::clicked, this, &MainWindow::sortButtonClicked);
    connect(ui->showTasksButton, &QPushButton::clicked, this, &MainWindow::showTasksButtonClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
    for (Task* task : tasks) {
        delete task;
    }

    if (file) {
        delete file;
    }
}

void MainWindow::openFile()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Open File", "", "Text Files (*.txt)");
    if (!filePath.isEmpty()) {
        loadTasksFromFile(filePath);
    }
}

void MainWindow::loadTasksFromFile(const QString& filePath)
{
    file = new QFile(filePath);
    if (!file->open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(this, "Error", "Failed to open the file.");
        return;
    }

    for (Task* task : tasks)
    {
        delete task;
    }
    tasks.clear();

    QTextStream in(file);
    while (!in.atEnd())
    {
        QString line = in.readLine();
        QStringList taskData = line.split(',');
        if (taskData.size() == 6)
        {
            QString projectName = taskData.at(0);
            QString task = taskData.at(1);
            QString executor = taskData.at(2);
            QString supervisor = taskData.at(3);
            QDate issueDate = QDate::fromString(taskData.at(4), "dd.MM.yyyy");
            QDate dueDate = QDate::fromString(taskData.at(5), "dd.MM.yyyy");

            if (projectName.isEmpty() || task.isEmpty() || executor.isEmpty() ||
                supervisor.isEmpty() || !issueDate.isValid() || !dueDate.isValid())
            {
                QMessageBox::warning(this, "Error", "Invalid data detected in the file.");
                file->close();
                return;
            }

            Task* taskObj = new Task(projectName, task, executor, supervisor, issueDate, dueDate);
            tasks.append(taskObj);
        }
        else
        {
            QMessageBox::warning(this, "Error", "Invalid data format detected in the file.");
            file->close();
            return;
        }
    }

    file->close();
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(tasks.size());

    for (int i = 0; i < tasks.size(); ++i)
    {
        Task* task = tasks.at(i);
        QTableWidgetItem* projectNameItem = new QTableWidgetItem(task->getProjectName());
        QTableWidgetItem* taskItem = new QTableWidgetItem(task->getTask());
        QTableWidgetItem* executorItem = new QTableWidgetItem(task->getExecutor());
        QTableWidgetItem* supervisorItem = new QTableWidgetItem(task->getSupervisor());
        QTableWidgetItem* issueDateItem = new QTableWidgetItem(task->getIssueDate().toString("dd.MM.yyyy"));
        QTableWidgetItem* dueDateItem = new QTableWidgetItem(task->getDueDate().toString("dd.MM.yyyy"));

        ui->tableWidget->setItem(i, 0, projectNameItem);
        ui->tableWidget->setItem(i, 1, taskItem);
        ui->tableWidget->setItem(i, 2, executorItem);
        ui->tableWidget->setItem(i, 3, supervisorItem);
        ui->tableWidget->setItem(i, 4, issueDateItem);
        ui->tableWidget->setItem(i, 5, dueDateItem);
    }
}
void MainWindow::addTableRow(const Task& task)
{
    int row = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(row);

    QTableWidgetItem* projectNameItem = new QTableWidgetItem(task.getProjectName());
    QTableWidgetItem* taskItem = new QTableWidgetItem(task.getTask());
    QTableWidgetItem* executorItem = new QTableWidgetItem(task.getExecutor());
    QTableWidgetItem* supervisorItem = new QTableWidgetItem(task.getSupervisor());
    QTableWidgetItem* issueDateItem = new QTableWidgetItem(task.getIssueDate().toString("dd.MM.yyyy"));
    QTableWidgetItem* dueDateItem = new QTableWidgetItem(task.getDueDate().toString("dd.MM.yyyy"));
    ui->tableWidget->setItem(row, 0, projectNameItem);
    ui->tableWidget->setItem(row, 1, taskItem);
    ui->tableWidget->setItem(row, 2, executorItem);
    ui->tableWidget->setItem(row, 3, supervisorItem);
    ui->tableWidget->setItem(row, 4, issueDateItem);
    ui->tableWidget->setItem(row, 5, dueDateItem);
}
void MainWindow::removeSelectedTableRow()
{
    int selectedRow = ui->tableWidget->currentRow();
    if (selectedRow >= 0) {
        ui->tableWidget->removeRow(selectedRow);
    }
}
void MainWindow::editSelectedTableRow(const Task& task)
{
    int selectedRow = ui->tableWidget->currentRow();
    if (selectedRow >= 0) {
        QTableWidgetItem* projectNameItem = new QTableWidgetItem(task.getProjectName());
        QTableWidgetItem* taskItem = new QTableWidgetItem(task.getTask());
        QTableWidgetItem* executorItem = new QTableWidgetItem(task.getExecutor());
        QTableWidgetItem* supervisorItem = new QTableWidgetItem(task.getSupervisor());
        QTableWidgetItem* issueDateItem = new QTableWidgetItem(task.getIssueDate().toString());
        QTableWidgetItem* dueDateItem = new QTableWidgetItem(task.getDueDate().toString());

        ui->tableWidget->setItem(selectedRow, 0, projectNameItem);
        ui->tableWidget->setItem(selectedRow, 1, taskItem);
        ui->tableWidget->setItem(selectedRow, 2, executorItem);
        ui->tableWidget->setItem(selectedRow, 3, supervisorItem);
        ui->tableWidget->setItem(selectedRow, 4, issueDateItem);
        ui->tableWidget->setItem(selectedRow, 5, dueDateItem);
    }
}

void MainWindow::on_openFileButton_clicked()
{
    openFile();
}

void MainWindow::on_searchButton_clicked()
{
    QString projectName = ui->projectLineEdit->text();

    QVector<Task*> filteredTasks;
    for (Task* task : tasks) {
        if (task->getProjectName() == projectName) {
            filteredTasks.append(task);
        }
    }

    if (filteredTasks.isEmpty()) {

        ui->tableWidget->clear();
        ui->tableWidget->setRowCount(tasks.size());
        for (int i = 0; i < tasks.size(); ++i) {
            Task* task = tasks.at(i);
            QTableWidgetItem* projectNameItem = new QTableWidgetItem(task->getProjectName());
            QTableWidgetItem* taskItem = new QTableWidgetItem(task->getTask());
            QTableWidgetItem* executorItem = new QTableWidgetItem(task->getExecutor());
            QTableWidgetItem* supervisorItem = new QTableWidgetItem(task->getSupervisor());
            QTableWidgetItem* issueDateItem = new QTableWidgetItem(task->getIssueDate().toString("dd.MM.yyyy"));
            QTableWidgetItem* dueDateItem = new QTableWidgetItem(task->getDueDate().toString("dd.MM.yyyy"));

            ui->tableWidget->setItem(i, 0, projectNameItem);
            ui->tableWidget->setItem(i, 1, taskItem);
            ui->tableWidget->setItem(i, 2, executorItem);
            ui->tableWidget->setItem(i, 3, supervisorItem);
            ui->tableWidget->setItem(i, 4, issueDateItem);
            ui->tableWidget->setItem(i, 5, dueDateItem);
        }
    } else {

        ui->tableWidget->clear();
        ui->tableWidget->setRowCount(filteredTasks.size());
        for (int i = 0; i < filteredTasks.size(); ++i) {
            Task* task = filteredTasks.at(i);
            QTableWidgetItem* projectNameItem = new QTableWidgetItem(task->getProjectName());
            QTableWidgetItem* taskItem = new QTableWidgetItem(task->getTask());
            QTableWidgetItem* executorItem = new QTableWidgetItem(task->getExecutor());
            QTableWidgetItem* supervisorItem = new QTableWidgetItem(task->getSupervisor());
            QTableWidgetItem* issueDateItem = new QTableWidgetItem(task->getIssueDate().toString("dd.MM.yyyy"));
            QTableWidgetItem* dueDateItem = new QTableWidgetItem(task->getDueDate().toString("dd.MM.yyyy"));

            ui->tableWidget->setItem(i, 0, projectNameItem);
            ui->tableWidget->setItem(i, 1, taskItem);
            ui->tableWidget->setItem(i, 2, executorItem);
            ui->tableWidget->setItem(i, 3, supervisorItem);
            ui->tableWidget->setItem(i, 4, issueDateItem);
            ui->tableWidget->setItem(i, 5, dueDateItem);
        }
    }
}
void MainWindow::sortButtonClicked()
{
    ui->tableWidget->sortItems(0, Qt::AscendingOrder);
}

void MainWindow::onAddButtonClicked()
{
    QString projectName = ui->projectLineEdit->text();
    QString task = ui->taskLineEdit->text();
    QString executor = ui->executorLineEdit->text();
    QString issueDateStr = ui->issueDateLineEdit->text();
    QString supervisor = ui->supervisorLineEdit->text();
    QString dueDateStr = ui-> dueDateLineEdit->text();

    QDate issueDate = QDate::fromString(issueDateStr, "dd.MM.yyyy");
    if (!issueDate.isValid()) {
        QMessageBox::warning(this, "Ошибка", "Некорректная дата.");
        return;
    }
    QDate dueDate = QDate::fromString(dueDateStr, "dd.MM.yyyy");
    if (!dueDate.isValid()) {
        QMessageBox::warning(this, "Ошибка", "Некорректная дата.");
        return;
    }

    Task* newTask = new Task(projectName, task, executor, supervisor, issueDate, dueDate);

    tasks.push_back(newTask);

    int row = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(row);

    QTableWidgetItem *projectItem = new QTableWidgetItem(projectName);
    QTableWidgetItem *taskItem = new QTableWidgetItem(task);
    QTableWidgetItem *executorItem = new QTableWidgetItem(executor);
    QTableWidgetItem *issueDateItem = new QTableWidgetItem(issueDateStr);
    QTableWidgetItem *supervisorItem = new QTableWidgetItem(supervisor);
    QTableWidgetItem *dueDateItem = new QTableWidgetItem(dueDateStr);

    ui->tableWidget->setItem(row, 0, projectItem);
    ui->tableWidget->setItem(row, 1, taskItem);
    ui->tableWidget->setItem(row, 2, executorItem);
    ui->tableWidget->setItem(row, 3, supervisorItem);
    ui->tableWidget->setItem(row, 4, issueDateItem);
    ui->tableWidget->setItem(row, 5, dueDateItem);
}
void MainWindow::onDeleteButtonClicked()
{
    removeSelectedTableRow();
}
void MainWindow::onEditButtonClicked()
{
    int selectedRow = ui->tableWidget->currentRow();
    if (selectedRow >= 0) {
        QString projectName = ui->projectLineEdit->text();
        QString task = ui->taskLineEdit->text();
        QString executor = ui->executorLineEdit->text();
        QString supervisor = ui->supervisorLineEdit->text();
        QString issueDateStr = ui->issueDateLineEdit->text();
        QString dueDateStr = ui->dueDateLineEdit->text();

        QTableWidgetItem* projectNameItem = ui->tableWidget->item(selectedRow, 0);
        QTableWidgetItem* taskItem = ui->tableWidget->item(selectedRow, 1);
        QTableWidgetItem* executorItem = ui->tableWidget->item(selectedRow, 2);
        QTableWidgetItem* supervisorItem = ui->tableWidget->item(selectedRow, 3);
        QTableWidgetItem* issueDateItem = ui->tableWidget->item(selectedRow, 4);
        QTableWidgetItem* dueDateItem = ui->tableWidget->item(selectedRow, 5);

        if (!projectName.isEmpty()) {
            projectNameItem->setText(projectName);
        }
        if (!task.isEmpty()) {
            taskItem->setText(task);
        }
        if (!executor.isEmpty()) {
            executorItem->setText(executor);
        }
        if (!supervisor.isEmpty()) {
            supervisorItem->setText(supervisor);
        }
        if (!issueDateStr.isEmpty()) {
            QDate issueDate = QDate::fromString(issueDateStr, "dd.MM.yyyy");
            if (!issueDate.isValid()) {
                QMessageBox::warning(this, "Ошибка", "Некорректная дата.");
                return;
            }
            issueDateItem->setText(issueDateStr);
        }
        if (!dueDateStr.isEmpty()) {
            QDate dueDate = QDate::fromString(dueDateStr, "dd.MM.yyyy");
            if (!dueDate.isValid()) {
                QMessageBox::warning(this, "Ошибка", "Некорректная дата.");
                return;
            }
            dueDateItem->setText(dueDateStr);
        }

        Task* editedTask = tasks[selectedRow];
        editedTask->projectName = projectNameItem->text();
        editedTask->task = taskItem->text();
        editedTask->executor = executorItem->text();
        editedTask->supervisor = supervisorItem->text();
        editedTask->issueDate = QDate::fromString(issueDateItem->text(), "dd.MM.yyyy");
        editedTask->dueDate = QDate::fromString(dueDateItem->text(), "dd.MM.yyyy");

    }
}

void MainWindow::showTasksButtonClicked()
{

    ui->projectLineEdit->clear();
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(tasks.size());
    for (int i = 0; i < tasks.size(); ++i) {
        Task* task = tasks.at(i);
        QTableWidgetItem* projectNameItem = new QTableWidgetItem(task->getProjectName());
        QTableWidgetItem* taskItem = new QTableWidgetItem(task->getTask());
        QTableWidgetItem* executorItem = new QTableWidgetItem(task->getExecutor());
        QTableWidgetItem* supervisorItem = new QTableWidgetItem(task->getSupervisor());
        QTableWidgetItem* issueDateItem = new QTableWidgetItem(task->getIssueDate().toString("dd.MM.yyyy"));
        QTableWidgetItem* dueDateItem = new QTableWidgetItem(task->getDueDate().toString("dd.MM.yyyy"));

        ui->tableWidget->setItem(i, 0, projectNameItem);
        ui->tableWidget->setItem(i, 1, taskItem);
        ui->tableWidget->setItem(i, 2, executorItem);
        ui->tableWidget->setItem(i, 3, supervisorItem);
        ui->tableWidget->setItem(i, 4, issueDateItem);
        ui->tableWidget->setItem(i, 5, dueDateItem);
    }
}
