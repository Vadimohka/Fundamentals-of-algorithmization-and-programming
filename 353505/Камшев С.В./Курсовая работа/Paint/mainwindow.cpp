#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QMenu* FileMenu = new QMenu;
    QAction* NewFileActioon = new QAction("Новый файл CTRL + N");
    QAction* OpenFileActioon = new QAction("Открыть файл CTRL + O");
    QAction*SaveFileActioon = new QAction("Сохранить как CTRL + S");
    QAction*OpenLibaryActioon = new QAction("Открыть библиотеку CTRL + R");
    QAction*CreateLibaryActioon = new QAction("Создать библиотеку CTRL + E");
    QAction*HelpActioon = new QAction("Справка F1");

    FileMenu->addAction(NewFileActioon);
    FileMenu->addAction(OpenFileActioon);
    FileMenu->addAction(SaveFileActioon);
    FileMenu->addAction(OpenLibaryActioon);
    FileMenu->addAction(CreateLibaryActioon);
    FileMenu->addAction(HelpActioon);

    FilePushButton = new QPushButton(this);
    FilePushButton->setText("Меню");
    FilePushButton->setGeometry(0, 0, 70, 20);
    FilePushButton->setMenu(FileMenu);

    WorkLabel = new QLabel(this);
    WorkLabel->setGeometry(0, 60, 100, 20);
    WorkLabel->setText("Paint");

    LabelForPaint = new QLabel(ui->scrollArea);
    LabelForPaint->setAlignment(Qt::AlignTop);
    ui->scrollArea->setWidget(LabelForPaint);

    Color1PushButton = new QPushButton(this);
    Color1PushButton->setPalette(Qt::black);
    Color1PushButton->setGeometry(100, 0, 20, 20);

    Color2PushButton = new QPushButton(this);
    Color2PushButton->setPalette(Qt::white);
    Color2PushButton->setGeometry(130, 0, 20, 20);

    FillChechBox = new QCheckBox(this);
    FillChechBox->setGeometry(130, 25, 80, 20);
    FillChechBox->setText("Заливка");


    WidthOfPenComboBox = new QComboBox(this);
    WidthOfPenComboBox->setGeometry(160, 0, 100, 20);
    QStringList ComboBoxList = {"1 px", "2 px", "3 px", "4 px", "5 px", "6 px", "7 px", "8 px", "9 px", "10 px"};
    WidthOfPenComboBox->addItems(ComboBoxList);

    ToolComboBox = new QComboBox(this);
    ComboBoxList = {"Карандаш", "Эллипс", "Стерка", "Прямоугольник", "Линия", "Треугольник", "Полигон", "Выделение области", "Заливка"};
    ToolComboBox->addItems(ComboBoxList);
    ToolComboBox->setGeometry(300, 0, 200, 20);

    LibaryComboBox = new QComboBox(this);
    LibaryComboBox->setGeometry(300, 40, 200, 20);
    LibaryComboBox->setVisible(false);

    ImageComboBox = new QComboBox(this);
    ImageComboBox->setGeometry(300, 70, 200, 20);
    ImageComboBox->setVisible(false);


    connect(OpenFileActioon, &QAction::triggered, [=](){OpenFile();});
    connect(HelpActioon, &QAction::triggered, [=](){showHelp();});

    connect(SaveFileActioon, &QAction::triggered, [=](){
        if (WorkArea == "Libary") {
            if (HasChanges){
                SaveNewImageToLibaryDialog * dialog = new SaveNewImageToLibaryDialog(this->x(), this->y(), VectorOfPixMap.back());
                dialog->exec();
                if (dialog->ans == true){
                    HasChanges = false;
                }
                else {
                    QMessageBox::information(this, "Внимание", "Не сохранено");
                }

            }
            else{
                QMessageBox::information(this, "Внимание", "Не было никаких изменений");
            }
        }
        else{
            SaveFile();
        }
    });
    connect(NewFileActioon, &QAction::triggered, [=](){newFile();});
    connect(CreateLibaryActioon, &QAction::triggered, [=](){
        if (HasChanges){
            SaveDialog * dialog = new SaveDialog(this->x(), this->y());
            dialog->exec();
            if (dialog->ans == 1){
                bool save = SaveFile();
                if (save){
                    CreateNewLibary();
                }
            }
            else if (dialog->ans == -1){
                CreateNewLibary();
            }
            else{
                return;
            }
        }
        else{
            CreateNewLibary();
        }
    });
    connect(OpenLibaryActioon, &QAction::triggered, [=](){OpenLibary();});
    connect(Color1PushButton, SIGNAL(pressed()), this, SLOT(on_Color1PushButton_clicked()));
    connect(Color2PushButton, SIGNAL(pressed()), this, SLOT(on_Color2PushButton_clicked()));
    connect(WidthOfPenComboBox, &QComboBox::activated, [&](){WidthOfPen = (WidthOfPenComboBox->currentText().split(' ')[0]).toInt();});
    connect(ToolComboBox, &QComboBox::activated, [&](){
        if (HasFill && ToolNumber == 8){
            HasFill = false;
            Repaint = true;
            ToolNumber = ToolComboBox->currentIndex() + 1;
            repaint();
        }
        ToolNumber = ToolComboBox->currentIndex() + 1;
        if (ToolNumber == 10 && !VectorOfLibarysName.isEmpty()){
            ImageComboBox->show();
            LibaryComboBox->show();
        }
        else{
            ImageComboBox->hide();
            LibaryComboBox->hide();
        }
    });
    connect(LibaryComboBox, &QComboBox::activated, [&](){ImageComboBox->clear(); ImageComboBox->addItems(VectorOfFilesName[LibaryComboBox->currentIndex()]);});

    newFile();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::newFile()
{
    if (WorkArea == "Libary") return;
    if (HasChanges) {
        SaveDialog * dialog = new SaveDialog(this->x(), this->y());
        dialog->exec();
        if (dialog->ans == 1){
            SaveFile();
            loadFile("/home/stepan/Kursach/untitled/template.png");
        }
        else if (dialog->ans == -1) loadFile("/home/stepan/Kursach/untitled/template.png");

    }
    else{
        loadFile("/home/stepan/Kursach/untitled/template.png");
    }
    appendPixMap = VectorOfPixMap.back();
}

