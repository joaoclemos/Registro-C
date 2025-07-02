#include <iostream>
#include <algorithm>

using namespace std;

class Carro {
private:
    const double CAPACIDADE_TANQUE = 50.0;
    const double CONSUMO = 15.0;
    double combustivel;
    double distanciaPercorrida;

public:
    Carro() : combustivel(0.0), distanciaPercorrida(0.0) {}

    void abastecer(double quantidade) {
        combustivel = min(quantidade, CAPACIDADE_TANQUE);
    }

    void mover(double distancia) {
        double combustivelNecessario = distancia / CONSUMO;
        if (combustivel >= combustivelNecessario) {
            combustivel -= combustivelNecessario;
            distanciaPercorrida += distancia;
        } else {
            distanciaPercorrida += combustivel * CONSUMO;
            combustivel = 0.0;
        }
    }

    double getCombustivelRestante() {
        return combustivel;
    }

    double getDistanciaPercorrida() {
        return distanciaPercorrida;
    }
};

int main() {
    int combustivel1, combustivel2, distancia1, distancia2;
    cin >> combustivel1 >> combustivel2 >> distancia1 >> distancia2;

    Carro carro1, carro2;
    carro1.abastecer(combustivel1);
    carro2.abastecer(combustivel2);

    carro1.mover(distancia1);
    carro2.mover(distancia2);

    cout << "Carro 1:" << endl;
    cout << "Distância percorrida: " << (int)carro1.getDistanciaPercorrida() << endl;
    cout << "Combustível restante: " << (int)carro1.getCombustivelRestante() << endl;

    cout << "Carro 2:" << endl;
    cout << "Distância percorrida: " << (int)carro2.getDistanciaPercorrida() << endl;
    cout << "Combustível restante: " << (int)carro2.getCombustivelRestante() << endl;

    return 0;
}