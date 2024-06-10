#ifndef LAB5TASK1_DISPLAY_H
#define LAB5TASK1_DISPLAY_H

#include <QWidget>
#include <QTime>
#include <QTimer>


QT_BEGIN_NAMESPACE
namespace Ui { class Display; }
QT_END_NAMESPACE

class Display : public QWidget {
Q_OBJECT

    std::vector<QColor> symbolColour;

    int language;

    const QString Text[6] = {
            {"Berlin ist die Hauptstadt Deutschlands."
             " Berlin ist eine Stadt und auch ein Bundesland,"
             " wie Hamburg oder Bremen. Mit rund 3,5 Millionen Einwohnern"
             " ist Berlin die zweitgrößte Stadt der EU. "
             "Die Metropole an der Spree ist über 770 Jahre alt."
             " Nach 1949 war die Stadt in zwei Teile geteilt. "
             "Das waren West- und Ostberlin. Die Grenze zwischen zwei"
             " Teilen war seit 1961 die Berliner Mauer. Nach dem Fall "
             "der Mauer 1989 und nach der Wiedervereinigung 1990 wurde "
             "Berlin wieder Hauptstadt des Landes."},
            {"À l'origine, les claviers étaient conçus pour les machines à "
             "écrire mécaniques. La disposition des touches était organisée de "
             "manière à réduire les blocages des leviers de frappe. Aujourd'hui,"
             " les claviers modernes utilisent des technologies électroniques, "
             "mais la disposition des touches QWERTY est restée prédominante."
             "Les claviers ergonomiques sont conçus pour réduire la fatigue et "
             "les blessures dues à une utilisation prolongée. Ils présentent souvent"
             " des formes courbes et des touches disposées de manière à s'adapter à "
             "la position naturelle des mains et des doigts."
             "L'apprentissage de la dactylographie nécessite de la pratique et de"
             " la patience. Les exercices réguliers permettent de développer la mémoire"
             " musculaire et d'améliorer la vitesse de frappe. Il est essentiel de garder "
             "une bonne posture et de faire des pauses pour éviter les tensions et les douleurs musculaires."
             "Avec le développement de la technologie, les claviers virtuels et les "
             "claviers rétroéclairés sont devenus courants. Les claviers virtuels, disponibles"
             " sur les écrans tactiles, offrent une flexibilité et une portabilité accrues, "
             "tandis que les claviers rétroéclairés facilitent la frappe"
             " dans des conditions de faible luminosité."},
            {"في البداية، كانت لوحات المفاتيح مصممة للآلات الكاتبة الميكانيكية."
             " تم تنظيم ترتيب المفاتيح بطريقة تقلل من انسداد الأذرع"
             " الضاربة. اليوم، تستخدم لوحات المفاتيح الحديثة تقنيات "
             "إلكترونية، ولكن ترتيب المفاتيح QWERTY لا يزال هو السائد."
             "تم تصميم لوحات المفاتيح المريحة لتقليل التعب والإصابات"
             " الناتجة عن الاستخدام الطويل. غالبًا ما تحتوي على أشكال منحنية"
             " ومفاتيح مرتبة بطريقة تتناسب مع الوضع الطبيعي لليدين والأصابع."
             "يتطلب تعلم الطباعة ممارسة وصبرًا. تتيح التمارين المنتظمة"
             " تطوير الذاكرة العضلية وتحسين سرعة الكتابة. من الضروري"
             " الحفاظ على وضعية جيدة وأخذ فترات راحة لتجنب التوتر وآلام العضلات."
             "مع تطور التكنولوجيا، أصبحت لوحات المفاتيح الافتراضية ولوحات المفاتيح ذات الإضاءة"
             " الخلفية شائعة. توفر لوحات المفاتيح الافتراضية، المتوفرة على الشاشات التي "
             "تعمل باللمس، مرونة وقابلية للنقل، في حين تسهل لوحات المفاتيح"
             " ذات الإضاءة الخلفية الكتابة في ظروف الإضاءة المنخفضة."},
            {"Zài chūxiān, jiànpán shì wèi jīshù zhī zìhuì méihéng de. Jiànpán de"
             " páizi zhǐfāngzài zhìyuán zài huódòngzhōng. Jīntiān, xiàndài jiànpán shǐyòng "
             "diànzǐ jìshù, dàn páizi de páizi háishi zhùyào de. Ér gōngnéng jiànpán "
             "shì wèi jiǎnshǎo lèi láiyuán yǐnjìn de. Tāmen chángcháng huì yǒu wěi dānxián hé "
             "jiǎnxián míngpiàn, zhèxiē míngpiàn zhìlì rén shǐyòng tìgāo sùdù. Rújīn, xiǎnkǎo shùzìhuà,"
             " xiǎngfā gǎnyìngzhě, zhèxiē yǐnsù wèi bùděng yùyán shǐyòngzhě tígōng le xīnxī shèjì hé "
             "sānqiáng yùsǔn hé yòngyǒu xìngnéng.Díngxué shūyǎng xūqiú yǒu xúnliàn hé rěnwùxìng. Jīngcháng "
             "de yùndòng nénggòu fāzhǎn jīyì jī dàibiàn kuàisù. Yánjíng duōbāo hǎo de zhìliàng hé pāizhà "
             "gǎnyìng zhě xíngyòng. Jiǎnchéng shèjì de jiànpán yǔ xìnwǎng jiànpán yǐjīng chángyòng. "
             "Jìnlìng guójì huò zhǔyào xìtǒng wèi dǎkāi le shíyòng zhèngzài jī jīmiàn shèqū de "
             "tígōng yīnjiàn shèjì hé yǔ zhòngduān shèjì."},
            {"Яна пайшла ў сваю каморку, выняла з-пад сенніка калоду старых,"
             " як і сама яна, карт, прысела на табарэцік каля невялічкага століка,"
             " што стаяў пры пасцелі, патасавала сваім манерам і пачала спаважна раскладваць"
             " іх на восем кучак па тры карты ў кожнай. Калі такім чынам карты былі разложаны,"
             " а ляжалі яны тварам уніз, бабка Параска пераварочвала кучкі ў тым жа парадку,"
             " у якім раскладала іх. Кожная тройка карт мела сваё прызначэнне: «для дому»,"
             " «для лёсу», «для шчасця», «для дружбы» і г. д. Перавярнуўшы адну карту,"
             " бабка Параска пільна ўглядалася. У першай кучцы пасярэдзіне аказаўся вінны туз,"
             " а з краю — званковая дзявятка, з другога — храстовы ніжнік, гэта значыць — Лабановіч."
             " Бабка незадаволена паківала галавою: такое спалучэнне карт было не ў руку настаўніку,"
             " бо яно азначала невясёлыя думкі, згрызоты і цяжкі клопат. Нічога добрага для настаўніка"
             " не было і ў другой, і ў трэцяй, і ў наступных кучках карт. То замешваўся нейкі"
             " злы і хітры мужчына, то непрыязная жанчына, то сумная дарога. Бабка зусім засмуцілася."
             " Яна змяшала карты, ператасавала як мае быць ды ізноў пачала новую раскладку."
             " Але і на гэты раз нічога добрага для Лабановіча не варажылі карты. А бабка не"
             " хацела мірыцца з гэтым. Шмат разоў раскідала яна карты, і толькі тады заспакоілася,"
             " калі характар варажбы змяніўся ў лепшы бок."},
            {"בטח! הנה טקסט בעברית שניתן להשתמש בו למטרות תרגול מקלדת:להתחלה, המקלדת פותחה כדי לשיפור יכולת הכתיבה על"
             " מכונות כתיבה מכניות. סידור המקשים הוא ארגון למניעת תקלות במנגנון הדפסה. היום,"
             " מקלדות מודרניות משתמשות בטכנולוגיות אלקטרוניות, אך סידור המקשים QWERTY נותר"
             " נפוץ.מקלדות ארגונומיות מיועדות להפחתת עייפות ופציעות כתוצאה משימוש ממושך."
             " הן תמיד מכילות צורות מעוגלות ומקשים מסודרים כך שיתאימו למקום הטבעי של "
             "הידיים והאצבעות. למידת הקלדה דורשת תרגול וסבלנות. אימונים תדירים מאפשרים"
             " לפתח זיכרון שרירים ולשפר מהירות קלדה. חשוב לשמור על ישיבה תקינה ולעשות "
             "הפסקות כדי למנוע מתח וכאבי שרירים.עם התפתחות הטכנולוגיה, מקלדות וירטואליות "
             "ומקלדות עם תאורה אחורית הפכו לנפוצות. המקלדות הוירטואליות, הזמינות על מסכי מגע,"
             " מספקות גמישות וניידות, בעוד שמקלדות עם תאורה אחורית קלות את ההקלדה בתנאים של תאורה נמוכה."}};

public:
    explicit Display(QWidget *parent = nullptr);

    ~Display() override;

    void getKey(QString key);

    void updateSelf(int index);

private:
    Ui::Display *ui;

    bool first;
    int counter;
    int counterRight;

    QTime time;
    QTimer *timer;

private slots:

    void timerEmiter();

signals:

    void percent(double);

    void symbolsAndTime(int symbols, QTime time);

};


#endif //LAB5TASK1_DISPLAY_H
