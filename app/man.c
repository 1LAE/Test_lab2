 
/**
 * man.c 
 *
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <assert.h>
#include "common.h"
#include "text/text.h"

void man(){
    
    FILE *list;
    
    /* Открываем файл для чтения, контролируя ошибки */
    if ((list = fopen("common.h", "r")) == NULL) {
        printf("Man is unavaible\n");
        return;
    }
    
    char buf[MAXLINE + 1];
    
    printf("______________\n");
    
    while (fgets(buf, MAXLINE, list)) {
        
        if(buf[0] == 'v' &&
           buf[1] == 'o' &&
           buf[2] == 'i' &&
           buf[3] == 'd'){
            
            int i = 5;
            while(buf[i] != '('){
                printf("%c", buf[i]);
                i++;
            }
            
            printf("\n");
            
        }
    }
    
    printf("______________\n");
    fclose(list);
    
}
