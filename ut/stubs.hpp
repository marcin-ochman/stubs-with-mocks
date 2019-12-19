#ifndef STUBS_HPP_
#define STUBS_HPP_

#include <gtest/gtest.h>
#include <gmock/gmock.h>

namespace stubs
{

class ExternalMock
{
public:
  MOCK_METHOD1(foo, void(int));
  MOCK_METHOD1(goo, void(double));
};


ExternalMock* getMock();
void freeMock();

}

#endif /* STUBS_HPP_ */
