//

//          Copyright Sundeep S. Sangha 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <string>
#include "../../include/iwriter.hpp"
#include "../../include/owriter.hpp"
#include "person.hpp"

/* writer for the person class */
class person_writer
  : public typesystems::iwriter<person>
  , public typesystems::owriter<person>{
public:
  typedef iwriter<person>::type type;

  typedef iwriter<person>::value_type
  value_type;

  person_writer();

private:
  virtual void
  do_put(
    value_type const & _value
  , typesystems::typebuffer_container
    const & _buffer
  , typesystems::owriter_container
    const & _writer
  ) const;

  virtual void
  do_get(
    value_type & _value
  , typesystems::typebuffer_container
    const & _buffer
  , typesystems::iwriter_container
    const & _writer
  ) const;

  virtual bool
  do_empty(
    typesystems::typebuffer_container
    const & _buffer
  , typesystems::iwriter_container
    const & _writer
  ) const;
};

/* ctor */
person_writer::person_writer()
: typesystems::iwriter<person>()
, typesystems::owriter<person>() {
}

/* do_write */
void
person_writer::do_put(
  value_type const & _value
,   typesystems
  ::typebuffer_container const & _buffer
,   typesystems
  ::owriter_container const & _writer
) const {
typesystems::rewrite(
  _value.get_age()
, _buffer
, _writer
);
typesystems::rewrite(
  _value.name
, _buffer
, _writer
);
}

/* do_write */
void
person_writer::do_get(
  value_type & _value
,   typesystems
  ::typebuffer_container const & _buffer
,   typesystems
  ::iwriter_container const & _writer
) const {
std::string str;
int i;
  typesystems
::rewrite(str, _buffer, _writer);
  typesystems
::rewrite(i, _buffer, _writer);
_value = person(i, str);
}

bool
person_writer::do_empty(
   typesystems
  ::typebuffer_container const & _buffer
,  typesystems
  ::iwriter_container const & _writer
) const {
return (
    typesystems
  ::empty<std::string>(_buffer, _writer)
&&
    typesystems
  ::empty<int>(_buffer, _writer)
);
}
