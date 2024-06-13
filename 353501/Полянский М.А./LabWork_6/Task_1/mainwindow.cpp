#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(): ui(new Ui::MainWindow) {
  ui->setupUi(this);
  fillData();
  ui->material->setMaxLength(1);
  connect(ui->name, &QLineEdit::textChanged, [&](QString newval){kidtoy->SetName(newval);});

  connect(ui->ageCat, &QSpinBox::valueChanged, 
          [&](int val){kidtoy->SetAgeCar(val);});
  
  connect(ui->price, &QDoubleSpinBox::valueChanged,
    [&](double val){kidtoy->SetPrice(val);});

  connect(ui->material, &QLineEdit::textChanged,
  [&](QString val){kidtoy->SetMaterial(val[0]);});

  connect(ui->safety, &QCheckBox::stateChanged,
  [&](int check){kidtoy->SetSafety(check == Qt::Checked);});

  connect(ui->poscom, &QSpinBox::valueChanged, 
  [&](long long val){kidtoy->SetComment(0, val);});

  connect(ui->negotivecom, &QSpinBox::valueChanged,
  [&](long long val){kidtoy->SetComment(1, val);});
}


void MainWindow::fillData(){
  ui->name->setText(kidtoy->GetName());
  ui->ageCat->setValue(kidtoy->GetAgeCar());
  ui->price->setValue(kidtoy->GetPrice());
  ui->material->setText(QString(kidtoy->GetMaterial()));
  ui->safety->setChecked(kidtoy->GetSafety());
  ui->poscom->setValue(kidtoy->GetComment(0));
  ui->negotivecom->setValue(kidtoy->GetComment(1));
}


void MainWindow::on_print_clicked()
{
  QPrinter printer;
  QPrintDialog dialog(&printer, this);
  dialog.setWindowTitle(tr("Print Report"));
  if (dialog.exec() != QDialog::Accepted)
    return;


  QTextDocument td;
  td.setHtml(kidtoy->generateReport());
  td.print(&printer);
}