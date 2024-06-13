#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , _keyboard(new VirtualKeyboard(this))
    , _analizer(new InputAnalizer("", _keyboard, Bel, this))
{
    ui->setupUi(this);
    ui->editorsLayout->addWidget(_keyboard);
    ui->checkTextEdit->installEventFilter(_analizer);

    ui->checkTextEdit->setReadOnly(true);

    connect(ui->presetBtn, SIGNAL(clicked(bool)), SLOT(slotInsertPreset()));
    connect(ui->openBtn, SIGNAL(clicked(bool)), SLOT(slotOpenFile()));
    connect(ui->langBox, SIGNAL(currentIndexChanged(int)), SLOT(slotChangeLang(int)));
    connect(ui->startBtn, SIGNAL(clicked(bool)), SLOT(slotStartCheck()));
    connect(_analizer, SIGNAL(endCheck()), SLOT(slotFinishCheck()));
    connect(_analizer, SIGNAL(updateStat()), SLOT(slotUpdateInfo()));
    connect(_analizer, SIGNAL(textChanged(QChar)), SLOT(slotColorText(QChar)));

    _redF.setForeground(Qt::red);
    _greenF.setForeground(Qt::darkGreen);
    _blackF.setForeground(Qt::black);

    presets();
    ui->aimTextEdit->setText(_presets.at(_languge));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotInsertPreset()
{
    ui->aimTextEdit->setText(_presets.at(static_cast<int>(_languge)));
}

bool MainWindow::isReadOnly() const
{
    return _isReadOnly;
}

void MainWindow::setReadOnly(bool newStatus)
{
    _isReadOnly = newStatus;

    ui->presetBtn->setEnabled(!newStatus);
    ui->openBtn->setDisabled(newStatus);
    ui->checkTextEdit->setReadOnly(!newStatus);
    ui->aimTextEdit->setReadOnly(newStatus);
}

void MainWindow::presets()
{
    _presets.at(0) = "Гонар за родную зямлю. Ён нараджаецца яшчэ ў маленстве і, як першы вясновы парастак, набірае сілу, крэпне на працягу ўсяго жыцця. Гонар за родную зямлю не можа пачацца па волі кагосьці іншага або стварацца спецыяльнымі законамі. Ён бярэ свой выток з сэрца, душы чалавека разам з любоўю да роднага дома, квяцістага лугу, блакітнага льнянога палетка і пошуму дуброў.";
    _presets.at(1) = "Stolz auf sein Heimatland. Es wird bereits in der Kindheit geboren und gewinnt als erster Frühlingspross im Laufe des Lebens an Kraft und wird stärker. Der Stolz auf das Heimatland kann nicht nach dem Willen eines anderen beginnen oder durch spezielle Gesetze geschaffen werden. Er nimmt seine Quelle aus dem Herzen, der Seele des Menschen, zusammen mit der Liebe zu seiner Heimat, der bunten Wiese, dem blauen Leinenflug und dem Rauschen der Eichen.";
    _presets.at(2) = "Fierté pour la terre natale. Il est né dans l'enfance et, comme la première pousse printanière, gagne en force, se renforce tout au long de la vie. La fierté de la terre natale ne peut pas commencer par la volonté de quelqu'un d'autre ou être créée par des lois spéciales. Il prend sa source du cœur, de l'âme de l'homme, avec l'amour de sa maison natale, de sa Prairie colorée, de son vol de Lin bleu et de son chêne.";
    _presets.at(3) = "فخر في الأرض الأصلية. يولد في مرحلة الطفولة ، ومثل أول برعم ربيعي ، يكتسب القوة ويزداد قوة طوال الحياة. لا يمكن أن يبدأ الفخر بالأرض الأصلية بإرادة شخص آخر أو يتم إنشاؤه بموجب قوانين خاصة. ينشأ من القلب ، روح الشخص ، جنبا إلى جنب مع الحب لمنزله الأصلي ، مرج منمق ، رحلة الكتان الأزرق وضجيج أشجار البلوط.";
    _presets.at(4) = "gùtǔ de jiāoào tā chūshēng zài yīngérqī jiù xiàng dìyīgè chūntiān de méngyá yīyàng zài zhěnggè shēngmìng zhōng huòdé lìliàng bìng biàndé gèng qiángzhuàng duì zǔguó de jiāoào bùnéng cóng biérén de yìyuàn kāishǐ yě bùnéng yóu tèshū de fǎlǜ chuàngzào tā qǐyuányú yīgè rén de xīnlíng línghún yǐjí duì tā de jiāxiāng de ài yīgè huálì de cǎodì lánsè de yàmábù fēixíng hé xiàngshù de zàoyīn.";
}

void MainWindow::slotChangeLang(int newLangIndex)
{
    _languge = static_cast<Language>(newLangIndex);
    _keyboard->setLanguage(_languge);
    _analizer->setLanguage(_languge);
    ui->aimTextEdit->setText(_presets.at(_languge));
}

void MainWindow::slotStartCheck()
{
    if (_analizer->isRunning()) {
        _analizer->finishCheck();
        return;
    }
    setReadOnly(true);
    ui->checkTextEdit->clear();
    ui->checkTextEdit->setFocus();

    _text = ui->aimTextEdit->toPlainText();
    _charCntr = 0;
    QTextCursor cursor = ui->aimTextEdit->textCursor();
    cursor.select(QTextCursor::Document);
    cursor.mergeCharFormat(_blackF);
    _analizer->setText(ui->aimTextEdit->toPlainText());
    _analizer->slotStartCheck();
    slotUpdateInfo();
}

void MainWindow::slotFinishCheck()
{
    setReadOnly(false);
    ui->langBox->setFocus();
    slotUpdateInfo();
}

void MainWindow::slotColorText(QChar newChar)
{
    QTextCursor cursor(ui->aimTextEdit->document());
    cursor.setPosition(_charCntr, QTextCursor::MoveAnchor);

    cursor.movePosition(QTextCursor::NextCharacter, QTextCursor::KeepAnchor);

    if (ui->aimTextEdit->toPlainText().at(_charCntr) == newChar){
        cursor.mergeCharFormat(_greenF);
    } else {
        cursor.mergeCharFormat(_redF);
    }
    ++_charCntr;
}

void MainWindow::slotUpdateInfo()
{
    ui->label_2->setText(QString::number(_analizer->seconds()));
    ui->label_3->setText(QString::number(_analizer->words()));
    ui->label_4->setText(QString::number(_analizer->accuracy()));
}

void MainWindow::slotOpenFile()
{
    QString fileName = QFileDialog::getOpenFileName(nullptr, "Open Text File", "", "");
    if (fileName.isEmpty()) {
        return;
    }
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return;
    }
    QTextStream in(&file);
    _text = in.readAll();
    file.close();
    ui->aimTextEdit->setText(_text);
}