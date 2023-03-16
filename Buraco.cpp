//PROJETO BURACO

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <locale.h>

using namespace std;

int main() {
	setlocale(LC_ALL, "Portuguese");
    srand(time(0)); 
    
    int cartas[2][4][13]; // vetor para registrar as cartas dos 2 baralhos
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 13; k++) {
                cartas[i][j][k] = 0;
            }
        }
    }
    int jogadores[4][11]; // vetor para registrar as cartas de cada jogador
    for (int i = 0; i < 4; i++) { {
            for (int j = 0;j < 11; j++) {
                jogadores[i][j] = 0;
            }
        }
    }
    // distribuição das cartas
    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 4; j++) {
            int baralho = rand() % 2; // escolhe um dos dois baralhos
            int naipe, valor;
            do {
                naipe = rand() % 4; // escolhe um dos quatro naipes 
                valor = rand() % 13; // escolhe um dos treze valores de carta
            } while (cartas[baralho][naipe][valor] != 0); // verifica se a carta está disponível
            
            cartas[baralho][naipe][valor] = j + 1; // marca a carta como sendo do jogador atual
            jogadores[j][i] =  (naipe+1) * 1000 + valor *10 + baralho+1; // registra a carta no vetor do jogador
        }
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 13; k++) {
                cout << cartas[i][j][k] << " ";
        }
        cout << endl; 
        }
        cout << endl;
        cout << endl;
    }
    
    for (int i = 0; i < 4; i++) {
        cout << "Cartas do jogador " << i+1 << ": ";
        for (int j = 0; j < 11; j++) {
            int carta = jogadores[i][j];
            int naipe = carta / 1000;
            int valor = (carta - naipe * 1000)/ 10;
			int baralho = carta - naipe * 1000 - valor * 10;
            cout << naipe << "-" << valor + 1 << "-" << baralho << " ";
        }
        cout << endl;
        cout << endl;
    }
    cout << endl;
	cout << endl;
    cout << "Padrão de representação das cartas: N - 99 - B" << endl;
    cout << "N  -> Naipe (1-Copas / 2-Paus / 3-Ouro / 4-Espada)" << endl;
	cout << "99 -> Número da carta (01-Ás / 13-Rei)" << endl;
	cout << "B  -> Baralho (1 ou 2)" << endl;
    
    return 0;
}
