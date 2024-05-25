#include "model/exception.h"

namespace model {

path_error::path_error(const std::string& what_arg) : domain_error(what_arg) {}
path_error::path_error(const char* what_arg) : domain_error(what_arg) {}

state_error::state_error(const std::string& what_arg) : runtime_error(what_arg) {}
state_error::state_error(const char* what_arg) : runtime_error(what_arg) {}

turret_error::turret_error(const std::string& what_arg) : runtime_error(what_arg) {}
turret_error::turret_error(const char* what_arg) : runtime_error(what_arg) {}

}  // namespace model
