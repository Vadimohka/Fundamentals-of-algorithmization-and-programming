#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QTextDocument>
#include <QTextTable>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QMovie>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void DeleteRow();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void GenericHeroParsing(const QString &heroName, QList<QList<QString>> &heroCounters);

    void AllHeroParsing();
private:
    Ui::MainWindow *ui;
    QList<QList<QString>> allHeroes;
    QList<QString> SelectedHeroes;

    int numberOfParsed=0;
    bool parsed = false;
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QList<QList<QString>> AllCounters;

    QList<QList<QString>> AbaddonCounters;
    QList<QList<QString>> AlchemistCounters;
    QList<QList<QString>> AncientApparitionCounters;
    QList<QList<QString>> AntiMageCounters;
    QList<QList<QString>> ArcWardenCounters;
    QList<QList<QString>> AxeCounters;
    QList<QList<QString>> BaneCounters;
    QList<QList<QString>> BatriderCounters;
    QList<QList<QString>> BeastmasterCounters;
    QList<QList<QString>> BloodseekerCounters;
    QList<QList<QString>> BountyHunterCounters;
    QList<QList<QString>> BrewmasterCounters;
    QList<QList<QString>> BristlebackCounters;
    QList<QList<QString>> BroodmotherCounters;
    QList<QList<QString>> CentaurWarrunnerCounters;
    QList<QList<QString>> ChaosKnightCounters;
    QList<QList<QString>> ChenCounters;
    QList<QList<QString>> ClinkzCounters;
    QList<QList<QString>> ClockwerkCounters;
    QList<QList<QString>> CrystalMaidenCounters;
    QList<QList<QString>> DarkSeerCounters;
    QList<QList<QString>> DarkWillowCounters;
    QList<QList<QString>> DawnbreakerCounters;
    QList<QList<QString>> DazzleCounters;
    QList<QList<QString>> DeathProphetCounters;
    QList<QList<QString>> DisruptorCounters;
    QList<QList<QString>> DoomCounters;
    QList<QList<QString>> DragonKnightCounters;
    QList<QList<QString>> DrowRangerCounters;
    QList<QList<QString>> EarthSpiritCounters;
    QList<QList<QString>> EarthshakerCounters;
    QList<QList<QString>> ElderTitanCounters;
    QList<QList<QString>> EmberSpiritCounters;
    QList<QList<QString>> EnchantressCounters;
    QList<QList<QString>> EnigmaCounters;
    QList<QList<QString>> FacelessVoidCounters;
    QList<QList<QString>> GrimstrokeCounters;
    QList<QList<QString>> GyrocopterCounters;
    QList<QList<QString>> HoodwinkCounters;
    QList<QList<QString>> HuskarCounters;
    QList<QList<QString>> InvokerCounters;
    QList<QList<QString>> IoCounters;
    QList<QList<QString>> JakiroCounters;
    QList<QList<QString>> JuggernautCounters;
    QList<QList<QString>> KeeperOfTheLightCounters;
    QList<QList<QString>> KunkkaCounters;
    QList<QList<QString>> LegionCommanderCounters;
    QList<QList<QString>> LeshracCounters;
    QList<QList<QString>> LichCounters;
    QList<QList<QString>> LifestealerCounters;
    QList<QList<QString>> LinaCounters;
    QList<QList<QString>> LionCounters;
    QList<QList<QString>> LoneDruidCounters;
    QList<QList<QString>> LunaCounters;
    QList<QList<QString>> LycanCounters;
    QList<QList<QString>> MagnusCounters;
    QList<QList<QString>> MarciCounters;
    QList<QList<QString>> MarsCounters;
    QList<QList<QString>> MedusaCounters;
    QList<QList<QString>> MeepoCounters;
    QList<QList<QString>> MiranaCounters;
    QList<QList<QString>> MonkeyKingCounters;
    QList<QList<QString>> MorphlingCounters;
    QList<QList<QString>> MuertaCounters;
    QList<QList<QString>> NagaSirenCounters;
    QList<QList<QString>> NaturesProphetCounters;
    QList<QList<QString>> NecrophosCounters;
    QList<QList<QString>> NightStalkerCounters;
    QList<QList<QString>> NyxAssassinCounters;
    QList<QList<QString>> OgreMagiCounters;
    QList<QList<QString>> OmniknightCounters;
    QList<QList<QString>> OracleCounters;
    QList<QList<QString>> OutworldDestroyerCounters;
    QList<QList<QString>> PangolierCounters;
    QList<QList<QString>> PhantomAssassinCounters;
    QList<QList<QString>> PhantomLancerCounters;
    QList<QList<QString>> PhoenixCounters;
    QList<QList<QString>> PrimalBeastCounters;
    QList<QList<QString>> PuckCounters;
    QList<QList<QString>> PudgeCounters;
    QList<QList<QString>> PugnaCounters;
    QList<QList<QString>> QueenOfPainCounters;
    QList<QList<QString>> RazorCounters;
    QList<QList<QString>> RikiCounters;
    QList<QList<QString>> RubickCounters;
    QList<QList<QString>> SandKingCounters;
    QList<QList<QString>> ShadowDemonCounters;
    QList<QList<QString>> ShadowFiendCounters;
    QList<QList<QString>> ShadowShamanCounters;
    QList<QList<QString>> SilencerCounters;
    QList<QList<QString>> SkywrathMageCounters;
    QList<QList<QString>> SlardarCounters;
    QList<QList<QString>> SlarkCounters;
    QList<QList<QString>> SnapfireCounters;
    QList<QList<QString>> SniperCounters;
    QList<QList<QString>> SpectreCounters;
    QList<QList<QString>> SpiritBreakerCounters;
    QList<QList<QString>> StormSpiritCounters;
    QList<QList<QString>> SvenCounters;
    QList<QList<QString>> TechiesCounters;
    QList<QList<QString>> TemplarAssassinCounters;
    QList<QList<QString>> TerrorbladeCounters;
    QList<QList<QString>> TidehunterCounters;
    QList<QList<QString>> TimbersawCounters;
    QList<QList<QString>> TinkerCounters;
    QList<QList<QString>> TinyCounters;
    QList<QList<QString>> TreantProtectorCounters;
    QList<QList<QString>> TrollWarlordCounters;
    QList<QList<QString>> TuskCounters;
    QList<QList<QString>> UnderlordCounters;
    QList<QList<QString>> UndyingCounters;
    QList<QList<QString>> UrsaCounters;
    QList<QList<QString>> VengefulSpiritCounters;
    QList<QList<QString>> VenomancerCounters;
    QList<QList<QString>> ViperCounters;
    QList<QList<QString>> VisageCounters;
    QList<QList<QString>> VoidSpiritCounters;
    QList<QList<QString>> WarlockCounters;
    QList<QList<QString>> WeaverCounters;
    QList<QList<QString>> WindrangerCounters;
    QList<QList<QString>> WinterWyvernCounters;
    QList<QList<QString>> WitchDoctorCounters;
    QList<QList<QString>> WraithKingCounters;
    QList<QList<QString>> ZeusCounters;
};

#endif // MAINWINDOW_H