void MainWindow::loadFile(QString nameOfFile)
{
    if (WorkArea == "Libary") return;
    WorkLabel->setText(WorkArea);
    VectorOfPixMap.clear();
    bool a = pix.load(nameOfFile);
    if (a){
        HasChanges = false;
        pix.scaled(1000, 1000, Qt::KeepAspectRatio);
        VectorOfPixMap.append(pix);
        LabelForPaint->setPixmap(VectorOfPixMap.back());

    }
    else QMessageBox::critical(this, "Ошибка", "Не удалось открыть файл");
    if (LabelForPaint->width() >= VectorOfPixMap.back().width() && LabelForPaint->height() >= VectorOfPixMap.back().height()) AddWhiteBackground();

}

void MainWindow::OpenFile()
{
    if (WorkArea == "Libary") return;
    if (HasChanges){
        SaveDialog * dialog = new SaveDialog(this->x(), this->y());
        dialog->exec();
        if (dialog->ans == 1){
            SaveFile();
            QString FileName = QFileDialog::getOpenFileName(this, tr("Открыть файл"), "/home/stepan/Изображения",tr("Изображения (*.png *.bmp *.jpg);;Все файлы (*.*)"));
            if (FileName != "") loadFile(FileName);
        }
        else if (dialog->ans == -1){
            QString FileName = QFileDialog::getOpenFileName(this, tr("Открыть файл"), "/home/stepan/Изображения",tr("Изображения (*.png *.bmp *.jpg);;Все файлы (*.*)"));
            if (FileName != "") loadFile(FileName);
        }
    }
    else{
        QString FileName = QFileDialog::getOpenFileName(this, tr("Открыть файл"), "/home/stepan/Изображения",tr("Изображения (*.png *.bmp *.jpg);;Все файлы (*.*)"));
        if (FileName != "") loadFile(FileName);
    }
}

bool MainWindow::SaveFile()
{    
    const QString initialPath = QDir::currentPath() + "/untitled.png";
    const QString FileName =
        QFileDialog::getSaveFileName(this, tr("Сохранить как"), initialPath,
                                     tr("Изображения PNG (*.png);;Изображения BMP (*.bmp);;")+
                                         tr("Изображения JPG (*.jpg);;Все файлы (*.*)"));

    if (!FileName.isEmpty()) {
        QFileInfo fi(FileName);
        bool b = VectorOfPixMap.back().save(FileName, fi.completeSuffix().toStdString().c_str());
        if (b) HasChanges = false;
        else QMessageBox::critical(this, tr("Ошибка"), tr("Не удалось сохранить файл"));
        return b;
    }
    return false;
}

void MainWindow::AddWhiteBackground()
{
    QPixmap scaledPixmap(LabelForPaint->width(), LabelForPaint->height());
    if(WorkArea == "Paint"){
        scaledPixmap.fill(Qt::white);

    }
    else{
        scaledPixmap.fill(Qt::transparent);
    }
    QPainter paint(&scaledPixmap);
    paint.drawPixmap(0, 0, VectorOfPixMap.back());
    VectorOfPixMap.back() = scaledPixmap;
    LabelForPaint->setPixmap(VectorOfPixMap.back());
}

void MainWindow::CropBackground()
{
    HasChanges = true;
    QPixmap scaledPixmap = VectorOfPixMap.back().copy(QRect(0,0, ui->scrollArea->width(), ui->scrollArea->height()));
    VectorOfPixMap.append(scaledPixmap);
    LabelForPaint->setPixmap(VectorOfPixMap.back());
}

void MainWindow::pen()
{
    HasChanges = true;
    painter.begin(&appendPixMap);
    painter.setPen(QPen(ColorOfPen, WidthOfPen, Qt::SolidLine));
    painter.drawLine(StartLinePoint, EndPoint);
    painter.end();
    LabelForPaint->setPixmap(appendPixMap);
}

void MainWindow::eraser()
{
    HasChanges = true;
    painter.begin(&appendPixMap);
    if (WorkArea == "Paint"){
        painter.setPen(QPen(Qt::white, WidthOfPen, Qt::SolidLine));
    }
    painter.drawLine(StartLinePoint, EndPoint);
    painter.end();
    LabelForPaint->setPixmap(appendPixMap);
}

