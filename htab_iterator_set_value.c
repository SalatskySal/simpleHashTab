// htab_iterator_set_value.c
// Řešení IJC-DU2, příklad 2), 21.3.2019 
// Autor: Serhii Salatskyi, FIT 
// Přeloženo: gcc 7.3
// Strucny popis: prepisuje hodnotu

#include "htab_create.h"

int htab_iterator_set_value(htab_iterator_t it, int val){
	return (htab_iterator_valid(it) ? it.ptr->data=val : -1);
}
