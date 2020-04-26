/**
 * tst_m.h - проверка работы функции m.c по перемещению курсора
 * */

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>

/* using namespace testing; */
extern "C" {
#include "common.h"
}

TEST(move_crsr, correct){
    text txt = create_text();
    load(txt, (char*)"../../test/txt/for_load.txt");

    testing::internal::CaptureStdout();
    char* line = (char*)"2";
    char* num = (char*)"10";
    m(line, num, txt);

    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ("Qt Creator is a cross-platform C++, JavaScript and QML integrated development \nenvironment which simplifies GUI application development. \nIt is part\x1B[36m|\x1B[0m of the SDK for the Qt \n\nGUI application development framework and uses \nthe Qt API, which encapsulates host OS GUI function calls. \nIt includes a visual debugger and an integrated WYSIWYG GUI layout and forms designer. \nThe editor has features such as syntax \n\nhighlighting and autocompletion. \nQt Creator uses the C++ compiler from the GNU Compiler Collection on Linux and FreeBSD. On Windows it can use MinGW or MSVC with the default install and can also use Microsoft Console Debugger when \ncompiled from source code. Clang is also \nsupported. \n"
              , output);
}

TEST(move_crsr, func_textbegin){
    text txt = create_text();
    load(txt, (char*)"../../test/txt/for_load.txt");

    testing::internal::CaptureStderr();
    testing::internal::CaptureStdout();

    char* line = (char*)"-1";
    char* num = (char*)"1";
    m(line, num, txt);


    std::string err_output = testing::internal::GetCapturedStderr();
    std::string output = testing::internal::GetCapturedStdout();


    EXPECT_EQ("\x1B[33mNOTE: line starts from '0' \n    Cursor is placed at begining of the text\n\x1B[0m"
              , err_output);
    EXPECT_EQ("\x1B[36m|\x1B[0mQt Creator is a cross-platform C++, JavaScript and QML integrated development \n\nenvironment which simplifies GUI application development. \nIt is part of the SDK for the Qt \nGUI application development framework and uses \nthe Qt API, which encapsulates host OS GUI function calls. \nIt includes a visual debugger and an integrated WYSIWYG GUI layout and forms designer. \nThe editor has features such as syntax \n\nhighlighting and autocompletion. \nQt Creator uses the C++ compiler from the GNU Compiler Collection on Linux and FreeBSD. On Windows it can use MinGW or MSVC with the default install and can also use Microsoft Console Debugger when \ncompiled from source code. Clang is also \nsupported. \n"
              , output);

}

TEST(move_crsr, func_linebegin){
    text txt = create_text();
    load(txt, (char*)"../../test/txt/for_load.txt");

    testing::internal::CaptureStderr();
    testing::internal::CaptureStdout();

    char* line = (char*)"1";
    char* num = (char*)"-1";
    m(line, num, txt);


    std::string err_output = testing::internal::GetCapturedStderr();
    std::string output = testing::internal::GetCapturedStdout();


    EXPECT_EQ("\x1B[33mNOTE: position starts from '0' \n   Cursor is placed at begining of the line\n\x1B[0m"
              , err_output);
    EXPECT_EQ("Qt Creator is a cross-platform C++, JavaScript and QML integrated development \n\x1B[36m|\x1B[0menvironment which simplifies GUI application development. \n\nIt is part of the SDK for the Qt \nGUI application development framework and uses \nthe Qt API, which encapsulates host OS GUI function calls. \nIt includes a visual debugger and an integrated WYSIWYG GUI layout and forms designer. \nThe editor has features such as syntax \n\nhighlighting and autocompletion. \nQt Creator uses the C++ compiler from the GNU Compiler Collection on Linux and FreeBSD. On Windows it can use MinGW or MSVC with the default install and can also use Microsoft Console Debugger when \ncompiled from source code. Clang is also \nsupported. \n"
              , output);
}

