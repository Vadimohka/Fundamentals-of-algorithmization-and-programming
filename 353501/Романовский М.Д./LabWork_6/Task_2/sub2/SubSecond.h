
#include <qtconfigmacros.h>
#include <qtmetamacros.h>
#include <qwidget.h>


QT_BEGIN_NAMESPACE
namespace Ui {
class SubSecond;
}
QT_END_NAMESPACE


class SubSecond : public QWidget {
  Q_OBJECT
public:
  SubSecond(QWidget *parent = nullptr);
  ~SubSecond();

protected:
  void resizeTable(int targetCount);

private slots:
  void onSave();
  void onOpen();
  void onNewCount();

protected:
  Ui::SubSecond *ui;
};
