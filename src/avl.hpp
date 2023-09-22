#ifndef avl_hpp
#define avl_hpp

#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <iostream>
#include "huff.hpp"

using namespace std;

typedef struct Record Record;
typedef struct Tree Tree;
typedef struct vetor_avl vetor_avl;

struct vetor_avl {
    char *palavra;
};

struct Record {
    int key;
    char *palavra;
    vetor_avl *palavras;
    int cont;
    int value;

};

struct Tree {
    Record reg;
    Tree *left, *right;
    int weight;
};

Tree *CreateTree();
void insertTree(Tree **t, Record r);
void pesquisa(Tree **t, Tree **aux, Record r);
int isInTree(Tree *t, Record r);

void removeTree(Tree **t, Tree **f, Record r);
void antecessor(Tree **t, Tree *aux);
void rebalanceTree(Tree **t);

void preordem(Tree *t);

int getWeight(Tree **t);
int getMaxWeight(int left, int right);


void rotacaoSimplesDireita(Tree **t);
void rotacaoSimplesEsquerda(Tree **t);
void rotacaoDuplaDireita(Tree **t);
void rotacaoDuplaEsquerda(Tree **t);

// void Huff_AVL(No_AVL *no, unordered_map<char, string> codigos);


#endif
