#ifndef BLOWFISH_H
#define BLOWFISH_H

#include <QString>
#include <QDebug>

class BlowFish
{
private:
    static uint32_t* GetFirstConsts();
    static uint32_t** GetSecondConsts();
    static uint32_t F(uint32_t, uint32_t** &);
    static void padData (QByteArray &data);
    static quint32 toUint32(const QByteArray &data);
    static QByteArray toByteArray(quint32 value);
    static void encryptBlock(quint32 &xl, quint32 &xr, uint32_t* &, uint32_t** &);
    static void decryptBlock(quint32 &xl, quint32 &xr, uint32_t* &, uint32_t** &);



public:
    BlowFish();

    static QString Encrypt(QString);
    static QString Decrypt(QString);
};

#endif // BLOWFISH_H
