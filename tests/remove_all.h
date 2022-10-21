#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <string>

#include "common.h"
#include "text.h"
#include "_text.h"

using namespace std;

TEST(delite, positive)
{
  
    std::string output_text = "The text doesn't exist!\n";

    testing::internal::CaptureStdout();

    string txt;
    remove_all(txt)
    
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());
}
