#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->openBtn, &QPushButton::clicked, this, &MainWindow::open);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::open()
{
    m_path = QFileDialog::getExistingDirectory(nullptr, QObject::tr("Выберите папку"), "/home/masha", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    if (!m_path.isEmpty())
    {
        ui -> subfoldersLabel -> setText(QString::number(countSubfolders(m_path)));
        ui -> filesLabel -> setText(QString::number(countFiles(m_path)));
    }

}

long long MainWindow::countSubfolders(const QString& path)
{
    QDir directory(path);
    QFileInfoList allItems = directory.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot);
    long long foldersCount = allItems.size();

    for (const QFileInfo& item : allItems)
    {
        foldersCount += countSubfolders(item.filePath());
    }

    return foldersCount;
}

long long MainWindow::countFiles(const QString& path)
{
    QDir directory(path);
    QFileInfoList allItems = directory.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot);
    long long filesCount = 0;

    for (const QFileInfo& item : allItems)
    {
        if (item.isFile())
        {
            ++filesCount;
        }
        else if (item.isDir())
        {
            filesCount += countFiles(item.filePath());
        }
    }

    return filesCount;
}

