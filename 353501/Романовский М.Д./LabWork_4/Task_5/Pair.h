
template <typename F, typename S> class Pair {
public:
  Pair(F f, S s) : first(f), second(s){};

  F first;
  S second;
};