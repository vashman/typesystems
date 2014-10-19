//

#include "../../include/put_rewriter.hpp"
#include "../../include/get_rewriter.hpp"

using typesystems::put_rewriter;
using typesystems::get_rewriter;

int main(){
put_rewriter<person> * rwp = new person_rw_put(1);
get_rewriter<person> * rwg = new person_rw_get(1);
return 0;
}
