#include "address.h"
#include <iomanip>
#include <sstream>
#include <stdexcept>
#include <string>
#include <algorithm>
#include <iostream>


Address::Address(std::string init) {
    using std::istringstream;
    istringstream ss (init);
    std::string tmp;

    std::getline(ss, name, INIT_DELIM);
    
    std::getline(ss, tmp, INIT_DELIM);
    vOrC = std::stod(tmp); //should be catched
    if(std::find( std::begin(HOUSE), std::end(HOUSE), vOrC) == std::end(HOUSE)){
        throw std::invalid_argument("Invalid house");
    }
    

    std::getline(ss, tmp, INIT_DELIM);
    if(tmp.size() != 3 || tmp[0] != ' ' || tmp[2] != ' ' ||
        std::find(std::begin(WAS), std::end(WAS), tmp[1]) == std::end(WAS)){
        throw std::invalid_argument("Wrong village or city");
    }
    vOrC = tmp[1];


    std::getline(ss, tmp, INIT_DELIM );
    if(tmp != " true" && tmp     != " false" && tmp != " +" && tmp != " -" && tmp != " 0" && tmp != " 1")
    {
        throw std::invalid_argument("Wrong was or not Value : " + tmp);
    }
    wasOrNot = (tmp == " true" || tmp == " 1" || tmp == " +" );

    if(!ss){
        throw std::invalid_argument("Bad initial string");
    }
}

std::string Address::to_string() {

using std::ostringstream;

    ostringstream os{ };
     

     os << name;
     os << " | ";
     os << std::setprecision(5) << vOrC;
    os << " | ";
     os << vOrC;
     os << " | ";
    os << (wasOrNot ? '+' : '-');

    return os.str();
}
