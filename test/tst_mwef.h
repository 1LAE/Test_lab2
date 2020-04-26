#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

/* using namespace testing; */
extern "C" {
#include "common.h"
}

TEST(mwef, correct){
    text txt = create_text();
    load(txt, (char*)"../../test/txt/for_load.txt");

    testing::internal::CaptureStdout();

    m((char*)"1", (char*)"8", txt); // Move crsr to the center of some word
    mwef(txt);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ("Qt Creator is a cross-platform C++, JavaScript and QML integrated development \nenvironm\x1B[36m|\x1B[0ment which simplifies GUI application development. \n\nIt is part of the SDK for the Qt \nGUI application development framework and uses \nthe Qt API, which encapsulates host OS GUI function calls. \nIt includes a visual debugger and an integrated WYSIWYG GUI layout and forms designer. \nThe editor has features such as syntax \n\nhighlighting and autocompletion. \nQt Creator uses the C++ compiler from the GNU Compiler Collection on Linux and FreeBSD. On Windows it can use MinGW or MSVC with the default install and can also use Microsoft Console Debugger when \ncompiled from source code. Clang is also \nsupported. \nQt Creator is a cross-platform C++, JavaScript and QML integrated development \nenvironment\x1B[36m|\x1B[0m which simplifies GUI application development. \n\nIt is part of the SDK for the Qt \nGUI application development framework and uses \nthe Qt API, which encapsulates host OS GUI function calls. \nIt includes a visual debugger and an integrated WYSIWYG GUI layout and forms designer. \nThe editor has features such as syntax \n\nhighlighting and autocompletion. \nQt Creator uses the C++ compiler from the GNU Compiler Collection on Linux and FreeBSD. On Windows it can use MinGW or MSVC with the default install and can also use Microsoft Console Debugger when \ncompiled from source code. Clang is also \nsupported. \n"
              , output);
}

TEST(mwef, empty){
    text txt = create_text();
    load(txt, (char*)"../../test/txt/empty.txt");
    ASSERT_EXIT((mwef(txt),exit(0)),::testing::ExitedWithCode(0),".*");
}

TEST(mwef, wordend){
    text txt = create_text();
    load(txt, (char*)"../../test/txt/for_load.txt");

    testing::internal::CaptureStdout();

    m((char*)"1", (char*)"11", txt); // Move crsr to the center of some word
    mwef(txt);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ("Qt Creator is a cross-platform C++, JavaScript and QML integrated development \nenvironment\x1B[36m|\x1B[0m which simplifies GUI application development. \n\nIt is part of the SDK for the Qt \nGUI application development framework and uses \nthe Qt API, which encapsulates host OS GUI function calls. \nIt includes a visual debugger and an integrated WYSIWYG GUI layout and forms designer. \nThe editor has features such as syntax \n\nhighlighting and autocompletion. \nQt Creator uses the C++ compiler from the GNU Compiler Collection on Linux and FreeBSD. On Windows it can use MinGW or MSVC with the default install and can also use Microsoft Console Debugger when \ncompiled from source code. Clang is also \nsupported. \nQt Creator is a cross-platform C++, JavaScript and QML integrated development \nenvironment\x1B[36m|\x1B[0m which simplifies GUI application development. \n\nIt is part of the SDK for the Qt \nGUI application development framework and uses \nthe Qt API, which encapsulates host OS GUI function calls. \nIt includes a visual debugger and an integrated WYSIWYG GUI layout and forms designer. \nThe editor has features such as syntax \n\nhighlighting and autocompletion. \nQt Creator uses the C++ compiler from the GNU Compiler Collection on Linux and FreeBSD. On Windows it can use MinGW or MSVC with the default install and can also use Microsoft Console Debugger when \ncompiled from source code. Clang is also \nsupported. \n"
              , output);
}


TEST(mwef, textend){
    text txt = create_text();
    load(txt, (char*)"../../test/txt/for_load.txt");
    m((char*)"11", (char*)"12", txt);

    ASSERT_EXIT((mwef(txt),exit(0)),::testing::ExitedWithCode(0),".*");
}
