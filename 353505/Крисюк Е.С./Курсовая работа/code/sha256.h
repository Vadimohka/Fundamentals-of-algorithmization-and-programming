#ifndef SHA256_H
#define SHA256_H

#include <QString>
#include <QDebug>
#include <QList>

class SHA256
{
private:
    static QString GetDouble(QString &);

    static uint32_t right_rotate(uint32_t, uint32_t);

    static void Modify_zeros_in_chuncks(QList<uint32_t> &);

    static void Compress(QList<uint32_t> &,uint32_t* &, uint32_t*);

public:
    SHA256();

    static QString GetSha256(QString &);
};

#endif // SHA256_H
