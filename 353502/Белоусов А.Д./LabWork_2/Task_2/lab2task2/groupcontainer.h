#ifndef GROUPCONTAINER_H
#define GROUPCONTAINER_H

#include <vector>
#include "group.h"

class GroupContainer : public ConvertibleInstance
{
private:
    std::vector<Group*>* groups{new std::vector<Group*>};
public:
    GroupContainer();
    ~GroupContainer() override = default;
    void AddGroup(Group* group);
    int64_t FindGroup(Group* group);
    std::vector<Group*>* GetGroups();
    Group GetGroupAtPos(int64_t position);
    QString* ToQString() override;
    void FromQStringToInstance(QString* object) override;
};

#endif // GROUPSERVICE_H