void MainWindow::drawEllipse()
{
    appendPixMap = VectorOfPixMap.back();
    HasChanges = true;
    painter.begin(&appendPixMap);
    painter.setPen(QPen(ColorOfPen, WidthOfPen, Qt::SolidLine));
    if (FillChechBox->isChecked()) painter.setBrush(ColorOfFill);
    painter.drawEllipse(StartPoint + (EndPoint - StartPoint) / 2, (EndPoint - StartPoint).x() / 2, (EndPoint - StartPoint).y() / 2);
    painter.end();
    VectorOfPixMap.append(appendPixMap);
    LabelForPaint->setPixmap(VectorOfPixMap.back());
    repaint();
}

void MainWindow::drawRectangle()
{
    appendPixMap = VectorOfPixMap.back();
    HasChanges = true;
    painter.begin(&appendPixMap);
    painter.setPen(QPen(ColorOfPen, WidthOfPen, Qt::SolidLine));
    if (FillChechBox->isChecked()) painter.setBrush(ColorOfFill);
    painter.drawRect(StartPoint.x(), StartPoint.y(), (EndPoint - StartPoint).x(), (EndPoint - StartPoint).y());
    painter.end();
    VectorOfPixMap.append(appendPixMap);
    LabelForPaint->setPixmap(VectorOfPixMap.back());
    repaint();
}

void MainWindow::DrawLine()
{
    appendPixMap = VectorOfPixMap.back();
    HasChanges = true;
    painter.begin(&appendPixMap);
    painter.setPen(QPen(ColorOfPen, WidthOfPen, Qt::SolidLine));
    painter.drawLine(StartPoint, EndPoint);
    painter.end();
    VectorOfPixMap.append(appendPixMap);
    LabelForPaint->setPixmap(VectorOfPixMap.back());
    repaint();
}

void MainWindow::DrawTriangle()
{
    appendPixMap = VectorOfPixMap.back();
    HasChanges = true;
    QPoint point3 = QPoint(StartPoint.x() - (EndPoint.x() - StartPoint.x()), EndPoint.y());
    painter.begin(&appendPixMap);
    QPolygon polygon;
    polygon << StartPoint << EndPoint << point3;
    painter.setPen(QPen(ColorOfPen, WidthOfPen, Qt::SolidLine));
    if (FillChechBox->isChecked()) painter.setBrush(ColorOfFill);
    painter.drawPolygon(polygon);
    painter.end();
    VectorOfPixMap.append(appendPixMap);
    LabelForPaint->setPixmap(VectorOfPixMap.back());
    repaint();
}

void MainWindow::endPolygon()
{
    appendPixMap = VectorOfPixMap.back();
    HasChanges = true;
    painter.begin(&appendPixMap);
    painter.setPen(QPen(ColorOfPen, WidthOfPen, Qt::SolidLine));
    if (FillChechBox->isChecked()) painter.setBrush(ColorOfFill);
    QPolygon polygon;
    for (int i = 0 ; i < PolygonPoints.size(); ++i){
        polygon.append(PolygonPoints[i]);
    }
    painter.drawPolygon(polygon);
    painter.end();
    VectorOfPixMap.append(appendPixMap);
    LabelForPaint->setPixmap(VectorOfPixMap.back());
    HasPolygon = false;
    StartPolygonPoint = QPoint(-1, -1);
    repaint();
    PolygonPoints.clear();
}

void MainWindow::MakeShapeCorrect()
{
    if (ToolNumber == 2 || ToolNumber == 4){
        int deltaX = EndPoint.x() - StartPoint.x();
        int deltaY = EndPoint.y() - StartPoint.y();
        if (deltaX == 0 || deltaY == 0) return;
        if (abs(deltaX) < abs(deltaY)) deltaY = abs(deltaX) * deltaY/abs(deltaY);
        else deltaX = abs(deltaY) * deltaX/abs(deltaX);
        EndPoint = QPoint(StartPoint.x() + deltaX, StartPoint.y() + deltaY);
    }
    else if (ToolNumber == 5){
        int deltaX = EndPoint.x() - StartPoint.x();
        int deltaY = EndPoint.y() - StartPoint.y();
        if (abs(deltaX) > abs(deltaY)) EndPoint = QPoint(EndPoint.x(), StartPoint.y());
        else EndPoint = QPoint(StartPoint.x(), EndPoint.y());
    }
    else if (ToolNumber == 6){
        int y = StartPoint.y() + (EndPoint.y() - StartPoint.y()) / abs(EndPoint.y() - StartPoint.y()) * abs(EndPoint.x() - StartPoint.x()) * sqrt(3);
        EndPoint = QPoint(EndPoint.x(), y);
    }
}

