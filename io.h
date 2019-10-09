// io.h
// Řešení IJC-DU2, příklad 2), 21.3.2019 
// Autor: Serhii Salatskyi, FIT 
// Přeloženo: gcc 7.3
// Strucny popis: hlavickovy soubor pro io.c

#include <string.h>
#include <stdio.h>
#include <ctype.h>

#ifndef IO_H
#define IO_H

int get_word(char* s, int max, FILE *f);

#endif