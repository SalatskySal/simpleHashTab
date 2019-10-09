// htab_iterator_get_value.c
// Řešení IJC-DU2, příklad 2), 21.3.2019 
// Autor: Serhii Salatskyi, FIT 
// Přeloženo: gcc 7.3
// Strucny popis: vraci hodnotu

#include "htab_create.h"

int htab_iterator_get_value(htab_iterator_t it){
	return (htab_iterator_valid(it) ? it.ptr->data : -1);
}
