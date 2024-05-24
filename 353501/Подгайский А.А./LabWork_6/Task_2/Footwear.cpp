#include "Footwear.h"
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

Footwear::Footwear(std::string init) {
  using std::istringstream;
  istringstream ss(init);
  std::string tmp;

  std::getline(ss, tmp, INIT_DELIM);
  if (tmp.size() > NAME_LENGTH - 1) {
    throw std::invalid_argument("Name is too big");
    return;
  }

  for (int i = 0; i < tmp.size(); ++i) {
    name[i] = tmp[i];
  }
  for (int i = tmp.size(); i < NAME_LENGTH; ++i) {
    name[i] = 0;
  }

  std::getline(ss, tmp, INIT_DELIM);
  eu_size = std::stod(tmp); // should be catched
  if (std::find(std::begin(SIZES), std::end(SIZES), eu_size) ==
      std::end(SIZES)) {
    throw std::invalid_argument("Invalid size");
  }

  std::getline(ss, tmp, INIT_DELIM);
  if (tmp.size() != 3 || tmp[0] != ' ' || tmp[2] != ' ' ||
      std::find(std::begin(TYPES), std::end(TYPES), tmp[1]) ==
          std::end(TYPES)) {
    throw std::invalid_argument("Wrong gender");
  }
  gender = tmp[1];

  std::getline(ss, tmp, INIT_DELIM);
  if (tmp != " true" && tmp != " false" && tmp != " +" && tmp != " -" &&
      tmp != " 0" && tmp != " 1") {
    throw std::invalid_argument("Wrong Is Child Value : " + tmp);
  }
  is_child = (tmp == " true" || tmp == " 1" || tmp == " +");

  if (!ss) {
    throw std::invalid_argument("Bad initial string");
  }
}

std::string Footwear::to_string(char delim) {

  using std::ostringstream;

  ostringstream os{};

  os << &name[0];
  os << ' ' << delim << ' ';
  os << std::setprecision(5) << eu_size;
  os << ' ' << delim << ' ';
  os << gender;
  os << ' ' << delim << ' ';
  os << (is_child ? '+' : '-');

  return os.str();
}
