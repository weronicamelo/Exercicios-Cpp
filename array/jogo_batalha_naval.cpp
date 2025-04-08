#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    const int TAMANHO = 10;
    char tabuleiro[TAMANHO][TAMANHO];
    int navios[TAMANHO][TAMANHO]; 
    int n;
    
    cout << "====Jogo de Batalha Naval====" << endl; 
    cout << "Digite o tamanho do tabuleiro entre 2 e 10: ";
    cin >> n;

    while(n < 2 || n > 10) {
        cout << "Tamanho invalido! Digite um valor entre 2 e 10: ";
        cin >> n;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            tabuleiro[i][j] = '.'; 
            navios[i][j] = 0; 
        }
    }

    srand(time(0)); 
    int posicaoNavios = 0;
    while(posicaoNavios < n) {
        int x = rand() % n;
        int y = rand() % n;
        
        if(navios[x][y] == 0) { 
            navios[x][y] = 1;  
            posicaoNavios++; 
        }
    }

    cout << "\nTabuleiro " << n << "x" << n << endl;
    cout << "Voce tem que afundar " << n << " navios!\n" << endl;

    int tentativas = 0;
    while(true) {
        // Exibindo o tabuleiro
        cout << "  ";
        for(int i = 0; i < n; i++) 
        cout << i << " ";
        cout << endl;
        
        for(int i = 0; i < n; i++) {
            cout << i << " ";
            for(int j = 0; j < n; j++) {
                cout << tabuleiro[i][j] << " ";
            }
            cout << endl;
        }

        int linha, coluna;
        cout << "\nDigite linha e coluna para atacar: ";
        cin >> linha >> coluna;

        if(linha < 0 || linha >= n || coluna < 0 || coluna >= n) {
            cout << "Posicao invalida :(" << endl;
            cout << "Tente novamente!" << endl;
            continue;
        }

        if(tabuleiro[linha][coluna] != '.') {
            cout << "Voce ja atirou aqui :(" << endl;
            cout << "Tente outra posicao!" << endl;
            continue;
        }

        tentativas++;

        if(navios[linha][coluna] == 1) {  
            cout << "ISSO, ACERTOU! Voce afundou um navio!" << endl;
            tabuleiro[linha][coluna] = 'X'; 
        } else {
            int perto = 0;
            for(int i = linha-1; i <= linha+1; i++) {
                for(int j = coluna-1; j <= coluna+1; j++) {
                    if(i >= 0 && i < n && j >= 0 && j < n && !(i == linha && j == coluna)) {
                        if(navios[i][j] == 1) perto++;
                    }
                }
            }
            cout << "AINDA É ÁGUA! Tem " << perto << " navio(s) perto desta posicao." << endl;
            tabuleiro[linha][coluna] = 'O';
        }

        bool ganhou = true;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(navios[i][j] == 1 && tabuleiro[i][j] != 'X') {
                    ganhou = false;
                }
            }
        }

        if(ganhou) {
            cout << "\nMUITO BEM! Voce afundou todos os navios em " << tentativas << " tentativas!" << endl;
            cout << "-------------------------------------------------------" << endl;
            
            // Exibindo o tabuleiro
            cout << endl;
            cout << "===Tabuleiro final===" << endl;
            cout << "  ";
            for(int i = 0; i < n; i++)
            cout << i << " ";
            cout << endl;
            
            for(int i = 0; i < n; i++) {
                cout << i << " ";
                for(int j = 0; j < n; j++) {
                    cout << tabuleiro[i][j] << " ";
                }
                cout << endl;
            }
            
            break;
        }
    }

    return 0;
}
