#ifndef M_H
#define M_H

#include "all_tests.h"

TEST(m, on_first_begin)
{
    std::string output_text = "|";

    text txt = create_text();
    for (int i = 0; i < 10; i++) {
        append_line(txt, "m test " + std::to_string(i));
        output_text += "m test " + std::to_string(i) + "\n";
    }

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
    for (int i = 0; i < 10; i++) {
        append_line(txt, "m test " + std::to_string(i));

        if (i == 0) {
            output_text += "m test| " + std::to_string(i) + "\n";
        } else {
            output_text += "m test " + std::to_string(i) + "\n";
        }
    }

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
    for (int i = 0; i < 10; i++) {
        append_line(txt, "m test " + std::to_string(i));

        if (i == 5) {
            output_text += "|m test " + std::to_string(i) + "\n";
        } else {
            output_text += "m test " + std::to_string(i) + "\n";
        }
    }

    testing::internal::CaptureStdout();

    m(txt, 5, 0);
    show(txt);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());

    free(txt);
}

TEST(m, on_center)
{
    std::string output_text = "";

    text txt = create_text();
    for (int i = 0; i < 10; i++) {
        append_line(txt, "m test " + std::to_string(i));

        if (i == 5) {
            output_text += "m t|est " + std::to_string(i) + "\n";
        } else {
            output_text += "m test " + std::to_string(i) + "\n";
        }
    }

    testing::internal::CaptureStdout();

    m(txt, 5, 3);
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

    m(txt, 6, 0);
    show(txt);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());

    free(txt);
}


#endif // M_H
