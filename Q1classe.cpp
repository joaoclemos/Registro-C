#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Pessoa {
private:
    string nome;
    int idade;
    double altura;

public:
    Pessoa(string n, int i, double a) : nome(n), idade(i), altura(a) {}

    void exibir() {
        cout << "Nome: " << nome << ", Idade: " << idade << ", Altura: " << altura << endl;
    }
};

int main() {
    int N;
    cin >> N;
    vector<Pessoa> pessoas;

    for (int i = 0; i < N; i++) {
        string nome;
        int idade;
        double altura;
        cin >> nome >> idade >> altura;
        pessoas.emplace_back(nome, idade, altura);
    }

    for (auto& p : pessoas) {
        p.exibir();
    }

    return 0;
}