// htab_iterator_get_key.c
// Řešení IJC-DU2, příklad 2), 21.3.2019 
// Autor: Serhii Salatskyi, FIT 
// Přeloženo: gcc 7.3
// Strucny popis: vraci klic 

#include "htab_create.h"

const char* htab_iterator_get_key(htab_iterator_t it){
	return (htab_iterator_valid(it) ? it.ptr->key : "");
}
