// htab_clear.c
// Řešení IJC-DU2, příklad 2), 21.3.2019 
// Autor: Serhii Salatskyi, FIT 
// Přeloženo: gcc 7.3
// Strucny popis: zruši všechny položky, tabulka t zůstane prázdná

#include "htab_create.h"

void htab_clear(htab_t * t){
	for(int i = 0; (size_t)i < htab_bucket_count(t); i++){
		struct htab_item *next_item = t->list[i];
		struct htab_item *last_item = NULL;
		while (next_item != NULL) {
		    /* destroy item */
		    last_item = next_item;
		    next_item = next_item->next;
		    free(last_item->key);
			free(last_item);
		}
	}
	
	t->arr_size = 0;
	return;
}
