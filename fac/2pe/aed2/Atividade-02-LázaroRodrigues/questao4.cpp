#include <iostream>
#include <clocale>
using namespace std;

const int maxTam = 3;

struct TProduto{
    int codigo;
    string nome;
    double preco;
    int qtdEstoque;
};

struct TCelula{
    TProduto produto;
    TCelula *proximo;
};

struct TListaP{
    TCelula *primeiro;
    TCelula *ultimo;
    int contItens;
};

void criarListaPVazia(TListaP &lp){
    lp.primeiro = new TCelula;
    lp.ultimo = lp.primeiro;
    lp.primeiro->proximo = NULL;
    lp.contItens = 0;
}

bool estaVaziaLP(TListaP lp){
    return lp.primeiro == lp.ultimo;
}
bool estaCheiaLP(TListaP lp){
    return lp.contItens >= maxTam;
}
void inserir(TListaP &lp, TProduto x){
    if(!estaCheiaLP(lp)){
        lp.ultimo->proximo = new TCelula;
        lp.ultimo = lp.ultimo->proximo;
        lp.ultimo->produto = x;
        lp.ultimo->proximo = NULL;
        lp.contItens++;
    }else{
        cout << "Lista cheia!"<<endl;
    }
}

void mostrar(TListaP lp){
    if (estaVaziaLP(lp)){
        cout << "Lista vazia! Nenhum elemento para mostrar!" << endl;

    }
    else{
        TCelula *celAux;
        celAux = lp.primeiro->proximo;
        cout << "=== MOSTRANDO A LISTA === "<< endl;
        while (celAux != NULL){
            cout << "E.M.Cel: " << celAux << "   -   Valor: " << celAux->produto.nome << endl;
            celAux = celAux->proximo;
        }
    }
}

TCelula *pegaAnterior(TListaP lp, int chave){
    TCelula *celAux;
    bool achou = false;
    int i=1;
    celAux = lp.primeiro;
    cout << "=== PROCURANDO ITEM NA LISTA === "<< endl;
    while (celAux->proximo != NULL){
        if (i == chave){
            achou = true;
            cout << "E.M.Cel: " << celAux << "   -   Valor: " << celAux->produto.nome << endl;
        }
        celAux = celAux->proximo;
        i++;
    }
    if (achou == false){
        return NULL;
    }
}
void buscarPorCodigo(TListaP lp, int codigo){
    int i;
    i=0;
    if(estaVaziaLP(lp)){
        cout << "Lista Vazia!!"<<endl;
    }else{
        TCelula *Aux;
        Aux = lp.primeiro->proximo;
        while(Aux != NULL){
            if(Aux->produto.codigo == codigo){
                cout<<"O produto encontra-se na posi��o: " << i+1 << endl;
            }
            i++;
            Aux=Aux->proximo;
        }
    }
}
void mostraEstoqueBaixo(TListaP l){
    TCelula *Aux;
    Aux= l.primeiro->proximo;
    cout<<" === PRODUTOS COM ESTOQUE BAIXO === "<<endl;
    while(Aux != NULL){
        if(Aux->produto.qtdEstoque < 5){
            cout<<Aux->produto.nome<< endl;
        }
        Aux=Aux->proximo;
    }
}
void ProdMaisCaro(TListaP l){
    TCelula *Aux;
    Aux= l.primeiro->proximo;
    double maior=0;
    string maisCaro;
    while(Aux != NULL){
        if(Aux->produto.preco > maior){
            maior = Aux->produto.preco;
            maisCaro = Aux->produto.nome;
        }
        Aux=Aux->proximo;
    }
    cout << "Produto mais caro: "<< maisCaro<<endl;
}

void ProdMaisBarato(TListaP l){
    TCelula *Aux;
    Aux= l.primeiro->proximo;
    double menor = 9999999;
    string maisBarato;
    while(Aux != NULL){
        if(Aux->produto.preco < menor){
            menor = Aux->produto.preco;
            maisBarato = Aux->produto.nome;
        }
        Aux=Aux->proximo;
    }
    cout << "Produto mais barato: "<< maisBarato<<endl;
}

void retirarPorChave(TListaP &lp, int chave){
    TCelula *p = pegaAnterior(lp,chave);
    TCelula *q;

    if(p == NULL){
        cout << "Chave n�o encontrada!!!" << endl;
    }else{
        q = p->proximo;
        p->proximo = q->proximo;
        cout << "EM Exclu�do: " << q << endl;
        delete(q);
    }
}

int main(){

    setlocale(LC_ALL,"Portuguese");

    TListaP lista;
    criarListaPVazia(lista);

    TProduto prodAux;
    prodAux.codigo = 1;
    prodAux.qtdEstoque = 5;
    prodAux.nome = "feijao";
    prodAux.preco = 5;
    inserir(lista,prodAux);

    prodAux.codigo = 3;
    prodAux.nome = "arroz";
    prodAux.qtdEstoque = 3;
    prodAux.preco = 10;
    inserir(lista,prodAux);

    prodAux.codigo = 5;
    prodAux.nome = "batata";
    prodAux.qtdEstoque = 2;
    prodAux.preco = 2;
    inserir(lista,prodAux);

    mostrar(lista);
    buscarPorCodigo(lista, 5);
    pegaAnterior(lista, 3);
    mostraEstoqueBaixo(lista);
    ProdMaisCaro(lista);
    ProdMaisBarato(lista);

    return 0;
}
