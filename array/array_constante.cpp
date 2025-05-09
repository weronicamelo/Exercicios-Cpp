#include <iostream>
using namespace std;

int main(){
    
    const int ARRAY_SIZE = 6;
    const float TAXA_IMPOSTO = 0.30;
    float salario_func[ARRAY_SIZE];
    int cont;
    
    for(cont = 0; cont < ARRAY_SIZE; cont++){
        cout << "Digite o salário do funcionário: " << cont + 1 << ": ";
        cin >> salario_func[cont];
    }
    
    cout << "\nImposto a pagar: \n";
    
    for(cont = 0; cont < ARRAY_SIZE; cont++){
       cout << "Funcionário " << cont + 1 << ": R$ " << salario_func[cont] * TAXA_IMPOSTO << endl;
    }
    
    return 0;
}
