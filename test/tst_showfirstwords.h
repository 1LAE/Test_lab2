#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

/* using namespace testing; */
extern "C" {
#include "common.h"
}

TEST(showfirstwords, sample){
    text txt = create_text();
    load(txt, (char*)"../../test/txt/for_load.txt");

    testing::internal::CaptureStdout();

    ASSERT_EXIT((showfirstwords(txt),exit(0)),::testing::ExitedWithCode(0),".*");

    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ("Qt\nenvironment\nIt\nGUI\nthe\nIt\nThe\n\nhighlighting\nQt\ncompiled\nsupported.\n", output);
}

TEST(showfirstwords, empty){
    text txt = create_text();
    load(txt, (char*)"../../test/txt/empty.txt");

    testing::internal::CaptureStdout();

    ASSERT_EXIT((showfirstwords(txt),exit(0)),::testing::ExitedWithCode(0),".*");

    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ("", output);

    remove("../../test/txt/temp/temp.txt");
}

