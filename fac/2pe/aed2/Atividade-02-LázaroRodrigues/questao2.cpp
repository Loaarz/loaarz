#include <iostream>
#include <clocale>
using namespace std;

const int maxTam=10;

struct TItem{
    int chave;
};
struct TCelula{
   TCelula *proximo;
   TItem item;
};


struct Tlista{
    TCelula *primeiro;
    TCelula *ultimo;
    int contItens;
};

void crialistaVaziaLA(Tlista &la){
    la.primeiro = new TCelula;
    la.ultimo = la.primeiro;
    la.primeiro->proximo=NULL;
    la.contItens=0;
}
bool estavaziaLA(Tlista la){
    return la.primeiro == la.ultimo;
}

TCelula *pegaAnterior(Tlista lp, int chave){
    TCelula *celAux;
    bool achou = false;

    celAux = lp.primeiro;

    cout << "=== PROCURANDO ITEM NA LISTA === "<< endl;
    while (celAux->proximo != NULL){
        if (celAux->proximo->item.chave == chave){
            achou = true;
            return celAux;
        }
        celAux = celAux->proximo;
    }
    if (achou == false){
        return NULL;
    }
}

void retirarPorChave(Tlista &lp, int chave){
    TCelula *p = pegaAnterior(lp,chave);
    TCelula *q;

    if(p == 0){
        cout << "Chave n�o encontrada!!!" << endl;
    }else{
        q = p->proximo;
        p->proximo = q->proximo;
        cout << "EM Exclu�do: " << q << endl;
        delete(q);
    }
}
void inserir(Tlista &la, TItem x){
    la.ultimo->proximo = new TCelula;
    la.ultimo = la.ultimo->proximo;
    la.ultimo->item = x;
    la.ultimo->proximo = NULL;
    la.contItens++;

}
void inserirLA(Tlista &la, TItem x){
    TCelula *CelAux;
    TCelula *aux;
    CelAux= la.primeiro;

    if(estavaziaLA(la)){
        inserir(la,x);
    }else{
        bool menor = false;
        while(CelAux->proximo != NULL){
            if(x.chave < CelAux->proximo->item.chave){
                cout<<"menor";
                aux = new TCelula;
                aux->proximo = CelAux->proximo;
                aux->item = x;
                CelAux->proximo = aux;
                la.contItens++;
                menor = true;
                break;
            }
            CelAux = CelAux->proximo;
        }
        if(!menor){
            inserir(la,x);
        }
    }
}

void verificarItem(Tlista lp, int x){
    TCelula *aux;
    aux = lp.primeiro;
    if(estavaziaLA(lp)){
        cout << "Lista vazia!"<<endl;
    }else{
        while(aux->proximo != NULL){
            if(aux->proximo->item.chave == x){
                cout << "Item encontrado!" << endl;
                cout << aux->proximo->item.chave<< endl;
            }
           aux= aux->proximo;
        }
    }
}

void copiarItensLA(Tlista la, Tlista &lb){
     TCelula *celAux;
        celAux = la.primeiro->proximo;

        cout << "=== Copiando a lista === "<< endl;
        while (celAux != NULL){
            inserir(lb, celAux->item);
            celAux = celAux->proximo;
        }
}
void concatenar(Tlista l1, Tlista l2, Tlista &l3){
    copiarItensLA(l1, l3);
    copiarItensLA(l2, l3);
}
void intercalar(Tlista l1, Tlista l2, Tlista &l4){
        TCelula *celAux1;
        TCelula *celAux2;
        celAux1 = l1.primeiro->proximo;
        celAux2 = l2.primeiro->proximo;

        cout << "=== Copiando a lista === "<< endl;
        while (celAux1 != NULL){
            inserir(l4, celAux1->item);
            inserir(l4, celAux2->item);
            celAux1 = celAux1->proximo;
            celAux2 = celAux2->proximo;
        }
}

void mostrarLA(Tlista lp){
     if (estavaziaLA(lp)){
        cout << "Lista vazia! Nenhum elemento para mostrar!" << endl;

    }
    else{
        TCelula *celAux;
        celAux = lp.primeiro->proximo;

        cout << "-----Mostrando a lista-----"<< endl;
        while (celAux != NULL){
            cout << "E.M.Cel: " << celAux << "   -   Valor: " << celAux->item.chave << endl;
            celAux = celAux->proximo;
        }
    }
}
int main(){
    setlocale(LC_ALL, "Portuguese");
    TItem numeros;
    Tlista lista1A;
    Tlista lista2A;
    Tlista lista3A;
    Tlista lista4A;
    crialistaVaziaLA(lista1A);
    crialistaVaziaLA(lista2A);
    crialistaVaziaLA(lista3A);
    crialistaVaziaLA(lista4A);

     numeros.chave=6;
     inserir(lista1A,numeros);
     numeros.chave=5;
     inserir(lista1A,numeros);
     numeros.chave=4;
     inserir(lista1A,numeros);
     numeros.chave=3;
     inserir(lista1A,numeros);
     mostrarLA(lista1A);
     verificarItem(lista1A,5);
     retirarPorChave(lista1A, 5);
     mostrarLA(lista1A);
     copiarItensLA(lista1A,lista2A);
     mostrarLA(lista2A);
     concatenar(lista1A,lista2A,lista3A);
     mostrarLA(lista3A);
     intercalar(lista1A,lista2A,lista4A);
     mostrarLA(lista4A);
     numeros.chave=6;
     inserirLA(lista1A,numeros);
     numeros.chave=5;
     inserirLA(lista1A,numeros);
     numeros.chave=7;
     inserirLA(lista1A,numeros);
     mostrarLA(lista1A);

return 0;
}
