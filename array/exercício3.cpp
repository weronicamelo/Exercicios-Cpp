#include <iostream>
#include <random>

using namespace std;

void preencher(int ordenar[], int tamanho);
void exibir(const int ordenar[], int tamanho);
void decrescente(int ordenar[], int tamanho);

int gen() {
    random_device rd;
    mt19937 gen_numb(rd());
    uniform_int_distribution<> dis(1, 100);
    return dis(gen_numb);
}

int main() {
    const int size = 10;
    int num[size];
    
    preencher(num, size);
    
    cout << "Array original:\n";
    exibir(num, size);
    
    decrescente(num, size);
    
    cout << "\nArray ordenado:\n";
    exibir(num, size);
    
    return 0;
}

void preencher(int ordenar[], int tamanho) {
    for(int i = 0; i < tamanho; i++) {
        ordenar[i] = gen();
    }
}

void exibir(const int ordenar[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        cout << ordenar[i] << " ";
    }
    cout << endl;
}

void decrescente(int ordenar[], int tamanho){
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = i + 1; j < tamanho; j++) {
            if (ordenar[i] < ordenar[j]) { 
                swap(ordenar[i], ordenar[j]);
            }
        }
    }
}



