#include <QApplication>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QString>

class NumberReverser : public QMainWindow
{
Q_OBJECT

public:
    NumberReverser(QWidget *parent = nullptr)
            : QMainWindow(parent)
    {
        setWindowTitle("Task 3");
        QWidget *centralWidget = new QWidget(this);
        QVBoxLayout *layout = new QVBoxLayout;

        nLineEdit = new QLineEdit(this);
        QLabel *nLabel = new QLabel("Enter number (without zeros):", this);

        resultLabel = new QLabel(this);
        QLabel *resultDescLabel = new QLabel("Number in reverse order:", this);

        layout->addWidget(nLabel);
        layout->addWidget(nLineEdit);
        layout->addWidget(resultDescLabel);
        layout->addWidget(resultLabel);

        centralWidget->setLayout(layout);
        setCentralWidget(centralWidget);

        connect(nLineEdit, &QLineEdit::textChanged, this, &NumberReverser::reverseNumber);
    }

private slots:
    void reverseNumber()
    {
        QString nText = nLineEdit->text();

        bool nOk;
        int n = nText.toInt(&nOk);

        if (nOk)
        {
            int result = reverse(n);
            resultLabel->setText(QString::number(result));
        }
        else
        {
            resultLabel->setText("Invalid number format");
        }
    }

private:
    int reverse(int n)
    {
        if (n < 10)
            return n;

        int lastDigit = n % 10;
        int remainingDigits = n / 10;
        int reversed = reverse(remainingDigits);

        int digitsCount = 1;
        int temp = remainingDigits;
        while (temp > 0)
        {
            digitsCount *= 10;
            temp /= 10;
        }

        return lastDigit * digitsCount + reversed;
    }

    QLineEdit *nLineEdit;
    QLabel *resultLabel;
};

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    NumberReverser window;
    window.show();

    return app.exec();
}

#include "main.moc"