TEST(move_crsr, func_textend){
    text txt = create_text();
    load(txt, (char*)"../../test/txt/for_load.txt");

    testing::internal::CaptureStderr();
    testing::internal::CaptureStdout();

    char* line = (char*)"100";
    char* num = (char*)"1";
    m(line, num, txt);

    std::string err_output = testing::internal::GetCapturedStderr();
    std::string output = testing::internal::GetCapturedStdout();


    EXPECT_EQ("\x1B[33mNo such line found, cursor plased to the end of the text\n\x1B[0m\x1B[33mNOTE: cursor placed at the end of the line\n\x1B[0m"
              , err_output);
    EXPECT_EQ("Qt Creator is a cross-platform C++, JavaScript and QML integrated development \nenvironment which simplifies GUI application development. \nIt is part of the SDK for the Qt \nGUI application development framework and uses \nthe Qt API, which encapsulates host OS GUI function calls. \nIt includes a visual debugger and an integrated WYSIWYG GUI layout and forms designer. \nThe editor has features such as syntax \n\nhighlighting and autocompletion. \nQt Creator uses the C++ compiler from the GNU Compiler Collection on Linux and FreeBSD. On Windows it can use MinGW or MSVC with the default install and can also use Microsoft Console Debugger when \ncompiled from source code. Clang is also \nsupported. \n\x1B[36m|\x1B[0m\n"
              , output);
}

TEST(move_crsr, func_linetend){
    text txt = create_text();
    load(txt, (char*)"../../test/txt/for_load.txt");

    testing::internal::CaptureStderr();
    testing::internal::CaptureStdout();

    char* line = (char*)"1";
    char* num = (char*)"1000";
    m(line, num, txt);

    std::string err_output = testing::internal::GetCapturedStderr();
    std::string output = testing::internal::GetCapturedStdout();


    EXPECT_EQ("\x1B[33mNOTE: cursor placed at the end of the line\n\x1B[0m"
              , err_output);
    EXPECT_EQ("Qt Creator is a cross-platform C++, JavaScript and QML integrated development \nenvironment which simplifies GUI application development. \n\x1B[36m|\x1B[0m\nIt is part of the SDK for the Qt \nGUI application development framework and uses \nthe Qt API, which encapsulates host OS GUI function calls. \nIt includes a visual debugger and an integrated WYSIWYG GUI layout and forms designer. \nThe editor has features such as syntax \n\nhighlighting and autocompletion. \nQt Creator uses the C++ compiler from the GNU Compiler Collection on Linux and FreeBSD. On Windows it can use MinGW or MSVC with the default install and can also use Microsoft Console Debugger when \ncompiled from source code. Clang is also \nsupported. \n"
              , output);
}

TEST(move_crsr, error){
    text txt = create_text();
    load(txt, (char*)"../../test/txt/for_load.txt");

    testing::internal::CaptureStdout();
    testing::internal::CaptureStderr();

    char* line = (char*)" ";
    char* num = (char*) "two";

    m(line, num, txt);

    std::string err_output = testing::internal::GetCapturedStderr();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ("\x1B[33mNOTE: line starts from '0' \n    Cursor is placed at begining of the text\n\x1B[0m"
              , err_output);
    EXPECT_EQ("\x1B[36m|\x1B[0mQt Creator is a cross-platform C++, JavaScript and QML integrated development \n\nenvironment which simplifies GUI application development. \nIt is part of the SDK for the Qt \nGUI application development framework and uses \nthe Qt API, which encapsulates host OS GUI function calls. \nIt includes a visual debugger and an integrated WYSIWYG GUI layout and forms designer. \nThe editor has features such as syntax \n\nhighlighting and autocompletion. \nQt Creator uses the C++ compiler from the GNU Compiler Collection on Linux and FreeBSD. On Windows it can use MinGW or MSVC with the default install and can also use Microsoft Console Debugger when \ncompiled from source code. Clang is also \nsupported. \n", output);
}


