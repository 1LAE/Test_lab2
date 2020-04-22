 /**
 * remove_all.c -- реализует функцию очистки текста
 *
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "_text.h"
#include <string.h>
#include <stdio.h>


#define YELLOW  "\x1b[33m"
#define RESET   "\x1b[0m"


/**
 * 
 * @param txt текст
 * @returns none
 */
void move_crsr(text txt, int line, int num)
{
    /* Проверяем, имеется ли текст */
    if (txt == NULL || txt->length == 0) {
        return;
    }
    
    if(num < 0 && line >= 0){
        fprintf(stderr, YELLOW "NOTE: position starts from '0' \n   Cursor is placed at begining of the line\n" RESET);
        num = 0;
    }
    
    if(line < 0){
        fprintf(stderr, YELLOW "NOTE: line starts from '0' \n    Cursor is placed at begining of the text\n" RESET);
        line = 0;
        num = 0;
    }
    
    /* Проверка существования строки */
    node* current = txt->begin;
    int counter = 0;
    int flag_line = 0;
    int flag_goto = 0;
    
    for(counter = 0; counter < line; counter++){ //Считаем линии
        
        while(flag_goto == 0){  //Идем по листу
        
            int length = strlen(current->contents);
            for(int i = 0; i < length; i++){
                if(current->contents[i] == '\n'){
                    counter++;
                    if(counter == line){   //Достигли текущей строки
                        flag_line = 1;    //Выход из for
                        flag_goto = 1;   //Выход из while 
                        break;
                    }
                }
            }
            
            if((current = current->next) == NULL){
            fprintf(stderr, YELLOW "No such line found, cursor plased to the end of the text\n" RESET);
            current = txt->end;
            num = MAXLINE; //strlen(current->contents);
            
            flag_goto = 1;
            flag_line = 1;
            
            break;
            
            }
        }
            
        if(flag_line == 1){
            break;
        }
    }
    

    txt->cursor->line = current;
        if(num > (int)strlen(current->contents)){
            fprintf(stderr, YELLOW "NOTE: cursor placed at the end of the line\n" RESET);
            txt->cursor->position = strlen(current->contents);
        } else {
            txt->cursor->position = num;
        }

}






