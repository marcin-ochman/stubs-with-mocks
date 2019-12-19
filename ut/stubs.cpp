#include <mutex>
#include "external/external.hpp"
#include "stubs.hpp"

namespace stubs {

  std::mutex mockMutex;
  std::unique_ptr<ExternalMock> externalMock;
  ExternalMock* getMock()
  {
    mockMutex.lock();

    externalMock.reset(new ExternalMock);

    return externalMock.get();
  }


  void freeMock()
  {
    externalMock.reset();
    mockMutex.unlock();
  }
}


namespace ext
{
  double foo(int x)
  {
    stubs::externalMock->foo(x);
    return 10.99;
  }

  int goo(double x)
  {
    stubs::externalMock->goo(x);
    return 9;
  }
}
