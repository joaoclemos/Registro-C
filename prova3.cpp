#include <iostream>
#include <vector>

using namespace std;

class Figura {
protected: // Para permitir acesso nas classes filhas
    float base;
    float altura;

public:
    Figura() : base(0.0f), altura(0.0f) {}
    Figura(float b, float h) : base(b), altura(h) {}
    
    virtual void Exibe() {
        cout << "Base: " << base << ", Altura: " << altura << endl;
    }

    float getBase() { return base; }
    float getAltura() { return altura; }
};

class Retangulo : public Figura {
public:
    // Construtor vazio
    Retangulo() : Figura() {}

    // Construtor com parâmetros
    Retangulo(float b, float h) : Figura(b, h) {}

    // Cálculo da área
    float GetArea() {
        return getBase() * getAltura();
    }

    // Cálculo do perímetro
    float GetPerimetro() {
        return 2 * getBase() + 2 * getAltura();
    }

    // Sobrescrita do método Exibe
    void Exibe() override {
        Figura::Exibe(); // Chama o Exibe da classe pai
        cout << "Area: " << GetArea() << endl;
        cout << "Perimetro: " << GetPerimetro() << endl;
    }
};

class Triangulo : public Figura {
public:
    // Construtor vazio
    Triangulo() : Figura() {}

    // Construtor com parâmetros
    Triangulo(float b, float h) : Figura(b, h) {}

    // Cálculo da área
    float GetArea() {
        return (getBase() * getAltura()) / 2;
    }

    // Cálculo do perímetro (equilátero, 3 vezes a base)
    float GetPerimetro() {
        return 3 * getBase();
    }

    // Sobrescrita do método Exibe
    void Exibe() override {
        Figura::Exibe(); // Chama o Exibe da classe pai
        cout << "Area: " << GetArea() << endl;
        cout << "Perimetro: " << GetPerimetro() << endl;
    }
};

int main() {
    vector<Figura*> figuras(5); // Vetor de 5 ponteiros para Figura

    // Criação e inicialização das figuras
    for (int i = 0; i < 5; i++) {
        int tipo;
        float base, altura;
        cout << "\nFigura " << i + 1 << ":" << endl;
        cout << "Escolha o tipo (1 para Retangulo, 2 para Triangulo): ";
        cin >> tipo;
        cout << "Digite a base: ";
        cin >> base;
        cout << "Digite a altura: ";
        cin >> altura;

        if (tipo == 1) {
            figuras[i] = new Retangulo(base, altura);
        } else if (tipo == 2) {
            figuras[i] = new Triangulo(base, altura);
        } else {
            cout << "Tipo inválido, usando Retangulo por padrão." << endl;
            figuras[i] = new Retangulo(base, altura);
        }
    }

    // Exibição dos dados de cada figura
    cout << "\nDetalhes das Figuras:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "\nFigura " << i + 1 << ":" << endl;
        figuras[i]->Exibe();
    }

    // Liberação de memória
    for (int i = 0; i < 5; i++) {
        delete figuras[i];
    }

    return 0;
}