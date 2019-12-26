#include <iostream>
#include <clocale>
using namespace std;

struct TDuracao{
    int minutos;
    int segundos;
};
struct TMusica{
    string titulo;
    string artista;
    TDuracao duracao;
};

struct TCelula{
    TCelula *proximo;
    TMusica musica;
};

struct TLista{
    TCelula *primeiro;
    TCelula *ultimo;
    int contItens;
};

void crialistaVaziaLP(TLista &lp){
    lp.primeiro = new TCelula;
    lp.ultimo = lp.primeiro;
    lp.primeiro->proximo=NULL;
    lp.contItens=0;
}

bool estavaziaLP(TLista lp){
    return lp.primeiro == lp.ultimo;
}

void inserirLP(TLista &lp, TMusica x){
    lp.ultimo->proximo = new TCelula;
    lp.ultimo = lp.ultimo->proximo;
    lp.ultimo->musica = x;
    lp.ultimo->proximo = NULL;
    lp.contItens++;
}

void mostrarLP(TLista lp){
    if(estavaziaLP(lp)){
        cout << "A lista est� vazia!!";
    }else{
        TCelula *aux;
        aux= lp.primeiro->proximo;
        cout << "Mostrando Musicas: "<<endl;
        while(aux != NULL){
            cout << "Artista: " << aux->musica.artista<<endl;
            cout << "Dura��o: " << aux->musica.duracao.minutos << ":" << aux->musica.duracao.segundos<<endl;
            cout << "Titulo: " << aux->musica.titulo<<endl;
            aux= aux->proximo;
            cout<<endl;
        }
    }
}
void buscarPorChave(TLista lp, string chave){
    if(estavaziaLP(lp)){
        cout<<"Lista vazia!!"<<endl;
    }else{
        TCelula *CelAux;
        CelAux = lp.primeiro->proximo;
        cout<<"===== BUSCANDO MUSICA ====="<<endl;
        while(CelAux != NULL){
            if(CelAux->musica.titulo == chave){
                cout << "Artista: " << CelAux->musica.artista << endl;
                cout << "Dura��o: " << CelAux->musica.duracao.minutos << ":"<< CelAux->musica.duracao.segundos<<endl;
                cout << "Titulo: " << CelAux->musica.titulo<<endl;
            }
            CelAux = CelAux->proximo;
        }
    }
}

void buscarPorArtista(TLista lp, string art){
    if(estavaziaLP(lp)){
        cout << "Lista Vazia!!"<<endl;
    }else{
        TCelula *CelAux;
        CelAux = lp.primeiro->proximo;
        cout<<"=====  COLE��O DE MUSICAS ====="<<endl;
        while(CelAux != NULL){
            if(CelAux->musica.artista == art){
                cout << CelAux->musica.titulo<<endl;
            }
            CelAux = CelAux->proximo;
        }

    }

}

struct TFilaP{
    TCelula *frente;
    TCelula *tras;
    int contItens;
};
void criarFilaPVazia(TFilaP &f){
   f.frente = new TCelula;
   f.tras = f.frente;
   f.frente->proximo = NULL;
   f.contItens = 0;
}
bool estaVaziaF(TFilaP f){
    return f.frente == f.tras;
}

void enfileirar(TFilaP &f, TMusica x){
    f.tras->proximo = new TCelula;
    f.tras = f.tras->proximo;
    f.tras->musica = x;
    f.tras->proximo = NULL;
    f.contItens++;
}

void mostrar(TFilaP f){
    TCelula *celAux;
    celAux = f.frente->proximo;

    cout << "=== MOSTRANDO A FILA === "<< endl;
    if (estaVaziaF(f)){
        cout << "Fila vazia! Nenhum elemento para mostrar!" << endl;
    }
    else{
        while (celAux != NULL){
            cout << "E.M.Cel: " << celAux << "   -   Chave: " << celAux->musica.artista<< endl;
            celAux = celAux->proximo;
           Sleep(500);
        }
    }
}

void desenfileirar(TFilaP &f){
    if (estaVaziaF(f)){
        cout << "Fila Vazia! Nenhum elemento para desenfileirar..." << endl;
    }
    else{
        TCelula *aux = f.frente;
        f.frente = f.frente->proximo;
        delete(aux);
        f.contItens--;
    }
}

struct TPilha{
    TCelula *topo;
    TCelula *fundo;
    int contItens;
};

