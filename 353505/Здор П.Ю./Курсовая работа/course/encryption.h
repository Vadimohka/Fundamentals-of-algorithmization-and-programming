#ifndef ENCRYPTION_H
#define ENCRYPTION_H
#include <string>
#include <QApplication>
#include <vector>
#include <QFile>
class Encryption
{
public:
    Encryption();
    int nod(int,int);
    std::string RSA(std::wstring);
    std::string RC4(std::wstring);
    void RC4_implement(std::vector <int>&,std::vector <int>&);
    std::vector <int> RC4_encryption(std::vector<int>&,std::vector<int>&);
    std::string decryptVigenere(std::string&,std::string&);
    std::string encryptVigenere(std::string&,std::string&);
    void Vigener_cypher(std::string&);
    void Hill_cipher(std::string&);
    std::string Hill_encrypt(std::string,std::vector<std::vector<int>>);
    std::vector<std::vector<int>> getInverseMatrix(std::vector<std::vector<int>>&);
    int gen_key(int);
    int binpow(int,int,int);
    std::pair<std::vector<int>, int> Hamil_encrypt(std::string, int, int, int);
    std::string Hamil_decrypt(std::vector<int> en_msg, int p, int key, int q);
    void Hamil_cipher(std::string a);
private:
    int i1=0;
    int j1=0;


};

#endif // ENCRYPTION_H
