#include <cstddef>
#include <QVector>

class Search {

private:
    static long _binsearch(const QVector<long>& vect, long val, size_t beg, size_t end);

public:
    static long binsearch(const QVector<long>& vect, long val);

};