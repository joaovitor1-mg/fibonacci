#include <iostream>
using namespace std;

class Fila {
public:
    int Valor;
    Fila* elo;

    Fila* Inserir(Fila* F, int N) {
        Fila* novo = new Fila();
        novo->Valor = N;
        novo->elo = nullptr;

        if (F != nullptr) {
            F->elo = novo;
        }

        F = novo;
        return F;
    }

    void Listar(Fila* I) {
        Fila* aux = I;
        cout << "\nSequencia de Fibonacci na FILA:\n";
        while (aux != nullptr) {
            cout << aux->Valor << " ";
            aux = aux->elo;
        }
        cout << endl;
    }
};

class Pilha {
private:
    int Valor;
    Pilha* elo;

public:
    Pilha* InserirPilha(Pilha* T, int N) {
        Pilha* aux = new Pilha();
        aux->Valor = N;
        aux->elo = T;
        T = aux;
        return T;
    }

    void PercorrerPilha(Pilha* T) {
        Pilha* aux = T;
        cout << "\nSequencia de Fibonacci na PILHA:\n";
        if (aux == nullptr) {
            cout << "Pilha vazia!\n";
        } else {
            while (aux != nullptr) {
                cout << aux->Valor << " ";
                aux = aux->elo;
            }
        }
        cout << endl;
    }
};

int main() {
    Fila fila;
    Pilha pilha;

    Fila* inicioFila = nullptr;
    Fila* fimFila = nullptr;
    Pilha* topoPilha = nullptr;

    int qtd;
    cout << "Quantos numeros da sequencia de Fibonacci deseja gerar? ";
    cin >> qtd;

    int a = 0, b = 1, cont = 0;
    while (cont < qtd) {
        if (inicioFila == nullptr) {
            inicioFila = fila.Inserir(nullptr, a);
            fimFila = inicioFila;
        } else {
            fimFila = fila.Inserir(fimFila, a);
        }

        topoPilha = pilha.InserirPilha(topoPilha, a);

        int proximo = a + b;
        a = b;
        b = proximo;
        cont++;
    }

    fila.Listar(inicioFila);
    pilha.PercorrerPilha(topoPilha);

    return 0;
}
