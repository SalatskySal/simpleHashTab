// htab_free.c
// Řešení IJC-DU2, příklad 2), 21.3.2019 
// Autor: Serhii Salatskyi, FIT 
// Přeloženo: gcc 7.3
// Strucny popis: zrušení tabulky t (volá htab_clear())

#include "htab_create.h"

void htab_free(htab_t * t){
	htab_clear(t);
	free(t);
	
	return;	
}
