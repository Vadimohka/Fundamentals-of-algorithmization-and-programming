#ifndef CDBD0DF3_AB66_4C7A_9079_82E73E96EB68
#define CDBD0DF3_AB66_4C7A_9079_82E73E96EB68

#include "coretypes.h"
#include <QFormLayout>
#include <QPushButton>
#include <QWidget>
#include <qobject.h>
#include <qtmetamacros.h>
#include <QThreadPool>



#define CHECK_STOP if(stopRequest){return;}
struct EffectInfo{
    int begin;
    int end;
    QString name;
};

class BaseEffect : public QObject{

    Q_OBJECT  

protected:
    QWidget* gui = nullptr;
    QFormLayout* layout = nullptr;
    QPushButton *applyBtn = nullptr, *revertBtn = nullptr, *saveBtn = nullptr;

    bool stopRequest = false;
    bool finished = true; 

    public: ~BaseEffect();

protected:
    virtual void _process(Sample* buf, int size, int max_in, short channel) = 0;
    virtual void updateProperties() = 0;
    virtual void reset();

protected slots:
    virtual void apply(); 

public:
    virtual void setUpUi(QWidget*);

    void requestStop();
    bool hasStopped();

signals:
    void modifiedBuffer(int, int, QString);


};

#endif /* CDBD0DF3_AB66_4C7A_9079_82E73E96EB68 */
