// htab_begin.c
// Řešení IJC-DU2, příklad 2), 21.3.2019 
// Autor: Serhii Salatskyi, FIT 
// Přeloženo: gcc 7.3
// Strucny popis: hleda a vraci iterator na prvni zaznam v tabulce t


#include "htab_create.h"

htab_iterator_t htab_begin(const htab_t *t){
	for(int idx = 0; (size_t)idx < htab_bucket_count(t); idx++){
			if(t->list[idx] != NULL){
					htab_iterator_t begin = {.t = t, .ptr = t->list[idx], .idx = idx};
					return begin;
			}
	}
	return htab_end(t);
}
