#include "external/external.hpp"
#include <iostream>


namespace ext
{
  double foo(int x)
  {
    std::cout << "ext::foo() from original lib called\n";
    return 10.99;
  }

  int goo(double x)
  {
    std::cout << "ext::foo() from original lib called\n";
    return 9;
  }

}
