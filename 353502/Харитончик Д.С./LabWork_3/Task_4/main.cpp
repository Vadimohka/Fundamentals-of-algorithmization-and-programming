#include <QApplication>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QString>
#include <QTextBrowser>

class HanoiTower : public QMainWindow
{
Q_OBJECT

public:
    HanoiTower(QWidget *parent = nullptr)
            : QMainWindow(parent)
    {
        setWindowTitle("Task 4");
        QWidget *centralWidget = new QWidget(this);
        QVBoxLayout *layout = new QVBoxLayout;

        nLineEdit = new QLineEdit(this);
        QLabel *nLabel = new QLabel("Enter the number of rings:", this);

        stepsTextBrowser = new QTextBrowser(this);

        layout->addWidget(nLabel);
        layout->addWidget(nLineEdit);
        layout->addWidget(stepsTextBrowser);

        centralWidget->setLayout(layout);
        setCentralWidget(centralWidget);

        connect(nLineEdit, &QLineEdit::textChanged, this, &HanoiTower::solveHanoi);
    }

private slots:
    void solveHanoi()
    {
        QString nText = nLineEdit->text();

        bool nOk;
        int n = nText.toInt(&nOk);

        if (nOk)
        {
            stepsTextBrowser->clear();
            hanoi(n, 'A', 'C', 'B');
        }
        else
        {
            stepsTextBrowser->setText("Invalid number format");
        }
    }

private:
    void hanoi(int n, char from, char to, char aux)
    {
        if (n == 1)
        {
            stepsTextBrowser->append(QString("Move the ring %1 from %2 to %3").arg(n).arg(from).arg(to));
            return;
        }

        hanoi(n - 1, from, aux, to);
        stepsTextBrowser->append(QString("Move the ring %1 from %2 to %3").arg(n).arg(from).arg(to));
        hanoi(n - 1, aux, to, from);
    }

    QLineEdit *nLineEdit;
    QTextBrowser *stepsTextBrowser;
};

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    HanoiTower window;
    window.show();

    return app.exec();
}

#include "main.moc"
