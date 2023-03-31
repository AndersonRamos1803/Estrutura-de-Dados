#include <iostream>
#include <string>

using namespace std;

int main() {
    string mensagem;
    cout << "Digite a mensagem: ";
    getline(cin, mensagem);

    int largura_tela = 80; 
    int largura_mensagem = mensagem.length();
    int espacos_lado = (largura_tela - largura_mensagem) / 2;
    int posicao_atual = 5; 

    for (int i = 0; i < espacos_lado; i++) {
        cout << " ";
    }

    cout << mensagem << endl;

    for (int linha = 6; linha <= 20; linha++) {
        for (int i = 0; i < espacos_lado; i++) {
            cout << " ";
        }

        for (int i = 0; i < largura_mensagem; i++) {
            if (linha == posicao_atual + i) {
                cout << mensagem[i];
            } else {
                cout << " ";
            }
        }

        cout << endl;
    }

    return 0;
}
