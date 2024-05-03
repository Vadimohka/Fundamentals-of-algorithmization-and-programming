#include "disk.h"

#include <utility>

disk::disk() = default;

disk::disk(QString newtype, QString newname, QString newauthor, int newcost, QString newprim) : cost(newcost),
                                                                                                type(std::move(newtype)),
                                                                                                name(std::move(newname)),
                                                                                                author(std::move(newauthor)),
                                                                                                prim(std::move(newprim)) {}