void MainWindow::MoveFill()
{
    QPoint deltaPoint;
    HasChanges = true;
    if (FirstFillPoint.x() > EndFillPoint.x() && FirstFillPoint.y() > EndFillPoint.y()){
        deltaPoint = FirstFillPoint;
        FirstFillPoint = EndFillPoint;
        EndFillPoint = deltaPoint;
    }
    else if (FirstFillPoint.x() < EndFillPoint.x() && FirstFillPoint.y() > EndFillPoint.y()){
        deltaPoint = FirstFillPoint;
        FirstFillPoint = QPoint(FirstFillPoint.x(), EndFillPoint.y());
        EndFillPoint = QPoint(EndFillPoint.x(), deltaPoint.y());
    }
    else if (FirstFillPoint.x() > EndFillPoint.x() && FirstFillPoint.y() < EndFillPoint.y()){
        deltaPoint = FirstFillPoint;
        FirstFillPoint = QPoint(EndFillPoint.x(), FirstFillPoint.y());
        EndFillPoint = QPoint(deltaPoint.x(), EndFillPoint.y());
    }

    appendPixMap = VectorOfPixMap.back();
    deltaPoint = StartPoint - FirstFillPoint;
    QPixmap scaledPixmap, pixmap;
    scaledPixmap = VectorOfPixMap.back().copy(QRect(FirstFillPoint, EndFillPoint));
    pixmap = VectorOfPixMap.back().copy(QRect(FirstFillPoint, EndFillPoint));
    if (WorkArea == "Paint"){
        pixmap.fill(Qt::white);
    }
    else{
        pixmap.fill(Qt::transparent);
    }
    painter.begin(&appendPixMap);
    painter.drawPixmap(FirstFillPoint, pixmap);
    painter.drawPixmap(EndPoint - deltaPoint, scaledPixmap);
    painter.end();
    VectorOfPixMap.append(appendPixMap);
    LabelForPaint->setPixmap(VectorOfPixMap.back());
    repaint();

}

void MainWindow::ReturnOldPixMap()
{
    HasFill = false;
    if (VectorOfPixMap.size() > 1){
        VectorOfPixMap.pop_back();
        LabelForPaint->setPixmap(VectorOfPixMap.back());
    }
}

void MainWindow::FillingArea(QPoint point)
{
    QImage image = appendPixMap.toImage();
    const unsigned char *data = image.bits();
    int offset = (point.x() + point.y() * image.width()) * 4;
    QRgb colorOfPixel = qRgba(data[offset], data[offset + 1], data[offset + 2], data[offset + 3]);
    QColor color = QColor::fromRgba(colorOfPixel);
    if (color != colorOfStartFilling){
        return;
    }
    if ((color == ColorOfPen || (color.red() == ColorOfPen.blue() && color.green() == ColorOfPen.green() && color.blue() == ColorOfPen.red()))  ){
        return;
    }
    RecursionDepth++;
    painter.begin(&appendPixMap);
    painter.setPen(QPen(ColorOfPen, 1, Qt::SolidLine));
    painter.drawPoint(point);
    LabelForPaint->setPixmap(appendPixMap);
    painter.end();
    Repaint = true;
    repaint();
    if (RecursionDepth > 1000){
        return;
    }
    image = appendPixMap.toImage();
    if (point.x() > 0){
        int ind1 = (point.x() - 1 + point.y() * image.width()) * 4;
        QRgb colorOfPixel1 = qRgba(data[ind1], data[ind1 + 1], data[ind1 + 2], data[ind1 + 3]);
        QColor color1 = QColor::fromRgba(colorOfPixel1);
        if (!(color1 == ColorOfPen || color1 != colorOfStartFilling)){
            FillingArea(QPoint(point.x() - 1, point.y()));
        }

    }
    image = appendPixMap.toImage();
    if (point.x() < image.width()){
        int ind1 = (point.x() + 1 + point.y() * image.width()) * 4;
        QRgb colorOfPixel1 = qRgba(data[ind1], data[ind1 + 1], data[ind1 + 2], data[ind1 + 3]);
        QColor color1 = QColor::fromRgba(colorOfPixel1);
        if (!(color1 == ColorOfPen || color1 != colorOfStartFilling)){
            FillingArea(QPoint(point.x() + 1, point.y()));
        }

    }
    image = appendPixMap.toImage();
    if (point.y() > 0){
        int ind1 = (point.x() + (point.y() - 1) * image.width()) * 4;
        QRgb colorOfPixel1 = qRgba(data[ind1], data[ind1 + 1], data[ind1 + 2], data[ind1 + 3]);
        QColor color1 = QColor::fromRgba(colorOfPixel1);
        if (!(color1 == ColorOfPen || color1 != colorOfStartFilling)){
            FillingArea(QPoint(point.x(), point.y() - 1));
        }

    }
    image = appendPixMap.toImage();
    if (point.y() < image.height()){
        int ind1 = (point.x() + (point.y() + 1) * image.width()) * 4;
        QRgb colorOfPixel1 = qRgba(data[ind1], data[ind1 + 1], data[ind1 + 2], data[ind1 + 3]);
        QColor color1 = QColor::fromRgba(colorOfPixel1);
        if (!(color1 == ColorOfPen || color1 != colorOfStartFilling)){
            FillingArea(QPoint(point.x(), point.y() + 1));
        }
    }

}

void MainWindow::Copy()
{
    QPoint deltaPoint;
    if (FirstFillPoint.x() > EndFillPoint.x() && FirstFillPoint.y() > EndFillPoint.y()){
        deltaPoint = FirstFillPoint;
        FirstFillPoint = EndFillPoint;
        EndFillPoint = deltaPoint;
    }
    else if (FirstFillPoint.x() < EndFillPoint.x() && FirstFillPoint.y() > EndFillPoint.y()){
        deltaPoint = FirstFillPoint;
        FirstFillPoint = QPoint(FirstFillPoint.x(), EndFillPoint.y());
        EndFillPoint = QPoint(EndFillPoint.x(), deltaPoint.y());
    }
    else if (FirstFillPoint.x() > EndFillPoint.x() && FirstFillPoint.y() < EndFillPoint.y()){
        deltaPoint = FirstFillPoint;
        FirstFillPoint = QPoint(EndFillPoint.x(), FirstFillPoint.y());
        EndFillPoint = QPoint(deltaPoint.x(), EndFillPoint.y());
    }

    appendPixMap = VectorOfPixMap.back();
    deltaPoint = StartPoint - FirstFillPoint;
    QPixmap scaledPixmap, pixmap;
    CopyPixMap = VectorOfPixMap.back().copy(QRect(FirstFillPoint, EndFillPoint));
    LabelForPaint->setPixmap(VectorOfPixMap.back());
    Repaint = false;
    repaint();
}

