#include "groupcontainer.h"

GroupContainer::GroupContainer() = default;

void GroupContainer::AddGroup(Group *group)
{
    Group* groupToAdd = new Group(*group);
    groups->push_back(groupToAdd);
}

int64_t GroupContainer::FindGroup(Group *group)
{
    int64_t size = groups->size();

    for (int iterator = 0;iterator<size;iterator++)
    {
        if (*group->GetName() == *groups->at(iterator)->GetName())
        {
            return iterator;
        }
    }

    return size;
}

std::vector<Group *> *GroupContainer::GetGroups()
{
    return groups;
}

Group GroupContainer::GetGroupAtPos(int64_t position)
{
    return *groups->at(position);
}

QString *GroupContainer::ToQString()
{
    QString* answer = new QString("");
    for (Group* group : *groups)
    {
        answer->append(group->ToQString());
        answer->append(QString::fromStdString(", "));
    }

    return answer;
}

void GroupContainer::FromQStringToInstance(QString *object)
{
    int size = object->size();
    QString* groupInString = new QString("");

    for (int i = 0;i<size;i++)
    {
        if ((*object)[i] == ',')
        {
            Group* newGroup = new Group;
            newGroup->FromQStringToInstance(groupInString);
            AddGroup(newGroup);
            *groupInString = "";
            delete newGroup;
            i++;
        }
        else
        {
            groupInString->append((*object)[i]);
        }
    }

    if (*groupInString != "")
    {
        Group* newGroup = new Group(groupInString);
        AddGroup(newGroup);
        *groupInString = "";
        delete newGroup;
    }

    delete groupInString;
}
