// tail.c
// Řešení IJC-DU2, příklad 1.a), 21.3.2019 
// Autor: Serhii Salatskyi, FIT 
// Přeloženo: gcc 7.3
// Strucny popis: implementace GNU prikazu tail v jazyce C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1023

void tailprint(FILE* in, int n) 
{ 
    int count = 0;  // To count '\n' characters  
    int limit = 0;  
    int c;

    while ((c = fgetc(in)) != EOF){
            if(limit <= MAX && count >= n-1)
                printf("%c", c);
            if(c == '\n'){
                limit = 0;   
                count++;
            }
            limit++;
    }
}

void tail(FILE* in, int n) 
{ 
    int count = 0;  // To count '\n' characters
    unsigned long long pos; 
  
    // Go to End of file 
    if (fseek(in, 0, SEEK_END)) 
        perror("fseek() failed"); 
    else{ 
        pos = ftell(in); 
  
        // search for '\n' characters 
        while (pos) 
        { 
            // Move 'pos' away from end of file. 
            if (!fseek(in, --pos, SEEK_SET)) 
            { 
                if (fgetc(in) == '\n') 
  
                    // stop reading when n newlines 
                    // is found 
                    if (count++ == n) 
                        break; 
            } 
            else
                perror("fseek() failed"); 
        } 
        tailprint(in, 0);  
    }
}

int main(int argc, char **argv){
    FILE *file = NULL;
    int count = 0;
    char* mod;
    
    switch(argc){
        case 2:
            if((file = fopen(argv[1], "r")) == NULL)
                fprintf(stderr, "Program cannot read file\n"), exit(1);

            tail(file, 10);
            break;
        case 4: 
            if(strcmp(argv[1], "-n"))
                fprintf(stderr, "Invalid parameter of program: %s\n", argv[1]), exit(1);

            count = strtol(argv[2], &mod, 10);
            if(*mod)
                fprintf(stderr, "Invalid number of lines: %s\n", argv[2]), exit(1);

            if((file = fopen(argv[3], "r")) == NULL)
                fprintf(stderr, "Program cannot read file %s\n", argv[3]), exit(1);
            
            (argv[2][0] == '+') ? tailprint(file, count):tail(file, (count<0) ? -count:count);
            
            break;
        default:
            fprintf(stderr, "Incorrect count of arguments\n"), exit(1);
            break;
    }

}