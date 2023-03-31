#include <iostream>
#include <fstream>
#include <sstream>

int main() {
    std::ifstream infile("nomes.txt");
    if (!infile) {
        std::cout << "Não foi possível abrir o arquivo." << std::endl;
        return 1;
    }
    std::string line;
    while (std::getline(infile, line)) {
        std::string sobrenome = "";
        int pos = line.find_last_of(" ");
        if (pos != std::string::npos) {
            sobrenome = line.substr(pos + 1);
            line.erase(pos);
        }
        std::string iniciais = "";
        std::string palavra;
        std::istringstream iss(line);
        iss >> palavra;
        iniciais += palavra + " ";
        while (iss >> palavra) {
            if (palavra.length() > 2) {
                iniciais += palavra.substr(0, 1) + ". ";
            } else {
                iniciais += palavra + " ";
            }
        }
        std::cout << sobrenome + ", " + iniciais << std::endl;
    }
    infile.close();
    return 0;
}
