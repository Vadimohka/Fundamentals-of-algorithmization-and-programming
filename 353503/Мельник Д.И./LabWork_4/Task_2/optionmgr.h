#pragma once

#include <QComboBox>

class OptionMgr : public QObject {
    Q_OBJECT
public:
    explicit OptionMgr (QComboBox *) ;
    bool run () ;
    void end () ;
public slots:
    void updateOptions (int) ;
private:
    QComboBox * m_menu ;
};
