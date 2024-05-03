#ifndef C896FCDA_75B2_401E_AFA3_A87440B832C8
#define C896FCDA_75B2_401E_AFA3_A87440B832C8


#include "Common.h"
#include "TTKeyDict.h"
#include "TTTextEdit.h"
#include <QMainWindow>
#include <QScopedPointer>
#include <QTimer>
#include <qgraphicsscene.h>

using namespace Common;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

  public:
    const int STATS_UPDATE_FREQ = 1'000;
    const int STATS_UPDATE_CALLS_BEFORE_FREEZE = 4;

  MainWindow();

  TTKeyDict keyDict;
  QString vstring;
  const int fontSzPx = 19;
  QFont inpFont = QFont("Monospace");

  QScopedPointer<QTimer> statsUpdater;

  long lastTotalSymbols = -1;
  long updateStatsCallsWithNoChange = 0;

void removeMultipleSpaces(QString& s);
void defaultTrainingRoutine(Locale loc);
void customTrainingRoutine();

private slots:
  void handleInput(InputState);
  void updateStats();
  void provideValidString();
  void onTrainingCompleted();
  void highlightChar(QChar);
  void onInputBlocked();

  void on_defTrainingBtn_clicked();
  void on_customTrainingBtn_clicked();



protected:
  Ui::MainWindow *ui;
};


#endif /* C896FCDA_75B2_401E_AFA3_A87440B832C8 */
