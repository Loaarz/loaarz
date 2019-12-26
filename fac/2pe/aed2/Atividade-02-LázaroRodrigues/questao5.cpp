#include <iostream>
#include <clocale>
#include <stdlib.h>
using namespace std;

const int maxTam = 5;
struct TConta{
    int numero;
    string tipo;
    double saldo;
};

struct TCliente{
    string cpf;
    string nome;
    int idade;
    TConta conta;
};

struct TlistaA{
    TCliente clientes[maxTam];
    int primeiro;
    int ultimo;
    int qtdItens;
};

void criarListaLAVazia(TlistaA &l){
    l.primeiro = 0;
    l.ultimo = l.primeiro;
    l.qtdItens = 0;
}

bool estaVaziaLA(TlistaA l){
    return l.primeiro == l.ultimo;
}

bool estaCheiaLA(TlistaA l){
    return l.ultimo >= maxTam;
}

void inserirLA(TlistaA &l, TCliente cli){
    if(estaCheiaLA(l)){
        cout << "A lista est� cheia!!"<<endl;
    }else{
        l.clientes[l.ultimo] = cli;
        l.ultimo++;
        l.qtdItens++;
    }
}

void mostrarLA(TlistaA l){
    cout << "==== MOSTRANDO DADOS DOS CLIENTES ===="<<endl;
    for(int i=l.primeiro; i<l.ultimo; i++){
        cout << "Cliente " << i+1 << ": "<<endl;
        cout<< "Nome: " <<  l.clientes[i].nome<<endl;
        cout<< "Cpf: " <<  l.clientes[i].cpf<<endl;
        cout<< "Idade: " <<  l.clientes[i].idade<<endl;
        cout<< "Numero da conta: " <<  l.clientes[i].conta.numero<<endl;
        cout<< "Tipo da conta: " <<  l.clientes[i].conta.tipo<<endl;
        cout<< "Saldo da conta: " <<  l.clientes[i].conta.saldo<<endl;
    }
}
void mostrarSaldoTotal(TlistaA l){
    double STotal;
    cout << "==== MOSTRANDO Saldo do Banco ===="<<endl;
    for(int i=l.primeiro; i<l.ultimo; i++){
        STotal+= l.clientes[i].conta.saldo;
    }
    cout << STotal<<endl;
}

struct TCelula{
    TCelula *proximo;
    TCliente cliente;
};

struct TFilaP{
    TCelula *frente;
    TCelula *tras;
    int qtdItens;
};

void criaFilaVaziaP(TFilaP &f){
    f.frente = new TCelula;
    f.tras = f.frente;
    f.frente->proximo = NULL;
    f.qtdItens = 0;
}

void enfileirar(TFilaP &f, TCliente cli){
    f.tras->proximo = new TCelula;
    f.tras = f.tras->proximo;
    f.tras->cliente = cli;
    f.tras->proximo = NULL;
    f.qtdItens++;
}
bool estaVaziaF(TFilaP f){
    return f.frente == f.tras;
}
void desenfileirar(TFilaP &f){
    if (estaVaziaF(f)){
        cout << "Fila Vazia! Nenhum elemento para desenfileirar..." << endl;
    }
    else{
        TCelula *aux = f.frente;
        cout << "Desenfilerei o item de chave: " << aux->proximo->cliente.nome << endl;
        f.frente = f.frente->proximo;
        delete(aux);
        f.qtdItens--;
    }
}
void mostrarFilaP(TFilaP f){
    if(estaVaziaF(f)){
        cout << "LISTA VAZIA!"<<endl;
    }else{
        cout << "==== MOSTRANDO A FILA ===="<<endl;
        TCelula *Aux;
        Aux = f.frente->proximo;
        while(Aux != NULL){
            cout << Aux->cliente.nome<<endl;;
            Aux = Aux->proximo;
        }
    }
}

struct TPilha{
    TCelula *topo;
    TCelula *fundo;
    int qtdItens;
};

void criaPilhaVazia(TPilha &p){
   p.topo = new TCelula;
   p.fundo = p.topo;
   p.fundo->proximo = NULL;
   p.qtdItens = 0;
}

void empilhar(TPilha &p, TCliente cli){
    TCelula *aux = new TCelula;
    p.topo->cliente= cli;
    aux->proximo = p.topo;
    p.topo = aux;
    p.qtdItens++;
}

bool estaVaziaP(TPilha p){
    return p.fundo == p.topo;
}

void mostrarPilha(TPilha p){
    if(estaVaziaP(p)){
        cout<<"PILHA VAZIA!"<<endl;
    }else{
        TCelula *Aux;
        Aux = p.topo;
        cout<<"==== MOSTRANDO A PILHA ===="<<endl;
        while(Aux != NULL){
            cout <<Aux->cliente.nome<<endl;
            Aux = Aux->proximo;
        }
    }
}

void inserirAleatorio(TlistaA l, TFilaP &f){
    int num;
    for(int i=0; i<5; i++){
        num= (rand()%5);
        enfileirar(f,l.clientes[num]);

    }
}

void atendimento(TFilaP &f, TPilha &p){
    TCelula *Aux;
    Aux = f.frente->proximo;
    while(Aux != NULL){
        empilhar(p,Aux->cliente);
        Aux = Aux->proximo;
        desenfileirar(f);
    }
}
int main(){
    setlocale(LC_ALL,"Portuguese");
    TCliente cliente;
    TlistaA lista;
    criarListaLAVazia(lista);
    TFilaP fila;
    criaFilaVaziaP(fila);
    TPilha pilha;
    criaPilhaVazia(pilha);

    cliente.nome = "jorge";
    cliente.cpf= "1063418564";
    cliente.idade = 19;
    cliente.conta.numero = 123456;
    cliente.conta.saldo = 4000;
    cliente.conta.tipo = "p";
    inserirLA(lista, cliente);

    cliente.nome = "joao";
    cliente.cpf= "1063418564";
    cliente.idade = 19;
    cliente.conta.numero = 123456;
    cliente.conta.saldo = 4000;
    cliente.conta.tipo = "p";
    inserirLA(lista, cliente);

    cliente.nome = "maria";
    cliente.cpf= "1063418564";
    cliente.idade = 19;
    cliente.conta.numero = 123456;
    cliente.conta.saldo = 4000;
    cliente.conta.tipo = "p";
    inserirLA(lista, cliente);

    cliente.nome = "jose";
    cliente.cpf= "1063418564";
    cliente.idade = 19;
    cliente.conta.numero = 123456;
    cliente.conta.saldo = 4000;
    cliente.conta.tipo = "p";
    inserirLA(lista, cliente);

    cliente.nome = "abelah";
    cliente.cpf= "1063418564";
    cliente.idade = 19;
    cliente.conta.numero = 123456;
    cliente.conta.saldo = 4000;
    cliente.conta.tipo = "p";
    inserirLA(lista, cliente);

    mostrarLA(lista);
    mostrarSaldoTotal(lista);
    inserirAleatorio(lista,fila);
    mostrarFilaP(fila);
    atendimento(fila,pilha);
    mostrarLA(lista);
    mostrarPilha(pilha);
    mostrarFilaP(fila);

return 0;
}
