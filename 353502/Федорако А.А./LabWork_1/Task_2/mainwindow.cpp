#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  scene = new PaintScene();

  ui->graphicsView->setScene(scene);

  ui->graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);

  timerForUpdateInformation = new QTimer();
  timerForButtonsPlusSize = new QTimer();
  timerForButtonsMinusSize = new QTimer();
  timerForButtonsRotateLeft = new QTimer();
  timerForButtonsRotateRight = new QTimer();

  timerForUpdateInformation->setInterval(5);
  timerForButtonsPlusSize->setInterval(30);
  timerForButtonsMinusSize->setInterval(30);
  timerForButtonsRotateLeft->setInterval(20);
  timerForButtonsRotateRight->setInterval(20);

  connect(timerForUpdateInformation, &QTimer::timeout, this,
          &MainWindow::slotTimer);
  connect(timerForUpdateInformation, &QTimer::timeout, this,
          &MainWindow::updateLabel);
  connect(timerForButtonsPlusSize, &QTimer::timeout, this,
          &MainWindow::plusSize);
  connect(timerForButtonsMinusSize, &QTimer::timeout, this,
          &MainWindow::minusSize);
  connect(timerForButtonsRotateLeft, &QTimer::timeout, this,
          &MainWindow::rotateLeft);
  connect(timerForButtonsRotateRight, &QTimer::timeout, this,
          &MainWindow::rotateRight);
}

void MainWindow::clearLabel() {
  ui->ValueAreaLabel->setText(" ");
  ui->ValueCentreLabel->setText("(0,0)");
  ui->ValuePerimetrLabel->setText(" ");
  ui->ValueTypeFigureLabel->setText(" ");
}

void MainWindow::updateLabel() {
  timerForUpdateInformation->start();

  if (scene->getSizeSetFigures() != 0) {
    QString getNowFigureSelectionAreaString =
        QString::number(scene->getNowFigureSelection()->getArea());
    ui->ValueAreaLabel->setText(getNowFigureSelectionAreaString);
    QString getNowFigureSelectionCentreFirstCoordinateString =
        QString::number(scene->getNowFigureSelection()->getCentreFigure().x() +
                        scene->getNowFigureSelection()->getMoveFigureAlongX());
    QString getNowFigureSelectionCentreSecondCoordinateString =
        QString::number(scene->getNowFigureSelection()->getCentreFigure().y() +
                        scene->getNowFigureSelection()->getMoveFigureAlongY());
    ui->ValueCentreLabel->setText(
        '(' + getNowFigureSelectionCentreFirstCoordinateString + ',' +
        getNowFigureSelectionCentreSecondCoordinateString + ')');
    QString getNowFigureSelectionPerimetrString =
        QString::number(scene->getNowFigureSelection()->getPerimetr());
    ui->ValuePerimetrLabel->setText(getNowFigureSelectionPerimetrString);

    QString nameNowFigure;
    switch (scene->getNowFigureSelection()->getTypeFigure()) {
      case PaintScene::SquareTypeScene: {
        nameNowFigure = "Square";
        break;
      }
      case PaintScene::RombTypeScene: {
        nameNowFigure = "Romb";
        break;
      }
      case PaintScene::TriangleTypeScene: {
        nameNowFigure = "Triangle";
        break;
      }
      case PaintScene::RectangleTypeScene: {
        nameNowFigure = "Rectangle";
        break;
      }
      case PaintScene::CircleTypeScene: {
        nameNowFigure = "Circle";
        break;
      }
      case PaintScene::FivePointerStarTypeScene: {
        nameNowFigure = "Five pointer star";
        break;
      }
      case PaintScene::SixPointerStarTypeScene: {
        nameNowFigure = "Six pointer star";
        break;
      }
      case PaintScene::EightPointerStarTypeScene: {
        nameNowFigure = "Eight pointer star";
        break;
      }
      case PaintScene::HexagonTypeScene: {
        nameNowFigure = "Hexagon";
        break;
      }
    }
    ui->ValueTypeFigureLabel->setText(nameNowFigure);
  }
}

void MainWindow::slotTimer() {
  timerForUpdateInformation->stop();
  scene->setSceneRect(0, 0, ui->graphicsView->width() - 20,
                      ui->graphicsView->height() - 20);
}

