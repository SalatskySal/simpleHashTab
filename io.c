// io.c
// Řešení IJC-DU2, příklad 2), 21.3.2019 
// Autor: Serhii Salatskyi, FIT 
// Přeloženo: gcc 7.3
// Strucny popis: hleda slovo ve souboru, uklada ho do retezcu a vraci delku slova

#include "io.h"

int get_word(char *s, int max, FILE *f){
    int c;
    if(feof(f))
        return EOF;

    int idx = 0;
    while(!isspace(c = fgetc(f))){
        if(feof(f))
            break;
        if(idx < max)
            s[idx++] = c;
    }
    
    s[idx] = '\0';

    return idx;
}