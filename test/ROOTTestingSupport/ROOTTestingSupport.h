#ifndef ROOT_TESTINGSUPPORT_H
#define ROOT_TESTINGSUPPORT_H

#include "gtest/gtest.h"
#include "gmock/gmock.h"

namespace {
using testing::internal::GetCapturedStderr;
using testing::internal::CaptureStderr;
using testing::internal::RE;
class ExpectedErrorRAII {
   std::string ExpectedRegex;
   void pop();

public:
   ExpectedErrorRAII(std::string E);
   ~ExpectedErrorRAII();
};
}

#define EXPECT_ROOT_ERROR(expression, expected_error) \
   {                                                  \
      ExpectedErrorRAII EE(expected_error);           \
      expression;                                     \
   }

#endif // ROOT_TESTINGSUPPORT_H
