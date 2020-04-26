/**
 * editor.c -- строковый текстовый редактор
 * 
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "text/text.h"
#include "common.h"

#define MAXLINE 255
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define RESET   "\x1b[0m"

int main()
{
    char cmdline[MAXLINE + 1];
    char *cmd;
    char *arg;
    char *arg1;
    
    /* Создаем объект для представления текста */
    text txt = create_text();
    
    

    /* Цикл обработки команд */
    while (1) {
        
        printf(GREEN);
        printf("ed > ");
        printf(RESET);
        
        /* Получаем команду */
        if(fgets(cmdline, MAXLINE, stdin) == NULL){
            continue;
        }        

        /* Извлекаем имя команды */
        if ((cmd = strtok(cmdline, " \n")) == NULL) {
            continue;
        }

        /* Распознаем поддерживаемую команду */
        
        /* Завершаем работу редактора */
        if (strcmp(cmd, "quit") == 0) {
            fprintf(stderr, GREEN "Bye!\n" RESET);
            break;
        }

        /* Загружаем содержимое файла, заданного параметром */
        if (strcmp(cmd, "load") == 0) {
            if ((arg = strtok(NULL, " \n")) == NULL) {
                fprintf(stderr, "Usage: load filename\n");
            } else {
                load(txt, arg);
            }
            continue;
        }
        
         if (strcmp(cmd, "save") == 0) {
            if ((arg = strtok(NULL, " \n")) == NULL) {
                fprintf(stderr, "Usage: load filename\n");
            } else {
                save(txt, arg);
            }
            continue;
        }

        /* Выводим текст */
        if (strcmp(cmd, "show") == 0) {
            show(txt);
            continue;
        }
        
        /* Manual */
        if (strcmp(cmd, "showfirstwords") == 0) {
            showfirstwords(txt);
            continue;
        }
        
        if (strcmp(cmd, "rn") == 0) {
            if((arg = strtok(NULL, "\n")) == NULL){
                fprintf(stderr, "Usage: enter " YELLOW "line"RESET " number\n");
            } else {
                rn(txt, arg);
            }
            continue;
        }
        
        if (strcmp(cmd, "m") == 0) {
            if ((arg = strtok(NULL, " \n")) == NULL || (arg1 = strtok(NULL, " \n")) == NULL) {
                fprintf(stderr, "Usage: enter " YELLOW "line " RESET "&" YELLOW " number\n" RESET);
            } else {
                m(arg, arg1, txt);
            }
            continue;
        }
        
        if (strcmp(cmd, "mwef") == 0) {
            mwef(txt);
            continue;
        }                
        
        /* Если команда не известна */
        fprintf(stderr, "Unknown command: %s\n", cmd);
    }

    return 0;
}