void MainWindow::resizeEvent(QResizeEvent* event) {
  timerForUpdateInformation->start();
  QMainWindow::resizeEvent(event);
}

void MainWindow::on_Rectangle_clicked() {
  scene->setTypeFigure(PaintScene::RectangleTypeScene);
  figure->setTypeFigure(Figure::FigureRectangle);
}

void MainWindow::on_Rhombus_clicked() {
  scene->setTypeFigure(PaintScene::RombTypeScene);
  figure->setTypeFigure(Figure::FigureRomb);
}

void MainWindow::on_Square_clicked() {
  scene->setTypeFigure(PaintScene::SquareTypeScene);
  figure->setTypeFigure(Figure::FigureSquare);
}

void MainWindow::on_Close_clicked() {
  close();
}

void MainWindow::on_Clear_clicked() {
  clearLabel();
  scene->clearScene();
  scene->setTypeFigure(PaintScene::CircleTypeScene);
  figure->setTypeFigure(Figure::FigureCircle);
}

void MainWindow::on_Triangle_clicked() {
  scene->setTypeFigure(PaintScene::TriangleTypeScene);
  figure->setTypeFigure(Figure::FigureTriangle);
}

void MainWindow::on_Circle_clicked() {
  scene->setTypeFigure(PaintScene::CircleTypeScene);
  figure->setTypeFigure(Figure::FigureCircle);
}

void MainWindow::on_FivePointer_star_clicked() {
  scene->setTypeFigure(PaintScene::FivePointerStarTypeScene);
  figure->setTypeFigure(Figure::FigureFivePointerStar);
}

void MainWindow::on_SixPointer_star_clicked() {
  scene->setTypeFigure(PaintScene::SixPointerStarTypeScene);
  figure->setTypeFigure(Figure::FigureSixPointerStar);
}

void MainWindow::on_EightPointed_star_clicked() {
  scene->setTypeFigure(PaintScene::EightPointerStarTypeScene);
  figure->setTypeFigure(Figure::FigureEightPointerStar);
}

void MainWindow::on_Rotation_clicked() {
  if (scene->getSizeSetFigures() != 0) {
    scene->setTypeFigure(PaintScene::ChangePositionTypeScene);
    figure->setTypeFigure(Figure::ActionChangePosition);
  }
}

void MainWindow::on_nextFigure_clicked() {
  scene->changeToNextPointerSetFigure();
}

void MainWindow::on_backFigure_clicked() {
  scene->changeToPreviosPointerSetFigure();
}

void MainWindow::on_PlusSize_pressed() {
  timerForButtonsPlusSize->start();
}

void MainWindow::plusSize() {
  if (scene->getSizeSetFigures() != 0)
    scene->actionFigureSizeIncrease();
}

void MainWindow::on_PlusSize_released() {
  timerForButtonsPlusSize->stop();
}

void MainWindow::on_MinusSize_pressed() {
  timerForButtonsMinusSize->start();
}

void MainWindow::minusSize() {
  if (scene->getSizeSetFigures() != 0)
    scene->actionFigureSizeDecrease();
}

void MainWindow::on_MinusSize_released() {
  timerForButtonsMinusSize->stop();
}

void MainWindow::rotateLeft() {
  if (scene->getSizeSetFigures() != 0)
    scene->actionRotateFigureLeft();
}

void MainWindow::on_ChangeLeft_pressed() {
  timerForButtonsRotateLeft->start();
}

void MainWindow::on_ChangeLeft_released() {
  timerForButtonsRotateLeft->stop();
}

void MainWindow::on_ChangeRight_pressed() {
  timerForButtonsRotateRight->start();
}

void MainWindow::on_ChangeRight_released() {
  timerForButtonsRotateRight->stop();
}

void MainWindow::rotateRight() {
  if (scene->getSizeSetFigures() != 0)
    scene->actionRotateFigureRight();
}

void MainWindow::on_Hexagon_clicked() {
  scene->setTypeFigure(PaintScene::HexagonTypeScene);
}

void MainWindow::on_deleteFigureButton_clicked() {
  scene->deleteFigure();
  scene->updateNowFigureSelection();
  if (scene->getSizeSetFigures() == 0) {
    clearLabel();
  }
}
