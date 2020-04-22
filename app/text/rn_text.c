#include "_text.h"
#define YELLOW  "\x1b[33m"
#define RESET   "\x1b[0m"

void rn_text(text txt, int index)
{
    if (!txt->length) { fprintf(stderr, "There are already no any lines in the text!\n"); return; }
    if (index < 0 || index > (int) txt->length - 1) { fprintf(stderr, YELLOW "No such line found\n   Nothing happened\n" RESET); return; }
    
    node *line = txt->begin;
    for (int k = 0; k != index; k++, line = line->next); 
    
    node *list1 = line->previous;
    node *list2 = line;
    node *list3 = line->next;
    if (list1) list1->next = list3;
    if (list3) list3->previous = list1;
    if (list2 == txt->begin) txt->begin = list3;
    if (list2 == txt->end) txt->end = list1;
    if (line == txt->cursor->line) { txt->cursor->line = txt->begin, txt->cursor->position = 0; }
    txt->length--;
    free(line);
    
}
