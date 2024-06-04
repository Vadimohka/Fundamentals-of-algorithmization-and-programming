#ifndef AB9DEBC9_DC45_4F08_B8FD_C368D0B22FB2
#define AB9DEBC9_DC45_4F08_B8FD_C368D0B22FB2

#include <QtCharts>
#include <qchartview.h>

class PlotBuilder {
private:
  static QVector<unsigned long long> generateRandomKeys(size_t sz);

public:
  static const size_t HASH_TEST_SZ = 256;
  static void hashComparisonPlot(QChartView *view, size_t ht_size);
  static void speedComparisonPlot(QChartView *view, size_t ht_size);
  //void searchSpeedPlot(QChartView *view);
};

#endif /* AB9DEBC9_DC45_4F08_B8FD_C368D0B22FB2 */
