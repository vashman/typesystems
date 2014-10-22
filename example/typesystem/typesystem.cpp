//

//          Copyright Sundeep S. Sangha 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <iostream>
#include <vector>
#include <deque>
#include "../../src/typesystem.cpp"
#include "../../src/typebuffer_map.cpp"
#include "../../src/total_typeid.cpp"
#include "../../src/rewriter_base.cpp"
#include "../../src/typebuffer.cpp"

using std::cout;
using std::endl;
using std::vector;
using std::deque;
using typesystems::typesystem;
using typesystems::set_typebuffer;
using typesystems::has_put_rewriter;
using typesystems::has_get_rewriter;

int main(){
typesystem ts;

// push buffer
set_typebuffer<int, vector<int> >(ts);
set_typebuffer<double, deque<double> >(ts);
set_typebuffer<char, vector<char> >(ts);

// send int to typesystem buffers
int value = 200;
float fvalue = 2.25;
int result = 0;

  if (has_put_rewriter<int>(ts)){
    if (ts.put_rewrite(value)){
      if (has_get_rewriter<int>(ts)){
      ts.get_rewrite(result);
      cout << "value written was: " << result << endl;
      }
    } else {
    cout << "error occured writing" << endl;
    }
  }
return 0;
}
