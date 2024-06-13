//
// Created by acryoz on 14.2.24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "../headers/mainwindow.h"
#include "ui_MainWindow.h"


MainWindow::MainWindow(QWidget *parent) :
        QWidget(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    this->ticker = new QTimer;
    QObject::connect(this->ticker, SIGNAL(timeout()), SLOT(upd()));
    this->ticker->start(1000/60);
    this->triangle_button = new QRadioButton("△");
    QObject::connect(this->triangle_button, SIGNAL(clicked(bool)), this, SLOT(selectFigure()));

    this->rectangle_button = new QRadioButton("▭");
    QObject::connect(this->rectangle_button, SIGNAL(clicked(bool)), this, SLOT(selectFigure()));

    this->circle_button = new QRadioButton("⃝");
    QObject::connect(this->circle_button, SIGNAL(clicked(bool)), this, SLOT(selectFigure()));

    this->square_button = new QRadioButton("□");
    QObject::connect(this->square_button, SIGNAL(clicked(bool)), this, SLOT(selectFigure()));

    this->hexagon_button = new QRadioButton("⬡");
    QObject::connect(this->hexagon_button, SIGNAL(clicked(bool)), this, SLOT(selectFigure()));

    this->rhombus_button = new QRadioButton("▱");
    QObject::connect(this->rhombus_button, SIGNAL(clicked(bool)), this, SLOT(selectFigure()));

    this->pentagram_button= new QRadioButton("☆");
    QObject::connect(this->pentagram_button, SIGNAL(clicked(bool)), this, SLOT(selectFigure()));

    this->hexagram_button= new QRadioButton("☆(6)");
    QObject::connect(this->hexagram_button, SIGNAL(clicked(bool)), this, SLOT(selectFigure()));

    this->octagram_button= new QRadioButton("☆(8)");
    QObject::connect(this->octagram_button, SIGNAL(clicked(bool)), this, SLOT(selectFigure()));

    this->custom_button = new QRadioButton("⬠");
    QObject::connect(this->custom_button, SIGNAL(clicked(bool)), this, SLOT(selectFigure()));

    this->buttons = new QHBoxLayout;
    this->buttons->addWidget(triangle_button);
    this->buttons->addWidget(rectangle_button);
    this->buttons->addWidget(circle_button);
    this->buttons->addWidget(square_button);
    this->buttons->addWidget(hexagon_button);
    this->buttons->addWidget(rhombus_button);
    this->buttons->addWidget(pentagram_button);
    this->buttons->addWidget(hexagram_button);
    this->buttons->addWidget(octagram_button);
    this->buttons->addWidget(custom_button);

    this->draw_button = new QPushButton("Draw");
    this->draw_button->setMaximumWidth(200);

    this->canvas = new Canvas(this);
    this->canvas->setStyleSheet("border: 1px solid black");

    this->vbox = new QVBoxLayout;
    this->vbox->addLayout(buttons);
    this->vbox->addWidget(canvas);

    this->redact_area = new RedactArea;
    this->redact_area->setMaximumWidth(200);
    this->redact_area->setStyleSheet("border: 1px solid black");
    QObject::connect(this->draw_button, SIGNAL(clicked()), this->canvas, SLOT(newFigure()));
    QObject::connect(this->draw_button, SIGNAL(clicked()), SLOT(resetSliders()));

    this->choose_next = new QPushButton(">");
    QObject::connect(this->choose_next, SIGNAL(clicked()), this, SLOT(next()));

    this->choose_prev= new QPushButton("<");
    QObject::connect(this->choose_prev, SIGNAL(clicked()), this, SLOT(previous()));

    this->choice_buttons = new QHBoxLayout;
    this->choice_buttons->addWidget(this->choose_prev);
    this->choice_buttons->addWidget(this->choose_next);

    this->info = new QLabel;

    this->x_validator = new QDoubleValidator(0, this->size().width(), 2, this);
    this->y_validator = new QDoubleValidator(0, this->size().height(), 2, this);

    this->line1x = new QLineEdit;
    this->line1x->setMaximumWidth(100);
    this->line1x->setPlaceholderText("100");
    this->line1x->setValidator(this->x_validator);
    QObject::connect(this->line1x, SIGNAL(textChanged(const QString &)), this->canvas->figures[this->canvas->cur_figure], SLOT(setV1x(QString)));

    this->line2x = new QLineEdit;
    QObject::connect(this->line2x, SIGNAL(textChanged(const QString &)), this->canvas->figures[this->canvas->cur_figure], SLOT(setV2x(QString)));
    this->line2x->setMaximumWidth(100);
    this->line2x->setPlaceholderText("100");
    this->line2x->setValidator(this->x_validator);

    this->line3x = new QLineEdit;
    QObject::connect(this->line3x, SIGNAL(textChanged(const QString &)), this->canvas->figures[this->canvas->cur_figure], SLOT(setV3x(QString)));
    this->line3x->setMaximumWidth(100);
    this->line3x->setPlaceholderText("100");
    this->line3x->setValidator(this->x_validator);

    this->line4x = new QLineEdit;
    QObject::connect(this->line4x, SIGNAL(textChanged(const QString &)), this->canvas->figures[this->canvas->cur_figure], SLOT(setV4x(QString)));
    this->line4x->setMaximumWidth(100);
    this->line4x->setPlaceholderText("100");
    this->line4x->setValidator(this->x_validator);

    this->line1y = new QLineEdit;
    QObject::connect(this->line1y, SIGNAL(textChanged(const QString &)), this->canvas->figures[this->canvas->cur_figure], SLOT(setV1y(QString)));
    this->line1y->setMaximumWidth(100);
    this->line1y->setPlaceholderText("100");
    this->line1y->setValidator(this->y_validator);

    this->line2y = new QLineEdit;
    QObject::connect(this->line2y, SIGNAL(textChanged(const QString &)), this->canvas->figures[this->canvas->cur_figure], SLOT(setV2y(QString)));
    this->line2y->setMaximumWidth(100);
    this->line2y->setPlaceholderText("100");
    this->line2y->setValidator(this->y_validator);

    this->line3y = new QLineEdit;
    QObject::connect(this->line3y, SIGNAL(textChanged(const QString &)), this->canvas->figures[this->canvas->cur_figure], SLOT(setV3y(QString)));
    this->line3y->setMaximumWidth(100);
    this->line3y->setPlaceholderText("100");
    this->line3y->setValidator(this->y_validator);

    this->line4y = new QLineEdit;
    QObject::connect(this->line4y, SIGNAL(textChanged(const QString &)), this->canvas->figures[this->canvas->cur_figure], SLOT(setV4y(QString)));
    this->line4y->setMaximumWidth(100);
    this->line4y->setPlaceholderText("100");
    this->line4y->setValidator(this->y_validator);

    this->lines = new QGridLayout;
    this->lines->addWidget(this->line1x, 0, 0);
    this->lines->addWidget(this->line1y, 0, 1);

    this->lines->addWidget(this->line2x, 1, 0);
    this->lines->addWidget(this->line2y, 1, 1);

    this->lines->addWidget(this->line3x, 2, 0);
    this->lines->addWidget(this->line3y, 2, 1);

    this->lines->addWidget(this->line4x, 3, 0);
    this->lines->addWidget(this->line4y, 3, 1);

    this->redact_vbox = new QVBoxLayout;
    this->redact_vbox->addWidget(this->redact_area);
    this->redact_vbox->addLayout(this->lines);
    this->redact_vbox->addWidget(this->info);
    this->redact_vbox->addLayout(this->choice_buttons);
    this->redact_vbox->addWidget(this->draw_button);

    this->hbox = new QHBoxLayout;
    this->hbox->addLayout(vbox);
    this->hbox->addLayout(this->redact_vbox);

    this->setWindowTitle("Paint");
    this->resize(1200, 800);
    this->setLayout(hbox);
}

