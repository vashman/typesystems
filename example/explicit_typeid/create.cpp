#include "../../include/explicit_typeid.hpp"

using typesystems::explicit_typeid;
using typesystems::explicit_typeid_type;

int main(){
explicit_typeid_type id = explicit_typeid<float>::raw_typeid();

return 0;
}
