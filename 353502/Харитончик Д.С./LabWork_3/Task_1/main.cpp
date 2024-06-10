#include <QApplication>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QString>

class ConverterToBinary : public QMainWindow
{
    Q_OBJECT

public:
    ConverterToBinary(QWidget *parent = nullptr)
            : QMainWindow(parent)
    {
        setWindowTitle("Task 1");
        QWidget *centralWidget = new QWidget(this);
        QVBoxLayout *layout = new QVBoxLayout;

        inputLineEdit = new QLineEdit(this);
        QLabel *inputLabel = new QLabel("Enter a decimal number:", this);

        outputLabel = new QLabel(this);
        QLabel *outputDescLabel = new QLabel("Binary representation:", this);

        layout->addWidget(inputLabel);
        layout->addWidget(inputLineEdit);
        layout->addWidget(outputDescLabel);
        layout->addWidget(outputLabel);

        centralWidget->setLayout(layout);
        setCentralWidget(centralWidget);

        connect(inputLineEdit, &QLineEdit::textChanged, this, &ConverterToBinary::convertToBinary);
    }

private slots:
    void convertToBinary()
    {
        QString inputText = inputLineEdit->text();
        bool ok;
        double decimalNumber = inputText.toDouble(&ok);

        if (ok)
        {
            QString binary = toBinary(decimalNumber);
            outputLabel->setText(binary);
        }
        else
        {
            outputLabel->setText("Invalid number format");
        }
    }

private:
    QString toBinary(int n)
    {
        if (n == 0)
            return "0";
        if (n == 1)
            return "1";
        if (n < 0)
            return "-" + toBinary(-n);

        if (n % 2 == 0)
            return toBinary(n / 2) + "0";
        else
            return toBinary(n / 2) + "1";
    }

    QString toBinary(double n)
    {
        int intPart = static_cast<int>(n);
        double fractionalPart = n - intPart;

        QString intBinary = toBinary(intPart);
        QString fractionalBinary = "";

        while (fractionalPart > 0 && fractionalBinary.length() < 6) // ограничение на длину дробной части
        {
            fractionalPart *= 2;
            int bit = static_cast<int>(fractionalPart);
            fractionalBinary += QString::number(bit);
            fractionalPart -= bit;
        }

        if (!fractionalBinary.isEmpty())
            return intBinary + "." + fractionalBinary;
        else
            return intBinary;
    }

    QLineEdit *inputLineEdit;
    QLabel *outputLabel;
};

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    ConverterToBinary window;
    window.show();

    return app.exec();
}

#include "main.moc"