#include <QApplication>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QString>

class FunctionCalculator : public QMainWindow
{
Q_OBJECT

public:
    FunctionCalculator(QWidget *parent = nullptr)
            : QMainWindow(parent)
    {
        setWindowTitle("Task 2");
        QWidget *centralWidget = new QWidget(this);
        QVBoxLayout *layout = new QVBoxLayout;

        mLineEdit = new QLineEdit(this);
        QLabel *mLabel = new QLabel("Enter m:", this);

        nLineEdit = new QLineEdit(this);
        QLabel *nLabel = new QLabel("Enter n:", this);

        resultLabel = new QLabel(this);
        QLabel *resultDescLabel = new QLabel("Result A(m, n):", this);

        layout->addWidget(mLabel);
        layout->addWidget(mLineEdit);
        layout->addWidget(nLabel);
        layout->addWidget(nLineEdit);
        layout->addWidget(resultDescLabel);
        layout->addWidget(resultLabel);

        centralWidget->setLayout(layout);
        setCentralWidget(centralWidget);

        connect(mLineEdit, &QLineEdit::textChanged, this, &FunctionCalculator::calculateFunction);
        connect(nLineEdit, &QLineEdit::textChanged, this, &FunctionCalculator::calculateFunction);
    }

private slots:
    void calculateFunction()
    {
        QString mText = mLineEdit->text();
        QString nText = nLineEdit->text();

        bool mOk, nOk;
        int m = mText.toInt(&mOk);
        int n = nText.toInt(&nOk);

        if (mOk && nOk)
        {
            long long result = calculateA(m, n);
            resultLabel->setText(QString::number(result));
        }
        else
        {
            resultLabel->setText("Invalid number format");
        }
    }

private:
    long long calculateA(int m, int n)
    {
        if (m == 0)
            return n + 1;
        if (n == 0)
            return calculateA(m - 1, 1);

        if (m == 1)
            return n + 2;
        if (m == 2)
            return 2 * n + 3;

        long long result = n + 3;
        for (int i = 0; i < n - 1; ++i)
        {
            result = 2 * result - 1;
        }
        return result;
    }

    QLineEdit *mLineEdit;
    QLineEdit *nLineEdit;
    QLabel *resultLabel;
};

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    FunctionCalculator window;
    window.show();

    return app.exec();
}

#include "../Lab3_1/cmake-build-debug/Lab3_1_autogen/include/main.moc"
