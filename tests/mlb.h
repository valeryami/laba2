#ifndef MLB_H
#define MLB_H

#include "all_tests.h"

TEST(mlb, on_first_begin)
{
    std::string output_text = "|";

    text txt = create_text();
    
    append_line(txt, "milka");
    output_text += "milka\n";
    append_line(txt, "milka");
    output_text += "milka\n";
    append_line(txt, "milka");
    output_text += "milka\n";
    
    testing::internal::CaptureStdout();

    m(txt, 0, 0);
    mlb(txt);
    show(txt);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());
}

TEST(mlb, on_first)
{
    std::string output_text = "|";

    
    
    text txt = create_text();
    
    append_line(txt, "milka and poilka");
    output_text += "milka and poilka\n";
    append_line(txt, "milka and poilka");
    output_text += "milka and poilka\n";
    append_line(txt, "milka and poilka");
    output_text += "milka and poilka\n";
    
    testing::internal::CaptureStdout();

    m(txt, 0, 5);
    mlb(txt);
    show(txt);
    std::string text = testing::internal::GeCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());
}

TEST(mlb, on_center)
{
    std::string output_text = "";

    text txt = create_text();
    
    append_line(txt, "milka and poilka");
    output_text += "milka and poilka\n";
    append_line(txt, "milka and poilka");
    output_text += "milka and poilka\n";
    append_line(txt, "milka and poilka");
    output_text += "|milka and poilka\n";

    testing::internal::CaptureStdout();

    m(txt, 2, 0);
    mlb(txt);
    show(txt);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());
}


TEST(mlb, on_center)
{
    std::string output_text = "";

    
    text txt = create_text();
    
    append_line(txt, "milka and poilka");
    output_text += "milka and poilka\n";
    append_line(txt, "milka and poilka");
    output_text += "milka and poilka\n";
    append_line(txt, "milka and poilka");
    output_text += "milka and poilka\n";
    append_line(txt, "milka and poilka");
    output_text += "milka and poilka\n";
    append_line(txt, "milka and poilka");
    output_text += "|milka and poilka\n";
    append_line(txt, "milka and poilka");
    output_text += "milka and poilka\n";
   
    testing::internal::CaptureStdout();

    m(txt, 4, 8);
    mlb(txt);
    show(txt);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());
}
#endif // MLB_H
