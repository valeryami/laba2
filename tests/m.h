#ifndef M_H
#define M_H

#include "all_tests.h"

TEST(m, on_first_begin)
{
    std::string output_text = "|";

    text txt = create_text();
    
    append_line(txt, "Тестъ ");
    output_text += "Тестъ \n";
    append_line(txt, "Тестъ ");
    output_text += "Тестъ \n";
    append_line(txt, "Тестъ ");
    output_text += "Тестъ \n";

    testing::internal::CaptureStdout();

    m(txt, 0, 0);
    show(txt);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());

    free(txt);
}

TEST(m, on_first)
{
    std::string output_text = "";

    text txt = create_text();
    
    append_line(txt, "Тестъ ");
    output_text += "Тестъ |\n";
    append_line(txt, "Тестъ ");
    output_text += "Тестъ \n";
    append_line(txt, "Тестъ ");
    output_text += "Тестъ \n";
                
    testing::internal::CaptureStdout();

    m(txt, 0, 6);
    show(txt);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());

    free(txt);
}

TEST(m, on_center_begin)
{
    std::string output_text = "";

    text txt = create_text();
    
    append_line(txt, "Тестъ ");
    output_text += "Тестъ \n";
    append_line(txt, "Тестъ ");
    output_text += "|Тестъ \n";
    append_line(txt, "Тестъ ");
    output_text += "Тестъ \n";

    testing::internal::CaptureStdout();

    m(txt, 1, 0);
    show(txt);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());

    free(txt);
}

TEST(m, on_center)
{
    std::string output_text = "";

    text txt = create_text();
    
    append_line(txt, "Тестъ ");
    output_text += "Тестъ \n";
    append_line(txt, "Тестъ ");
    output_text += "Тес|тъ \n";
    append_line(txt, "Тестъ ");
    output_text += "Тестъ \n";
    
    testing::internal::CaptureStdout();

    m(txt, 1, 3);
    show(txt);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());

    free(txt);
}
                
TEST(m, out_of_str)
{
    std::string output_text = "";

    text txt = create_text();
    
    append_line(txt, "Тестъ ");
    output_text += "Тестъ \n";
    append_line(txt, "Тестъ ");
    output_text += "|Тестъ \n";
    append_line(txt, "Тестъ ");
    output_text += "Тестъ \n";

    testing::internal::CaptureStdout();

    m(txt, 2, 30);
    show(txt);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());

    free(txt);
}

TEST(m, minus_str)
{
    std::string output_text = "";

    text txt = create_text();
    
    append_line(txt, "Тестъ ");
    output_text += "Тестъ \n";
    append_line(txt, "Тестъ ");
    output_text += "|Тестъ \n";
    append_line(txt, "Тестъ ");
    output_text += "Тестъ \n";

    testing::internal::CaptureStdout();

    m(txt, -10, 10);
    show(txt);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());

    free(txt);
}

TEST(m, more_str)
{
    std::string output_text = "";

    text txt = create_text();
    
    append_line(txt, "Тестъ ");
    output_text += "Тестъ \n";
    append_line(txt, "Тестъ ");
    output_text += "|Тестъ \n";
    append_line(txt, "Тестъ ");
    output_text += "Тестъ \n";

    testing::internal::CaptureStdout();

    m(txt, 5, 10);
    show(txt);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());

    free(txt);
}

TEST(m, minus_pos)
{
    std::string output_text = "";

    text txt = create_text();
    
    append_line(txt, "Тестъ ");
    output_text += "Тестъ \n";
    append_line(txt, "Тестъ ");
    output_text += "|Тестъ \n";
    append_line(txt, "Тестъ ");
    output_text += "Тестъ \n";

    testing::internal::CaptureStdout();

    m(txt, 0, -10);
    show(txt);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());

    free(txt);
}

TEST(m, empty_str)
{
    std::string output_text = "";

    text txt = create_text();
    append_line(txt, "");
    output_text += "\n";
    append_line(txt, "");
    output_text += "|\n";
    append_line(txt, "");
    output_text += "\n";

    testing::internal::CaptureStdout();

    m(txt, 1, 10);
    show(txt);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());

    free(txt);
}

TEST(m, one_str)
{
    std::string output_text = "|\n";
    text txt = create_text();
    append_line(txt, "");

    testing::internal::CaptureStdout();

    m(txt, 0, 0);
    show(txt);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());

    free(txt);
}

TEST(m, nothing)
{
    std::string output_text = "";
    text txt = create_text();

    testing::internal::CaptureStdout();

    m(txt, 3, 0);
    show(txt);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());

    free(txt);
}

#endif // M_H
