#include "../Headers/widget.h"
#include "../Ui/ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent), ui(new Ui::Widget) {
    ui->setupUi(this);

    _scoreFile = USER_DATA_PATH;
    if (_scoreFile != nullptr && !input.is_open()) {
        input.open(_scoreFile.toUtf8(), std::ofstream::in);
    }
    if (input.is_open()) {
        std::string profileScore;
        std::getline(input, profileScore);
        _profileScore = std::stoi(profileScore);
        input.close();
    }

    ui->profileScore_lineEdit->setText("Profile Score: " + QString::number(_profileScore));
    QFont font = ui->profileScore_lineEdit->font();
    font.setPointSize(16);
    ui->profileScore_lineEdit->setFont(font);
}

Widget::~Widget() {
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event) {
    QPainter *painter = new QPainter;
    QRect *rect = new QRect(0, 0, this->width(), this->height());
    painter->begin(this);
    QImage * image  = new QImage("/home/zgdarya/QTWORKS/Nonogram/Files/Sakura.jpg");
    painter->drawImage(*rect,*image);
    painter->end();
}

void Widget::on_add_new_nonogram_clicked() {
    _path = QFileDialog::getOpenFileName(nullptr, "Open Files", "../Pictures", "png file (*.png);;");
}

void Widget::on_exit_clicked() {
    close();
}

void Widget::on_start_clicked() {
    if (_path != nullptr) {
        PictureService* pictureService = new PictureService(this);
        QImage image;
        image = QImage(_path);
        pictureService->createNonogram(image);
        pictureService->show();
    }
}


void Widget::on_updateScore_button_clicked() {
    if (_scoreFile != nullptr && !input.is_open()) {
        input.open(_scoreFile.toUtf8(), std::ofstream::in);
    }
    if (input.is_open()) {
        std::string profileScore;
        std::getline(input, profileScore);
        _profileScore = std::stoi(profileScore);
        input.close();
    }

    ui->profileScore_lineEdit->setText("Profile Score: " + QString::number(_profileScore));
    QFont font = ui->profileScore_lineEdit->font();
    font.setPointSize(16);
    ui->profileScore_lineEdit->setFont(font);
}

