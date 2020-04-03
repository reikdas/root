#include "ROOTTestingSupport.h"

namespace {

      void ExpectedErrorRAII::pop() {
         std::string Seen = GetCapturedStderr();
         bool match = RE::FullMatch(Seen, RE(ExpectedRegex));
         EXPECT_TRUE(match);
         if (!match) {
            std::string msg = "Match failed!\nSeen: '" + Seen + "'\nRegex: '" + ExpectedRegex + "'\n";
            GTEST_NONFATAL_FAILURE_(msg.c_str());
         }
      }

      ExpectedErrorRAII::ExpectedErrorRAII(std::string E) : ExpectedRegex(E) { CaptureStderr(); }

      ExpectedErrorRAII::~ExpectedErrorRAII() { ExpectedErrorRAII::pop(); }
}
