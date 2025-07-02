#include <iostream>
#include <vector>

using namespace std;

class Figura {
private:
    int numLados;
    float altura, base;

public:
    // Construtor padrão
    Figura() {
        Inicializar(1, 1.0f, 1.0f);
    }

    // Construtor parametrizado
    Figura(float novaBase, float novaAltura, int lados) {
        Inicializar(lados, novaBase, novaAltura);
    }

    // Método de inicialização
    void Inicializar(int lados, float nBase, float nAltura) {
        SetLados(lados);
        SetBase(nBase);
        SetAltura(nAltura);
    }

    // Setters (atribuem valores)
    void SetAltura(float nova) {
        if (nova >= 0) altura = nova;
    }

    void SetBase(float nova) {
        if (nova >= 0) base = nova;
    }

    void SetLados(int quant) {
        if (quant >= 0) numLados = quant;
    }

    // Getters (retornam valores)
    float GetAltura() {
        return altura;
    }

    float GetBase() {
        return base;
    }

    int GetLados() {
        return numLados;
    }

    // Método para exibir os atributos
    void Exibe() {
        cout << "Numero de Lados: " << GetLados() << endl;
        cout << "Altura: " << GetAltura() << endl;
        cout << "Base: " << GetBase() << endl;
    }
};

int main() {
    vector<Figura> figuras(10); // Vetor de 10 figuras

    // Solicitação e atualização dos dados para cada figura
    for (int i = 0; i < 10; i++) {
        int lados;
        float altura, base;
        cout << "Figura " << i + 1 << ":" << endl;
        cout << "Digite o numero de lados: ";
        cin >> lados;
        cout << "Digite a altura: ";
        cin >> altura;
        cout << "Digite a base: ";
        cin >> base;
        figuras[i].SetLados(lados);
        figuras[i].SetAltura(altura);
        figuras[i].SetBase(base);
    }

    // Exibição dos dados de cada figura
    cout << "\nDetalhes das Figuras:" << endl;
    for (int i = 0; i < 10; i++) {
        cout << "\nFigura " << i + 1 << ":" << endl;
        figuras[i].Exibe();
    }

    return 0;
}