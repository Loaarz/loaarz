#include <iostream>
using namespace std;

const int mt1 = 5;
const int mt2 = 10;

struct ListaA{
  int itens[mt1];
  int pri;
  int ult;
};

void criarListaVazia(ListaA &l){
  l.pri = 0;
  l.ult = 0;
}

bool estaCheia(ListaA l){
  return l.ult >= mt1;
}

bool estaVazia(ListaA l){
  return l.pri == l.ult;
}

void inserir(ListaA &l, int  i){
    if(estaCheia(l)){
        cout << "Lista cheia!"<< endl;
    }else{
        if(estaVazia(l)){
            l.itens[l.ult]= i;
            l.ult++;
        }else{
            int pos = -1;
            for(int h=0; h < l.ult; h++){
                if(i < l.itens[h]){
                    pos = h;
                    break;
                }
            }
            if(pos == -1){
                l.itens[l.ult]= i;
                l.ult++;
            }else{
                for(int h = l.ult; h > pos; h--){
                    l.itens[h]=l.itens[h-1];
                }
                l.itens[pos]= i;
                l.ult++;
            }
        }

    }

}

void mostrar(ListaA l){
  if(estaVazia(l)){
    cout << "Sem itens para mostar!!" << endl;
  }else {
    for(int i=l.pri;i<l.ult;i++){
      cout << "Pos: " << i << ": " << l.itens[i] << endl;
    }
  }
}

void remover(ListaA &l, int i){
    int a;
    if((estaVazia(l)) || (i>=l.ult) || (i<l.pri)){
        cout << "Retirada impossivel!" << endl;
    }
    else{
       l.ult--;
       for(a=i;a<l.ult;a++){
            l.itens[a] = l.itens[a+1];
       }
       cout << "O elemento foi retirado com sucesso!" << endl;
    }
}

int olhar(ListaA l, int i){
    for(int n=0; n<mt1; n++){
        if(l.itens[n] == i){
            return l.itens[n];   
        }
    }  
    return -1;
}

void enviar(ListaA &l, int i){
  cout << "Insira cinco valores: " << endl;
  for(int k=0;k<5;k++){
    cout << "Valor-" << k+1 << ": ";
    cin >> i;
    inserir(l, i);
  }
}

void inserirn(ListaA &c, int i){
    if(estaCheia(c)){
        cout << "A lista esta cheia" << endl;
    }else{
        c.itens[c.ult]= i;
        c.ult++;
    }
}

void copiar(ListaA l, ListaA &c){
   for(int i=l.pri; i<l.ult; i++){
       inserirn(c, l.itens[i]);
   } 
}

void intercalar(ListaA l1, ListaA l2, ListaA &l4){
    for(int i=l1.pri;i<l1.ult;i++){
        inserirn(l4,l1.itens[i]);
        inserirn(l4,l2.itens[i]);
    }
}

void concatenar(ListaA l1, ListaA l2, ListaA &l3){
    copiar(l1, l3);
    copiar(l2, l3);
}

int main(){
  ListaA lista1A, lista2A, lista3A, lista4A;
  int i;
  
  criarListaVazia(lista1A);
  criarListaVazia(lista2A);
  criarListaVazia(lista3A);
  criarListaVazia(lista4A);

  enviar(lista1A, i);
  mostrar(lista1A);
  cout << "Digite uma chave: ";
  cin >> i;
  if(olhar(lista1A, i) == -1){
    cout << "Chave nao presente na lista!" << endl;
  }else{
    cout << "O item " << olhar(lista1A, i) << " esta presente na lista!"<< endl;
  }
  cout << "Digite uma posicao para remover: ";
  cin >> i;
  cout << "-----Lista inteira-----" << endl;
  mostrar(lista1A);
  cout << "-----Lista sem um item-----" << endl;
  remover(lista1A, i); 
  mostrar(lista1A);
  cout << "-----Lista copiada-----" << endl;
  copiar(lista1A, lista2A);
  mostrar(lista2A);
  cout << "-----Lista concatenada-----" << endl;
  concatenar(lista1A, lista2A, lista3A);
  mostrar(lista3A); 
  cout << "-----Lista intercalada-----" << endl;
  intercalar(lista1A, lista2A, lista4A);
  mostrar(lista4A); 
  return 0;
}
