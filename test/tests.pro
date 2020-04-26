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
        ../app/text/text.h \
        tst_m.h \
        tst_mwef.h \
        tst_rn.h \
        tst_save.h \
        tst_showfirstwords.h

SOURCES += main.cpp \    
    ../app/save.c \
    ../app/load.c \
    ../app/m.c \
    ../app/show.c \
    ../app/rn.c \
    ../app/mwef.c \
    ../app/showfirstwords.c \
    ../app/text/move_crsr.c \
    ../app/text/numberise.c \
    ../app/text/process_forward.c \
    ../app/text/create_text.c \
    ../app/text/remove_all.c \
    ../app/text/append_line.c \
    ../app/text/rn_text.c \
    ../app/text/mwef_text.c

INCLUDEPATH += \
    ../app \
    ../app/text
