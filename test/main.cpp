#include "tst_m.h"
#include "tst_mwef.h"
#include "tst_rn.h"
#include "tst_save.h"
#include "tst_showfirstwords.h"

#include <gtest/gtest.h>

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
