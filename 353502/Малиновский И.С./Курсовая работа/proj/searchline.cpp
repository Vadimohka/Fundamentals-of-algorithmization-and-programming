#include "searchline.h"

SearchLine::SearchLine() : QLineEdit() {
    QFile file("/home/ilyamzy/proj/courseWork/Resources/positions.txt");

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Unable to open file!";
        return;
    }


    QTextStream in(&file);
    while (!in.atEnd()) {
        int x, y, r;
        QString text;
        in >> x >> y >> r;
        in.skipWhiteSpace();
        text = in.readLine();
        names.push_back(text);
    }
    file.close();

    model = new QStringListModel(this);
    completer = new QCompleter(model, this);
    completer->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    setCompleter(completer);

    connect(this, &QLineEdit::textChanged, this, &SearchLine::findNames);
}

void SearchLine::findNames() {
    QString text = this->text();
    if (text.isEmpty()) return;

    int lPos = 0, rPos = names.size() - 1;
    while (rPos - lPos > 1) {
        int midPos = (lPos + rPos) / 2;
        if (text <= names[midPos]) rPos = midPos;
        else lPos = midPos;
    }

    int ind = lPos;
    if (text <= names[rPos]) ind = rPos;
    QStringList list;
    for (int i = ind; i < names.size(); i++) {
        if (!isEqual(text, names[i])) break;
        list << names[i];
    }
    if (list.size() == 1 && text == list[0])
    {
        (*infoWidgets)[indNames[text]].showInfo();
    }
    model->setStringList(list);
    completer->setModel(model);
}

void SearchLine::setInfoWidgets(QVector<CityInfoWidget>* infoWidgets) {
    this->infoWidgets = infoWidgets;
    for (int i = 0; i < names.size(); i++) {
        indNames[names[i]] = i;
    }
    sort();
}

bool SearchLine::isEqual(const QString pref, const QString name) {
    if (name.size() < pref.size()) return false;

    QString str = pref + "$" + name;
    int n = str.size();
    QVector<int> z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (r >= i) z[i] = qMin(z[i - l], r - i + 1);
        while (i + z[i] < n && str[z[i]] == str[z[i] + i]) z[i]++;
        if (r < i + z[i] - 1) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return (z[pref.size() + 1] == pref.size());
}

void SearchLine::sort()
{
    for (int i=0; i<names.size(); i++)
    {
        for (int j=i+1; j<names.size(); j++) {
            if (names[j]<names[i]) qSwap(names[i], names[j]);
        }
    }
}