void criaPilhaVazia(TPilha &p){
   p.topo = new TCelula;
   p.fundo = p.topo;
   p.fundo->proximo = NULL;
   p.contItens = 0;
}
bool estaVaziaP(TPilha p){
    return p.topo == p.fundo;
}

void empilhar(TPilha &p, TMusica mus){
    TCelula *aux = new TCelula;
    p.topo->musica = mus;
    aux->proximo = p.topo;
    p.topo = aux;
    p.contItens++;
}

void mostrarPilha(TPilha p){
    TCelula *CelAux;
    CelAux = p.topo->proximo;
    cout<< "===== MOSTRANDO A PILHA ====="<<endl;
    while(CelAux != NULL){
        if(estaVaziaP(p)){
            cout<< "Pilha vazia!!"<<endl;
        }else{
            cout << "E.M.Cel: " << CelAux << "   -   Chave: " << CelAux->musica.titulo << endl;
            CelAux = CelAux->proximo;
        }
    }
}

void inserirFl(TFilaP &f, TLista lp, TPilha &p){
    TCelula *CelAux;
    char exec;
    int num,i,tam;
    tam=1;
    i=0;
    cout << "Executar lista(a para aleat�rio e s para sequ�ncia): ";
    cin >> exec;
    if(exec=='a'){
        while(tam <= lp.contItens){
            CelAux=lp.primeiro->proximo;
            num = (rand()% lp.contItens)+1;
            i=1;
            while(CelAux != NULL){
                if(i==num){
                    cout<<"igual";
                    enfileirar(f,CelAux->musica);
                    empilhar(p, f.tras->musica);
                    mostrar(f);
                    desenfileirar(f);
                }
                i++;
                CelAux= CelAux->proximo;
            }
            tam++;
        }
    }else{
        if(exec=='s'){
            CelAux=lp.primeiro->proximo;
            while(CelAux != NULL){
                enfileirar(f,CelAux->musica);
                CelAux = CelAux->proximo;
                empilhar(p, f.tras->musica);
                mostrar(f);
                desenfileirar(f);
            }
        }else{
            cout<< "Op��o inv�lida!!"<<endl;
        }
    }
}
void maiormenor(TLista l){
    int menor = 99999;
    int maior= 0;
    string musMaior, musMenor;
    TCelula *Aux;
    Aux = l.primeiro->proximo;
    while(Aux != NULL){
          if((Aux->musica.duracao.minutos) > maior){
                maior=Aux->musica.duracao.minutos;
                musMaior = Aux->musica.titulo;
          }
          if((Aux->musica.duracao.minutos) < menor){
            menor = Aux->musica.duracao.minutos;
            musMenor = Aux->musica.titulo;
          }

        Aux= Aux->proximo;
    }
    cout<< "Musica com maior dura��o: "<< endl;
    buscarPorChave(l, musMaior);
    cout<< endl;
    cout<< "Musica com menor dura��o: "<<endl;
    buscarPorChave(l, musMenor);
    cout<<endl;
}
int main(){
    setlocale(LC_ALL,"Portuguese");
    TLista lista;
    TMusica musica;
    TFilaP fila;
    TPilha pilha;
    crialistaVaziaLP(lista);
    criarFilaPVazia(fila);
    criaPilhaVazia(pilha);

    musica.artista="joao";
    musica.duracao.minutos=3;
    musica.duracao.segundos=2;
    musica.titulo="teste";
    inserirLP(lista, musica);

    musica.artista="jose";
    musica.duracao.minutos=3;
    musica.duracao.segundos=2;
    musica.titulo="xablau";
    inserirLP(lista, musica);

    musica.artista="jose";
    musica.duracao.minutos=3;
    musica.duracao.segundos=2;
    musica.titulo="xab";
    inserirLP(lista, musica);

    musica.artista="tiao";
    musica.duracao.minutos=1;
    musica.duracao.segundos=1;
    musica.titulo="xabz";
    inserirLP(lista, musica);

    musica.artista="jorge";
    musica.duracao.minutos=3;
    musica.duracao.segundos=2;
    musica.titulo="xab";
    inserirLP(lista, musica);

    mostrarLP(lista);
    buscarPorChave(lista, "teste");
    buscarPorArtista(lista, "jose");

    inserirFl(fila,lista,pilha);
    mostrarPilha(pilha);
    mostrar(fila);
    maiormenor(lista);
    return 0;
}
