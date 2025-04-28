#include <iostream>
#include <string>

using namespace std;

int main() {
    double chuva[7]; 
    double total = 0;
    double maisChuva, menosChuva; 
    int maiorChuva = 0, menorChuva = 0; 

    string diasDaSemana[7] = {"Segunda-feira", "Terça-feira", "Quarta-feira", "Quinta-feira", "Sexta-feira", "Sábado", "Domingo"};

    cout << "Digite a quantidade de chuva (em mm) para cada dia da semana:\n";
    for (int i = 0; i < 7; i++) {
        cout << diasDaSemana[i] << ": ";
        cin >> chuva[i];
        total += chuva[i]; 

        if (i == 0) {
            maisChuva = chuva[i];
            menosChuva = chuva[i];
        }
        if (chuva[i] > maisChuva) {
            maisChuva = chuva[i];
            maiorChuva = i;
        }
        if (chuva[i] < menosChuva) {
            menosChuva = chuva[i];
            menorChuva = i;
        }
    }

    double media = total / 7;

    cout << "\nResultado da semana com as chuvas\n";
    cout << "Dia com mais chuva: " << diasDaSemana[maiorChuva] << " com " << maisChuva << " mm\n";
    cout << "Dia com menos chuva: " << diasDaSemana[menorChuva] << " com " << menosChuva << " mm\n";
    cout << "Total de chuva na semana: " << total << " mm\n";
    cout << "Média de chuva na semana: " << media << " mm\n";

    return 0;
}