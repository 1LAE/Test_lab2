/**
 * common.h -- прототипы функций реализации команд редактора
 * 
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#ifndef COMMON_H
#define COMMON_H

#include "text/text.h"

/* Декларирует неиспользуемый аргумент,
 * корректно подавляя предупреждение вида "unused parameter" */
#define UNUSED(x) (void)(x)

void show(text txt);

void load(text txt, char *filename);

void save(text txt, char *filename);

void showfirstwords(text txt); //вывод первого слова из каждой строки в прямом порядке следования строк

void mwef(text txt); //перемещение курсора в конец текущего слова, если это возможно

void rn(text txt, char* line); //удаление строки, заданной номером

void m(char* line, char* num, text txt); //перемещение курсора

#endif
