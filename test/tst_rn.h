#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

/* using namespace testing; */
extern "C" {
#include "common.h"
}

TEST(rn_text, correct){
    text txt = create_text();
    load(txt, (char*)"../../test/txt/for_load.txt");

    testing::internal::CaptureStdout();
    char* line = (char*)"2";

    rn(txt, line);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ("Qt Creator is a cross-platform C++, JavaScript and QML integrated development \nenvironment which simplifies GUI application development. \nGUI application development framework and uses \nthe Qt API, which encapsulates host OS GUI function calls. \nIt includes a visual debugger and an integrated WYSIWYG GUI layout and forms designer. \nThe editor has features such as syntax \n\nhighlighting and autocompletion. \nQt Creator uses the C++ compiler from the GNU Compiler Collection on Linux and FreeBSD. On Windows it can use MinGW or MSVC with the default install and can also use Microsoft Console Debugger when \ncompiled from source code. Clang is also \nsupported. \n\x1B[36m|\x1B[0m\n"
              , output);
}

TEST(rn_text, nonexist){
    text txt = create_text();
    load(txt, (char*)"../../test/txt/for_load.txt");
    freopen("../../test/txt/temp/temp.txt", "w", stdout);

    testing::internal::CaptureStderr();
    char* line = (char*)"100";

    rn(txt, line);
    std::string err_output = testing::internal::GetCapturedStderr();
    EXPECT_EQ("\x1B[33mNo such line found\n   Nothing happened\n\x1B[0m", err_output);
}

TEST(rn_text, empty){
    text txt = create_text();
    load(txt, (char*)"../../test/txt/empty.txt");

    testing::internal::CaptureStdout();
    char* line = (char*)"1";

    ASSERT_EXIT((rn(txt, line),exit(0)),::testing::ExitedWithCode(0),".*");
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ("", output);
}

TEST(rn_text, incorrect){
    text txt = create_text();
    load(txt, (char*)"../../test/txt/for_load.txt");
    freopen("../../test/txt/temp/temp.txt", "w", stdout);

    testing::internal::CaptureStderr();    
    char* line = (char*)"abc";

    rn(txt, line);
    std::string err_output = testing::internal::GetCapturedStderr();
    EXPECT_EQ("\x1B[33mNo such line found\n   Nothing happened\n\x1B[0m"
              , err_output);
}

TEST(rn_text, negative){
    text txt = create_text();
    load(txt, (char*)"../../test/txt/for_load.txt");
    freopen("../../test/txt/temp/temp.txt", "w", stdout);

    testing::internal::CaptureStderr();
    char* line = (char*)"-3";

    rn(txt, line);
    std::string err_output = testing::internal::GetCapturedStderr();
    EXPECT_EQ("\x1B[33mNo such line found\n   Nothing happened\n\x1B[0m", err_output);
}

TEST(rn_text, fraction){
    text txt = create_text();
    freopen("../../test/txt/temp/temp.txt", "w", stdout);
    load(txt, (char*)"../../test/txt/for_load.txt");

    testing::internal::CaptureStderr();
    char* line = (char*)"3.14159265";

    rn(txt, line);
    std::string err_output = testing::internal::GetCapturedStderr();
    EXPECT_EQ("\x1B[33mNo such line found\n   Nothing happened\n\x1B[0m", err_output);
}

