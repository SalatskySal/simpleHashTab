// htab_lookup_add.c
// Řešení IJC-DU2, příklad 2), 21.3.2019 
// Autor: Serhii Salatskyi, FIT 
// Přeloženo: gcc 7.3
// Strucny popis: V tabulce t vyhledá záznam odpovídající řetězci key a 
// - pokud jej nalezne, vrátí iterátor na záznam 
// - pokud nenalezne, automaticky přidá záznam a vrátí iterátor

#include "htab_create.h"

htab_iterator_t htab_lookup_add(htab_t * t, const char *key){
	int index = htab_hash_function(key) % htab_bucket_count(t);

	htab_item *next_item, *last_item;
	next_item = t->list[index];
	last_item = NULL;
    	/* Search for an existing key. */
    while (next_item != NULL) {
	    if(!strcmp(next_item->key, (char*)key)){
			htab_iterator_t new_iter = {.t = t, .ptr = next_item, .idx = index};
			return new_iter;
		}

		last_item = next_item;
		next_item = last_item->next;

	}
	
    	/*create a new item */
    htab_item *new_item = NULL;
    new_item = (htab_item *) malloc(sizeof(htab_item));
    if (new_item == NULL){
		return htab_end(t);
	}
	
	new_item->key=(char*)malloc(strlen(key)+1);
	if(new_item->key == NULL){
		return htab_end(t);
	}
	memcpy(new_item->key, (char*)key, strlen(key)+1);
	new_item->data = 0;
	new_item->next = NULL;
	
    	/*Tack the new item on the end or right on the table*/
   	if (last_item != NULL)
		last_item->next = new_item;
	else
		t->list[index] = new_item;
	t->size++;

	htab_iterator_t new_iter = {.t = t, .ptr = new_item, .idx = index};
	
	return new_iter;
}