void MainWindow::insert()
{
    HasChanges = true;
    QPoint deltaPoint = StartPoint - QPoint(0 ,0);
    appendPixMap = VectorOfPixMap.back();
    painter.begin(&appendPixMap);
    painter.drawPixmap(EndPoint - deltaPoint, CopyPixMap);
    painter.end();
    VectorOfPixMap.append(appendPixMap);
    LabelForPaint->setPixmap(VectorOfPixMap.back());
    repaint();
    Operation = "Move";
}

void MainWindow::CreateNewLibary()
{
    WorkArea = "Libary";
    WorkLabel->setText(WorkArea);
    HasChanges = false;
    tmpPix = VectorOfPixMap.back();
    QImage image(tmpPix.width(), tmpPix.height(), QImage::Format_ARGB32);
    image.fill(Qt::transparent);
    VectorOfPixMap.clear();
    VectorOfPixMap.append(QPixmap::fromImage(image));
    LabelForPaint->setPixmap(VectorOfPixMap.back());
    appendPixMap = VectorOfPixMap.back();
    repaint();

}

void MainWindow::OpenLibary()
{
    QVector <QPixmap> vector;
    QVector <QString> nameVector;
    QString initialPath = QFileDialog::getExistingDirectory();

    if (VectorOfLibarysName.contains(initialPath)){
        QMessageBox::critical(this, "Ошибка", "библиотека уже добавлена");
        return;
    }

    QDir directory(initialPath);
    QStringList pngFiles = directory.entryList(QStringList("*.png"), QDir::Files);

    if (pngFiles.isEmpty()){
        QMessageBox::critical(this, "Ошибка", "Не было найдено изображений");
        return;
    }

    for (int i = 0; i < pngFiles.size(); ++i){
        QString nameOfFile = pngFiles[i];
        nameVector.append(nameOfFile);
        nameOfFile = initialPath + "/" + pngFiles[i];
        QPixmap pix;
        pix.load(nameOfFile);
        vector.append(pix);
    }
    VectorOfLibarysPixMap.append(vector);
    VectorOfLibarysName.append(initialPath);
    VectorOfFilesName.append(nameVector);
    if (ToolComboBox->count() == 9){
        ToolComboBox->addItem("Файл из библиотеки");
    }
    LibaryComboBox->addItem(initialPath.split("/").back());
    LibaryComboBox->setCurrentIndex(LibaryComboBox->count() - 1);
    ImageComboBox->clear();
    ImageComboBox->addItems(nameVector);
}

void MainWindow::drawImage()
{
    QPoint deltaPoint;
    HasChanges = true;
    if (StartPoint.x() > EndPoint.x() && StartPoint.y() > EndPoint.y()){
        deltaPoint = StartPoint;
        StartPoint = EndPoint;
        EndPoint = deltaPoint;
    }
    else if (StartPoint.x() < EndPoint.x() && StartPoint.y() > EndPoint.y()){
        deltaPoint = StartPoint;
        StartPoint = QPoint(StartPoint.x(), EndPoint.y());
        EndPoint = QPoint(EndPoint.x(), deltaPoint.y());
    }
    else if (StartPoint.x() > EndPoint.x() && StartPoint.y() < EndPoint.y()){
        deltaPoint = StartPoint;
        StartPoint = QPoint(EndPoint.x(), StartPoint.y());
        EndPoint = QPoint(deltaPoint.x(), EndPoint.y());
    }
    painter.begin(&appendPixMap);
    painter.drawPixmap(StartPoint.x(), StartPoint.y() , EndPoint.x() - StartPoint.x(), EndPoint.y() - StartPoint.y(), LibaryPixMap);
    painter.end();

}

void MainWindow::showHelp()
{
    HelpMenu * menu = new HelpMenu;
    menu->exec();
}

