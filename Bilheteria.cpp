//PROJETO BILHETERIA

#include <iostream>
#include <iomanip> 
#include <locale.h>

using namespace std;

const int fileiras = 15;
const int poltronas = 40;

char lugares[fileiras][poltronas];

void iniciaMatriz() {
    for (int i = 0; i < fileiras; i++) {
        for (int j = 0; j < poltronas; j++) {
            lugares[i][j] = '.';
        }
    }
}

void reservarLugar() {
    int f, p;

while(true){    
cout << "Digite o número da fileira (1 a 15): ";
    cin >> f;

    if (f < 1 || f > fileiras) {
        cout << "Fileira inválida. Tente novamente." << endl;
    }
else{
break;
}
}

while(true){
    cout << "Digite o número da poltrona (1 a 40): ";
    cin >> p;

    if (p < 1 || p > poltronas) {
        cout << "Poltrona inválida. Tente novamente." << endl;
            }
else{
break;
}
}

    int linha = f - 1;
    int coluna = p - 1;

    if (lugares[linha][coluna] == '#') {
        cout << "Lugar já está ocupado. Tente outro lugar." << endl;
        return;
    }

    lugares[linha][coluna] = '#';

    cout << "Lugar reservado com sucesso!" << endl;
}

void mostrarLugares() {
    cout << "Mapa de ocupação:" << endl;

    for (int i = 0; i < fileiras; i++) {
        for (int j = 0; j < poltronas; j++) {
            cout << lugares[i][j] << " ";
        }
        cout << endl;
    }
}

void calcularFaturamento(int& qtdeOcupados, double& valorTotal) {
    qtdeOcupados = 0;
    valorTotal = 0;

    for (int i = 0; i < fileiras; i++) {
        double valorFileira;

        if (i < 5) {
            valorFileira = 50.0;
        } else if (i < 10) {
            valorFileira = 30.0;
        } else {
            valorFileira = 15.0;
        }

        for (int j = 0; j < poltronas; j++) {
            if (lugares[i][j] == '#') {
                qtdeOcupados++;
                valorTotal += valorFileira;
            }
        }
    }
}

int main() {
	setlocale(LC_ALL, "Portuguese");
    iniciaMatriz();

    while (true) {
        cout << "Selecione uma opção:" << endl;
        cout << "0. Finalizar" << endl;
        cout << "1. Reservar poltrona" << endl;
        cout << "2. Mapa de ocupação" << endl;
        cout << "3. Faturamento" << endl;

        int opcao;
        cin >> opcao;

        if (opcao == 0) {
            break;
        } else if (opcao == 1) {
            reservarLugar();
        } else if (opcao == 2) {
            mostrarLugares();
            cout << " . representa os lugares vagos" << endl;
			cout << " # representa os lugares ocupados" << endl;
        } else if (opcao == 3) {
            int qtdeOcupados;
            double valorTotal;

            calcularFaturamento(qtdeOcupados, valorTotal);

            cout << "Quantidade de lugares ocupados: " << qtdeOcupados << endl;
            cout << "Valor da bilheteria: R$ " << fixed << setprecision(2) << valorTotal << endl;
        } else {
            cout << "Opção inválida. Tente novamente." << endl;
        }
    }

    return 0;
}
