#include <QMainWindow>
#include <qcontainerfwd.h>
#include <qgraphicsscene.h>
#include <qdir.h>
#include <QTreeWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();

private:
    QFont fileFont;

private slots:
   // void openFolder();
    QPair<long, long> setTree(const QString &folderPath, QTreeWidgetItem *parentItem);

    void on_openFileButton_clicked();

protected:
    Ui::MainWindow *ui;
};
