#include <QApplication>
#include <QLabel>
#include <QLineEdit>
#include <QMainWindow>
#include <QPushButton>
#include <QTextEdit>
#include <QTime>
#include <QVBoxLayout>
#include <algorithm>
#include <vector>

QT_BEGIN_NAMESPACE

namespace Ui {
class MainWindow;
}

QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit MainWindow(QWidget* parent = nullptr);
  ~MainWindow() override;

 private slots:
  void sortArray();
  void searchNumber();
  void Heap();
  void Quick();
  void Merge();
  void heapify(int* arr, int n, int i);
  void quickSort(int* arr, int low, int high);
  int partition(int* arr, int low, int high);
  void mergeSort(int* array, int const begin, int const end);
  void merge(int* array, int const left, int const mid, int const right);

 private:
  Ui::MainWindow* ui;
  int quickSteps = 0;
  int heapSteps = 0;
  int mergeSteps = 0;
  //QLineEdit* arrayEdit;
  // QLineEdit* numberEdit;
  //QLabel* outputLabel;
};
