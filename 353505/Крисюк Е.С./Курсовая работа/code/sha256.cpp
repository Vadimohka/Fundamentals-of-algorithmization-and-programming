#include "sha256.h"

SHA256::SHA256()
{

}

QString SHA256::GetSha256(QString &str){

    QString result = GetDouble(str);

    uint32_t* h = new uint32_t [8] {
        0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a, 0x510e527f, 0x9b05688c, 0x1f83d9ab,0x5be0cd19,
    };

    uint32_t* consts = new uint32_t[64]{
        0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
        0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
        0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
        0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
        0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
        0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
        0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
        0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
    };


    QString result_length = QString::number(result.length(),2);


    for(int i = result_length.length(); i < 64; ++i){
        result_length.insert(0,"0");
    }

    result.append('1');

    long long count_of_zero_add = (448 - (result.length() % 512) + 512) % 512;

    result += QString('0').repeated(count_of_zero_add);

    result += result_length;


    QList<uint32_t> words_list;

    int binary_temp;

    for(int i = 0; i < result.length(); i += 32){

        binary_temp = result.mid(i, 32).toInt(nullptr,2);

        words_list.append(binary_temp);

    }


    QList<QList<uint32_t>> chuncks;

    for(int i = 0; i < words_list.length() / 16; ++i){

        chuncks.append(words_list.mid(i,i + 16));
    }

    for(int i = 0; i < chuncks.length(); ++i){
        for(int j = chuncks[i].length(); j < 64; ++j){

            chuncks[i].append(0x00);
        }

        Modify_zeros_in_chuncks(chuncks[i]);
    }

    for(int i = 0; i < chuncks.length(); ++i){
        Compress(chuncks[i], h, consts);
    }


    QString hash;

    for(int i = 0; i < 8; ++i){
        hash += QString::number(h[i],16).toUpper();
    }


    return hash;

}

uint32_t SHA256::right_rotate(uint32_t val, uint32_t bits){
    return (val >> bits) | (val << (32 - bits));
}

void SHA256::Modify_zeros_in_chuncks(QList<uint32_t> & list){

    for (int i = 16; i < 64; i++) {
        uint32_t s0 = right_rotate(list[i-15],7) ^ right_rotate(list[i-15],18) ^ (list[i-15] >> 3);

        uint32_t s1 = right_rotate(list[i-2],17) ^ right_rotate(list[i-2],19) ^ (list[i-2] >> 10);

        list[i] = list[i-16] + s0 + list[i-7] + s1;
    }
}

QString SHA256::GetDouble(QString &str){
    QString result;

    QByteArray byte_array = str.toUtf8();

    QChar symbol;

    for(int i = 0; i < byte_array.length(); ++i){
        symbol = byte_array[i];

        QString bynary_symbol = QString::number(symbol.toLatin1(), 2);

        result += bynary_symbol.rightJustified(8,'0');
    }

    return result;
}

void SHA256::Compress(QList<uint32_t> & list, uint32_t* &h_array, uint32_t* consts){

    uint32_t a = h_array[0];
    uint32_t b = h_array[1];
    uint32_t c = h_array[2];
    uint32_t d = h_array[3];
    uint32_t e = h_array[4];
    uint32_t f = h_array[5];
    uint32_t g = h_array[6];
    uint32_t h = h_array[7];

    for (int i = 0; i < 64; i++) {
        uint32_t S1 = right_rotate(e, 6) ^ right_rotate(e, 11) ^ right_rotate(e, 25);
        uint32_t ch = (e & f) ^ ((~e) & g);
        uint32_t temp1 = h + S1 + ch + consts[i] + list[i];
        uint32_t S0 = right_rotate(a, 2) ^ right_rotate(a, 13) ^ right_rotate(a, 22);
        uint32_t maj = (a & b) ^ (a & c) ^ (b & c);
        uint32_t temp2 = S0 + maj;

        h = g;
        g = f;
        f = e;
        e = d + temp1;
        d = c;
        c = b;
        b = a;
        a = temp1 + temp2;
    }

    h_array[0] += a;
    h_array[1] += b;
    h_array[2] += c;
    h_array[3] += d;
    h_array[4] += e;
    h_array[5] += f;
    h_array[6] += g;
    h_array[7] += h;
}
