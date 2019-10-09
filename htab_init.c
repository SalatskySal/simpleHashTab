// htab_init.c
// Řešení IJC-DU2, příklad 2), 21.3.2019 
// Autor: Serhii Salatskyi, FIT 
// Přeloženo: gcc 7.3
// Strucny popis: vytvari a inicializuje tabulku z poctem prvku t

#include "htab_create.h"

htab_t *htab_init(size_t t){
	assert(t > 0);
	//inicializace pomoci malloc
	htab_t* new_htab = (htab_t*)calloc(sizeof(htab_t) + t*sizeof(htab_item*), 1);
	if(!new_htab){
		return NULL;
	}

	if(!new_htab->list){
                return NULL;
        }

	new_htab->size=0;
	new_htab->arr_size=t;

	for(int i = 0; i < (int)t; i++){
		new_htab->list[i] = NULL;
	}

	return new_htab;
}
