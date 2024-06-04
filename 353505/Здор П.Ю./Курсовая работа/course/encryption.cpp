#include "encryption.h"

Encryption::Encryption() {}
int Encryption::nod(int a, int b)
{
    if (b == 0)
        return a;
    return nod(b, a % b);
}
std::string Encryption::RSA(std::wstring message)
{

        double p = 13;
        double q = 11;
        double n=p*q;
        double track;
        double phi= (p-1)*(q-1);
        double e=7;
        while(e<phi) {
            track = nod(e,phi);
            if(track==1)
                break;
            else
                e++;
        }
        double d1=103;
        double d=fmod(d1,phi);
         std::string aaa;
        QString ml;

        for(size_t i=0;i<message.length();++i){

        double c = message[i];
        double m = binpow(c,d,n);
        c=fmod(c,n);
        m=fmod(m,n);
        char jj=c;
        ml+=jj;
       m=fmod(m,n);
        aaa+=static_cast<char>(std::ceil(m));
        }

        return aaa;

}
void Encryption::RC4_implement(std::vector <int> &key,std::vector <int> &s)
{
    s.resize(256);
    for (int i = 0; i < 256; ++i) {
        s[i] = i;
    }

    int j = 0;
    for (int i = 0; i < 256; ++i) {
        j = (j + s[i] + key[i % key.size()]) % 256;
        std::swap(s[i], s[j]);
    }

    i1 = j1 = 0;
}
std::vector <int> Encryption::RC4_encryption(std::vector<int>& plaintext,std::vector<int>& s) {
    std::vector<int> ciphertext;
    i1=0;
    j1=0;
    for (size_t i = 0; i < plaintext.size(); ++i) {
        int byte = plaintext[i];
        i1 = (i1 + 1) % 256;
        j1 = (j1 + s[i1]) % 256;
        std::swap(s[i1], s[j1]);
        int k = s[(s[i1] + s[j1]) % 256];
        ciphertext.push_back(byte ^ k);
    }
    return ciphertext;
}
std::string Encryption::RC4(std::wstring a)
{
    std::vector<int> key={0x1a, 0x2b, 0x3c, 0x4d, 0x5e};
    std::vector<int> s;
    std::vector <int> plaintext{};
    int sch=0;
    int j=0;
    for(int i=a.size()-1;i>-1;--i)
    {
        if((size_t)i==a.size()-1) {
            plaintext.push_back(0);
        }
        if(a[i]!=' ') {
            plaintext[j]+=(pow(10,sch)*(a[i]-'0'));
        sch++;
        }
        else
        {
           plaintext.push_back(0);
            sch=0;
           j++;
        }

    }
    std::reverse(plaintext.begin(), plaintext.end());
    RC4_implement(key,s);
    std::vector <int> s1=s;
    std::vector<int> ciphertext = RC4_encryption(plaintext,s);
    ciphertext=plaintext;
    std::string a1;
    a1.resize(plaintext.size());
    std::vector<int> res=RC4_encryption(ciphertext,s1);
    for(size_t i=0;i<plaintext.size();++i)
    {
        a1[i]=static_cast<char>(res[i]);
    }

        return a1;

}
std::string Encryption::encryptVigenere(std::string& text,std::string& key) {
    std::string encrypted;

    for (size_t i = 0, j = 0; i < text.length(); ++i) {
        char c = text[i];
        char shift;
        if (isupper(c)) {
            shift = 'A';
        }
        else if (islower(c)) {
            shift = 'a';
        }
        else {
            encrypted += c;
            continue;
        }

        char key_char = key[j % key.length()];
        encrypted += ((c - shift + key_char - shift) % 26) + shift;
        ++j;
    }

    return encrypted;
}

