//

#ifndef TYPESYSTEMS_TYPEBUFFER_ADAPTER_TCC
#define TYPESYSTEMS_TYPEBUFFER_ADAPTER_TCC

namespace typesystems {
/* ctor */
template <typename T, typename Sequence>
  typebuffer_adapter<T,Sequence>
::typebuffer_adapter(
  Sequence const & _cntr
)
: typebuffer<T> ()
, c (_cntr){
}

/* copy ctor */
template <typename T, typename Sequence>
  typebuffer_adapter<T,Sequence>
::typebuffer_adapter(
  typebuffer_adapter<T,Sequence> const &
  _buff
)
: typebuffer<T> (_buff)
, c (_buff.c){
}

/* copy operator */
template <typename T, typename Sequence>
typebuffer_adapter<T,Sequence> &
  typebuffer_adapter<T,Sequence>
::operator=(
  typebuffer_adapter<T,Sequence> const &
  _buff
){
  if (this != &_buff){
  this->c = _buff.c;
  }
return *this;
}

#if __cplusplus >= 201103L
/* move ctor */
template <typename T, typename Sequence>
  typebuffer_adapter<T,Sequence>
::typebuffer_adapter(
  typebuffer_adapter<T,Sequence> &&
  _buff
)
: typebuffer<T> (_buff)
, c (_buff.c){
}

/* move operator */
template <typename T, typename Sequence>
typebuffer_adapter<T,Sequence> &
  typebuffer_adapter<T,Sequence>
::operator=(
  typebuffer_adapter<T,Sequence> &&
  _buff
){
this->c = _buff.c;
return *this;
}
#endif

/* dtor */
template <typename T, typename Sequence>
  typebuffer_adapter<T,Sequence>
::~typebuffer_adapter(
){
}

/* get_container */
template <typename T, typename Sequence>
Sequence &
  typebuffer_adapter<T,Sequence>
::get_container(
){
return this->c;
}

/* do_clear */
template <typename T, typename Sequence>
void
  typebuffer_adapter<T,Sequence>
::do_clear(
){
this->c.clear();
}

/* do_empty */
template <typename T, typename Sequence>
bool
  typebuffer_adapter<T,Sequence>
::do_empty(
) const {
return this->c.empty();
}

/* do_push copy */
template <typename T, typename Sequence>
void
typebuffer_adapter<T,Sequence>::do_push(
  typename typebuffer<T>
  ::value_type const & _var
){
this->c.push_back(_var);
}

#if __cplusplus >= 201103L
/* do_push move */
template <typename T, typename Sequence>
void
typebuffer_adapter<T,Sequence>::do_push(
  typename typebuffer<T>::value_type &&
  _var
){
this->c.push_back(_var);
}
#endif

/* do_pop */
template <typename T, typename Sequence>
void
typebuffer_adapter<T,Sequence>::do_pop(
){
this->c.erase(this->c.begin());
}

/* do_front */
template <typename T, typename Sequence>
typename typebuffer<T>::value_type &
  typebuffer_adapter<T,Sequence>
::do_front(
){
return this->c.front();
}

/* do_back */
template <typename T, typename Sequence>
typename typebuffer<T>::value_type &
  typebuffer_adapter<T,Sequence>
::do_back(
){
return this->c.back();
}

} /* typesystems */
#endif
