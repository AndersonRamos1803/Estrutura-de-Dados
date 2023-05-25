#include <iostream>

using namespace std;

struct Lista {
    int senha;
    Lista* next;
};

Lista* senhasGeradas = NULL;
Lista* senhasAtendidas = NULL;
int proximaSenha = 1;

void gerarSenha()
{
    Lista* novoNo = new Lista;
    novoNo->senha = proximaSenha++;
    novoNo->next = NULL;

    if (senhasGeradas == NULL) {
        senhasGeradas = novoNo;
    } else {
        Lista* atual = senhasGeradas;
        while (atual->next != NULL) {
            atual = atual->next;
        }
        atual->next = novoNo;
    }
}

void realizarAtendimento()
{
    if (senhasGeradas != NULL) {
        Lista* noRemover = senhasGeradas;
        senhasGeradas = senhasGeradas->next;

        noRemover->next = NULL;

        if (senhasAtendidas == NULL) {
            senhasAtendidas = noRemover;
        } else {
            Lista* atual = senhasAtendidas;
            while (atual->next != NULL) {
                atual = atual->next;
            }
            atual->next = noRemover;
        }

        cout << "Senha atendida: " << noRemover->senha << endl;
    } else {
        cout << "Não há senhas aguardando atendimento." << endl;
    }
}

void liberarMemoria(Lista* no)
{
    if (no == NULL) {
        return;
    }

    liberarMemoria(no->next);
    delete no;
}

void liberarLista()
{
    liberarMemoria(senhasGeradas);
    liberarMemoria(senhasAtendidas);
}

int main()
{
    int opcao = -1;

    while (senhasGeradas != NULL || opcao != 0)
    {
        cout << "Quantidade de senhas aguardando atendimento: ";

        int count = 0;
        Lista* atual = senhasGeradas;
        while (atual != NULL) {
            atual = atual->next;
            count++;
        }
        cout << count << endl;

        cout << "Selecione uma opção:" << endl;
        cout << "0. Sair" << endl;
        cout << "1. Gerar senha" << endl;
        cout << "2. Realizar atendimento" << endl;
        cin >> opcao;

        switch (opcao)
        {
            case 0:
                if (senhasGeradas != NULL)
                {
                    cout << "Ainda há senhas aguardando atendimento." << endl;
                    cout << "Quantidade de senhas atendidas: ";

                    count = 0;
                    atual = senhasAtendidas;
                    while (atual != NULL) {
                        atual = atual->next;
                        count++;
                    }
                    cout << count << endl;
                }
                else
                {
                    cout << "Encerrando o programa." << endl;
                    cout << "Quantidade de senhas atendidas: ";

                    count = 0;
                    atual = senhasAtendidas;
                    while (atual != NULL) {
                        atual = atual->next;
                        count++;
                    }
                    cout << count << endl;
                }
                break;
            case 1:
                gerarSenha();
                break;
            case 2:
                realizarAtendimento();
                break;
            default:
                cout << "Opção inválida. Por favor, selecione novamente." << endl;
                break;
        }

        cout << endl;
    }

    liberarLista();

    return 0;
}
