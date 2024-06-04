#ifndef D7AC22BD_6478_4D1E_AF97_CE416BDB720D
#define D7AC22BD_6478_4D1E_AF97_CE416BDB720D
#include <string>

struct Footwear {



public:
  std::string name;
  double eu_size;
  char gender = 'U';
  bool is_child = false;




  static constexpr char INIT_DELIM = '|'; 

  static constexpr char TYPES[] = {'M', 'F', 'U'};

  static constexpr double SIZES[] = {32, 33,   34, 34.5, 35, 36,   36.5, 37,   37.5,
                           38, 38.5, 39, 40, 41, 42,   43,   43.5, 44,
                           45, 45.5, 46, 46.5, 47, 47.5, 48};

public:
    Footwear() = default;
    Footwear(std::string init);
    std::string to_string();
};

#endif /* D7AC22BD_6478_4D1E_AF97_CE416BDB720D */
