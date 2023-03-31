#include <iostream>
#include <fstream>
#include <sstream>


int main() {
    std::ifstream infile("nomes.txt");
    if (!infile) {
        std::cout << "Não foi possível abrir o arquivo." << std::endl;
        return 1;
    }
    std::string linha;
    while (std::getline(infile, linha)) {
        std::string sobrenome = "";
        int pos = linha.find_last_of(" ");
        if (pos != std::string::npos) {
            sobrenome = linha.substr(pos + 1);
            linha.erase(pos);
        }
        std::string nome = "";
        std::string palavra;
        std::istringstream iss(linha);
        while (iss >> palavra) {
            nome += palavra + " ";
        }
        std::cout << sobrenome + ", " + nome << std::endl;
    }
    infile.close();
    return 0;
}

