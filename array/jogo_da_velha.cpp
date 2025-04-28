#include <iostream>
using namespace std;

int main() {
    char tabuleiro[3][3];
    char jogador = 'X';
    int linha, coluna;
    int jogadas;
    char jogarNovamente = 's';
    
    cout << "Jogo da Velha!" << endl;

    while (jogarNovamente == 's' || jogarNovamente == 'S') {
        jogadas = 0;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                tabuleiro[i][j] = ' ';

        while (true) {
            cout << "\n";
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    cout << " " << tabuleiro[i][j];
                    if (j < 2) cout << " |";
                }
                cout << endl;
                if (i < 2) cout << "---+---+---" << endl;
            }

            cout << "\nJogador " << jogador << ", escolha linha (entre 0 e 2) e coluna (entre 0 e 2): ";
            cin >> linha >> coluna;

            if (linha < 0 || linha > 2 || coluna < 0 || coluna > 2 || tabuleiro[linha][coluna] != ' ') {
                cout << "Posição inválida! Tente novamente.\n";
                continue;
            }

            tabuleiro[linha][coluna] = jogador;
            jogadas++;

            if ((tabuleiro[0][0] == jogador && tabuleiro[0][1] == jogador && tabuleiro[0][2] == jogador) ||
                (tabuleiro[1][0] == jogador && tabuleiro[1][1] == jogador && tabuleiro[1][2] == jogador) ||
                (tabuleiro[2][0] == jogador && tabuleiro[2][1] == jogador && tabuleiro[2][2] == jogador) ||
                (tabuleiro[0][0] == jogador && tabuleiro[1][0] == jogador && tabuleiro[2][0] == jogador) ||
                (tabuleiro[0][1] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][1] == jogador) ||
                (tabuleiro[0][2] == jogador && tabuleiro[1][2] == jogador && tabuleiro[2][2] == jogador) ||
                (tabuleiro[0][0] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][2] == jogador) ||
                (tabuleiro[0][2] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][0] == jogador)) {
                
                cout << "\nTabuleiro final:\n";
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        cout << " " << tabuleiro[i][j];
                        if (j < 2) cout << " |";
                    }
                    cout << endl;
                    if (i < 2) cout << "---+---+---" << endl;
                }

                cout << "\nJogador " << jogador << " venceu!\n";
                break;
            }
            
            if (jogadas == 9) {
                // Mostrar tabuleiro final
                cout << "\nTabuleiro final:\n";
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        cout << " " << tabuleiro[i][j];
                        if (j < 2) cout << " |";
                    }
                    cout << endl;
                    if (i < 2) cout << "---+---+---" << endl;
                }

                cout << "\nEmpate!\n";
                break;
            }

            if (jogador == 'X') {
                jogador = 'O';
            } else {
                jogador = 'X';
            }

        }

        cout << "\nDeseja jogar novamente? (s/n): ";
        cin >> jogarNovamente;
    }

    cout << "\nFim do jogo. Obrigado por jogar!\n";

    return 0;
}
