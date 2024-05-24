#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    openBtn = new QPushButton("Открыть",this);
    openBtn->setGeometry(10,10,230,35);
    connect(openBtn,SIGNAL(clicked(bool)),SLOT(openDolphin()));

    Close = new QPushButton("Закрыть",this);
    Close->setGeometry(1060,10,100,800);
    connect(Close,SIGNAL(clicked(bool)),SLOT(My_close()));

    {
        fun_proshl_day = new QPushButton("Прошлый день",this);
        connect(fun_proshl_day,SIGNAL(clicked(bool)),SLOT(funPrevDay()));
        fun_proshl_day->setGeometry(10,10,230,35);

        Year_visok = new QPushButton("Год високосный ?",this);
        connect(Year_visok,SIGNAL(clicked(bool)),SLOT(funIsLeapYear()));
        Year_visok->setGeometry(10,50,230,35);

        What_number_week = new QPushButton("Какой номер недели",this);
        connect(What_number_week,SIGNAL(clicked(bool)),SLOT(funWeekNumber()));
        What_number_week->setGeometry(10,90,230,35);
    }

    {
        // Date_Birthday = new QLabel("Выберите дату дня рождения ",this);
        // Date_Birthday->setGeometry(10,140,230,35);

        // calendar_To_Se_Date_Birthday = new QDateEdit(this);
        // calendar_To_Se_Date_Birthday->setGeometry(10,170,230,35);
        // QDate date;
        // QDateTime o1o1ooo1;
        // calendar_To_Se_Date_Birthday->setDateTime(o1o1ooo1(QDate(1,1,1),QTime(0,0,0));


        // date.setDate(1,1,1);
        // calendar_To_Se_Date_Birthday->setMinimumDate(date);
        // date.setDate(9999, 12, 31);
        // calendar_To_Se_Date_Birthday->setMaximumDate(date);
        // calendar_To_Se_Date_Birthday->setDisplayFormat("dd MM yyyy");
        // calendar_To_Se_Date_Birthday->setDate(QDate::currentDate());
        // calendar_To_Se_Date_Birthday->setCalendarPopup(true);

        // fun_Day_for_next_HB = new QPushButton("Дней до дня рождения",this);
        // connect(fun_Day_for_next_HB,SIGNAL(clicked(bool)),SLOT(funBirthDay()));
        // fun_Day_for_next_HB->setGeometry(10,210,230,35);



        Date_Birthday = new QLabel("Выберите дату дня рождения ",this);
        Date_Birthday->setGeometry(10,140,230,35);

        edit = new QLineEdit(this);
        edit->setGeometry(10,170,230,35);
        // QDate date;
        // date.setDate(1,1,1);
        // edit->setDate(QDate(1,1,1));
        // //edit->setMinimumDate(date);
        // date.setDate(9999, 12, 31);
        // edit->setMaximumDate(date);
        //edit->setDisplayFormat("dd MM yyyy");
        //edit->setDate(QDate::currentDate());
        //edit->setCalendarPopup(true);

        fun_Day_for_next_HB = new QPushButton("Дней до дня рождения",this);
        connect(fun_Day_for_next_HB,SIGNAL(clicked(bool)),SLOT(funBirthDay()));
        fun_Day_for_next_HB->setGeometry(10,210,230,35);
    }

    {
        selectDateToFindLbl = new QLabel("Выберите Дату для Добавления/Поиска",this);
        selectDateToFindLbl->setGeometry(10,260,230,35);


        edit1 = new QLineEdit(this);
        //0add_new_date = new QDateEdit(this);
        edit1->setGeometry(10,290,230,35);
        //add_new_date->setDisplayFormat("dd MM yyyy");
        //add_new_date->setDate(QDate::currentDate());
        //add_new_date->setCalendarPopup(true);

        addThisDateBtn =  new QPushButton("Добавить дату",this);
        connect(addThisDateBtn,SIGNAL(clicked(bool)),SLOT(funAddDate()));
        addThisDateBtn->setGeometry(10,330,230,35);
    }

    {
        prob = new QLabel("Выберите дату для замены",this);
        prob->setGeometry(10,380,230,35);

        calendarReplaceToDate = new QLineEdit(this);
        calendarReplaceToDate->setGeometry(10,410,230,35);
        //calendarReplaceToDate->setDisplayFormat("dd MMM yyyy");
        //calendarReplaceToDate->setDate(QDate::currentDate());
        //calendarReplaceToDate->setCalendarPopup(true);

        cngThisDateBtn = new QPushButton("Дата изменения",this);
        connect(cngThisDateBtn, SIGNAL(clicked(bool)), SLOT(funReplaceDate()));
        cngThisDateBtn->setGeometry(10,450,230,35);
    }

    table = new QTableView(this);
    table->setGeometry(250,10,800,800);
    model = new QStandardItemModel(0, 4, this);

    table->setModel(model);

    model->setHeaderData(0, Qt::Horizontal, "Значение файла");
    model->setHeaderData(1, Qt::Horizontal, "Следующий день");
    model->setHeaderData(2, Qt::Horizontal, "Разница");
    model->setHeaderData(3, Qt::Horizontal, "Результат функции");

    table->setColumnWidth(0, 130);
    table->setColumnWidth(1, 130);
    table->setColumnWidth(3, 170);


    table->setEditTriggers(QAbstractItemView::NoEditTriggers);

    un_show_pushBtn();
}

