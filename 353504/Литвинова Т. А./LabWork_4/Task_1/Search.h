class VisVector;

class Search {
private:
  static int BinSearch(VisVector *arr, int el, int l, int r);

public:
  static int BinSearch(VisVector *arr, int el);
};