#include "dialoginputstudent.h"
#include "qtimer.h"
#include "ui_dialoginputstudent.h"

DialogInputStudent::DialogInputStudent(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogInputStudent)
{
    ui->setupUi(this);


    setStyleSheet("QLineEdit:disabled, QSpinBox:disabled, QPushButton:disabled,"
                  " QComboBox:disabled, QListWidget:disabled { background-color: #D3D3D3; }");


    FACULTIES = {"—", "ФРЭ", "ФКСиС", "ИЭФ"};

    FKSIS = {"—", "ИиТП", "КИ", "ПИ"};
    IEF = {"—", "ИСиТ", "ЭЭ"};
    FRE = {"—", "ИиУСФУ", "ИПД", "МиН", "НиН", "РиР"};

    GROUPS_PI = {"—", "351001", "351002", "351003", "351004", "351005"};
    GROUPS_KI = {"—", "358301", "358302", "358303", "358304", "358305", "358306", "358307"};
    GROUPS_IITP = {"—", "353501", "353502", "353503", "353504", "353505"};

    GROUPS_ISIT = {"—", "378101", "378102" ,"378103", "378104", "378105", "378106", "378107", "378108"};
    GROUPS_EE = {"—", "373901", "373902", "373903", "373904"};

    GROUPS_IIUSFU = {"—", "348001"};
    GROUPS_IPD = {"—", "344671"};
    GROUPS_MIN = {"—", "348601", "348602"};
    GROUPS_NIN = {"—", "343201"};
    GROUPS_RIR = {"—", "348801", "348802", "348803", "348804"};

    ui->comboFaculty->clear();
    ui->comboFaculty->addItems(FACULTIES);

    connect(ui->comboFaculty, &QComboBox::currentIndexChanged, this, &DialogInputStudent::changeSpecialityCombo);
    connect(ui->comboSpeciality, &QComboBox::currentIndexChanged, this, &DialogInputStudent::changeGroupCombo);

    ui->spinAgila->findChild<QLineEdit*>()->setMaxLength(2);
    ui->spinDM->findChild<QLineEdit*>()->setMaxLength(2);
    ui->spinHist->findChild<QLineEdit*>()->setMaxLength(2);
    ui->spinMatan->findChild<QLineEdit*>()->setMaxLength(2);
    ui->spinOAIP->findChild<QLineEdit*>()->setMaxLength(2);

    ui->lineName->setMaxLength(75);

    ui->spinAgila->setRange(0, 10);
    ui->spinDM->setRange(0, 10);
    ui->spinHist->setRange(0, 10);
    ui->spinMatan->setRange(0, 10);
    ui->spinOAIP->setRange(0, 10);

    QTimer* timer = new QTimer();

    connect(timer, &QTimer::timeout, [=](){
        if(ui->comboFaculty->count() > 0 && ui->comboFaculty->currentText() != "—" && ui->comboSpeciality->count() > 0
            && ui->comboSpeciality->currentText() != "—" && ui->comboGroup->count() > 0 && ui->comboGroup->currentText() != "—"
            && ui->lineName->text() != "")
        {
            ui->buttonBox->setEnabled(true);
        }
        else
        {
            ui->buttonBox->setEnabled(false);
        }

        double avgMark = (ui->spinAgila->value() + ui->spinDM->value() + ui->spinHist->value() + ui->spinMatan->value() + ui->spinOAIP->value()) / 5.0;
        ui->lineAvgMark->setText(QString::number(avgMark));
    });

    timer->start(10);


}

DialogInputStudent::~DialogInputStudent()
{
    delete ui;
}

void DialogInputStudent::changeSpecialityCombo()
{
    if(ui->comboFaculty->currentText() == "—")
    {
        ui->comboSpeciality->clear();
        ui->comboGroup->clear();
    }

    else if(ui->comboFaculty->currentText() == "ФРЭ")
    {
        ui->comboSpeciality->clear();
        ui->comboSpeciality->addItems(FRE);
        ui->comboGroup->clear();
    }
    else if(ui->comboFaculty->currentText() == "ФКСиС")
    {
        ui->comboSpeciality->clear();
        ui->comboSpeciality->addItems(FKSIS);
        ui->comboGroup->clear();
    }
    else if(ui->comboFaculty->currentText() == "ИЭФ")
    {
        ui->comboSpeciality->clear();
        ui->comboSpeciality->addItems(IEF);
        ui->comboGroup->clear();
    }
}

Student DialogInputStudent::getStudentInfo()
{
    QString name = ui->lineName->text();

    QString fac = ui->comboFaculty->currentText(), spec = ui->comboSpeciality->currentText(), gr = ui->comboGroup->currentText();
    double matan = ui->spinMatan->value(), oaip = ui->spinOAIP->value(), agila = ui->spinAgila->value(),
        hist = ui->spinHist->value(), dm = ui->spinDM->value();

    return Student(name, fac, spec, gr, matan, oaip, agila, hist, dm);
}

void DialogInputStudent::setStudentInfo(Student student)
{
    ui->lineName->setText(student.getFIO());

    ui->spinAgila->setValue(student.getAgila());
    ui->spinDM->setValue(student.getDm());
    ui->spinHist->setValue(student.getHist());
    ui->spinMatan->setValue(student.getMatan());
    ui->spinOAIP->setValue(student.getOaip());

    ui->comboFaculty->setCurrentText(student.getFaculty());
    ui->comboSpeciality->setCurrentText(student.getSpeciality());
    ui->comboGroup->setCurrentText(student.getGroup());
}

void DialogInputStudent::changeGroupCombo()
{
    if(ui->comboFaculty->currentText() == "ФКСиС")
    {
        if(ui->comboSpeciality->currentText() == "КИ")
        {
            ui->comboGroup->clear();
            ui->comboGroup->addItems(GROUPS_KI);
        }
        else if(ui->comboSpeciality->currentText() == "ПИ")
        {
            ui->comboGroup->clear();
            ui->comboGroup->addItems(GROUPS_PI);
        }
        else if(ui->comboSpeciality->currentText() == "ИиТП")
        {
            ui->comboGroup->clear();
            ui->comboGroup->addItems(GROUPS_IITP);
        }
    }
    else if(ui->comboFaculty->currentText() == "ФРЭ")
    {
        if(ui->comboSpeciality->currentText() == "ИиУСФУ")
        {
            ui->comboGroup->clear();
            ui->comboGroup->addItems(GROUPS_KI);
        }
        else if(ui->comboSpeciality->currentText() == "ИПД")
        {
            ui->comboGroup->clear();
            ui->comboGroup->addItems(GROUPS_IPD);
        }
        else if(ui->comboSpeciality->currentText() == "МиН")
        {
            ui->comboGroup->clear();
            ui->comboGroup->addItems(GROUPS_MIN);
        }
        else if(ui->comboSpeciality->currentText() == "НиН")
        {
            ui->comboGroup->clear();
            ui->comboGroup->addItems(GROUPS_NIN);
        }
        else if(ui->comboSpeciality->currentText() == "РиР")
        {
            ui->comboGroup->clear();
            ui->comboGroup->addItems(GROUPS_RIR);
        }
    }
    else if(ui->comboFaculty->currentText() == "ИЭФ")
    {
        if(ui->comboSpeciality->currentText() == "ЭЭ")
        {
            ui->comboGroup->clear();
            ui->comboGroup->addItems(GROUPS_EE);
        }
        else if(ui->comboSpeciality->currentText() == "ИСиТ")
        {
            ui->comboGroup->clear();
            ui->comboGroup->addItems(GROUPS_ISIT);
        }
    }
}