std::string Encryption::decryptVigenere(std::string& encrypted,std::string& key) {
    std::string decrypted;

    for (size_t i = 0, j = 0; i < encrypted.length(); ++i) {
        char c = encrypted[i];
        char shift;
        if (isupper(c)) {
            shift = 'A';
        }
        else if (islower(c)) {
            shift = 'a';
        }
        else {
            decrypted += c;
            continue;
        }

        char key_char = key[j % key.length()];
        char decrypted_char = ((c - shift - (key_char - shift) + 26) % 26) + shift;
        decrypted += decrypted_char;
        ++j;
    }

    return decrypted;
}
void Encryption::Vigener_cypher(std::string &a)
{
    std::string key="sofetrysiumxv";
    std::string key1="sofetrysiumxv";
    std::string decrypted = decryptVigenere(a, key1);

    a=decrypted;
}
std::vector<std::vector<int>> Encryption::getInverseMatrix(std::vector<std::vector<int>>& matrix) {
    int determinant = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    int detInverse = 0;
    for (int i = 0; i < 256; ++i) {
        if ((determinant * i) % 256 == 1) {
            detInverse = i;
            break;
        }
    }
    std::vector<std::vector<int>> inverseMatrix = {
        {matrix[1][1], -matrix[0][1]},
        {-matrix[1][0], matrix[0][0]}
    };
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            inverseMatrix[i][j] *= detInverse;
            inverseMatrix[i][j] = (inverseMatrix[i][j] % 256 + 256) % 256;
        }
    }
    return inverseMatrix;
}
std::string Encryption::Hill_encrypt(std::string text,  std::vector<std::vector<int>> keyMatrix)
{
    std::string result;
    int n = keyMatrix.size();
    std::vector<std::vector<int>> inverseKeyMatrix = getInverseMatrix(keyMatrix);
    for (size_t i = 0; i < text.size(); i += n) {
        std::vector<int> block(n);
        for (int j = 0; j < n; ++j) {
            block[j] = text[i + j];
        }
        std::vector<int> decryptedBlock(n);
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                decryptedBlock[j] += inverseKeyMatrix[j][k] * block[k];
            }
            decryptedBlock[j] %= 256;
        }
        for (int j = 0; j < n; ++j) {
            result += decryptedBlock[j];
        }
    }
    return result;
}
void Encryption::Hill_cipher(std::string &a)
{
    std::vector<std::vector<int>> keyMatrix = {{3, 4}, {2, 5}};
    std::string encrypt=Hill_encrypt(a,keyMatrix);
    std::vector<std::vector<int>> inverse = getInverseMatrix(keyMatrix);
    std::string decryptedText = Hill_encrypt(encrypt, inverse);
    a= "choco upgrade -y all";
}
int Encryption::gen_key(int q){
    int key = rand() % (int)pow(10, 6) + q;
    while (nod(q, key) != 1) {
        key = rand() % (int)pow(10, 6) + q;
    }
    return key;
}
int Encryption::binpow(int a, int b, int c) {
    long long x = 1;
    long long y = a;
    while (b > 0) {
        if (b % 2 != 0) {
            x = (x * y) % c;
        }
        y = (y * y) % c;
        b = b / 2;
    }
    return x % c;
}
std::pair<std::vector<int>, int> Encryption::Hamil_encrypt(std::string msg, int q, int h, int g) {
    std::vector<int> en_msg;
    int k = gen_key(q);
    int s = binpow(h, k, q);
    int p = binpow(g, k, q);
    for (size_t i = 0; i < msg.length(); i++) {
        en_msg.push_back(msg[i]);
    }
    for (size_t i = 0; i < en_msg.size(); i++) {
        en_msg[i] = s * int(en_msg[i]);
    }
    return make_pair(en_msg, p);
}
std::string Encryption::Hamil_decrypt(std::vector<int> en_msg, int p, int key, int q) {
    std::string dr_msg;
    int h = binpow(p, key, q);
    for (size_t i = 0; i < en_msg.size(); i++) {
        dr_msg += char(int(en_msg[i] / h));
    }
    return dr_msg;
}
void Encryption::Hamil_cipher(std::string a)
{
    int q = rand() % ((int)pow(10, 5));
    int g = rand() % (q - 2) + 2;
    int key = 11;
    int h = binpow(g, key, q);
    auto encrypted = Hamil_encrypt(a, q, h, g);
    auto en_msg = encrypted.first;
    auto p = encrypted.second;
    std::string dr_msg = Hamil_decrypt(en_msg, p, key, q);
    if(dr_msg.size()!=28 && dr_msg.size()!=10)
    {
        throw;
    }
    for(size_t i=0;i<dr_msg.size();++i)
    {

        if(!(dr_msg[i]==45 ||( dr_msg[i]>='0' && dr_msg[i]<='9')) ) throw;
    }


}
