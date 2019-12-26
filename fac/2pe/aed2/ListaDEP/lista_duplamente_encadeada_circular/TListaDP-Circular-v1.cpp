/* PARA CASA:

    Exercício.
    - IMPLEMENTE UMA LISTA CIRCULAR ENCADEADA (APENAS 1 SENTIDO)
    - DEMONSTRE SUA UTILIZAÇÃO PARA TODAS AS OPERAÇÕES BÁSICAS
    - CRIE, PELO MENOS, 1 OPERAÇÃO SUA QUE TENHA SENTIDO NESSE CONTEXTO!
*/

#include <iostream>
#include <clocale>
using namespace std;

// ESTRUTURAS
struct TItem{
    int chave;
    // ...
};

struct TCelula{
    TItem item;
    TCelula *proximo;
};

struct TListaDP{
    TCelula *primeiro;
    TCelula *ultimo;
};


// OPERAÇÕES BÁSICAS

void criarListaPVazia(TListaDP &lp){
    lp.primeiro = new TCelula;
    lp.ultimo = lp.primeiro;
    lp.primeiro->proximo = lp.ultimo;
    lp.ultimo->proximo = lp.primeiro;
}

void inserir(TListaDP &lp, TItem x){
    cout << "entrou no inserir"<<endl;
    TCelula *a;
    a->item = x;
    lp.primeiro->proximo = a;
    a->proximo = lp.primeiro;
    cout << "saiu do inserir"<<endl;
}
//
void mostrarED(TListaDP lp){
    TCelula *celAux;
    celAux = lp.primeiro->proximo;

    cout << "=== MOSTRANDO A LISTA DA ESQ->DIR === "<< endl;
    while (celAux != lp.primeiro){
        cout << "E.M.Cel: " << celAux << "   -   Valor: " << celAux->item.chave << endl;
        celAux = celAux->proximo;
    }
}

//
//TCelula *pegaAnterior(TListaP lp, int chave){
//    TCelula *celAux;
//    bool achou = false;
//
//    celAux = lp.primeiro;   //não começamos pela célula válida, e sim
//                            // pela cabeça
//
//    cout << "=== PROCURANDO ITEM NA LISTA === "<< endl;
//    while (celAux->proximo != NULL){
//        if (celAux->proximo->item == chave){
//            achou = true;
//            return celAux;
//        }
//        celAux = celAux->proximo;
//    }
//    if (achou == false){
//        return NULL;
//    }
//}
//
//void retirarPorChave(TListaP &lp, int chave){
//    TCelula *p = pegaAnterior(lp,chave); //anterior
//    TCelula *q; //alvo
//
//    q = p->proximo;
//    p->proximo = q->proximo;
//    cout << "EM Excluído: " << q << endl;
//    delete(q);
//}

int main(){

    setlocale(LC_ALL,"Portuguese");

    TListaDP lista; // instanciação

    //preparando a lista para uso!
    criarListaPVazia(lista);

    cout << "EM cel Prim:  " << lista.primeiro << endl;
    cout << "EM cel Ulti:  " << lista.ultimo << endl;
    // se eu quiser mostrar as de baixo, tenho que apontar lá na criar!
    // mas isso não se justifica!
    // ISTO NOM ECSISTE!!!
//    cout << "Ant de Prim:  " << lista.primeiro->anterior << endl;
//    cout << "Prox de Prim: " << lista.primeiro->proximo << endl;
//    cout << "Ant de Ult:   " << lista.ultimo->anterior << endl;
//    cout << "Prox Ultimo:  " << lista.ultimo->proximo << endl;

    TItem iAux;
    iAux.chave = 5;
    inserir(lista,iAux);

    iAux.chave = 7;
    inserir(lista,iAux);

    iAux.chave = 4;
    inserir(lista,iAux);
//
    mostrarED(lista);

//    inserir(lista,72);
//    inserir(lista,9);
//    inserir(lista,14);
//    inserir(lista,5);
//    inserir(lista,23);
//
//    mostrar(lista);
//
//    cout << "E.M.Ant: " << pegaAnterior(lista,23) << endl;
//
//    retirarPorChave(lista,23);
//
//    mostrar(lista);
    return 0;
}
