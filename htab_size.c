// htab_size.c
// Řešení IJC-DU2, příklad 2), 21.3.2019 
// Autor: Serhii Salatskyi, FIT 
// Přeloženo: gcc 7.3
// Strucny popis: vraci pocet zaznamu v tabulce t

#include "htab_create.h"

size_t htab_size(const htab_t *t){
	return t->size;	
}
