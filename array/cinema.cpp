#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

void mostrarFilmes(const string filmes[], int numFilmes);
int escolherFilme(int numFilmes);
void mostrarAssentos(int assentos[], int numAssentos);
int escolherAssento(int assentos[], int numAssentos);
void mostrarComidas(const string comidas[], const double precosComidas[], int numComidas);
double escolherComidas(const double precosComidas[], int numComidas);
void mostrarNotaFiscal(string filmeSelecionado, int escolhaAssento, double totalComidas, double precoIngresso, string formaPagamentoStr, int numeroIngresso);

int main() {
    const int numFilmes = 3;
    const int numAssentos = 10;
    const int numComidas = 4;
    const double precoIngresso = 25.00; 

    string filmes[numFilmes] = {"Thunderbolts", "Premonição 6: Laços de Sangue", "Homem com H"};

    int assentos[numAssentos] = {0};

    string comidas[numComidas] = {"Pipoca Pequena", "Pipoca Grande", "Refrigerante", "Chocolate"};
    double precosComidas[numComidas] = {30.00, 40.00, 15.00, 10.00};

    cout << "\n===================================\n";
    cout << "      BEM-VINDO AO CINEMA            \n";
    cout << "===================================\n\n";

    mostrarFilmes(filmes, numFilmes);

    int escolhaFilme = escolherFilme(numFilmes);

    string filmeSelecionado = filmes[escolhaFilme - 1];

    mostrarAssentos(assentos, numAssentos);

    int escolhaAssento = escolherAssento(assentos, numAssentos);

    assentos[escolhaAssento - 1] = 1;

    mostrarComidas(comidas, precosComidas, numComidas);

    double totalComidas = escolherComidas(precosComidas, numComidas);

    cout << "\nFormas de pagamento:\n";
    cout << "  1. Cartão\n";
    cout << "  2. Dinheiro\n";
    cout << "  3. Pix\n";
    cout << "Escolha a forma de pagamento: ";
    int formaPagamento;
    cin >> formaPagamento;

    string formaPagamentoStr;
    if (formaPagamento == 1) {
        formaPagamentoStr = "Cartão";
    } else if (formaPagamento == 2) {
        formaPagamentoStr = "Dinheiro";
    } else {
        formaPagamentoStr = "Pix";
    }
    
    srand(time(0));
    int numeroIngresso = rand() % 10000 + 1000;

    double total = precoIngresso + totalComidas;

    mostrarNotaFiscal(filmeSelecionado, escolhaAssento, totalComidas, precoIngresso, formaPagamentoStr, numeroIngresso);

    cout << "\nObrigado por escolher o nosso Cinema! Aproveite o filme!\n";

    return 0;
}

void mostrarFilmes(const string filmes[], int numFilmes) {
    cout << "Filmes em cartaz:\n";
    for (int i = 0; i < numFilmes; ++i) {
        cout << "  " << i + 1 << ". " << filmes[i] << "\n";
    }
}

int escolherFilme(int numFilmes) {
    int escolhaFilme;
    cout << "\nEscolha o número do filme desejado: ";
    cin >> escolhaFilme;

    if (escolhaFilme < 1 || escolhaFilme > numFilmes) {
        cout << "\nOpção inválida. Por favor, tente novamente!\n";
        return escolherFilme(numFilmes); 
    }
    return escolhaFilme;
}

void mostrarAssentos(int assentos[], int numAssentos) {
    cout << "\nAssentos disponíveis:\n";
    for (int i = 0; i < numAssentos; ++i) {
        cout << "  " << i + 1;
        if (assentos[i] == 1) {
            cout << " - Ocupado";
        } else {
            cout << " - Livre";
        }
        if ((i + 1) % 5 == 0) {
            cout << "\n";
        } else {
            cout << "  ";
        }
    }
    cout << endl;
}

int escolherAssento(int assentos[], int numAssentos) {
    int escolhaAssento;
    cout << "\nDigite o número do assento que deseja: ";
    cin >> escolhaAssento;

    if (escolhaAssento < 1 || escolhaAssento > numAssentos || assentos[escolhaAssento - 1] == 1) {
        cout << "\nAssento inválido ou já ocupado. Por favor, tente novamente!\n";
        return escolherAssento(assentos, numAssentos);
    }
    return escolhaAssento;
}

void mostrarComidas(const string comidas[], const double precosComidas[], int numComidas) {
    cout << "\nComidas disponíveis:\n";
    for (int i = 0; i < numComidas; ++i) {
        cout << "  " << i + 1 << ". " << comidas[i] << " - R$ " << precosComidas[i] << "\n";
    }
}

double escolherComidas(const double precosComidas[], int numComidas) {
    double totalComidas = 0;
    int escolhaComida;

    cout << "\nEscolha as comidas desejadas (0 para nenhuma opção):\n";
    do {
        cout << "Digite o número da comida: ";
        cin >> escolhaComida;

        if (escolhaComida > 0 && escolhaComida <= numComidas) {
            totalComidas += precosComidas[escolhaComida - 1];
            cout << "Comida adicionada ao pedido!\n";
        } else if (escolhaComida != 0) {
            cout << "Opção inválida, tente novamente.\n";
        }
    } while (escolhaComida != 0);

    return totalComidas;
}

void mostrarNotaFiscal(string filmeSelecionado, int escolhaAssento, double totalComidas, double precoIngresso, string formaPagamentoStr, int numeroIngresso) {
    double total = precoIngresso + totalComidas;
    cout << "\n========================================\n";
    cout << "             NOTA FISCAL               \n";
    cout << "========================================\n";
    cout << "Filme: " << filmeSelecionado << "\n";
    cout << "Assento: " << escolhaAssento << "\n";
    cout << "Forma de pagamento: " << formaPagamentoStr << "\n";
    cout << "Número do ingresso: " << numeroIngresso << "\n";
    cout << "Total a pagar: R$ " << total << "\n";
    cout << "========================================\n";
}
