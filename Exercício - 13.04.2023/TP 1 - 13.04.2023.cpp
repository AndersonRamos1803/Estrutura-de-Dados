// TP 1 - 13.04.2023.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include <locale.h>
#include <locale.h>
#include <string>
using namespace std;
const int QTDE_CONTATOS = 10;

class Data
{
private:
    int dia;
    int mes;
    int ano;
public:
    Data(int dia, int mes, int ano) {
        this->dia = dia;
        this->mes = mes;
        this->ano = ano;
    }
    Data() {
        this->dia = 0;
        this->mes = 0;
        this->ano = 0;
    }
    void setDia(int dia) {
        this->dia = dia;
    }
    void setMes(int mes) {
        this->mes = mes;
    }
    void setAno(int ano) {
        this->ano = ano;
    }
    int getDia() {
        return this->dia;
    }
    int getMes() {
        return this->mes;
    }
    int getAno() {
        return this->ano;
    }
    string getData()
    {
        return to_string(this->dia) + "/" +
            to_string(this->mes) + "/" +
            to_string(this->ano);
    }
};

class Contato
{
private:
    string email;
    string nome;
    string telefone;
    Data dtnasc;
public:
    Contato(string email, string nome, string telefone, Data dtnasc) {
        this->email = email;
        this->nome = nome;
        this->telefone = telefone;
        this->dtnasc = dtnasc;
    }
    Contato() {
        this->email = "";
        this->nome = "";
        this->telefone = "";
        this->dtnasc = Data();
    }
    void setEmail(string email) {
        this->email = email;
    }
    void setNome(string nome) {
        this->nome = nome;
    }
    void setTelefone(string telefone) {
        this->telefone = telefone;
    }
    void setDataNascimento(int dia, int mes, int ano) {
        this->dtnasc.setAno(ano);
        this->dtnasc.setMes(mes);
        this->dtnasc.setDia(dia);
    }
    string getEmail() {
        return this->email;
    }
    string getNome() {
        return this->nome;
    }
    string getTelefone() {
        return this->telefone;
    }
    Data getDataNascimento() {
        return this->dtnasc;
    }
    int idade() {
        // calcula a idade com base na data de nascimento
        // considerando que a data atual é 12/04/2023
        int idade = 2023 - this->dtnasc.getAno();
        if (this->dtnasc.getMes() > 4 || (this->dtnasc.getMes() == 4 && this->dtnasc.getDia() > 12)) {
            idade--;
        }
        return idade;
    }

};

void exibeContato(double media, Contato contatos[], int tamanho){
    cout << "Os contatos com idade supeior a " << media << " são:" << endl;
    for (int i = 0; i < tamanho; i++) {
        if (contatos[i].idade() > media) {
            cout << "|Nome: " << contatos[i].getNome() << endl;
        }
    }
};

void exibeMaior(Contato contatos[]) {
    int n = 0;
    for (int i = 0; i < 10; i++) {
        if (contatos[i].idade() >= 18) {
            n = n + 1;
        }
    }
   
    cout << "O número de contatos maiores de idade é: " << n << endl;
};

void maisVelho(Contato contatos[]) {
    int n = contatos[0].idade();
    for (int i = 1; i < 10; i++) {
        if (contatos[i].idade() > n) {
            n = contatos[i].idade();
        }
    }
    cout << "Os dados dos contatos mais velhos são:" << endl;
    for (int i = 0; i < 10; i++) {
        if (n == contatos[i].idade()) {
            cout << "|Nome: " << contatos[i].getNome() << endl;
            cout << "|E-mail: " << contatos[i].getEmail() << endl;
            cout << "|Telefone: " << contatos[i].getTelefone() << endl;
        }
    }

};



int main()
{
    setlocale(LC_ALL, "Portuguese");

    Contato contatos[QTDE_CONTATOS];

    for (int i = 0; i < QTDE_CONTATOS; i++) {
        string nome, email, telefone;
        int dia, mes, ano;

        cout << "Digite o nome do contato " << i + 1 << ": ";
        getline(cin, nome);

        cout << "Digite o e-mail do contato " << i + 1 << ": ";
        getline(cin, email);

        cout << "Digite o telefone do contato " << i + 1 << ": ";
        getline(cin, telefone);

        cout << "Digite a data de nascimento do contato " << i + 1 << " (DD MM AAAA): ";
        cin >> dia >> mes >> ano;
        cin.ignore();

        contatos[i].setNome(nome);
        contatos[i].setEmail(email);
        contatos[i].setTelefone(telefone);
        contatos[i].setDataNascimento(dia, mes, ano);
    }
    cout << "-------------------------------------------------" << endl;
    cout << endl;
    cout << "Lista de Contatos:" << endl;

    double media = 0;
    for (int i = 0; i < QTDE_CONTATOS; i++) {
        media = media + contatos[i].idade();
    }
    media = media / 10;
    cout << endl;
    cout << "-------------------------------------------------" << endl;
    cout << endl;
    exibeContato(media, contatos, QTDE_CONTATOS);
    cout << endl;
    cout << "-------------------------------------------------" << endl;
    cout << endl;
    exibeMaior(contatos);
    cout << endl;
    cout << "-------------------------------------------------" << endl;
    cout << endl;
    maisVelho(contatos);

    return 0;
}