#include <tuple>
#include "../include/typelist.hpp"
#include "../include/type_traits.hpp"

using typesystems::typelist;
using typesystems::make_typelist;
using typesystems::use_typelist;
using typesystems::has_type;

struct type_with_list {
  typedef typelist<int,float> type;
};

struct type_with_no_list {
  typedef int type;
};

// Use typelist and typedef ////////////
/* check plain types */
static_assert (
  use_typelist<has_type, int, int, int>::value
, "1: Ts... As <int,int> does not have int!"
);

/* check typedef */
static_assert (
  use_typelist<has_type, int, type_with_no_list::type, float>::value
, "2: struct::type As int, int, int does not have int!"
);

/* check typelist with extra types */
static_assert (
  use_typelist<has_type, int, make_typelist<type_with_no_list::type>, float>::value
, "3: typelist<struct::type As int>, int does not have int!"
);

/* check typelist with no end extra types */
static_assert (
  use_typelist<has_type, int, make_typelist<type_with_no_list::type>>::value
, "4: typelist<struct::type As int> does not have int!"
);

/* check typelist with no start types */
static_assert (
  use_typelist<has_type, make_typelist<type_with_no_list::type>, int, int>::value
, "5: Ts... As int, int does not have typelist<struct::type As int>!"
);

// typelist ////////////////////////////
/* check plain types */
static_assert (
  use_typelist<has_type, typelist<int,int,int>>::value
, "6: typelist As <int,int,int> does not have int!"
);

/* check typedef */
static_assert (
  use_typelist<has_type, int, typelist<type_with_no_list::type, int, float>>::value
, "7: typelist <struct::type As int>, int, int does not have int!"
);

// tuple to typelist ///////////////////
/* check typedef */
static_assert (
  use_typelist<has_type, int, type_with_list::type, int, float>::value
, "8: struct::type As tuple<int,float>,int,float does not have int!"
);

/* check typelist with extra types */
static_assert (
  use_typelist<has_type, int, get_typelist<type_with_list::type>, int, float>::value
, "9: typelist<struct::type As tuple<int,float>>,int,float does not have int!"
);

/* check typelist with no end extra types */
static_assert (
  use_typelist<has_type, int, make_typelist<type_with_list::type>>::value
, "10: typelist<struct::type As tuple<int,float>> does not have int!"
);

/* check typelist with no start types */
static_assert (
  use_typelist<has_type, make_typelist<type_with_list::type>, int, int>::value
, "11: int,int does not have typelist<struct::type As tuple <int,float>>!"
);

int main () {
return 0;
}
