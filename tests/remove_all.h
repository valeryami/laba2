#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <string>

#include "all_tests.h"

using namespace std;

TEST(delite, positive)
{
  
    std::string output_text = "The text doesn't exist!\n";

    testing::internal::CaptureStdout();

    remove_all(NULL);
    
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());
}