void MainWindow::DrawPolygonLine()
{
    PolygonPoints.append(StartPoint);
    HasChanges = true;
    if (StartPolygonPoint == QPoint(-1, -1)){
        StartPolygonPoint = StartPoint;
        HasPolygon = true;
        return;
    }
    appendPixMap = VectorOfPixMap.back();
    painter.begin(&appendPixMap);
    painter.setPen(QPen(ColorOfPen, WidthOfPen, Qt::SolidLine));
    painter.drawLine(StartLinePoint, StartPoint);
    painter.end();
    VectorOfPixMap.append(appendPixMap);
    LabelForPaint->setPixmap(VectorOfPixMap.back());
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if ((event->modifiers() &Qt::ControlModifier) && event->key() == 83){
        if (WorkArea == "Paint"){
            SaveFile();
        }
        else{
            if (HasChanges){
                SaveNewImageToLibaryDialog * dialog = new SaveNewImageToLibaryDialog(this->x(), this->y(), VectorOfPixMap.back());
                dialog->exec();
                if (dialog->ans == true){
                    HasChanges = false;
                }
                else {
                    QMessageBox::information(this, "Внимание", "Не сохранено");
                }

            }
            else{
                QMessageBox::information(this, "Внимание", "Не было никаких изменений");
            }
        }
    }
    else if ((event->modifiers() &Qt::ControlModifier) && event->key() == 16777216 && WorkArea == "Libary"){
        WorkArea = "Paint";
        HasChanges = false;
        newFile();
    }
    else if ((event->modifiers() &Qt::ControlModifier) && event->key() == 78) newFile();
    else if ((event->modifiers() &Qt::ControlModifier) && event->key() == 79) OpenFile();
    else if ((event->modifiers() &Qt::ControlModifier) && event->key() == 90) ReturnOldPixMap();
    else if ((event->modifiers() &Qt::ControlModifier) && event->key() == 69) {
        if (HasChanges){
            SaveDialog * dialog = new SaveDialog(this->x(), this->y());
            dialog->exec();
            if (dialog->ans == 1){
                bool save = SaveFile();
                if (save) CreateNewLibary();
            }
            else if (dialog->ans == -1){
                CreateNewLibary();
            }
            else{
                return;
            }
        }
        else{
            CreateNewLibary();
        }

    }
    else if ((event->modifiers() &Qt::ControlModifier) && event->key() == 82) OpenLibary();
    else if (event->key() == 16777264) showHelp();
    if (HasFill){
        if ((event->modifiers() &Qt::ControlModifier) && event->key() == 67){
            Copy();
            HasFill = false;
            EndMove = false;
        }
    }
    if ((event->modifiers() &Qt::ControlModifier) && event->key() == 86){
        if (!CopyPixMap.isNull()){
            ToolNumber = 11;
            Operation = "Insert";
            tmpPix = VectorOfPixMap.back();
            painter.begin(&tmpPix);
            painter.drawPixmap(QPoint(0, 0), CopyPixMap);
            painter.end();
            LabelForPaint->setPixmap(tmpPix);
        }
    }

}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if (WorkArea != "Paint"){
        event->ignore();
        if (HasChanges){
            SaveDialog * dialog = new SaveDialog(this->x(), this->y());
            dialog->exec();
            if (dialog->ans == 1){
                SaveNewImageToLibaryDialog * dialog = new SaveNewImageToLibaryDialog(this->x(), this->y(), VectorOfPixMap.back());
                dialog->exec();
                if (dialog->ans == true){
                    HasChanges = false;
                    event->accept();
                }
                else {
                    QMessageBox::information(this, "Внимание", "Не сохранено");
                    event->Close;
                }
            }
            else if (dialog->ans == -1){
                event->accept();
            }
            else{
                event->Close;
            }
        }
        else{
            event->accept();
        }

    }
    else{
        event->ignore();
        if (HasChanges){
            SaveDialog * dialog = new SaveDialog(this->x(), this->y());
            dialog->exec();
            if (dialog->ans == 1){
                bool save = SaveFile();
                if (save) event->accept();
            }
            else if (dialog->ans == -1){
                event->accept();
            }
            else{
                event->Close;
            }
        }
        else{
            event->accept();
        }
    }
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    if (isSrart){
        isSrart = false;
        return;
    }
    if (event->oldSize().width() < event->size().width() || event->oldSize().height()< event->size().height()) AddWhiteBackground();
}

void MainWindow::on_Color1PushButton_clicked()
{

    QColor color = QColorDialog::getColor();
    if (color.isValid()){
        ColorOfPen = color;
        Color1PushButton->setPalette(color);
    }
}

