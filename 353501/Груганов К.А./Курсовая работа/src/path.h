#ifndef PATH_H
#define PATH_H

class QPointF;

class Path
{
public:
    Path() { }
    virtual QPointF PointAt(float p) const = 0;
    virtual int Size() const = 0;
};

#endif // PATH_H
