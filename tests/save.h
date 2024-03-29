#ifndef SAVE_H
#define SAVE_H

#include <string>
#include "all_tests.h"

using namespace std;

TEST(save, with_empty_strs)
{
    text txt = create_text();
    for (int i = 0; i < 5; i++) {
        append_line(txt, "Непустая строка");
        append_line(txt, "");
    }

    save(txt, "save.test");

    QFile file("save.test");
    bool res = file.open(QIODevice::ReadOnly);
    ASSERT_EQ(res, true);

    QString line_file;
    auto line_text = txt->lines->begin();

    while (!file.atEnd()) {
        line_file = file.readLine();

        ASSERT_STREQ(line_file.toStdString().c_str(), (*line_text + "\n").c_str() );
        line_text++;
    }

    removeFiles();
}

TEST(save, nothing)
{
    text txt = create_text();
    save(txt, "save.test");

    QFile file("save.test");
    bool res = file.open(QIODevice::ReadOnly);
    ASSERT_EQ(res, true);

    QString line_file;
    auto line_text = txt->lines->begin();

    while (!file.atEnd()) {
        line_file = file.readLine();

        ASSERT_STREQ(line_file.toStdString().c_str(), (*line_text + "\n").c_str() );
        line_text++;
    }

    removeFiles();
}

#endif // TEST_SQ_EQ_H
