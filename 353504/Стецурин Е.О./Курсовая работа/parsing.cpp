#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::GenericHeroParsing(const QString &heroName, QList<QList<QString>> &heroCounters)
{
    QNetworkRequest request(QUrl(QString("https://www.dotabuff.com/heroes/%1/counters").arg(heroName.toLower())));
    QNetworkReply *reply = manager->get(request);
    QObject::connect(reply, &QNetworkReply::finished, [=, &heroCounters]() {
        if (reply->error()) {
            qDebug() << "ERROR!";
            qDebug() << reply->errorString();
            ui->stackedWidget->setCurrentIndex(2);
        } else {
            QByteArray responseData = reply->readAll();
            QString responseString = QString::fromUtf8(responseData);

            int index = responseString.indexOf("<table class=");
            responseString = responseString.mid(index);

            int index1 = responseString.indexOf("/table>");
            responseString = responseString.left(index1 + 7);

            QTextDocument doc;
            doc.setHtml(responseString);

            QTextTable* textTable = doc.findChild<QTextTable *>();

            for (int row = 1; row < textTable->rows(); ++row){
                heroCounters.append(QList<QString>{textTable->cellAt(row, 1).firstCursorPosition().block().text(), textTable->cellAt(row, 3).firstCursorPosition().block().text()});
            }
            heroCounters.append(QList<QString>{heroName, "1000.0%"});
            qDebug() << ++numberOfParsed << heroName.toLower();

            ui->label_5->setText(QString::number(numberOfParsed)+ " / 124");

            std::sort(heroCounters.begin(), heroCounters.end(), [](const QList<QString> &a, const QList<QString> &b) {
                return a.first() < b.first();
            });

            for (int i=0; i<124;++i){
                heroCounters[i][1].chop(1);
                double counterValue = heroCounters[i][1].toDouble();
                counterValue = 100 - counterValue;
                heroCounters[i][1] = QString::number(counterValue);
            }
            if (numberOfParsed==124){
                ui->stackedWidget->setCurrentIndex(1);
                //ui->label_5->setText("0 / 124");
                parsed = true;
            }

        }
        reply->deleteLater();
    });
}

