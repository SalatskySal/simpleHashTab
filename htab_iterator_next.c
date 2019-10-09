// htab_iterator_next.c
// Řešení IJC-DU2, příklad 2), 21.3.2019 
// Autor: Serhii Salatskyi, FIT 
// Přeloženo: gcc 7.3
// Strucny popis: posun iterátoru na další záznam v tabulce (nebo na htab_end(t))

#include "htab_create.h"

htab_iterator_t htab_iterator_next(htab_iterator_t it){
	int index = it.idx;
	if(it.ptr == NULL || it.ptr->next == NULL){
		index++;
	}
	else{
		htab_iterator_t next_iter = {.t = it.t, .ptr = it.ptr->next, .idx = index};
		return next_iter; 
	}	
	
	while((size_t)index < htab_bucket_count(it.t) && it.t->list[index] == NULL ){
		index++;
	}
	if((size_t)index >= htab_bucket_count(it.t))
		return htab_end(it.t);

	htab_iterator_t next_iter = {.t = it.t, .ptr=it.t->list[index], .idx = index};
	return next_iter;
}