void MainWindow::upd(){
    QObject::disconnect(this->redact_area->scale_slider, nullptr, nullptr, nullptr);
    QObject::disconnect(this->redact_area->rotation_slider, nullptr, nullptr, nullptr);

    QObject::disconnect(this->line1x, nullptr, nullptr, nullptr);
    QObject::disconnect(this->line2x, nullptr, nullptr, nullptr);
    QObject::disconnect(this->line3x, nullptr, nullptr, nullptr);
    QObject::disconnect(this->line4x, nullptr, nullptr, nullptr);


    QObject::disconnect(this->line1y, nullptr, nullptr, nullptr);
    QObject::disconnect(this->line2y, nullptr, nullptr, nullptr);
    QObject::disconnect(this->line3y, nullptr, nullptr, nullptr);
    QObject::disconnect(this->line4y, nullptr, nullptr, nullptr);

    QObject::connect(this->line1x, SIGNAL(textChanged(const QString &)), this->canvas->figures[this->canvas->cur_figure], SLOT(setV1x(QString)));
    QObject::connect(this->line2x, SIGNAL(textChanged(const QString &)), this->canvas->figures[this->canvas->cur_figure], SLOT(setV2x(QString)));
    QObject::connect(this->line3x, SIGNAL(textChanged(const QString &)), this->canvas->figures[this->canvas->cur_figure], SLOT(setV3x(QString)));
    QObject::connect(this->line4x, SIGNAL(textChanged(const QString &)), this->canvas->figures[this->canvas->cur_figure], SLOT(setV4x(QString)));
    QObject::connect(this->line1y, SIGNAL(textChanged(const QString &)), this->canvas->figures[this->canvas->cur_figure], SLOT(setV1y(QString)));
    QObject::connect(this->line2y, SIGNAL(textChanged(const QString &)), this->canvas->figures[this->canvas->cur_figure], SLOT(setV2y(QString)));
    QObject::connect(this->line3y, SIGNAL(textChanged(const QString &)), this->canvas->figures[this->canvas->cur_figure], SLOT(setV3y(QString)));
    QObject::connect(this->line4y, SIGNAL(textChanged(const QString &)), this->canvas->figures[this->canvas->cur_figure], SLOT(setV4y(QString)));

    if(this->canvas->figures[this->canvas->cur_figure]->figure_id == 1 ||this->canvas->figures[this->canvas->cur_figure]->figure_id == 2){
        this->line1x->setText(QString::number(this->canvas->figures[this->canvas->cur_figure]->vertices[0].x()));
        this->line2x->setText(QString::number(this->canvas->figures[this->canvas->cur_figure]->vertices[1].x()));
        this->line3x->setText(QString::number(this->canvas->figures[this->canvas->cur_figure]->vertices[2].x()));
        if(this->canvas->figures[this->canvas->cur_figure]->figure_id == 2){
            this->line4x->setText(QString::number(this->canvas->figures[this->canvas->cur_figure]->vertices[3].x()));
        }
        this->line1y->setText(QString::number(this->canvas->figures[this->canvas->cur_figure]->vertices[0].y()));
        this->line2y->setText(QString::number(this->canvas->figures[this->canvas->cur_figure]->vertices[1].y()));
        this->line3y->setText(QString::number(this->canvas->figures[this->canvas->cur_figure]->vertices[2].y()));
        if(this->canvas->figures[this->canvas->cur_figure]->figure_id == 2){
            this->line4y->setText(QString::number(this->canvas->figures[this->canvas->cur_figure]->vertices[3].y()));
        }
    }



    QObject::connect(this->redact_area->rotation_slider, SIGNAL(valueChanged(int)), this->canvas->figures[canvas->cur_figure], SLOT(rotate(int)));
    QObject::connect(this->redact_area->scale_slider, SIGNAL(valueChanged(int)), this->canvas->figures[canvas->cur_figure], SLOT(resize(int)));



    this->info->setText("Area: "
    + QString::number(this->canvas->figures[this->canvas->cur_figure]->getArea())
    + "\nPerimeter: "
    + QString::number(this->canvas->figures[this->canvas->cur_figure]->getPerimeter())
    + "\nCentre: x: "
    + QString::number(this->canvas->figures[this->canvas->cur_figure]->getCentre().x())
    + " y: "
    + QString::number(this->canvas->figures[this->canvas->cur_figure]->getCentre().y())
    );
}

