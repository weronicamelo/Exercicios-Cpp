#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    int sorteados[6];  
    int escolhidos[6]; 
    int acertos = 0;

    srand(time(0)); 
    
    for (int i = 0; i < 6; i++) {
        sorteados[i] = rand() % 60 + 1;
        for (int j = 0; j < i; j++) {
            if (sorteados[i] == sorteados[j]) {
                i--; 
                break;
            }
        }
    }
    
    cout << "Escolha 6 números entre 1 e 60:\n";
    for (int i = 0; i < 6; i++) {
        cout << "Digite o " << i + 1 << " número: ";
        cin >> escolhidos[i];
    }
    
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if (escolhidos[i] == sorteados[j]) {
                acertos++;
            }
        }
    }
    
    if (acertos == 6) {
        cout << "Parabéns! Você acertou todos os 6 números! Ganhou a Mega-Sena!\n";
    } else if (acertos == 5) {
        cout << "Você acertou 5 números! Ganhou a Quina!\n";
    } else if (acertos == 4) {
        cout << "Você acertou 4 números! Ganhou a Quadra!\n";
    } else {
        cout << "Você acertou " << acertos << " números. Tente novamente!\n";
    }
    
    cout << "\nNúmeros sorteados: ";
    for (int i = 0; i < 6; i++) {
        cout << sorteados[i];
        if (i < 5) cout << ", ";
    }
    cout << endl;

    return 0;
}