
#include <qtconfigmacros.h>
#include <qtmetamacros.h>
#include <qwidget.h>


QT_BEGIN_NAMESPACE
namespace Ui {
class SubFirst;
}
QT_END_NAMESPACE


class SubFirst : public QWidget {
  Q_OBJECT
public:
  SubFirst(QWidget *parent = nullptr);
  ~SubFirst();

private slots:
  void onSave();
  void onOpen();

protected:
  Ui::SubFirst *ui;
};
