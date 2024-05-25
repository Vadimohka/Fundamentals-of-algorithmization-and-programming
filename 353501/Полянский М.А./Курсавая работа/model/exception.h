#ifndef MODEL_EXCEPTION_H_
#define MODEL_EXCEPTION_H_

#include <exception>
#include <stdexcept>

namespace model {

class path_error : public std::domain_error {
   public:
    path_error(const std::string& what_arg);
    path_error(const char* what_arg = "An error occurred during path building");
};

class state_error : public std::runtime_error {
   public:
    state_error(const std::string& what_arg);
    state_error(const char* what_arg = "You can't do this operation in this state");
};

class turret_error : public std::runtime_error {
   public:
    turret_error(const std::string& what_arg);
    turret_error(const char* what_arg = "An error occured in a turret operation");
};

}  // namespace model

/*

*HOW 'TRY CATCH' WORKS:
try {
    throw new state_error("This is s state error");
} catch (std::Exception* e) {
    cout << e.What(); // contains the error string
}

*/

#endif