void Widget::openDolphin() {
    pathToFile = QFileDialog::getOpenFileName(this, "Open_file.txt","/home/egor1111/QT C++/build-Laba_2_Task_1-Desktop_Qt_6_6_1_GCC_64bit-Debug", tr("Text File (*.txt)"));
    if (pathToFile.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Ни один файл не выбран.");
        return;
    }
    file.setFileName(pathToFile);
    file.open(QIODevice::ReadWrite);
    QTextStream fileStream(&file);

    QString s;
    while (!fileStream.atEnd()) {
        s = fileStream.readLine();
        auto date = QDate::fromString(s, "dd.MM.yyyy");
        if (date.isNull()) {
            QMessageBox::warning(this, "Ошибка", "Ошибка при чтении информации из файла / Неправильный формат.");
            file.close();
            return;
        }
    }

    file.close();

    putDataFromFileToTable();
    show_pushBtn();
}


void Widget::putDataFromFileToTable() {
    if (pathToFile.isEmpty()) return;

    file.setFileName(pathToFile);
    file.open(QIODevice::ReadWrite);
    QTextStream fileStream(&file);
    QString s;
    do {
        fileStream >> s;
        if (!s.isEmpty()) {
            QDate date = QDate::fromString(s, "dd.MM.yyyy");
            if (!date.isNull()) {
                dates->addDate(date);
                if (!dates->getDate(nmbOfRow).isEmpty()) {
                    model->insertRow(nmbOfRow);
                    feelClm(nmbOfRow);
                    nmbOfRow++;
                }
            }
        }
    } while (!fileStream.atEnd());
    file.close();
}

void Widget::feelClm(int nmb) {
    index = model->index(nmb, COLUMN_CURRENT_DATE);
    model->setData(index, dates->getDate(nmb));

    index = model->index(nmb, COLUMN_NEXT_DATE);
    model->setData(index, dates->getNextDate(nmb));

    index = model->index(nmb, COLUMN_DIFFERENCE);
    model->setData(index, dates->getDefWithPrev(nmb));
}

void Widget::funPrevDay() {
    lastFun = 1;
    for (int i = 0; i < nmbOfRow; i++) {
        index = model->index(i, COLUMN_FUN);
        model->setData(index, dates->getPrevDate(i));
    }
}

void Widget::funIsLeapYear() {
    lastFun = 2;
    for (int i = 0; i < nmbOfRow; i++) {
        index = model->index(i, COLUMN_FUN);
        model->setData(index, dates->getIsYearLeap(i) ? "Високосный" : "Не Високосный");
    }
}

void Widget::funWeekNumber() {
    lastFun = 3;
    for (int i = 0; i < nmbOfRow; i++) {
        index = model->index(i, COLUMN_FUN);
        model->setData(index, dates->getWeekNumber(i));
    }
}

