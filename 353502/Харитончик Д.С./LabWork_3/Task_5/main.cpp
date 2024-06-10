#include <QApplication>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QString>
#include <QFileDialog>
#include <QDir>
#include <QDesktopServices>

class FolderCounter : public QMainWindow
{
public:
    FolderCounter(QWidget *parent = nullptr)
            : QMainWindow(parent)
    {
        setWindowTitle("Task 5");
        QWidget *centralWidget = new QWidget(this);
        QVBoxLayout *layout = new QVBoxLayout;

        pathLineEdit = new QLineEdit(this);
        QLabel *pathLabel = new QLabel("Enter the path to the main folder", this);

        countLabel = new QLabel(this);
        QLabel *countDescLabel = new QLabel("Total number of folders and files:", this);

        openButton = new QPushButton("Open file", this);

        layout->addWidget(pathLabel);
        layout->addWidget(pathLineEdit);
        layout->addWidget(countDescLabel);
        layout->addWidget(countLabel);
        layout->addWidget(openButton);

        centralWidget->setLayout(layout);
        setCentralWidget(centralWidget);

        connect(pathLineEdit, &QLineEdit::textChanged, this, &FolderCounter::countFoldersAndFiles);
        connect(openButton, &QPushButton::clicked, this, &FolderCounter::openSelectedFile);
    }

private:
    void countFoldersAndFiles()
    {
        QString path = pathLineEdit->text();
        QDir dir(path);

        int folders = 0;
        int files = 0;

        countFoldersAndFilesRecursive(dir, folders, files);

        countLabel->setText(QString("Folders: %1, Files: %2").arg(folders).arg(files));
    }

    void countFoldersAndFilesRecursive(QDir dir, int &folders, int &files)
    {
        QFileInfoList fileInfoList = dir.entryInfoList(QDir::AllEntries | QDir::NoDotAndDotDot);
        for (const QFileInfo &fileInfo : fileInfoList)
        {
            if (fileInfo.isDir())
            {
                folders++;
                QDir subDir(fileInfo.filePath());
                countFoldersAndFilesRecursive(subDir, folders, files);
            }
            else if (fileInfo.isFile())
            {
                files++;
            }
        }
    }

    void openSelectedFile()
    {
        QString path = pathLineEdit->text();
        QString filePath = QFileDialog::getOpenFileName(this, "Open file", path);
        if (!filePath.isEmpty())
        {
            QDesktopServices::openUrl(QUrl("file:///" + filePath));
        }
    }

    QLineEdit *pathLineEdit;
    QLabel *countLabel;
    QPushButton *openButton;
};

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    FolderCounter window;
    window.show();

    return app.exec();
}
