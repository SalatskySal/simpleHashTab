// wordcount.c
// Řešení IJC-DU2, příklad 1.a), 21.3.2019 
// Autor: Serhii Salatskyi, FIT 
// Přeloženo: gcc 7.3
// Strucny popis: pocita pocet slov ve souboru nebo na stdin

#include "htab.h"
#include <stdlib.h>
#include "io.h"

#define MAX 127
int main(){
	htab_t *table = htab_init(10000);
	char* str = (char*)calloc(MAX+1, 1);

	while(get_word(str, MAX, stdin) != EOF){
		if(!strcmp(str, "")){
			continue;
		}
		htab_iterator_t iterator = htab_lookup_add(table, str);
		if(htab_iterator_equal(iterator, htab_end(table))){
				htab_free(table);
				exit(-1);
		}

		htab_iterator_set_value(iterator, htab_iterator_get_value(iterator)+1);
	}

	for(htab_iterator_t iter = htab_begin(table); !htab_iterator_equal(iter, htab_end(table)); iter = htab_iterator_next(iter)){
		printf("%s\t%d\n", htab_iterator_get_key(iter), htab_iterator_get_value(iter));
	}

	free(str);
	htab_free(table);
}