void MainWindow::resetSliders() {

    this->canvas->cur_figure += 1;
    this->upd();
    this->redact_area->rotation_slider->setValue((int)this->canvas->figures[this->canvas->cur_figure]->getAngle());
    this->redact_area->scale_slider->setValue((int)(5*this->canvas->figures[this->canvas->cur_figure]->getScale()));
    if(this->canvas->figures[this->canvas->cur_figure]->figure_id == 1 ||this->canvas->figures[this->canvas->cur_figure]->figure_id == 2){
        this->line1x->setText(QString::number(this->canvas->figures[this->canvas->cur_figure]->vertices[0].x()));
        this->line2x->setText(QString::number(this->canvas->figures[this->canvas->cur_figure]->vertices[1].x()));
        this->line3x->setText(QString::number(this->canvas->figures[this->canvas->cur_figure]->vertices[2].x()));
        if(this->canvas->figures[this->canvas->cur_figure]->figure_id == 2){
            this->line4x->setText(QString::number(this->canvas->figures[this->canvas->cur_figure]->vertices[3].x()));
        }
        this->line1y->setText(QString::number(this->canvas->figures[this->canvas->cur_figure]->vertices[0].y()));
        this->line2y->setText(QString::number(this->canvas->figures[this->canvas->cur_figure]->vertices[1].y()));
        this->line3y->setText(QString::number(this->canvas->figures[this->canvas->cur_figure]->vertices[2].y()));
        if(this->canvas->figures[this->canvas->cur_figure]->figure_id == 2){
            this->line4y->setText(QString::number(this->canvas->figures[this->canvas->cur_figure]->vertices[3].y()));
        }
    }
}


void MainWindow::next() {
    if(this->canvas->cur_figure < this->canvas->figures.size() - 1){
        this->resetSliders();
    }
}
void MainWindow::previous(){
    if(this->canvas->cur_figure > 1){
        this->canvas->cur_figure -= 2;
        this->resetSliders();
    }
}


void MainWindow::selectFigure() {
    if(this->triangle_button->isChecked()){
        this->canvas->selected_id = 0;
    }
    else if(this->rectangle_button->isChecked()){
        this->canvas->selected_id = 1;
    }
    else if(this->circle_button->isChecked()){
        this->canvas->selected_id = 2;
    }
    else if(this->square_button->isChecked()){
        this->canvas->selected_id = 3;
    }
    else if(this->hexagon_button->isChecked()){
        this->canvas->selected_id = 4;
    }
    else if(this->rhombus_button->isChecked()){
        this->canvas->selected_id = 5;
    }
    else if(this->pentagram_button->isChecked()){
        this->canvas->selected_id = 6;
    }
    else if(this->hexagram_button->isChecked()){
        this->canvas->selected_id = 7;
    }
    else if(this->octagram_button->isChecked()){
        this->canvas->selected_id = 8;
    }
    else if(this->custom_button->isChecked()){
        this->canvas->selected_id = 9;
    }
}


MainWindow::~MainWindow() {
    delete ui;
}
