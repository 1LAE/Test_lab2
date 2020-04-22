TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    editor.c \
    load.c \
    m.c \
    mwef.c \
    rn.c \
    save.c \
    show.c \
    showfirstwords.c \
    text/append_line.c \
    text/create_text.c \
    text/move_crsr.c \
    text/mwef_text.c \
    text/numberise.c \
    text/process_forward.c \
    text/remove_all.c \
    text/rn_text.c

HEADERS += \
    common.h \
    text/_text.h \
    text/text.h

QMAKE_CFLAGS += -Wall -Wextra -Werror
