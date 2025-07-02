#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Relogio {
private:
    int hora, minuto, segundo;

public:
    Relogio(int h, int m, int s) : hora(h), minuto(m), segundo(s) {}

    void definirHorario(int h, int m, int s) {
        hora = h;
        minuto = m;
        segundo = s;
    }

    string obterHorario() {
        string h = (hora < 10 ? "0" : "") + to_string(hora);
        string m = (minuto < 10 ? "0" : "") + to_string(minuto);
        string s = (segundo < 10 ? "0" : "") + to_string(segundo);
        return h + ":" + m + ":" + s;
    }

    void avancarSegundo() {
        segundo++;
        if (segundo >= 60) {
            segundo = 0;
            minuto++;
            if (minuto >= 60) {
                minuto = 0;
                hora++;
                if (hora >= 24) {
                    hora = 0;
                }
            }
        }
    }
};

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int h, m, s;
        cin >> h >> m >> s;
        Relogio relogio(h, m, s);
        relogio.avancarSegundo();
        cout << relogio.obterHorario() << endl;
    }

    return 0;
}