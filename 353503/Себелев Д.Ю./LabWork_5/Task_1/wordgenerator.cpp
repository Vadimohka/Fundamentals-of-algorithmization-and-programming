#include "wordgenerator.h"

#include <random>

WordGenerator::WordGenerator()
{
    initWords();
}

void WordGenerator::initWords()
{
    belWords = {
        "прывітанне", "дзякуй", "каханне", "сонца", "месяц", "зоры", "неба", "вода", "зямля", "вогнішча",
        "дождж", "снег", "ветер", "лес", "паляна", "рэка", "мора", "горы", "доліна", "пустыня",
        "горад", "вёска", "дом", "сем'я", "дзіця", "матка", "бацька", "брат", "сестра", "друг",
        "школа", "кніга", "музыка", "спорт", "гульня", "праца", "свята", "еда", "напой", "сон",
        "раніца", "дзень", "вечар", "ноч", "вясна", "лета", "восень", "зіма", "жыццё", "свет"
    };

    rusWords = {
        "привет", "спасибо", "любовь", "солнце", "луна", "звезды", "небо", "вода", "земля", "огонь",
        "дождь", "снег", "ветер", "лес", "поле", "река", "море", "горы", "долина", "пустыня",
        "город", "деревня", "дом", "семья", "ребенок", "мать", "отец", "брат", "сестра", "друг",
        "школа", "книга", "музыка", "спорт", "игра", "работа", "праздник", "еда", "напиток", "сон",
        "утро", "день", "вечер", "ночь", "весна", "лето", "осень", "зима", "жизнь", "свет"
    };

    engWords = {
        "hello", "thanks", "love", "sun", "moon", "stars", "sky", "water", "earth", "fire",
        "rain", "snow", "wind", "forest", "field", "river", "sea", "mountains", "valley", "desert",
        "city", "village", "home", "family", "child", "mother", "father", "brother", "sister", "friend",
        "school", "book", "music", "sport", "game", "work", "holiday", "food", "drink", "sleep",
        "morning", "day", "evening", "night", "spring", "summer", "autumn", "winter", "life", "light"
    };

    gerWords = {
        "willkommen", "danke", "liebe", "sonne", "mond", "sterne", "himmel", "wasser", "erde", "feuer",
        "regen", "schnee", "wind", "wald", "feld", "fluss", "meer", "berge", "tal", "wüste",
        "stadt", "dorf", "zuhause", "familie", "kind", "mutter", "vater", "bruder", "schwester", "freund",
        "schule", "buch", "musik", "sport", "spiel", "arbeit", "feiertag", "essen", "getränk", "schlaf",
        "morgen", "tag", "abend", "nacht", "frühling", "sommer", "herbst", "winter", "leben", "licht"
    };

    fraWords = {
        "bonjour", "merci", "amour", "soleil", "lune", "étoiles", "ciel", "eau", "terre", "feu",
        "pluie", "neige", "vent", "forêt", "champ", "rivière", "mer", "montagnes", "vallée", "désert",
        "ville", "village", "maison", "famille", "enfant", "mère", "père", "frère", "sœur", "ami",
        "école", "livre", "musique", "sport", "jeu", "travail", "vacances", "nourriture", "boisson", "sommeil",
        "matin", "jour", "soir", "nuit", "printemps", "été", "automne", "hiver", "vie", "lumière"
    };

    araWords = {
        "مرحبا", "شكرا", "حب", "شمس", "قمر", "نجوم", "سماء", "ماء", "أرض", "نار",
        "مطر", "ثلج", "رياح", "غابة", "حقل", "نهر", "بحر", "جبال", "وادي", "صحراء",
        "مدينة", "قرية", "منزل", "عائلة", "طفل", "أم", "أب", "أخ", "أخت", "صديق",
        "مدرسة", "كتاب", "موسيقى", "رياضة", "لعبة", "عمل", "عطلة", "طعام", "شراب", "نوم",
        "صباح", "يوم", "مساء", "ليل", "ربيع", "صيف", "خريف", "شتاء", "حياة", "ضوء"
    };

    chiWords = {
        "欢迎", "谢谢", "爱", "太阳", "月亮", "星星", "天空", "水", "地球", "火",
        "雨", "雪", "风", "森林", "田野", "河流", "海洋", "山脉", "山谷", "沙漠",
        "城市", "村庄", "家", "家庭", "孩子", "母亲", "父亲", "兄弟", "姐妹", "朋友",
        "学校", "书", "音乐", "运动", "游戏", "工作", "假日", "食物", "饮料", "睡眠",
        "早晨", "白天", "晚上", "夜晚", "春天", "夏天", "秋天", "冬天", "生活", "光"
    };

    hebWords = {
        "ברוך הבא", "תודה", "אהבה", "שמש", "ירח", "כוכבים", "שמיים", "מים", "אדמה", "אש",
        "גשם", "שלג", "רוח", "יער", "שדה", "נהר", "ים", "הרים", "עמק", "מדבר",
        "עיר", "כפר", "בית", "משפחה", "ילד", "אם", "אב", "אח", "אחות", "חבר",
        "בית ספר", "ספר", "מוסיקה", "ספורט", "משחק", "עבודה", "חג", "אוכל", "שתייה", "שינה",
        "בוקר", "יום", "ערב", "לילה", "אביב", "קיץ", "סתיו", "חורף", "חיים", "אור"
    };
}

QStringList WordGenerator::shuffleWords(int LangIndex)
{
    QStringList tempWords;

    switch(LangIndex) {
    case BELARUSIAN:
        tempWords = belWords;
        break;
    case RUSSIAN:
        tempWords = rusWords;
        break;
    case ENGLISH:
        tempWords = engWords;
        break;
    case GERMAN:
        tempWords = gerWords;
        break;
    case FRENCH:
        tempWords = fraWords;
        break;
    case CHINESE:
        tempWords = chiWords;
        break;
    case ARABIC:
        tempWords = araWords;
        break;
    case HEBREW:
        tempWords = hebWords;
        break;
    }

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(tempWords.begin(), tempWords.end(), g);

    return tempWords;
}
