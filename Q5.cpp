#include <iostream>
#include <string>

using namespace std;

class Elevador {
private:
    int andarAtual;
    int totalAndares;
    int capacidade;
    int pessoasPresentes;

public:
    // Construtor padrão
    Elevador() : andarAtual(0), totalAndares(0), capacidade(0), pessoasPresentes(0) {}

    // Construtor com parâmetros
    Elevador(int cap, int total) : andarAtual(0), totalAndares(total), capacidade(cap), pessoasPresentes(0) {}

    // Inicializa o elevador
    void inicializa(int cap, int total) {
        capacidade = cap;
        totalAndares = total;
        andarAtual = 0;
        pessoasPresentes = 0;
    }

    // Simula entrada de uma pessoa
    void entra() {
        if (pessoasPresentes < capacidade) {
            pessoasPresentes++;
        }
    }

    // Simula saída de uma pessoa
    void sai() {
        if (pessoasPresentes > 0) {
            pessoasPresentes--;
        }
    }

    // Simula subir um andar
    void sobe() {
        if (andarAtual < totalAndares) {
            andarAtual++;
        }
    }

    // Simula descer um andar
    void desce() {
        if (andarAtual > 0) {
            andarAtual--;
        }
    }

    // Métodos de acesso
    int getAndarAtual() {
        return andarAtual;
    }

    int getTotalAndares() {
        return totalAndares;
    }

    int getCapacidade() {
        return capacidade;
    }

    int getPessoasPresentes() {
        return pessoasPresentes;
    }
};

int main() {
    int capacidade, totalAndares, numAcoes;
    string operacao;

    // Leitura de capacidade e total de andares
    cin >> capacidade >> totalAndares;

    // Criação e inicialização de dois elevadores
    Elevador elevador1, elevador2;
    elevador1.inicializa(capacidade, totalAndares);
    elevador2.inicializa(capacidade, totalAndares);

    // Leitura do número de ações
    cin >> numAcoes;
    cin.ignore(); // Ignora o '\n' após o número

    // Processamento das ações
    for (int i = 0; i < numAcoes; i++) {
        getline(cin, operacao);

        // Executa a operação no Elevador 1
        if (operacao == "entrar") {
            elevador1.entra();
        } else if (operacao == "sair") {
            elevador1.sai();
        } else if (operacao == "subir") {
            elevador1.sobe();
        } else if (operacao == "descer") {
            elevador1.desce();
        }

        // Exibe estado do Elevador 1
        cout << "Andar atual: " << elevador1.getAndarAtual() << endl;
        cout << "Pessoas presentes: " << elevador1.getPessoasPresentes() << endl;
    }

    return 0;
}