void Widget::funBirthDay() {
    lastFun = 4;
    QString line2 = edit->text();
    QDate date = QDate::fromString(line2,"dd.MM.yyyy");
    if(date.isValid()){

    }else{
        QMessageBox::warning(this, "Ошибка", "Некоректная дата");
        return;
    }
    // QDate dateToBD = add_new_date->date();
    for (int i = 0; i < nmbOfRow; i++) {
        index = model->index(i, COLUMN_FUN);
        model->setData(index, dates->cntDaysToBD(date, i));
    }
}

void Widget::funAddDate() {
    model->insertRow(nmbOfRow);
    QString line = edit1->text();
    QDate date3 = QDate::fromString(line,"dd.MM.yyyy");
    if(date3.isValid()){

    }else{
        QMessageBox::warning(this, "Ошибка", "Некоректная дата");
        return;
    }
    dates->addDate(date3);
    feelClm(nmbOfRow);
    nmbOfRow++;
    file.open(QIODevice::ReadWrite);
    QTextStream fileStream(&file);
    QString format = "dd.MM.yyyy";
    fileStream.seek((nmbOfRow - 1) * 11 * sizeof(char));
    fileStream << date3.toString(format) << "\n";
    file.close();

    switch (lastFun) {
    case 1:
        funPrevDay();
        break;
    case 2:
        funIsLeapYear();
        break;
    case 3:
        funWeekNumber();
        break;
    case 4:
        funBirthDay();
        break;
    default:
        break;
    }

}

void Widget::funReplaceDate() {
    QString line1 = calendarReplaceToDate->text();
    QDate dateReplace1 = QDate::fromString(line1,"dd.MM.yyyy");
    QString line = edit1->text();
    QDate date = QDate::fromString(line,"dd.MM.yyyy");
    if(date.isValid()){

    }else{
        QMessageBox::warning(this, "Ошибка", "Некоректная дата");
        return;
    }
    if(dateReplace1.isValid()){

    }else{
        QMessageBox::warning(this, "Ошибка", "Некоректная дата");
        return;
    }
    int firstFind = dates->changeDate(date,dateReplace1);
    file.open(QIODevice::ReadWrite);
    QTextStream fileStream(&file);
    fileStream.seek(firstFind * 11 * sizeof(char));
    for (int i = firstFind; i < nmbOfRow; i++) {
        feelClm(i);
        fileStream << dates->getDate(i) << "\n";
    }
    file.close();
    switch (lastFun) {
    case 1:
        funPrevDay();
        break;
    case 2:
        funIsLeapYear();
        break;
    case 3:
        funWeekNumber();
    case 4:
        funBirthDay();
        break;
    default:
        break;
    }
}

Widget::~Widget()
{
    delete ui;
}
void Widget::show_pushBtn()
{
    openBtn->setVisible(false);
    Close->setVisible(true);
    fun_proshl_day->setVisible(true);
    Year_visok->setVisible(true);
    What_number_week->setVisible(true);
    Date_Birthday->setVisible(true);
    edit->setVisible(true);
    fun_Day_for_next_HB->setVisible(true);
    selectDateToFindLbl->setVisible(true);
    edit1->setVisible(true);
    addThisDateBtn->setVisible(true);
    prob->setVisible(true);
    calendarReplaceToDate->setVisible(true);
    cngThisDateBtn->setVisible(true);
}

void Widget::un_show_pushBtn()
{
    openBtn->setVisible(true);
    Close->setVisible(true);
    fun_proshl_day->setVisible(false);
    Year_visok->setVisible(false);
    What_number_week->setVisible(false);
    Date_Birthday->setVisible(false);
    edit->setVisible(false);
    fun_Day_for_next_HB->setVisible(false);
    selectDateToFindLbl->setVisible(false);
    edit1->setVisible(false);
    addThisDateBtn->setVisible(false);
    prob->setVisible(false);
    calendarReplaceToDate->setVisible(false);
    cngThisDateBtn->setVisible(false);
}
