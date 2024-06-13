#include "TemplateSort.h"

bool lessThan(Statement *s1, Statement *s2)
{
    return s1->getName().toLower() < s2->getName().toLower();
}
