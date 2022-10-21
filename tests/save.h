#ifndef SAVE_H
#define SAVE_H

#include "all_tests.h"

TEST(save, line)
{
    text txt = create_text();

    append_line(txt, "Строка 1");
    append_line(txt, "Строка 2");
    append_line(txt, "Строка 3");

    save(txt, "test.save");

    text txt2 = create_text();

    load(txt2, "test.save");

    string* txt_arr = new string[txt->myList->size()];
    string* txt2_arr = new string[txt2->myList->size()];
    
    copy(txt->myList->begin(), txt->myList->end(), txt_arr);
    copy(txt2->myList->begin(), txt2->myList->end(), txt2_arr);
    
    for(unsigned int i = 0; i < txt->myList->size(); i++)
        EXPECT_STREQ(txt_arr[i].c_str(), txt2_arr[i].c_str());
    EXPECT_EQ(txt->myList->size(), txt2->myList->size());
    
    free(txt);
    free(txt2);
}

TEST(save, with_empty_strs)
{
    text txt = create_text();
    for (int i = 0; i < 5; i++) {
        append_line(txt, "Непустая строка");
        append_line(txt, "");
    }

    save(txt, "save.test");

    QFile file(save.test);
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

    QFile file(save.test);
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
