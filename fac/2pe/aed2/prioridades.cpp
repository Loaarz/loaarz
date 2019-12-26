#include <iostream>
using namespace std;

//estruturas

struct item{
    int chave, idade;
    string nome;
    bool gravidez;
    
};

struct celula{
    celula *anterior, *proximo;
    item i;
};

struct lista{
    celula *primeiro;
    celula *ultimo;
    celula *ultimopri;
};

void listavazia(lista &l){
    l.primeiro = new celula;
    l.ultimo = l.primeiro;
    l.ultimopri = l.primeiro;
    l.primeiro->anterior = NULL;
    l.primeiro->proximo = NULL;
}

void inserir(lista &l, item i){
    if(i.idade < 60 && i.gravidez == false){
        l.ultimo->proximo = new celula;
        l.ultimo->proximo->anterior = l.ultimo;
        l.ultimo->i = i;
        l.ultimo->proximo = NULL;
    }else{
        l.ultimopri->anterior = new celula;
        l.ultimopri->anterior->proximo = l.ultimopri;
        l.ultimopri->i = i;
        l.ultimopri->anterior = NULL;
    }
}

void mostrar(lista l){
    celula *aux;
    aux = l.primeiro->proximo;
    while(aux != NULL){
        cout << "Chave: " << endl;
        cout << "Nome: " << endl;
        aux = aux->proximo;
    }  
}

int main(){
	cout << "Merdaaa";
    lista l;
    item i;
    cin >> i;
    listavazia(l);
    i.chave = 1;
    i.idade = 45;
    i.nome = "JOSÈ";
    i.gravidez = false;
    inserir(l,i);
    inserir(l,i);
    mostrar(l);
    return 0;
}
