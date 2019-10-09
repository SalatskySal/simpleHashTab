// htab_create.h
// Řešení IJC-DU2, příklad 2), 21.3.2019 
// Autor: Serhii Salatskyi, FIT 
// Přeloženo: gcc 7.3
// Strucny popis: definuje privatni promenne ve zaznamech 

#include "htab.h"
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

#ifndef HTAB_CREATE_H
#define HTAB_CREATE_H

typedef struct htab_item{ 
	char *key; 
	int data; 
	struct htab_item *next; 
} htab_item;

struct htab{ 
	size_t size; 
	size_t arr_size; 
	htab_item *list[]; 
};

#endif
