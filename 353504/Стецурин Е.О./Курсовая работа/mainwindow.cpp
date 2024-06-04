#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    ui->tableWidget->setColumnWidth(0, 133);
    ui->pushButton_5->setEnabled(false);

    QMovie *movie = new QMovie("D:/BSUIR/Kursovaya/Pictures/nowifi.gif");
    ui->label_gif->setMovie(movie);
    ui->label_gif->setScaledContents(true);
    movie->start();

    QMovie *movie1 = new QMovie("D:/BSUIR/Kursovaya/Pictures/loading.gif");
    ui->label_loading->setMovie(movie1);
    ui->label_loading->setScaledContents(true);
    movie1->start();

    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/abaddon.jpg", "Abaddon"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/alchemist.jpg", "Alchemist"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/ancient_apparition.jpg", "Ancient Apparition"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/talant.jpg", "Anti-Mage"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/arc.jpg", "Arc Warden"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/axe.jpg", "Axe"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/bane.jpg", "Bane"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/batrider.jpg", "Batrider"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/beastmaster.jpg", "Beastmaster"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/seeker.jpg", "Bloodseeker"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/bh.jpg", "Bounty Hunter"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/pivo.jpg", "Brewmaster"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/back.jpg", "Bristleback"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/broodmother.jpg", "Broodmother"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/centaur.jpg", "Centaur Warrunner"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/ck.jpg", "Chaos Knight"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/chen.jpg", "Chen"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/bonik.jpg", "Clinkz"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/clock.jpg", "Clockwerk"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/cm.jpg", "Crystal Maiden"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/darkseer.jpg", "Dark Seer"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/willow.jpg", "Dark Willow"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/db.jpg", "Dawnbreaker"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/dazzle.jpg", "Dazzle"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/dp.jpg", "Death Prophet"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/disruptor.jpg", "Disruptor"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/doom.jpg", "Doom"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/dk.jpg", "Dragon Knight"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/trax.jpg", "Drow Ranger"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/espirit.jpg", "Earth Spirit"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/kostyanchik.jpg", "Earthshaker"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/titan.jpg", "Elder Titan"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/ember.jpg", "Ember Spirit"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/encha.jpg", "Enchantress"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/enigma.jpg", "Enigma"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/void.jpg", "Faceless Void"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/grim.jpg", "Grimstroke"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/gyro.jpg", "Gyrocopter"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/belka.jpg", "Hoodwink"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/huskar.jpg", "Huskar"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/sanya_tornado.jpg", "Invoker"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/wisp.jpg", "Io"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/jakiro.jpg", "Jakiro"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/urnero.jpg", "Juggernaut"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/kotl.jpg", "Keeper of the Light"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/kunkka.jpg", "Kunkka"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/lc♥.jpg", "Legion Commander"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/leshrak.jpg", "Leshrac"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/lich.jpg", "Lich"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/ghoul.jpg", "Lifestealer"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/lina.jpg", "Lina"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/lion.jpg", "Lion"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/druid.jpg", "Lone Druid"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/luna.jpg", "Luna"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/wolf.jpg", "Lycan"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/collapse.jpg", "Magnus"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/marci.jpg", "Marci"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/mars.jpg", "Mars"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/medusa.jpg", "Medusa"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/2017.jpg", "Meepo"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/mirana.jpg", "Mirana"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/mk.jpg", "Monkey King"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/voda.jpg", "Morphling"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/muerta.jpg", "Muerta"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/naga.jpg", "Naga Siren"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/furion.jpg", "Nature's Prophet"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/necr.jpg", "Necrophos"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/ns.jpg", "Night Stalker"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/nyx.jpg", "Nyx Assassin"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/nikitosik.jpg", "Ogre Magi"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/omni.jpg", "Omniknight"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/oracle.jpg", "Oracle"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/od.jpg", "Outworld Destroyer"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/pango.jpg", "Pangolier"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/pa.jpg", "Phantom Assassin"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/pl.jpg", "Phantom Lancer"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/seregga.jpg", "Phoenix"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/dino.jpg", "Primal Beast"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/puck.jpg", "Puck"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/pudge).jpg", "Pudge"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/pugna.jpg", "Pugna"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/qvopa.jpg", "Queen of Pain"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/razor.jpg", "Razor"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/riki.jpg", "Riki"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/rubick.jpg", "Rubick"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/sk.jpg", "Sand King"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/shd.jpg", "Shadow Demon"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/zxc.jpg", "Shadow Fiend"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/shaman.jpg", "Shadow Shaman"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/salo.jpg", "Silencer"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/petuh.jpg", "Skywrath Mage"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/seledka.jpg", "Slardar"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/haru.jpg", "Slark"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/babka.jpg", "Snapfire"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/sniper.jpg", "Sniper"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/spectre.jpg", "Spectre"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/bara.jpg", "Spirit Breaker"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/storm.jpg", "Storm Spirit"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/sven.jpg", "Sven"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/miner.jpg", "Techies"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/ta.jpg", "Templar Assassin"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/tb.jpg", "Terrorblade"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/arbuz.jpg", "Tidehunter"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/timber.jpg", "Timbersaw"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/gomo.jpg", "Tinker"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/airlines.jpg", "Tiny"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/trent.jpg", "Treant Protector"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/troll.jpg", "Troll Warlord"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/tusk.jpg", "Tusk"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/under.jpg", "Underlord"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/zondbi.jpg", "Undying"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/ursa.jpg", "Ursa"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/venga.jpg", "Vengeful Spirit"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/venik.jpg", "Venomancer"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/viper.jpg", "Viper"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/visage.jpg", "Visage"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/vs.jpg", "Void Spirit"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/warlock.jpg", "Warlock"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/juk.jpg", "Weaver"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/wr.jpg", "Windranger"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/wyvern.jpg", "Winter Wyvern"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/wd.jpg", "Witch Doctor"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/papich.jpg", "Wraith King"});
    allHeroes.append(QList<QString>{"D:/BSUIR/Kursovaya/Pictures/zeus.jpg", "Zeus"});

    for (int i = 0; i < 124; ++i){
        ui->comboBox->addItem(allHeroes[i][1]);

        AllCounters.append(QList<QString>{allHeroes[i][1], "0.0"});
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::DeleteRow()
{
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    int row = ui->tableWidget_2->indexAt(button->pos()).row();
    ui->tableWidget_2->removeRow(row);
    ui->pushButton_3->setEnabled(true);
    if (ui->tableWidget_2->rowCount() == 0) ui->pushButton_5->setEnabled(false);
    ui->tableWidget->setRowCount(0);
}

void MainWindow::on_pushButton_clicked()
{
    if (!parsed){
        AllHeroParsing();
        ui->stackedWidget->setCurrentIndex(3);
    }else {
        ui->stackedWidget->setCurrentIndex(1);
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->pushButton_5->setEnabled(false);
    ui->pushButton_3->setEnabled(true);
    ui->tableWidget_2->clearContents();
    ui->tableWidget_2->setRowCount(0);
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);
    ui->comboBox->setCurrentIndex(0);
    ui->stackedWidget->setCurrentIndex(0);
    SelectedHeroes.clear();
    AllCounters.clear();
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*AbaddonCounters.clear();
    AlchemistCounters.clear();
    AncientApparitionCounters.clear();
    AntiMageCounters.clear();
    ArcWardenCounters.clear();
    AxeCounters.clear();
    BaneCounters.clear();
    BatriderCounters.clear();
    BeastmasterCounters.clear();
    BloodseekerCounters.clear();
    BountyHunterCounters.clear();
    BrewmasterCounters.clear();
    BristlebackCounters.clear();
    BroodmotherCounters.clear();
    CentaurWarrunnerCounters.clear();
    ChaosKnightCounters.clear();
    ChenCounters.clear();
    ClinkzCounters.clear();
    ClockwerkCounters.clear();
    CrystalMaidenCounters.clear();
    DarkSeerCounters.clear();
    DarkWillowCounters.clear();
    DawnbreakerCounters.clear();
    DazzleCounters.clear();
    DeathProphetCounters.clear();
    DisruptorCounters.clear();
    DoomCounters.clear();
    DragonKnightCounters.clear();
    DrowRangerCounters.clear();
    EarthSpiritCounters.clear();
    EarthshakerCounters.clear();
    ElderTitanCounters.clear();
    EmberSpiritCounters.clear();
    EnchantressCounters.clear();
    EnigmaCounters.clear();
    FacelessVoidCounters.clear();
    GrimstrokeCounters.clear();
    GyrocopterCounters.clear();
    HoodwinkCounters.clear();
    HuskarCounters.clear();
    InvokerCounters.clear();
    IoCounters.clear();
    JakiroCounters.clear();
    JuggernautCounters.clear();
    KeeperOfTheLightCounters.clear();
    KunkkaCounters.clear();
    LegionCommanderCounters.clear();
    LeshracCounters.clear();
    LichCounters.clear();
    LifestealerCounters.clear();
    LinaCounters.clear();
    LionCounters.clear();
    LoneDruidCounters.clear();
    LunaCounters.clear();
    LycanCounters.clear();
    MagnusCounters.clear();
    MarciCounters.clear();
    MarsCounters.clear();
    MedusaCounters.clear();
    MeepoCounters.clear();
    MiranaCounters.clear();
    MonkeyKingCounters.clear();
    MorphlingCounters.clear();
    MuertaCounters.clear();
    NagaSirenCounters.clear();
    NaturesProphetCounters.clear();
    NecrophosCounters.clear();
    NightStalkerCounters.clear();
    NyxAssassinCounters.clear();
    OgreMagiCounters.clear();
    OmniknightCounters.clear();
    OracleCounters.clear();
    OutworldDestroyerCounters.clear();
    PangolierCounters.clear();
    PhantomAssassinCounters.clear();
    PhantomLancerCounters.clear();
    PhoenixCounters.clear();
    PrimalBeastCounters.clear();
    PuckCounters.clear();
    PudgeCounters.clear();
    PugnaCounters.clear();
    QueenOfPainCounters.clear();
    RazorCounters.clear();
    RikiCounters.clear();
    RubickCounters.clear();
    SandKingCounters.clear();
    ShadowDemonCounters.clear();
    ShadowFiendCounters.clear();
    ShadowShamanCounters.clear();
    SilencerCounters.clear();
    SkywrathMageCounters.clear();
    SlardarCounters.clear();
    SlarkCounters.clear();
    SnapfireCounters.clear();
    SniperCounters.clear();
    SpectreCounters.clear();
    SpiritBreakerCounters.clear();
    StormSpiritCounters.clear();
    SvenCounters.clear();
    TechiesCounters.clear();
    TemplarAssassinCounters.clear();
    TerrorbladeCounters.clear();
    TidehunterCounters.clear();
    TimbersawCounters.clear();
    TinkerCounters.clear();
    TinyCounters.clear();
    TreantProtectorCounters.clear();
    TrollWarlordCounters.clear();
    TuskCounters.clear();
    UnderlordCounters.clear();
    UndyingCounters.clear();
    UrsaCounters.clear();
    VengefulSpiritCounters.clear();
    VenomancerCounters.clear();
    ViperCounters.clear();
    VisageCounters.clear();
    VoidSpiritCounters.clear();
    WarlockCounters.clear();
    WeaverCounters.clear();
    WindrangerCounters.clear();
    WinterWyvernCounters.clear();
    WitchDoctorCounters.clear();
    WraithKingCounters.clear();
    ZeusCounters.clear();*/
    for (int i = 0; i < 124; ++i) AllCounters.append(QList<QString>{allHeroes[i][1], "0.0"});
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->tableWidget->setRowCount(0);
    int selectedHero = ui->comboBox->currentIndex();
    if (selectedHero == 0) return;
    selectedHero-=1;
    int row = ui->tableWidget_2->rowCount();

    QString newHero = allHeroes[selectedHero][1];
    for(int i = 0; i < row; ++i) {
        if(ui->tableWidget_2->item(i, 1)->text() == newHero) {
            QMessageBox::information(this, "Ошибка", "Герой уже добавлен");
            return;
        }
    }

    QPixmap pixmap(allHeroes[selectedHero][0]);
    QTableWidgetItem *item = new QTableWidgetItem, *item2 = new QTableWidgetItem(allHeroes[selectedHero][1]);
    item->setData(Qt::DecorationRole, pixmap);

    ui->tableWidget_2->insertRow(row);
    ui->tableWidget_2->setItem(row, 0, item);
    ui->tableWidget_2->setItem(row, 1, item2);
    QPushButton* delButton = new QPushButton("Удалить");
    connect(delButton, &QPushButton::clicked, this, &MainWindow::DeleteRow);
    ui->tableWidget_2->setCellWidget(row, 2, delButton);
    ui->pushButton_5->setEnabled(true);
    if (row==4) ui->pushButton_3->setEnabled(false);
}


void MainWindow::on_pushButton_4_clicked()
{
    this->close();
}


void MainWindow::on_pushButton_5_clicked()
{
    ui->tableWidget->setRowCount(0);

    SelectedHeroes.append("zxc");
    SelectedHeroes.clear();
    for (int i=0; i<ui->tableWidget_2->rowCount(); ++i){
        SelectedHeroes.append(ui->tableWidget_2->item(i,1)->text());
    }

    for (int i = 0; i < 124; ++i) {
        double allCounters = AllCounters[i][1].toDouble();
        for (QString hero : SelectedHeroes) {
            if (hero == "Abaddon") {
                allCounters += AbaddonCounters[i][1].toDouble();
            } else if (hero == "Alchemist") {
                allCounters += AlchemistCounters[i][1].toDouble();
            } else if (hero == "Ancient Apparition") {
                allCounters += AncientApparitionCounters[i][1].toDouble();
            } else if (hero == "Anti-Mage") {
                allCounters += AntiMageCounters[i][1].toDouble();
            } else if (hero == "Arc Warden") {
                allCounters += ArcWardenCounters[i][1].toDouble();
            } else if (hero == "Axe") {
                allCounters += AxeCounters[i][1].toDouble();
            } else if (hero == "Bane") {
                allCounters += BaneCounters[i][1].toDouble();
            } else if (hero == "Batrider") {
                allCounters += BatriderCounters[i][1].toDouble();
            } else if (hero == "Beastmaster") {
                allCounters += BeastmasterCounters[i][1].toDouble();
            } else if (hero == "Bloodseeker") {
                allCounters += BloodseekerCounters[i][1].toDouble();
            } else if (hero == "Bounty Hunter") {
                allCounters += BountyHunterCounters[i][1].toDouble();
            } else if (hero == "Brewmaster") {
                allCounters += BrewmasterCounters[i][1].toDouble();
            } else if (hero == "Bristleback") {
                allCounters += BristlebackCounters[i][1].toDouble();
            } else if (hero == "Broodmother") {
                allCounters += BroodmotherCounters[i][1].toDouble();
            } else if (hero == "Centaur Warrunner") {
                allCounters += CentaurWarrunnerCounters[i][1].toDouble();
            } else if (hero == "Chaos Knight") {
                allCounters += ChaosKnightCounters[i][1].toDouble();
            } else if (hero == "Chen") {
                allCounters += ChenCounters[i][1].toDouble();
            } else if (hero == "Clinkz") {
                allCounters += ClinkzCounters[i][1].toDouble();
            } else if (hero == "Clockwerk") {
                allCounters += ClockwerkCounters[i][1].toDouble();
            } else if (hero == "Crystal Maiden") {
                allCounters += CrystalMaidenCounters[i][1].toDouble();
            } else if (hero == "Dark Seer") {
                allCounters += DarkSeerCounters[i][1].toDouble();
            } else if (hero == "Dark Willow") {
                allCounters += DarkWillowCounters[i][1].toDouble();
            } else if (hero == "Dawnbreaker") {
                allCounters += DawnbreakerCounters[i][1].toDouble();
            } else if (hero == "Dazzle") {
                allCounters += DazzleCounters[i][1].toDouble();
            } else if (hero == "Death Prophet") {
                allCounters += DeathProphetCounters[i][1].toDouble();
            } else if (hero == "Disruptor") {
                allCounters += DisruptorCounters[i][1].toDouble();
            } else if (hero == "Doom") {
                allCounters += DoomCounters[i][1].toDouble();
            } else if (hero == "Dragon Knight") {
                allCounters += DragonKnightCounters[i][1].toDouble();
            } else if (hero == "Drow Ranger") {
                allCounters += DrowRangerCounters[i][1].toDouble();
            } else if (hero == "Earth Spirit") {
                allCounters += EarthSpiritCounters[i][1].toDouble();
            } else if (hero == "Earthshaker") {
                allCounters += EarthshakerCounters[i][1].toDouble();
            } else if (hero == "Elder Titan") {
                allCounters += ElderTitanCounters[i][1].toDouble();
            } else if (hero == "Ember Spirit") {
                allCounters += EmberSpiritCounters[i][1].toDouble();
            } else if (hero == "Enchantress") {
                allCounters += EnchantressCounters[i][1].toDouble();
            } else if (hero == "Enigma") {
                allCounters += EnigmaCounters[i][1].toDouble();
            } else if (hero == "Faceless Void") {
                allCounters += FacelessVoidCounters[i][1].toDouble();
            } else if (hero == "Grimstroke") {
                allCounters += GrimstrokeCounters[i][1].toDouble();
            } else if (hero == "Gyrocopter") {
                allCounters += GyrocopterCounters[i][1].toDouble();
            } else if (hero == "Hoodwink") {
                allCounters += HoodwinkCounters[i][1].toDouble();
            } else if (hero == "Huskar") {
                allCounters += HuskarCounters[i][1].toDouble();
            } else if (hero == "Invoker") {
                allCounters += InvokerCounters[i][1].toDouble();
            } else if (hero == "Io") {
                allCounters += IoCounters[i][1].toDouble();
            } else if (hero == "Jakiro") {
                allCounters += JakiroCounters[i][1].toDouble();
            } else if (hero == "Juggernaut") {
                allCounters += JuggernautCounters[i][1].toDouble();
            } else if (hero == "Keeper of the Light") {
                allCounters += KeeperOfTheLightCounters[i][1].toDouble();
            } else if (hero == "Kunkka") {
                allCounters += KunkkaCounters[i][1].toDouble();
            } else if (hero == "Legion Commander") {
                allCounters += LegionCommanderCounters[i][1].toDouble();
            } else if (hero == "Leshrac") {
                allCounters += LeshracCounters[i][1].toDouble();
            } else if (hero == "Lich") {
                allCounters += LichCounters[i][1].toDouble();
            } else if (hero == "Lifestealer") {
                allCounters += LifestealerCounters[i][1].toDouble();
            } else if (hero == "Lina") {
                allCounters += LinaCounters[i][1].toDouble();
            } else if (hero == "Lion") {
                allCounters += LionCounters[i][1].toDouble();
            } else if (hero == "Lone Druid") {
                allCounters += LoneDruidCounters[i][1].toDouble();
            } else if (hero == "Luna") {
                allCounters += LunaCounters[i][1].toDouble();
            } else if (hero == "Lycan") {
                allCounters += LycanCounters[i][1].toDouble();
            } else if (hero == "Magnus") {
                allCounters += MagnusCounters[i][1].toDouble();
            } else if (hero == "Marci") {
                allCounters += MarciCounters[i][1].toDouble();
            } else if (hero == "Mars") {
                allCounters += MarsCounters[i][1].toDouble();
            } else if (hero == "Medusa") {
                allCounters += MedusaCounters[i][1].toDouble();
            } else if (hero == "Meepo") {
                allCounters += MeepoCounters[i][1].toDouble();
            } else if (hero == "Mirana") {
                allCounters += MiranaCounters[i][1].toDouble();
            } else if (hero == "Monkey King") {
                allCounters += MonkeyKingCounters[i][1].toDouble();
            } else if (hero == "Morphling") {
                allCounters += MorphlingCounters[i][1].toDouble();
            } else if (hero == "Muerta") {
                allCounters += MuertaCounters[i][1].toDouble();
            } else if (hero == "Naga Siren") {
                allCounters += NagaSirenCounters[i][1].toDouble();
            } else if (hero == "Nature's Prophet") {
                allCounters += NaturesProphetCounters[i][1].toDouble();
            } else if (hero == "Necrophos") {
                allCounters += NecrophosCounters[i][1].toDouble();
            } else if (hero == "Night Stalker") {
                allCounters += NightStalkerCounters[i][1].toDouble();
            } else if (hero == "Nyx Assassin") {
                allCounters += NyxAssassinCounters[i][1].toDouble();
            } else if (hero == "Ogre Magi") {
                allCounters += OgreMagiCounters[i][1].toDouble();
            } else if (hero == "Omniknight") {
                allCounters += OmniknightCounters[i][1].toDouble();
            } else if (hero == "Oracle") {
                allCounters += OracleCounters[i][1].toDouble();
            } else if (hero == "Outworld Destroyer") {
                allCounters += OutworldDestroyerCounters[i][1].toDouble();
            } else if (hero == "Pangolier") {
                allCounters += PangolierCounters[i][1].toDouble();
            } else if (hero == "Phantom Assassin") {
                allCounters += PhantomAssassinCounters[i][1].toDouble();
            } else if (hero == "Phantom Lancer") {
                allCounters += PhantomLancerCounters[i][1].toDouble();
            } else if (hero == "Phoenix") {
                allCounters += PhoenixCounters[i][1].toDouble();
            } else if (hero == "Primal Beast") {
                allCounters += PrimalBeastCounters[i][1].toDouble();
            } else if (hero == "Puck") {
                allCounters += PuckCounters[i][1].toDouble();
            } else if (hero == "Pudge") {
                allCounters += PudgeCounters[i][1].toDouble();
            } else if (hero == "Pugna") {
                allCounters += PugnaCounters[i][1].toDouble();
            } else if (hero == "Queen of Pain") {
                allCounters += QueenOfPainCounters[i][1].toDouble();
            } else if (hero == "Razor") {
                allCounters += RazorCounters[i][1].toDouble();
            } else if (hero == "Riki") {
                allCounters += RikiCounters[i][1].toDouble();
            } else if (hero == "Rubick") {
                allCounters += RubickCounters[i][1].toDouble();
            } else if (hero == "Sand King") {
                allCounters += SandKingCounters[i][1].toDouble();
            } else if (hero == "Shadow Demon") {
                allCounters += ShadowDemonCounters[i][1].toDouble();
            } else if (hero == "Shadow Fiend") {
                allCounters += ShadowFiendCounters[i][1].toDouble();
            } else if (hero == "Shadow Shaman") {
                allCounters += ShadowShamanCounters[i][1].toDouble();
            } else if (hero == "Silencer") {
                allCounters += SilencerCounters[i][1].toDouble();
            } else if (hero == "Skywrath Mage") {
                allCounters += SkywrathMageCounters[i][1].toDouble();
            } else if (hero == "Slardar") {
                allCounters += SlardarCounters[i][1].toDouble();
            } else if (hero == "Slark") {
                allCounters += SlarkCounters[i][1].toDouble();
            } else if (hero == "Snapfire") {
                allCounters += SnapfireCounters[i][1].toDouble();
            } else if (hero == "Sniper") {
                allCounters += SniperCounters[i][1].toDouble();
            } else if (hero == "Spectre") {
                allCounters += SpectreCounters[i][1].toDouble();
            } else if (hero == "Spirit Breaker") {
                allCounters += SpiritBreakerCounters[i][1].toDouble();
            } else if (hero == "Storm Spirit") {
                allCounters += StormSpiritCounters[i][1].toDouble();
            } else if (hero == "Sven") {
                allCounters += SvenCounters[i][1].toDouble();
            } else if (hero == "Techies") {
                allCounters += TechiesCounters[i][1].toDouble();
            } else if (hero == "Templar Assassin") {
                allCounters += TemplarAssassinCounters[i][1].toDouble();
            } else if (hero == "Terrorblade") {
                allCounters += TerrorbladeCounters[i][1].toDouble();
            } else if (hero == "Tidehunter") {
                allCounters += TidehunterCounters[i][1].toDouble();
            } else if (hero == "Timbersaw") {
                allCounters += TimbersawCounters[i][1].toDouble();
            } else if (hero == "Tinker") {
                allCounters += TinkerCounters[i][1].toDouble();
            } else if (hero == "Tiny") {
                allCounters += TinyCounters[i][1].toDouble();
            } else if (hero == "Treant Protector") {
                allCounters += TreantProtectorCounters[i][1].toDouble();
            } else if (hero == "Troll Warlord") {
                allCounters += TrollWarlordCounters[i][1].toDouble();
            } else if (hero == "Tusk") {
                allCounters += TuskCounters[i][1].toDouble();
            } else if (hero == "Underlord") {
                allCounters += UnderlordCounters[i][1].toDouble();
            } else if (hero == "Undying") {
                allCounters += UndyingCounters[i][1].toDouble();
            } else if (hero == "Ursa") {
                allCounters += UrsaCounters[i][1].toDouble();
            } else if (hero == "Vengeful Spirit") {
                allCounters += VengefulSpiritCounters[i][1].toDouble();
            } else if (hero == "Venomancer") {
                allCounters += VenomancerCounters[i][1].toDouble();
            } else if (hero == "Viper") {
                allCounters += ViperCounters[i][1].toDouble();
            } else if (hero == "Visage") {
                allCounters += VisageCounters[i][1].toDouble();
            } else if (hero == "Void Spirit") {
                allCounters += VoidSpiritCounters[i][1].toDouble();
            } else if (hero == "Warlock") {
                allCounters += WarlockCounters[i][1].toDouble();
            } else if (hero == "Weaver") {
                allCounters += WeaverCounters[i][1].toDouble();
            } else if (hero == "Windranger") {
                allCounters += WindrangerCounters[i][1].toDouble();
            } else if (hero == "Winter Wyvern") {
                allCounters += WinterWyvernCounters[i][1].toDouble();
            } else if (hero == "Witch Doctor") {
                allCounters += WitchDoctorCounters[i][1].toDouble();
            } else if (hero == "Wraith King") {
                allCounters += WraithKingCounters[i][1].toDouble();
            } else if (hero == "Zeus") {
                allCounters += ZeusCounters[i][1].toDouble();
            }
            ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        }
        AllCounters[i][1] = QString::number(allCounters);
    }


    for (int i = 0; i < 124; ++i) {
        ui->tableWidget->insertRow(i);

        QPixmap pixmap(allHeroes[i][0]);
        QTableWidgetItem *item = new QTableWidgetItem;
        item->setData(Qt::DecorationRole, pixmap);
        ui->tableWidget->setItem(i, 0, item);
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(AllCounters[i][0]));

        AllCounters[i][1]=QString::number(AllCounters[i][1].toDouble()/SelectedHeroes.size());

        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(AllCounters[i][1]));
    }

    for(int i = 0; i < ui->tableWidget->rowCount(); ++i) {
        ui->tableWidget->item(i, 2)->setTextAlignment(Qt::AlignCenter);
    }

    for (int i = ui->tableWidget->rowCount() - 1; i >= 0; --i) {
        QTableWidgetItem *item = ui->tableWidget->item(i, 2);
        if (item && item->text().toDouble() < 0) {
            ui->tableWidget->removeRow(i);
        }
    }

    ui->tableWidget->sortItems(2, Qt::DescendingOrder);


    // переделать удаление
    // переделал || это хуйня норм удаление выше
    /*for (int i=0;i<124-SelectedHeroes.size();++i){
        for (QString name : SelectedHeroes) {
            if (name==ui->tableWidget->item(i,1)->text()){
                ui->tableWidget->removeRow(i);
                --i;
            }
        }
    }*/

    AllCounters.clear();
    for (int i = 0; i < 124; ++i) AllCounters.append(QList<QString>{allHeroes[i][1], "0.0"});
}


void MainWindow::on_pushButton_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

