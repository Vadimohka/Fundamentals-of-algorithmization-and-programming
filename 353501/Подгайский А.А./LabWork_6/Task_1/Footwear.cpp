#include "Footwear.h"
#include <iomanip>
#include <sstream>
#include <stdexcept>
#include <string>
#include <algorithm>
#include <iostream>


Footwear::Footwear(std::string init) {
    using std::istringstream;
    istringstream ss (init);
    std::string tmp;

    std::getline(ss, name, INIT_DELIM);
    
    std::getline(ss, tmp, INIT_DELIM);
    eu_size = std::stod(tmp); //should be catched
    if(std::find( std::begin(SIZES), std::end(SIZES), eu_size) == std::end(SIZES)){
        throw std::invalid_argument("Invalid size");
    }
    

    std::getline(ss, tmp, INIT_DELIM);
    if(tmp.size() != 3 || tmp[0] != ' ' || tmp[2] != ' ' ||
        std::find(std::begin(TYPES), std::end(TYPES), tmp[1]) == std::end(TYPES)){
        throw std::invalid_argument("Wrong gender");
    }
    gender = tmp[1];


    std::getline(ss, tmp, INIT_DELIM );
    if(tmp != " true" && tmp     != " false" && tmp != " +" && tmp != " -" && tmp != " 0" && tmp != " 1")
    {
        throw std::invalid_argument("Wrong Is Child Value : " + tmp);
    }
    is_child = (tmp == " true" || tmp == " 1" || tmp == " +" );

    if(!ss){
        throw std::invalid_argument("Bad initial string");
    }
}

std::string Footwear::to_string() {

using std::ostringstream;

    ostringstream os{ };
     

     os << name;
     os << " | ";
     os << std::setprecision(5) << eu_size;
    os << " | ";
     os << gender;
     os << " | ";
    os << (is_child ? '+' : '-');

    return os.str();
}