void MainWindow::on_Color2PushButton_clicked()
{
    QColor color = QColorDialog::getColor();
    if (color.isValid()){
        ColorOfFill = color;
        Color2PushButton->setPalette(color);
    }
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    if (Repaint == true){
        if (ToolNumber == 1){
            pen();
        }
        else if (ToolNumber == 2){
            tmpPix = VectorOfPixMap.back();
            painter.begin(&tmpPix);
            painter.setPen(QPen(ColorOfPen, WidthOfPen, Qt::SolidLine));
            if (FillChechBox->isChecked()) painter.setBrush(ColorOfFill);
            painter.drawEllipse(StartPoint + (EndPoint - StartPoint) / 2, (EndPoint - StartPoint).x() / 2, (EndPoint - StartPoint).y() / 2);
            painter.end();
            LabelForPaint->setPixmap(tmpPix);
        }
        else if (ToolNumber == 3){
            eraser();
        }
        else if (ToolNumber == 4){
            tmpPix = VectorOfPixMap.back();
            painter.begin(&tmpPix);
            painter.setPen(QPen(ColorOfPen, WidthOfPen, Qt::SolidLine));
            if (FillChechBox->isChecked()) painter.setBrush(ColorOfFill);
            painter.drawRect(StartPoint.x(), StartPoint.y(), (EndPoint - StartPoint).x(), (EndPoint - StartPoint).y());
            painter.end();
            LabelForPaint->setPixmap(tmpPix);
        }
        else if (ToolNumber == 5)
        {
            tmpPix = VectorOfPixMap.back();
            painter.begin(&tmpPix);
            painter.setPen(QPen(ColorOfPen, WidthOfPen, Qt::SolidLine));
            painter.drawLine(StartPoint, EndPoint);
            painter.end();
            LabelForPaint->setPixmap(tmpPix);
        }
        else if (ToolNumber == 6){
            QPoint point3 = QPoint(StartPoint.x() - (EndPoint.x() - StartPoint.x()), EndPoint.y());
            QPolygon polygon;
            polygon << StartPoint << EndPoint << point3;
            tmpPix = VectorOfPixMap.back();
            painter.begin(&tmpPix);
            painter.setPen(QPen(ColorOfPen, WidthOfPen, Qt::SolidLine));
            if (FillChechBox->isChecked()) painter.setBrush(ColorOfFill);
            painter.drawPolygon(polygon);
            painter.end();
            LabelForPaint->setPixmap(tmpPix);
        }
        else if (ToolNumber == 8){
            if (!HasFill){
                tmpPix = VectorOfPixMap.back();
                painter.begin(&tmpPix);
                painter.setPen(QPen(Qt::black, 1, Qt::DashLine));
                painter.drawRect(FirstFillPoint.x(), FirstFillPoint.y(), (EndFillPoint - FirstFillPoint).x(), (EndFillPoint - FirstFillPoint).y());
                painter.end();
                LabelForPaint->setPixmap(tmpPix);
            }
            else{
                    QPoint deltaPoint;
                    if (FirstFillPoint.x() > EndFillPoint.x() && FirstFillPoint.y() > EndFillPoint.y()){
                        deltaPoint = FirstFillPoint;
                        FirstFillPoint = EndFillPoint;
                        EndFillPoint = deltaPoint;
                    }
                    else if (FirstFillPoint.x() < EndFillPoint.x() && FirstFillPoint.y() > EndFillPoint.y()){
                        deltaPoint = FirstFillPoint;
                        FirstFillPoint = QPoint(FirstFillPoint.x(), EndFillPoint.y());
                        EndFillPoint = QPoint(EndFillPoint.x(), deltaPoint.y());
                    }
                    else if (FirstFillPoint.x() > EndFillPoint.x() && FirstFillPoint.y() < EndFillPoint.y()){
                        deltaPoint = FirstFillPoint;
                        FirstFillPoint = QPoint(EndFillPoint.x(), FirstFillPoint.y());
                        EndFillPoint = QPoint(deltaPoint.x(), EndFillPoint.y());
                    }
                    tmpPix = VectorOfPixMap.back();
                    deltaPoint = StartPoint - FirstFillPoint;
                    QPixmap scaledPixmap, pixmap;
                    scaledPixmap = VectorOfPixMap.back().copy(QRect(FirstFillPoint, EndFillPoint));
                    pixmap = VectorOfPixMap.back().copy(QRect(FirstFillPoint, EndFillPoint));
                    if (WorkArea == "Paint"){
                        pixmap.fill(Qt::white);
                    }
                    else{
                        pixmap.fill(Qt::transparent);
                    }
                    painter.begin(&tmpPix);
                    painter.drawPixmap(FirstFillPoint, pixmap);
                    painter.drawPixmap(EndPoint - deltaPoint, scaledPixmap);
                    painter.end();
                    LabelForPaint->setPixmap(tmpPix);
            }
        }
        else if (ToolNumber == 11){
            QPoint deltaPoint;
            tmpPix = VectorOfPixMap.back();
            deltaPoint = StartPoint - QPoint(0 ,0);
            QPixmap scaledPixmap, pixmap;
            scaledPixmap = CopyPixMap;
            painter.begin(&tmpPix);
            painter.drawPixmap(EndPoint - deltaPoint, scaledPixmap);
            painter.end();
            LabelForPaint->setPixmap(tmpPix);
        }
        else if (ToolNumber == 10){
            LibaryPixMap = VectorOfLibarysPixMap[LibaryComboBox->currentIndex()][ImageComboBox->currentIndex()];
            tmpPix = VectorOfPixMap.back();
            QPoint deltaPoint;



            if (StartPoint.x() > EndPoint.x() && StartPoint.y() > EndPoint.y()){
                LibaryPixMap = LibaryPixMap.transformed(QTransform().scale(1, -1));
                LibaryPixMap = LibaryPixMap.transformed(QTransform().scale(-1, 1));
                painter.begin(&tmpPix);
                painter.drawPixmap(EndPoint.x(), EndPoint.y() , StartPoint.x() - EndPoint.x(), StartPoint.y() - EndPoint.y(), LibaryPixMap);
                painter.end();
            }
            else if (StartPoint.x() < EndPoint.x() && StartPoint.y() > EndPoint.y()){
                LibaryPixMap = LibaryPixMap.transformed(QTransform().scale(1, -1));
                painter.begin(&tmpPix);
                painter.drawPixmap(StartPoint.x(), EndPoint.y() , EndPoint.x() - StartPoint.x(), StartPoint.y() - EndPoint.y(), LibaryPixMap);
                painter.end();

            }
            else if (StartPoint.x() > EndPoint.x() && StartPoint.y() < EndPoint.y()){
                LibaryPixMap = LibaryPixMap.transformed(QTransform().scale(-1, 1));
                painter.begin(&tmpPix);
                painter.drawPixmap(EndPoint.x(), StartPoint.y() , StartPoint.x() - EndPoint.x(), EndPoint.y() - StartPoint.y(), LibaryPixMap);
                painter.end();
            }
            else{
                painter.begin(&tmpPix);
                painter.drawPixmap(StartPoint.x(), StartPoint.y() , EndPoint.x() - StartPoint.x(), EndPoint.y() - StartPoint.y(), LibaryPixMap);
                painter.end();
            }
            LabelForPaint->setPixmap(tmpPix);

        }
        Repaint = false;
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *ev)
{
    if (!(ev->buttons() & Qt::LeftButton)) return;
    StartLinePoint = EndPoint;
    EndPoint = ev->pos() - ui->scrollArea->pos() + QPoint(ui->scrollArea->horizontalScrollBar()->value(), ui->scrollArea->verticalScrollBar()->value());
    if (EndPoint.x() < 0 || EndPoint.x() > LabelForPaint->width() + LabelForPaint->x() || EndPoint.y() < 0 || EndPoint.y() > LabelForPaint->height() + LabelForPaint->y()) return;

    if (QGuiApplication::keyboardModifiers() & Qt::ShiftModifier) MakeShapeCorrect();
    Repaint = true;
    repaint();
    if (ToolNumber == 8 && !HasFill){
        EndFillPoint = ev->pos() - ui->scrollArea->pos() + QPoint(ui->scrollArea->horizontalScrollBar()->value(), ui->scrollArea->verticalScrollBar()->value());
    }

}

void MainWindow::mousePressEvent(QMouseEvent *ev)
{
    if (ev->button() != Qt::LeftButton) return;
    StartLinePoint = StartPoint;
    StartPoint = ev->pos() - ui->scrollArea->pos() + QPoint(ui->scrollArea->horizontalScrollBar()->value(), ui->scrollArea->verticalScrollBar()->value());
    EndPoint = ev->pos() - ui->scrollArea->pos() + QPoint(ui->scrollArea->horizontalScrollBar()->value(), ui->scrollArea->verticalScrollBar()->value());
    if (StartPoint.x() < 0 || StartPoint.x() > LabelForPaint->width() + LabelForPaint->x() || StartPoint.y() < 0 || StartPoint.y() > LabelForPaint->height() + LabelForPaint->y()) return;
    if (ToolNumber == 8){
        if (!HasFill){
            FirstFillPoint = ev->pos() - ui->scrollArea->pos() + QPoint(ui->scrollArea->horizontalScrollBar()->value(), ui->scrollArea->verticalScrollBar()->value());
            EndFillPoint = ev->pos() - ui->scrollArea->pos() + QPoint(ui->scrollArea->horizontalScrollBar()->value(), ui->scrollArea->verticalScrollBar()->value());
        }
    }
    if (ToolNumber == 7) DrawPolygonLine();
    else{
        HasPolygon = false;
        StartPolygonPoint = QPoint(-1, -1);
    }
    if (ToolNumber == 1 || ToolNumber == 3) appendPixMap = VectorOfPixMap.back();

    if (ToolNumber == 9){
        appendPixMap = VectorOfPixMap.back();
        QImage image = VectorOfPixMap.back().toImage();
        const unsigned char *data = image.bits();
        int offset = (StartPoint.x() + StartPoint.y() * image.width()) * 4;
        QRgb colorOfPixel = qRgba(data[offset], data[offset + 1], data[offset + 2], data[offset + 3]);
        colorOfStartFilling = QColor::fromRgba(colorOfPixel);
        FillingArea(StartPoint);

        RecursionDepth = 0;
        VectorOfPixMap.append(appendPixMap);
        LabelForPaint->setPixmap(VectorOfPixMap.back());
    }
    if (ToolNumber == 10){
        appendPixMap = VectorOfPixMap.back();
        LibaryPixMap = VectorOfLibarysPixMap[LibaryComboBox->currentIndex()][ImageComboBox->currentIndex()];
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *ev)
{
    if (ev->button() != Qt::LeftButton) return;
    if (ToolNumber == 1){
        VectorOfPixMap.append(appendPixMap);
        appendPixMap = VectorOfPixMap.back();
    }
    else if (ToolNumber == 2) drawEllipse();
    else if (ToolNumber == 3){
        VectorOfPixMap.append(appendPixMap);
        appendPixMap = VectorOfPixMap.back();
    }
    else if (ToolNumber == 4) drawRectangle();
    else if (ToolNumber == 5) DrawLine();
    else if (ToolNumber == 6) DrawTriangle();
    else if (ToolNumber == 8){
        if (HasFill == true){
            EndMove = true;
        }
        else{
            HasFill = true;
        }
        if (EndMove){
            MoveFill();
            HasFill = false;
            EndMove = false;
        }
    }
    else if (ToolNumber == 11){
        insert();
        ToolNumber = ToolComboBox->currentIndex() + 1;
    }
    else if (ToolNumber == 10){
        appendPixMap = VectorOfPixMap.back();
        drawImage();
        VectorOfPixMap.append(appendPixMap);
        LabelForPaint->setPixmap(VectorOfPixMap.back());
    }
}

void MainWindow::mouseDoubleClickEvent(QMouseEvent *event)
{
    if (event->button() == Qt::RightButton) CropBackground();
    else if (event->button() == Qt::LeftButton && ToolNumber == 7 && HasPolygon) endPolygon();
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    ToolNumber = ToolComboBox->currentIndex() + 1;
}
