#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>

/* using namespace testing; */
extern "C" {
#include "../app/common.h"
#include "../app/text/text.h"
#include "../app/text/_text.h"
}

TEST(save, sample_func){

    text txt = create_text();
    load(txt, (char*)"./tests/txt/for_load.txt");
    save(txt, (char*)"./tests/txt/save/save_sample_func.txt");
    std::ifstream saved;
    std::ifstream reference;
    saved.open("./tests/txt/save/save_sample_func.txt");
    reference.open("./tests/txt/for_load.txt");

    ASSERT_EQ(sizeof (reference), sizeof (saved));

    std::string s_ref, s_sav;
    bool flag = true;
    while(std::getline(saved, s_sav)){
        std::getline(reference, s_ref);
        if(s_ref != s_sav){
            flag = 0;
            break;
        }
    }

    EXPECT_EQ(true, flag);
    remove("./tests/txt/save/save_sample_func.txt");
}


TEST(save, empty){
    text txt = create_text();
    load(txt, (char*)"../../test/txt/empty.txt");
    ASSERT_EXIT((save(txt, (char*)"../../test/txt/save/save_empty.txt"),exit(0)),::testing::ExitedWithCode(0),".*");
    std::ifstream file("../../test/txt/save/save_empty.txt");
    EXPECT_NE(-1, access("../../test/txt/save/save_empty.txt", 0));

    remove("../../test/txt/save/save_empty.txt");

}

TEST(save, expansion){
    text txt = create_text();
    load(txt, (char*)"../../test/txt/for_load.txt");

    save(txt, (char*)"../../test/txt/save/save_expansion.txt");
    EXPECT_NE(-1, access("../../test/txt/save/save_expansion.txt", 0));

    save(txt, (char*)"../../test/txt/save/save_expansion.zip");
    EXPECT_NE(-1, access("../../test/txt/save/save_expansion.zip", 0));

    save(txt, (char*)"../../test/txt/save/save_expansion.doc");
    EXPECT_NE(-1, access("../../test/txt/save/save_expansion.doc", 0));

    save(txt, (char*)"../../test/txt/save/save_expansion.abcde");
    EXPECT_NE(-1, access("../../test/txt/save/save_expansion.abcde", 0));

    remove("../../test/txt/save/save_expansion.txt");
    remove("../../test/txt/save/save_expansion.zip");
    remove("../../test/txt/save/save_expansion.doc");
    remove("../../test/txt/save/save_expansion.abcde");
}

TEST(save, dir){
    text txt = create_text();
    testing::internal::CaptureStdout();

    load(txt, (char*)"../../test/txt/for_load.txt");

    save(txt, (char*)"/save_permisson.txt");
    EXPECT_EQ(-1, access("/save_permisson.txt", 0));

    save(txt, (char*)"./abcde/save_permisson.txt");
    EXPECT_EQ(-1, access("./abcde/save_permisson.txt", 0));

    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ("Can't save to file /save_permisson.txt\nCan't save to file ./abcde/save_permisson.txt\n", output);
}


TEST(save, null){
    text txt = create_text();
    testing::internal::CaptureStdout();

    load(txt, (char*)"../../test/txt/for_load.txt");
    save(txt, (char*)"/dev/null/save_exist.txt");

    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(-1, access("/dev/null/save_exist.txt", 0));
    EXPECT_EQ("Can't save to file /dev/null/save_exist.txt\n", output);
}

