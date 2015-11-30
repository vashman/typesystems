#include "../include/type_traits.hpp"

using typesystems::has_type;

static_assert(has_type<int,int,int,int>::value,"Does not have int.");
static_assert(!has_type<int,float,double,double>::value,"Has an int.");

int main () {
return 0;
}
