#include <gtest/gtest.h>
#include "stubs.hpp"
#include "internal/internal.hpp"
#include <gmock/gmock.h>

using testing::DoubleEq;

class InternalFixture: public testing::Test {};


TEST_F(InternalFixture, fooTest)
{
  stubs::ExternalMock* mock = stubs::getMock(); // RAII is better

  EXPECT_CALL(*mock, foo(1)).Times(1);
  EXPECT_CALL(*mock, goo(DoubleEq(10.03))).Times(1);

  internal::bar();

  stubs::freeMock();
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
