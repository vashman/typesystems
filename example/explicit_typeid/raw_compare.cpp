#include <iostream>
#include "../../include/explicit_typeid.hpp"

using typesystems::explicit_typeid;
using typesystems::explicit_typeid_type;

int main(){

/* get raw id */
explicit_typeid_type raw_id = explicit_typeid<int>::raw_typeid();

/* compare raw id to type */
explicit_typeid<char>::raw_compare(raw_id);

return 0;
}
