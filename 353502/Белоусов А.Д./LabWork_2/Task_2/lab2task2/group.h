#ifndef GROUP_H
#define GROUP_H

#include <QString>
#include "convertibleinstance.h"

class Group : public ConvertibleInstance
{
private:
    QString* name{new QString};
public:
    Group();
    explicit Group(QString *name);
    ~Group() override = default;
    void SetName(QString* name);
    QString* GetName();
    QString* ToQString() override;
    void FromQStringToInstance(QString* object) override;
};

#endif // GROUP_H
