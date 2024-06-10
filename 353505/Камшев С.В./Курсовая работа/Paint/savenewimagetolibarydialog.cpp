#include "savenewimagetolibarydialog.h"

SaveNewImageToLibaryDialog::SaveNewImageToLibaryDialog(int x, int y, QPixmap pixMap) {
    this->setGeometry(x + 200, y +  200, 280, 130);
    this->setFixedSize(400, 200);
    this->setWindowTitle("Окно сохранения фигуры");

    this->pixMap = pixMap;

    ans = false;

    UseOldLibary = new QCheckBox(this);
    UseOldLibary->setText("Добавить в существующую библиотеку");
    UseOldLibary->setGeometry(0, 10, 350, 20);

    FolderNameValidator* folderValidator = new FolderNameValidator;
    nameOfLibary = new QLineEdit(this);
    nameOfLibary->setGeometry(0, 30, 350, 20);
    nameOfLibary->setText("ИмяБиблиотеки");
    nameOfLibary->setValidator(folderValidator);


    FileNameValidaror* fileValidator = new FileNameValidaror;
    nameOfFile = new QLineEdit(this);
    nameOfFile->setGeometry(0, 50, 350, 20);
    nameOfFile->setText("Name.png");
    nameOfFile->setValidator(fileValidator);

    ChangeAdress = new QPushButton(this);
    ChangeAdress->setText("Адрес сохранения");
    ChangeAdress->setGeometry(0, 70, 350, 20);

    SavePushButton = new QPushButton(this);
    SavePushButton->setText("Сохранить");
    SavePushButton->setGeometry(150, 170, 100, 20);




    connect(UseOldLibary, SIGNAL(pressed()), this, SLOT(on_UseOldLibary_clicked()));
    connect(ChangeAdress, SIGNAL(pressed()), this, SLOT(on_ChangeAdress_clicked()));
    connect(SavePushButton, SIGNAL(pressed()), this, SLOT(on_SavePushButton_clicked()));


}

void SaveNewImageToLibaryDialog::Save()
{
    if (!QDir(initialPath).exists(nameOfFile->text())){
        FileName = initialPath + "/" + nameOfFile->text();
        pixMap.save(FileName, "PNG");
        ans = true;
        this->hide();
    }
    else{
        QMessageBox::critical(this, "Ошибка", "Такой файл уже существует");
        return;
    }


}

void SaveNewImageToLibaryDialog::on_UseOldLibary_clicked()
{
    if(!UseOldLibary->isChecked()){
        nameOfLibary->hide();
    }
    else{
        nameOfLibary->show();
    }
}

void SaveNewImageToLibaryDialog::on_ChangeAdress_clicked()
{
    initialPath = QFileDialog::getExistingDirectory();
}

void SaveNewImageToLibaryDialog::on_SavePushButton_clicked()
{
    if (!UseOldLibary->isChecked()){
        if (!QDir(initialPath).exists(nameOfLibary->text())){
            initialPath += "/" + nameOfLibary->text();
            QDir().mkdir(initialPath);
        }
        else {
            QMessageBox::critical(this, "Ошибка", "Такая папка уже существует");
            return;
        }
    }
    Save();
}
