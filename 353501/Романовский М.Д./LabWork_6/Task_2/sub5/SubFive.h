
#include <qtconfigmacros.h>
#include <qtmetamacros.h>
#include <qwidget.h>


QT_BEGIN_NAMESPACE
namespace Ui {
class SubFive;
}
QT_END_NAMESPACE


class SubFive : public QWidget {
  Q_OBJECT
public:
  SubFive(QWidget *parent = nullptr);
  ~SubFive();

private slots:
  void onSave();
  void onOpen();

protected:
  Ui::SubFive *ui;
};
