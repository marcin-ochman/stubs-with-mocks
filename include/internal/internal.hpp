#ifndef INTERNAL_HPP_
#define INTERNAL_HPP_

#include "external/external.hpp"

namespace internal
{
  inline double bar() { return ext::foo(1) + ext::goo(10.03);}
}

#endif /* INTERNAL_HPP_ */
