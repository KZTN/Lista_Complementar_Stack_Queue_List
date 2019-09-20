#include <iostream>
using namespace std;
#define MAXTAM 500

struct Pilha {
    char c[MAXTAM];
    int topo = 0;
};
struct Fila {
    char c[MAXTAM];
    int n_elementos = 0;
    int head = 0;
    int tail = -1;
};
struct Lista {
    char c;
    struct Lista* next;  
};
void empilhar(Pilha &p, string cadeia);
void enfileirar(Fila &f, string cadeia);
void desenfileirar(Fila &f, string &cadeiaInversa);
void desempilhar(Pilha &p, string &cadeiaInversa);
int main() {
    string cadeia;
    Pilha p;
    Fila f;
    cout << "entre com uma cadeia de caracteres" << endl;
    getline(cin, cadeia, '\n');
    empilhar(p, cadeia);
    enfileirar(f, cadeia);
    string cadeiaInversa;
    desenfileirar(f, cadeiaInversa);
    desempilhar(p, cadeiaInversa);
    cout << "o resultado é: " << cadeiaInversa << endl;
    return 0;    
}
void empilhar(Pilha &p, string cadeia) {
    for(int i = 0; i < cadeia.length(); i++) {
            char cAux = cadeia.at(i);
            if(isdigit(cAux)) {
                p.c[p.topo] = cAux;
                p.topo++;
            }
        }
    }
void enfileirar(Fila &f, string cadeia) {
    for(int i = 0; i < cadeia.length(); i++) {
        char cAux = cadeia.at(i);
        if(!isdigit(cAux)) {
            f.n_elementos++;
            f.tail++;
            f.c[f.tail] = cAux; 
        }
    }
    
}
void desenfileirar(Fila &f, string &cadeiaInversa) {
    for(int i = f.head; i < f.n_elementos; i++) {
        cadeiaInversa+=f.c[i];
    }
}
void desempilhar(Pilha &p, string &cadeiaInversa) {
    while(p.topo != 0) {
        cadeiaInversa+= p.c[p.topo];
        p.topo--;
    }
}
void iniciarLista(Lista *l, string cadeia) {
    
}

