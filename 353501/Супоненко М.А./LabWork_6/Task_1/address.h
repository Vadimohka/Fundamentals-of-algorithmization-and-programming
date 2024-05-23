#ifndef D7AC22BD_6478_4D1E_AF97_CE416BDB720D
#define D7AC22BD_6478_4D1E_AF97_CE416BDB720D
#include <string>

struct Address {



public:
  std::string name;
  double address;
  char vOrC = 'v';
  bool wasOrNot = false;




  static constexpr char INIT_DELIM = '|'; 

  static constexpr char WAS[] = {'c', 'v'};

  static constexpr double HOUSE[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50};

public:
    Address() = default;
    Address(std::string init);
    std::string to_string();
};

#endif /* D7AC22BD_6478_4D1E_AF97_CE416BDB720D */
