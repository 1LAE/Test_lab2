 
/**
 * m.c -- реализует команду перемещения курсора
 *
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "common.h"
#include "text/text.h"

#define YELLOW  "\x1b[33m"
#define RESET   "\x1b[0m"
#define RED     "\x1b[31m"

void m(char* line, char* num, text txt){

    int n_line = numberise(line);
    int n_num  = numberise(num);
    
    /*
    if(n_num > MAXLINE + 1){
        
        int flag = 1;
        
        fprintf(stderr, YELLOW "NOTE: number is too high. Do you want to plase cursor at the end of the line? (y or n)\n" RESET);
        
        
        while(flag){
            
            char* ans;
            printf(RED);
            scanf("%s", ans);
            printf(RESET);
            if(strlen(ans) != 1){
                fprintf(stderr, YELLOW "NOTE: please, answer 'y' or 'n'\n" RESET);
                continue;
            }
            
            switch (ans[0]){
                case 'y':
                    n_num = MAXLINE;
                    flag = 0;
                    move_crsr(txt, n_line, n_num);
                    show(txt);
                    break;
                case 'n':
                    fprintf(stderr, YELLOW "NOTE: enter valid cursor position\n" RESET);
                    flag = 0;
                    break;
                default:
                    fprintf(stderr, YELLOW "NOTE: please, answer 'y' or 'n'\n" RESET);
                    break;
            }
        }
    } else { 
        */
        move_crsr(txt, n_line, n_num);
        show(txt);
        
    }
    

//}
