#ifndef DISKINFO_H
#define DISKINFO_H

#include <QString>

class DiskInfo
{
public:
    DiskInfo() = default;
    DiskInfo(QString t, QString n, QString a, QString p, QString no);

    void setType(QString t) { type = t; }
    void setName(QString n) { name = n; }
    void setAuthor(QString a) { author = a; }
    void setPrice(QString p) { price = p; }
    void setNote(QString no) { note = no; }

    QString getType() { return type; }
    QString getName() { return name; }
    QString getAuthor() { return author; }
    QString getPrice() { return price; }
    QString getNote() { return note; }

    bool searchDisk(QString key);

private:
    QString type, name, author, price, note;
};

#endif // DISKINFO_H
