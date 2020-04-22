/**
 * show.c -- реализует команду вывода хранимого текста на экран
 *
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include "common.h"
#include "text/text.h"

#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"

static void show_line(int index, char *contents, int cursor, void *data);

/**
 * Выводит содержимое указанного файла на экран
 */
void show(text txt)
{
    /* Применяем функцию show_line к каждой строке текста */
    process_forward(txt, show_line, NULL);
}

/**
 * Выводит содержимое указанного файла на экран
 */
static void show_line(int index, char *contents, int cursor, void *data)
{
    /* Функция обработчик всегда получает существующую строку */
    assert(contents != NULL);
    
    /* Декларируем неиспользуемые параметры */
    UNUSED(index);
    UNUSED(data);
    
    if(cursor != -1){
        /*
        char* start;
        char* finish = contents + cursor;
        */
        int length = strlen(contents);
        
        for(int i = 0; i < cursor;i ++){
            printf("%c", contents[i]);
        }

        printf(CYAN);
        printf("|");
        printf(RESET);
        
        for(int i = cursor; i < length; i++){
            printf("%c", contents[i]);
        }
        printf("\n");
        
        /*
        for(int i = 0; i < cursor;i ++){
            printf("%c", contents[i]);
        }
        
        printf(CYAN);
        printf("|");
        printf(RESET);
        
        int length = strlen(contents);
        
        for(int i = cursor; i < length;i ++){
            printf("%c", contents[i]);
        }
        */
    } else {
       printf("%s", contents);
    }
    
    
}
