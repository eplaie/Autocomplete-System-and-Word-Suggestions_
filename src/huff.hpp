#ifndef huff_hpp
#define huff_hpp

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

struct NoHuffmann
{
    string palavra;
    int frequencia;

    NoHuffmann* esq;
    NoHuffmann* dir;

    NoHuffmann(string p, int f) : palavra(p), frequencia(f), esq(nullptr), dir(nullptr) {}
};

struct Compara_NO {
    bool operator()(NoHuffmann* a, NoHuffmann* b){
        return a->frequencia > b->frequencia;
    }
};


NoHuffmann* ConstruirArvore(unordered_map<string, int>& frequencia);
void gerarCodigosHuffman(NoHuffmann* raiz, string codigo, unordered_map<string, string>& codigos);
string Codificar(const string& palavra, unordered_map<string, string>& codigos);
void preHuffmann(NoHuffmann *NoHuffmann);

#endif