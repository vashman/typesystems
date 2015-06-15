// typebuffer queue adapter

#ifndef TYPESYSTEMS_TYPEBUFFER_QUEUE_HPP
#define TYPESYSTEMS_TYPEBUFFER_QUEUE_HPP

#include <queue>
#include "typebuffer.hpp"

namespace typesystems {
/**/
template <
  typename T
, typename Container = std::deque<T>
>
class typebuffer_queue
  : public typebuffer<T> {
public:
  typedef T type;

  typedef typename typebuffer<T>
  ::value_type value_type;

  /* ctor */
  typebuffer_queue();

private:
  std::queue<T,Container> queue;
  
  virtual void
  do_push(value_type const &);
   
  virtual void
  do_push(value_type &&);
 
  virtual value_type &
  do_front();

  virtual value_type &
  do_back();

  virtual void
  do_pop(); 

  virtual bool
  do_empty() const;

  virtual void
  do_clear();
};

template <
  typename T
, typename Container
>
  typebuffer_queue<T,Container>
::typebuffer_queue(
){
}

/* do_push */
template <
  typename T
, typename Container
>
void
  typebuffer_queue<T,Container>
::do_push(
  value_type const & _value
){
this->queue.push(_value);
}

/* do_push move */
template <
  typename T
, typename Container
>
void
  typebuffer_queue<T,Container>
::do_push(
  value_type && _value
){
this->queue.push(_value);
}

/* do_front */
template <
  typename T
, typename Container
>
typename typebuffer_queue<T,Container>::
value_type &
  typebuffer_queue<T,Container>
::do_front(
){
return this->queue.front();
}

/* do_back */
template <
  typename T
, typename Container
>
typename typebuffer_queue<T,Container>
::value_type &
  typebuffer_queue<T,Container>
::do_back(
){
return this->queue.back();
}

/* do_empty */
template <
  typename T
, typename Container
>
bool
typebuffer_queue<T,Container>::do_empty(
) const {
return this->queue.empty();
}

/* do_clear */
template <
  typename T
, typename Container
>
void
typebuffer_queue<T,Container>::do_clear(
){
std::queue<T,Container> empty_queue;
std::swap(this->queue, empty_queue);
}

template <
  typename T
, typename Container
>
void
typebuffer_queue<T,Container>::do_pop(
){
this->queue.pop();
}

} /* typesystems */
#endif
