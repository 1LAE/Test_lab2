 
/**
 * man.c 
 *
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "common.h"
#include "text/text.h"

int convert(char* s);

void rn(text txt, char* line){
    
    int n_line = numberise(line);
    
    rn_text(txt, n_line);
    
    show(txt);
    
    
}