void MainWindow::AllHeroParsing()
{
    GenericHeroParsing("Abaddon", AbaddonCounters);
    GenericHeroParsing("Alchemist", AlchemistCounters);
    GenericHeroParsing("Ancient-Apparition", AncientApparitionCounters);
    GenericHeroParsing("Anti-Mage", AntiMageCounters);
    GenericHeroParsing("Arc-Warden", ArcWardenCounters);
    GenericHeroParsing("Axe", AxeCounters);
    GenericHeroParsing("Bane", BaneCounters);
    GenericHeroParsing("Batrider", BatriderCounters);
    GenericHeroParsing("Beastmaster", BeastmasterCounters);
    GenericHeroParsing("Bloodseeker", BloodseekerCounters);
    GenericHeroParsing("Bounty-Hunter", BountyHunterCounters);
    GenericHeroParsing("Brewmaster", BrewmasterCounters);
    GenericHeroParsing("Bristleback", BristlebackCounters);
    GenericHeroParsing("Broodmother", BroodmotherCounters);
    GenericHeroParsing("Centaur-Warrunner", CentaurWarrunnerCounters);
    GenericHeroParsing("Chaos-Knight", ChaosKnightCounters);
    GenericHeroParsing("Chen", ChenCounters);
    GenericHeroParsing("Clinkz", ClinkzCounters);
    GenericHeroParsing("Clockwerk", ClockwerkCounters);
    GenericHeroParsing("Crystal-Maiden", CrystalMaidenCounters);
    GenericHeroParsing("Dark-Seer", DarkSeerCounters);
    GenericHeroParsing("Dark-Willow", DarkWillowCounters);
    GenericHeroParsing("Dawnbreaker", DawnbreakerCounters);
    GenericHeroParsing("Dazzle", DazzleCounters);
    GenericHeroParsing("Death-Prophet", DeathProphetCounters);
    GenericHeroParsing("Disruptor", DisruptorCounters);
    GenericHeroParsing("Doom", DoomCounters);
    GenericHeroParsing("Dragon-Knight", DragonKnightCounters);
    GenericHeroParsing("Drow-Ranger", DrowRangerCounters);
    GenericHeroParsing("Earth-Spirit", EarthSpiritCounters);
    GenericHeroParsing("Earthshaker", EarthshakerCounters);
    GenericHeroParsing("Elder-Titan", ElderTitanCounters);
    GenericHeroParsing("Ember-Spirit", EmberSpiritCounters);
    GenericHeroParsing("Enchantress", EnchantressCounters);
    GenericHeroParsing("Enigma", EnigmaCounters);
    GenericHeroParsing("Faceless-Void", FacelessVoidCounters);
    GenericHeroParsing("Grimstroke", GrimstrokeCounters);
    GenericHeroParsing("Gyrocopter", GyrocopterCounters);
    GenericHeroParsing("Hoodwink", HoodwinkCounters);
    GenericHeroParsing("Huskar", HuskarCounters);
    GenericHeroParsing("Invoker", InvokerCounters);
    GenericHeroParsing("Io", IoCounters);
    GenericHeroParsing("Jakiro", JakiroCounters);
    GenericHeroParsing("Juggernaut", JuggernautCounters);
    GenericHeroParsing("Keeper-of-the-Light", KeeperOfTheLightCounters);
    GenericHeroParsing("Kunkka", KunkkaCounters);
    GenericHeroParsing("Legion-Commander", LegionCommanderCounters);
    GenericHeroParsing("Leshrac", LeshracCounters);
    GenericHeroParsing("Lich", LichCounters);
    GenericHeroParsing("Lifestealer", LifestealerCounters);
    GenericHeroParsing("Lina", LinaCounters);
    GenericHeroParsing("Lion", LionCounters);
    GenericHeroParsing("Lone-Druid", LoneDruidCounters);
    GenericHeroParsing("Luna", LunaCounters);
    GenericHeroParsing("Lycan", LycanCounters);
    GenericHeroParsing("Magnus", MagnusCounters);
    GenericHeroParsing("Marci", MarciCounters);
    GenericHeroParsing("Mars", MarsCounters);
    GenericHeroParsing("Medusa", MedusaCounters);
    GenericHeroParsing("Meepo", MeepoCounters);
    GenericHeroParsing("Mirana", MiranaCounters);
    GenericHeroParsing("Monkey-King", MonkeyKingCounters);
    GenericHeroParsing("Morphling", MorphlingCounters);
    GenericHeroParsing("Muerta", MuertaCounters);
    GenericHeroParsing("Naga-Siren", NagaSirenCounters);
    GenericHeroParsing("Natures-Prophet", NaturesProphetCounters);
    GenericHeroParsing("Necrophos", NecrophosCounters);
    GenericHeroParsing("Night-Stalker", NightStalkerCounters);
    GenericHeroParsing("Nyx-Assassin", NyxAssassinCounters);
    GenericHeroParsing("Ogre-Magi", OgreMagiCounters);
    GenericHeroParsing("Omniknight", OmniknightCounters);
    GenericHeroParsing("Oracle", OracleCounters);
    GenericHeroParsing("Outworld-Destroyer", OutworldDestroyerCounters);
    GenericHeroParsing("Pangolier", PangolierCounters);
    GenericHeroParsing("Phantom-Assassin", PhantomAssassinCounters);
    GenericHeroParsing("Phantom-Lancer", PhantomLancerCounters);
    GenericHeroParsing("Phoenix", PhoenixCounters);
    GenericHeroParsing("Primal-Beast", PrimalBeastCounters);
    GenericHeroParsing("Puck", PuckCounters);
    GenericHeroParsing("Pudge", PudgeCounters);
    GenericHeroParsing("Pugna", PugnaCounters);
    GenericHeroParsing("Queen-Of-Pain", QueenOfPainCounters);
    GenericHeroParsing("Razor", RazorCounters);
    GenericHeroParsing("Riki", RikiCounters);
    GenericHeroParsing("Rubick", RubickCounters);
    GenericHeroParsing("Sand-King", SandKingCounters);
    GenericHeroParsing("Shadow-Demon", ShadowDemonCounters);
    GenericHeroParsing("Shadow-Fiend", ShadowFiendCounters);
    GenericHeroParsing("Shadow-Shaman", ShadowShamanCounters);
    GenericHeroParsing("Silencer", SilencerCounters);
    GenericHeroParsing("Skywrath-Mage", SkywrathMageCounters);
    GenericHeroParsing("Slardar", SlardarCounters);
    GenericHeroParsing("Slark", SlarkCounters);
    GenericHeroParsing("Snapfire", SnapfireCounters);
    GenericHeroParsing("Sniper", SniperCounters);
    GenericHeroParsing("Spectre", SpectreCounters);
    GenericHeroParsing("Spirit-Breaker", SpiritBreakerCounters);
    GenericHeroParsing("Storm-Spirit", StormSpiritCounters);
    GenericHeroParsing("Sven", SvenCounters);
    GenericHeroParsing("Techies", TechiesCounters);
    GenericHeroParsing("Templar-Assassin", TemplarAssassinCounters);
    GenericHeroParsing("Terrorblade", TerrorbladeCounters);
    GenericHeroParsing("Tidehunter", TidehunterCounters);
    GenericHeroParsing("Timbersaw", TimbersawCounters);
    GenericHeroParsing("Tinker", TinkerCounters);
    GenericHeroParsing("Tiny", TinyCounters);
    GenericHeroParsing("Treant-Protector", TreantProtectorCounters);
    GenericHeroParsing("Troll-Warlord", TrollWarlordCounters);
    GenericHeroParsing("Tusk", TuskCounters);
    GenericHeroParsing("Underlord", UnderlordCounters);
    GenericHeroParsing("Undying", UndyingCounters);
    GenericHeroParsing("Ursa", UrsaCounters);
    GenericHeroParsing("Vengeful-Spirit", VengefulSpiritCounters);
    GenericHeroParsing("Venomancer", VenomancerCounters);
    GenericHeroParsing("Viper", ViperCounters);
    GenericHeroParsing("Visage", VisageCounters);
    GenericHeroParsing("Void-Spirit", VoidSpiritCounters);
    GenericHeroParsing("Warlock", WarlockCounters);
    GenericHeroParsing("Weaver", WeaverCounters);
    GenericHeroParsing("Windranger", WindrangerCounters);
    GenericHeroParsing("Winter-Wyvern", WinterWyvernCounters);
    GenericHeroParsing("Witch-Doctor", WitchDoctorCounters);
    GenericHeroParsing("Wraith-King", WraithKingCounters);
    GenericHeroParsing("Zeus", ZeusCounters);
}

