#include <iostream>
#include <string>

using namespace std;

int main() {
    string mensagem;
    cout << "Digite a mensagem: ";
    getline(cin, mensagem);

    string mensagemSemEspacos = "";
    for (int i = 0; i < mensagem.length(); i++) {
        if (mensagem[i] != ' ') {
            mensagemSemEspacos += mensagem[i];
        }
    }

    for (int i = 0; i < mensagemSemEspacos.length(); i++) {
        mensagemSemEspacos[i] = tolower(mensagemSemEspacos[i]);
    }

    char caracteres[mensagemSemEspacos.length() + 1];
    for (int i = 0; i < mensagemSemEspacos.length(); i++) {
        caracteres[i] = mensagemSemEspacos[i];
    }
    caracteres[mensagemSemEspacos.length()] = '\0';

    char caracteresInvertidos[mensagemSemEspacos.length() + 1];
    for (int i = 0; i < mensagemSemEspacos.length(); i++) {
        caracteresInvertidos[i] = mensagemSemEspacos[mensagemSemEspacos.length() - 1 - i];
    }
    caracteresInvertidos[mensagemSemEspacos.length()] = '\0';

    // verificar se a mensagem é um palíndromo
    bool palindromo = true;
    int n = mensagemSemEspacos.length();
    for (int i = 0; i < n; i++) {
        if (caracteres[i] != caracteresInvertidos[i]) {
            palindromo = false;
            break;
        }
    }

    if (palindromo) {
        cout << "A mensagem é um palíndromo." << endl;
    } else {
        cout << "A mensagem não é um palíndromo." << endl;
    }

    return 0;
}
