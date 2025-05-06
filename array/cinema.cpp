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
void mostrarNotaFiscal(string filmeSelecionado, int ingressosInteira, int ingressosMeia, double totalComidas, double totalIngressos, string formaPagamentoStr, int numeroIngresso);

int main() {
    const int numFilmes = 3;
    const int numAssentos = 10;
    const int numComidas = 4;
    const double precoIngressoInteira = 25.00;
    const double precoIngressoMeia = precoIngressoInteira / 2.0;

    string filmes[numFilmes] = {"Thunderbolts", "Premonição 6: Laços de Sangue", "Homem com H"};
    int assentos[numAssentos] = {};

    string comidas[numComidas] = {"Pipoca Pequena", "Pipoca Grande", "Refrigerante", "Chocolate"};
    double precosComidas[numComidas] = {30.00, 40.00, 15.00, 10.00};

    cout << "\n===================================\n";
    cout << "      BEM-VINDO AO CINEMA            \n";
    cout << "===================================\n\n";

    mostrarFilmes(filmes, numFilmes);

    int escolhaFilme = escolherFilme(numFilmes);
    string filmeSelecionado = filmes[escolhaFilme - 1];
    
    int comprar = 1;
    int escolhaAssento;
    int ingressosInteira = 0, ingressosMeia = 0; 

    while (comprar) {
        mostrarAssentos(assentos, numAssentos);
        escolhaAssento = escolherAssento(assentos, numAssentos);
        assentos[escolhaAssento - 1] = 1; 

        cout << "\nEscolha o tipo de ingresso:\n";
        cout << "1. Inteira (R$ " << precoIngressoInteira << ")\n";
        cout << "2. Meia entrada (R$ " << precoIngressoMeia << ")\n";
        int tipoIngresso;
        cout << "Resposta: ";
        cin >> tipoIngresso;

        if (tipoIngresso == 1) {
            ingressosInteira++;
        } else if (tipoIngresso == 2) {
            ingressosMeia++;
        } else {
            cout << "Opção inválida. Selecione novamente.\n";
            continue;
        }

        cout << "\nDeseja comprar mais ingressos?\n1. Sim\n0. Não\n";
        cout << "Resposta: ";
        cin >> comprar;
    }

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

    double totalIngressos = (precoIngressoInteira * ingressosInteira) + (precoIngressoMeia * ingressosMeia);
    double total = totalIngressos + totalComidas;

    mostrarNotaFiscal(filmeSelecionado, ingressosInteira, ingressosMeia, totalComidas, totalIngressos, formaPagamentoStr, numeroIngresso);

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

void mostrarNotaFiscal(string filmeSelecionado, int ingressosInteira, int ingressosMeia, double totalComidas, double totalIngressos, string formaPagamentoStr, int numeroIngresso) {
    double total = totalIngressos + totalComidas;
    cout << "\n========================================\n";
    cout << "             NOTA FISCAL               \n";
    cout << "========================================\n";
    cout << "Filme: " << filmeSelecionado << "\n";
    cout << "Ingressos Inteira: " << ingressosInteira << "\n";
    cout << "Ingressos Meia: " << ingressosMeia << "\n";
    cout << "Total ingressos: R$ " << totalIngressos << "\n";
    cout << "Total comidas: R$ " << totalComidas << "\n";
    cout << "Forma de pagamento: " << formaPagamentoStr << "\n";
    cout << "Número do ingresso: " << numeroIngresso << "\n";
    cout << "Total a pagar: R$ " << total << "\n";
    cout << "========================================\n";
}
