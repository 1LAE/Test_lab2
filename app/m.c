 
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
    
   
        move_crsr(txt, n_line, n_num);
        show(txt);
        
    }
    

