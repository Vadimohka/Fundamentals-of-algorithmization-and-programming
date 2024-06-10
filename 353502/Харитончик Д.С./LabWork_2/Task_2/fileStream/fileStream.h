#pragma once
#include "../applicants/applicant.h"
#include <QtWidgets>

class FileStream {
public:
    static bool LoadFromFile(const QString &fileName, QList<Applicant> &applicants);
    static bool SaveToFile(const QString &fileName, const QList<Applicant> &applicants);
};
