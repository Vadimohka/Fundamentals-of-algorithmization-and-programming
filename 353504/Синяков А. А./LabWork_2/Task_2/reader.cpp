#include "reader.h"

Reader::Reader(int code, const QString& fullName, const QString& address, const QString& phoneNumber)
    : m_code(code), m_fullName(fullName), m_address(address), m_phoneNumber(phoneNumber) {}


Reader::~Reader()
{

}
