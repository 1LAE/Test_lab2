#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

/* using namespace testing; */
extern "C" {
#include "common.h"
}

TEST(showfirstwords, sample){
    text txt = create_text();
    load(txt, (char*)"./tests/test_text.txt");

    testing::internal::CaptureStdout();

    ASSERT_EXIT((showfirstwords(txt),exit(0)),::testing::ExitedWithCode(0),".*");

    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ("In\nDuring\nAmong\nAlso\nfigurine.\n", output);
}

TEST(showfirstwords, empty){
    text txt = create_text();
    load(txt, (char*)"./tests/txt/empty.txt");

    testing::internal::CaptureStdout();

    ASSERT_EXIT((showfirstwords(txt),exit(0)),::testing::ExitedWithCode(0),".*");

    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ("", output);
}

