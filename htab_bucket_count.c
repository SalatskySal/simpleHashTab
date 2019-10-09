// htab_bucket_count.c
// Řešení IJC-DU2, příklad 2), 21.3.2019 
// Autor: Serhii Salatskyi, FIT 
// Přeloženo: gcc 7.3
// Strucny popis: vraci pocet polozek v tabulce

#include "htab_create.h"

size_t htab_bucket_count(const htab_t *t){
    return t->arr_size;
}