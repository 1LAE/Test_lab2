/**
 * mwef_text.c - перемещение курсора в конец слова
 *
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <assert.h>
#include "_text.h"

void mwef_text(text txt){

    if(txt == NULL || txt->length == 0){
        return;
    }
    
    node* current = txt->begin;
    while(current != txt->cursor->line){
        current = current->next;
    }
    
    int length = strlen(current->contents);
    while(
        current->contents[txt->cursor->position] != ' ' 
        && current->contents[txt->cursor->position] != '.'
        && current->contents[txt->cursor->position] != ','
        && current->contents[txt->cursor->position] != '\n' 
        && current->contents[txt->cursor->position] != EOF
        && txt->cursor->position < length){
        
        txt->cursor->position++;
    }    
}
