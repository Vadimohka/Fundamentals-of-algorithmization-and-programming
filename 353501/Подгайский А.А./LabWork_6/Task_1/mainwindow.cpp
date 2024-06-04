#include "mainwindow.h"
#include "Footwear.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <iterator>
#include <qfontmetrics.h>
#include <qgraphicsscene.h>
#include <qmessagebox.h>
#include <qnamespace.h>
#include <qprintdialog.h>
#include <qprinter.h>
#include <qtypes.h>
#include <stdexcept>
#include <QPrinter>
#include <QPrintDialog>
#include <QPainter>
#include <QGraphicsTextItem>
MainWindow::MainWindow() : ui(new Ui::MainWindow) {
  ui->setupUi(this);

  {
    QStringList lst;
    for (int i = 0; i < std::size(Footwear::SIZES); ++i) {
      lst.push_back(QString::number(Footwear::SIZES[i], 'g', 3));
    }
    ui->euSizeBox->addItems(lst);
  }

  {
    QStringList lst;
    for (int i = 0; i < std::size(Footwear::TYPES); ++i) {
      lst.push_back(QString(Footwear::TYPES[i]));
    }
    ui->genderBox->addItems(lst);
  }

  initDefaultFootwear();
}

MainWindow::~MainWindow() {
  if (fw) {
    delete fw;
  }
  delete ui;
}

void MainWindow::initDefaultFootwear() {
  // 1. Обращаться ко всем полям отдельно
  Footwear def_fw{};
  def_fw.gender = 'M';
  def_fw.eu_size = 37;
  def_fw.is_child = false;
  def_fw.name = "Nike Air Jordan";
  ui->fwData->setText(QString::fromStdString(def_fw.to_string()));
}

void MainWindow::on_initialiseButton_clicked() {
  // 2. Инициализирующая строка
  auto init_s = ui->initislizerEdit->text();
  Footwear *new_fw;
  try {

    new_fw = new Footwear(init_s.toStdString());

  } catch (const std::invalid_argument &ex) {

    QString what = ex.what();
    if (what == "stoi") {
      what = "Bad initialiser string";
    }
    QMessageBox::warning(
        this, "Warning",
        "No footwear was initialised: " + what +
            "\nAlso make sure to remove extra spaces and characters.");
    return;

  }

  resetFootwear(new_fw);
}

void MainWindow::on_initialiseValuesButton_clicked() {
  uchar way = std::rand() % 2;
  // 3 и 4. Либо по указателю, либо по ссылке в зависимости от рандомного
  // значения
  Footwear *new_fw = new Footwear();
  bool ok = true;
  if (way) {
    // 3. По указателю
    new_fw->name = ui->nameEdit->text().toStdString();

    double eu_size = ui->euSizeBox->currentText().toDouble();
    new_fw->eu_size = eu_size;

    char gen = ui->genderBox->currentText()[0].toLatin1();
    new_fw->gender = gen;

    bool isChild = ui->isChildBox->checkState();
    new_fw->is_child = isChild;
  } else {
    Footwear &new_fw_rf = *new_fw;

    new_fw_rf.name = ui->nameEdit->text().toStdString();

    double eu_size = ui->euSizeBox->currentText().toDouble();
    new_fw_rf.eu_size = eu_size;

    char gen = ui->genderBox->currentText()[0].toLatin1();
    new_fw_rf.gender = gen;

    bool isChild = ui->isChildBox->checkState();
    new_fw_rf.is_child = isChild;
  }

  resetFootwear(new_fw);
}

void MainWindow::resetFootwear(Footwear *new_fw) {
  if (fw) {
    delete fw;
    fw = nullptr;
  }
  fw = new_fw;
  ui->fwData->setText(QString::fromStdString(fw->to_string()));
}

void MainWindow::on_printButton_clicked() {

  QPrinter printer;
  QPrintDialog *dialog = new QPrintDialog(&printer);
  if(dialog->exec() != QPrintDialog::Accepted){
    return; 
  }

  const QString& src = ui->fwData->text();

QFont out_font = QFont("Monospace", 15);
  QFontMetrics fm(out_font);
  auto text_rect = fm.boundingRect(src);
  auto page_rect = printer.pageRect(QPrinter::DevicePixel);
  QRect out_rect = {(int)page_rect.x(),(int)page_rect.y(), (int)page_rect.width(), text_rect.height()};

  QPainter painter;
  painter.begin(&printer);
  painter.setFont(out_font);
  painter.drawText(out_rect, Qt::AlignTop|Qt::AlignHCenter, ui->fwData->text());
  painter.end();
  
}