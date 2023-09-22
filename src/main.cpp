#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include "bin.hpp"  // Certifique-se de incluir os headers corretos para suas estruturas
#include "avl.hpp"
#include "huff.hpp"
#include "heap.hpp"
#include "hash.hpp"

using namespace std;

#define MAX_TOP_WORDS 5

bool NoTexto(const string &texto, const string &palavra) {
    istringstream separador(texto);
    string palavra_notxt;

    while (separador >> palavra_notxt) {
        if (palavra == palavra_notxt) {
            return true;
        }
    }

    return false;
}

int main() {

    // Redireciona a saída padrão para o arquivo 'output.txt'
    freopen("./dataset/output.txt", "w", stdout);

    vector<string> nome_txt = { "filosofia.txt", "filosofia2.txt", "globalizacao.txt", "politica.txt", "ti.txt", "ti2.txt" };
    vector<pair<string, string>> par_txt;

    unordered_set<string> stopwords = StopWordExtractor("./dataset/stopwords.txt");
    for (auto &item : nome_txt) {
        string prefixo("./dataset/");
        string caminho = prefixo + item;
        string texto = "";

        texto = TextCollector(caminho);

        string texto_tratado = "";

        texto_tratado = TextAnalyzer(texto);

        string texto_semSW = "";

        texto_semSW = stopWordCleaner(texto_tratado, stopwords);

        par_txt.push_back(make_pair(item, texto_semSW));
    }

    fstream arquivo("./dataset/input.txt");

    if (arquivo.is_open()) {
        string palavra_pesq = "";

        while (arquivo >> palavra_pesq) {
            for (auto &par : par_txt) {
                if (NoTexto(par.second, palavra_pesq)) {
                    unordered_map<string, int> frequencia = occurrenceCounter(par.second);

                    int freq_encontrada = 0;

                    if (frequencia.find(palavra_pesq) != frequencia.end()) {
                        freq_encontrada = frequencia[palavra_pesq];
                    }

                    HeapMAX Heap;

                    for (const auto &item : frequencia) {
                        Heap.inserir(DataPair(item.first, item.second));
                    }

                    binaria *bin = Retornobinaria();
                    Tree *AVL = CreateTree();

                    for (int i = 0; i < MAX_TOP_WORDS && !Heap.Vazia(); i++) {
                        DataPair top = Heap.PesquisaMAX();
                        Item item;
                        item.freq = top.freq;
                        item.palavra = (char *)malloc(top.palavra.size() + 1);
                        strcpy(item.palavra, top.palavra.c_str());

                        Record rec;
                        rec.key = top.freq;
                        rec.palavra = (char*)malloc(top.palavra.size() + 1);
                        strcpy(rec.palavra, top.palavra.c_str());

                        Inserirbinaria(&bin, item);
                        insertTree(&AVL, rec);
                    }
                    cout << endl;
                    cout <<"********************************************************************************************************"<< endl;
                    cout << endl;
                    cout << "A palavra " << palavra_pesq << " foi encontrada no arquivo " << par.first << " com frequencia " << freq_encontrada << endl;
                    cout << endl;
                    cout <<"--------------------------------------------------------------------------------------------------------"<< endl;
                    cout <<"Binaria"<< endl;
                    preOrdemBinaria(bin);
                    cout <<"--------------------------------------------------------------------------------------------------------"<< endl;
                    cout << endl;

                    cout <<"--------------------------------------------------------------------------------------------------------"<< endl;
                    cout <<"AVL"<< endl;
                    preordem(AVL);
                    cout << endl;
                    cout <<"--------------------------------------------------------------------------------------------------------"<< endl;
                    cout << endl;

                    NoHuffmann *raiz = ConstruirArvore(frequencia);
                    cout << endl;

                    unordered_map<string, string> codigos;
                    gerarCodigosHuffman(raiz, "", codigos);

                    cout <<"--------------------------------------------------------------------------------------------------------"<< endl;
                    cout <<"Huffmann"<< endl;
                    Huff_bt(bin, codigos);
                    cout <<"--------------------------------------------------------------------------------------------------------"<< endl;
                    Heap.clean(Heap);
                    frequencia.clear();
                }
            }
        }

        arquivo.close();
    }

    // Fecha o arquivo 'output.txt' e retorna a saída para o terminal
    fclose(stdout);

    return 0;
}
