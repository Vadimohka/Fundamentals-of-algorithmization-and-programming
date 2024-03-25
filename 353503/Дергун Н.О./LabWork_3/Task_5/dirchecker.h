#ifndef DIRCHECKER_H
#define DIRCHECKER_H

#include <QDesktopServices>
#include <QDir>
#include <QObject>

class DirChecker : public QObject
{
    Q_OBJECT

    const int TAB_SIZE = 10;

    QVector<QFileInfo> fileVector_;
    QString path_;
    QString dirPlan_;
    int fileCnt_ = 0;
    int dirCnt_ = 0;

    void _checkFolder(QString path, int& dirCnt, int& fileCnt, int nesting);

public:
    DirChecker() = default;
    explicit DirChecker(QString path);

    int fileCnt() const;
    int dirCnt() const;
    QString directory() const;
    QString dirPlan() const;

public slots:
    void changeDirectory(QString path);
};

#endif // DIRCHECKER_H
