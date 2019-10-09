// htab.c
// Řešení IJC-DU2, příklad 2), 21.3.2019 
// Autor: Serhii Salatskyi, FIT 
// Přeloženo: gcc 7.3
// Strucny popis: definuje externi definice inline funkce pro -O0

#include "htab.h"

extern bool htab_iterator_valid(htab_iterator_t it);
extern bool htab_iterator_equal(htab_iterator_t it1, htab_iterator_t it2);