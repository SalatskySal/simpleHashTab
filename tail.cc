// tail.cc
// Řešení IJC-DU2, příklad 1.b), 21.3.2019 
// Autor: Serhii Salatskyi, FIT 
// Přeloženo: g++ 7.3
// Strucny popis: implementace GNU prikazu tail v jazyce C++

#include <iostream>
#include <fstream>
#include <queue>
#include <string>

void tail(std::ifstream& fin, int count){
    std::queue<std::string> turn;
    
    while(!fin.eof()){
        std::string input;
        std::getline(fin, input);
        if(input.length()){
            turn.push(input);
            if((int)turn.size() > count){
                turn.pop();
            }
        }
    }

    for(int i = 0; i < count; i++){
            std::cout << turn.front()<<std::endl;
            turn.pop();
    }
}

void tailplus(std::ifstream& fin, int count){
    int iter = 0; 
    while(!fin.eof()){
        std::string input;
        std::getline(fin, input);
        if (iter++ < count-1)
            continue;

        if(input.length())
            std::cout << input << std::endl;
    }
}

int main(int argc, char **argv){
    std::ios::sync_with_stdio(false);
    
    std::string arg_1 = "-n";
    std::ifstream fin; 
    int count = 10;

    switch(argc){
            case 2:
                fin.open(argv[1], std::fstream::in);
                tail(fin, count);
                break;
            case 4:
                if(arg_1.compare(argv[1])){
                    std::cerr << "Incorrect argument " << argv[1] << std::endl, exit(-1); 
                }

                char* mod;
                count = strtol(argv[2], &mod, 10);
                if(*mod)
                    std::cerr << "Invalid number of lines: " << argv[2] << std::endl, exit(1);

                fin.open(argv[3], std::fstream::in);

                (argv[2][0] == '+') ? tailplus(fin, count):tail(fin, (count<0) ? -count:count); 
                break;
            default:
                std::cerr << "Incorrect count of arguments: " << argc << std::endl; 
    }      

    fin.close();
    return 0;
}