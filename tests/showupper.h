#ifndef SHOWUPPER_H
#define SHOWUPPER_H

#include "all_tests.h"

using namespace std;

TEST(showupper, lower_ints)
{
    std::string output_text = "";
    text txt = create_text();
    for (int i = 0; i < 10; i++) {
        append_line(txt, "showupper " + to_string(i));
        output_text += "SHOWUPPER " + to_string(i) + "\n";
    }

    testing::internal::CaptureStdout();

    showupper(txt);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());
}

TEST(showupper, numbers)
{
    std::string output_text = "";
    text txt = create_text();
    for (int i = 0; i < 10; i++) {
        append_line(txt, " " + std::to_string(i));
        output += " " + std::to_string(i) + "\n";
    }

    testing::internal::CaptureStdout();

    showupper(txt);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());
}

TEST(showupper, zero)
{
    std::string output_text = "";
    text txt = create_text();

    testing::internal::CaptureStdout();

    showupper(txt);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());
}



#endif // SHOWUPPER_H
