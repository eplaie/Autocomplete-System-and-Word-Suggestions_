#include "bin.hpp"

binaria *Retornobinaria() {
    return NULL;
}
void Inserirbinaria(binaria **bin, Item item) {
    if (*bin == NULL) {
        (*bin) = (binaria *)malloc(sizeof(binaria));
        (*bin)->esq = NULL;
        (*bin)->dir = NULL;
        (*bin)->item.freq = item.freq;
        (*bin)->item.palavra = (char *)malloc(sizeof(item.palavra));
        (*bin)->item.palavras = (vetor *)malloc(sizeof(vetor) * 20);
        (*bin)->item.cont = 0;
        strcpy((*bin)->item.palavra, item.palavra);
    } else {
        if (item.freq < (*bin)->item.freq) {
            Inserirbinaria(&(*bin)->esq, item);

        } else if (item.freq > (*bin)->item.freq) {
            Inserirbinaria(&(*bin)->dir, item);
        } else if (item.freq == (*bin)->item.freq) {
            (*bin)->item.palavras[(*bin)->item.cont].palavra = (char *)malloc(sizeof(char) * strlen(item.palavra));
            strcpy((*bin)->item.palavras[(*bin)->item.cont].palavra, item.palavra);
            (*bin)->item.cont++;
        }
    }
}

void preOrdemBinaria(binaria *bin) {
    if (bin != NULL) {
        printf("%d %s\n", bin->item.freq, bin->item.palavra);
        for (int i = 0; i < bin->item.cont; i++) {
            cout << bin->item.freq << " " << bin->item.palavras[i].palavra << endl;
        }
        preOrdemBinaria(bin->esq);
        preOrdemBinaria(bin->dir);
    }

}

void Huff_bt(binaria *no, unordered_map<string, string> codigos){
    if (no == nullptr) {
        return;
    }

    string palavra(no->item.palavra);

    string codigo = Codificar(palavra, codigos);

    cout << palavra << " : " << codigo << endl;

    Huff_bt(no->esq, codigos);
    Huff_bt(no->dir, codigos);
}