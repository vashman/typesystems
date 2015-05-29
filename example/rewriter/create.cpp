//

//          Copyright Sundeep S. Sangha 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include "../../include/put_rewriter.hpp"
#include "../../include/get_rewriter.hpp"
#include "rwperson.hpp"

using typesystems::put_rewriter;
using typesystems::get_rewriter;

int main(){
put_rewriter<person> *
rwp = new person_rw_put(1);

get_rewriter<person> *
rwg = new person_rw_get(1);
return 0;
}
