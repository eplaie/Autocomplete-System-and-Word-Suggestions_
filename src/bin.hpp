#ifndef bin_hpp
#define bin_hpp
#include <string.h>
#include <string>
#include <iostream>
#include "huff.hpp"

using namespace std;

typedef struct binaria binaria;
typedef struct Item Item;
typedef struct vetor vetor;

struct vetor {
        char *palavra;
};

struct Item {
        int freq;
        char *palavra;
        vetor* palavras;
        int cont;

};
struct binaria {
        Item item;

        binaria *esq;
        binaria *dir;
};

binaria *Retornobinaria();
void Inserirbinaria(binaria **bin, Item item);
void preOrdemBinaria(binaria *bin);
void Imprimir(binaria *no);
void Huff_bt(binaria *no, unordered_map<string, string> codigos);

#endif
