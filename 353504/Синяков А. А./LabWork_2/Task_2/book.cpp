#include "book.h"

Book::Book(int code, const QString& author, const QString& title, int year, const QString& language)
    : m_code(code), m_author(author), m_title(title), m_year(year), m_language(language) {
}

Book::~Book() {

}
