include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

QMAKE_CXXFLAGS += -Wall -Wextra -Werror
QMAKE_CFLAGS += -Wall -Wextra -Werror

# gcov
QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov

HEADERS += \
        ../app/_text.h \
        ../app/text.h \
        ../app/common.h \
        tst_m.h \
        tst_mwef.h \
        tst_rn.h \
        tst_save.h \
        tst_showfirstwords.h

SOURCES += main.cpp \

INCLUDEPATH += \
    ../app \
    ../app/text
