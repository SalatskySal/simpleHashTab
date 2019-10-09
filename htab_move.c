// htab_move.c
// Řešení IJC-DU2, příklad 2), 21.3.2019 
// Autor: Serhii Salatskyi, FIT 
// Přeloženo: gcc 7.3
// Strucny popis: vytvari a inicializuje nové tabulky přesunem dat z tabulky from
// from nakonec zůstane prázdná a alokovaná

#include "htab_create.h"

htab_t *htab_move(size_t n, htab_t *from){
    /* create new hashtable */
    htab_t *new_htab = htab_init(n);
    if (new_htab == NULL)
	    return NULL;

    /* Iterate through the old hashtable. */
    for(htab_iterator_t iter = htab_begin(from); !htab_iterator_equal(iter, htab_end(from)); htab_iterator_next(iter)){
	    htab_iterator_t new_iter = htab_lookup_add(new_htab, htab_iterator_get_key(iter));
        if (htab_iterator_equal(new_iter, htab_end(new_htab))) {
	        /* Insert failed. Destroy new hashtable and return. */
	        htab_free(new_htab);
	        return NULL;
	    }
    }

    /* Destroy the old hashtable. */
    htab_clear(from);

    return new_htab;
}
