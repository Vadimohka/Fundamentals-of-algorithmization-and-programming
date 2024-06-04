#include <QVector>

const int MIN_HEIGHT = 16;
const int MAX_HEIGHT = 512;

class QGraphicsScene;
class QTableWidget;

enum ActionType {
  Read, 
  Write,
  Swap,
  Find
};

struct Action {
  ActionType type;
  int index;
  int value;
};

struct Stats {
  int reads;
  int writes;
  int swaps;
};

class VisVector {
public:
  VisVector(int size);

  void Draw(QGraphicsScene *scene);
  void FillTable(QTableWidget *table);

  int Read(int i);
  void Write(int i, int el);
  void Swap(int l, int r);
  int Size();

  void ReportFind(int index, int el = 0);

  Stats CollectStats();

  void SetCurrentAction(int action_i);
  void Reset();
  void ClearSearch();

private:
  

  int size;
  QVector<int> ini;
  QVector<int> cur;

  int currentAction = 0;
  QVector<Action> actions;
};