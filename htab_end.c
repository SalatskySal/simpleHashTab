// htab_end.c
// Řešení IJC-DU2, příklad 2), 21.3.2019 
// Autor: Serhii Salatskyi, FIT 
// Přeloženo: gcc 7.3
// Strucny popis: vraci iterátor označující (neexistující) první záznam za koncem

#include "htab_create.h"

htab_iterator_t htab_end(const htab_t *t){
	htab_iterator_t end_iter = {.t = t, .ptr = NULL, .idx = htab_size(t)};
	return end_iter;
}
