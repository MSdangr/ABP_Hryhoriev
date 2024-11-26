#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

class Pratsivnyky {
    char *prizvyshche;
    char *initsialy;
    unsigned int rikNarodzhennya;
    float oklad;

public:
    Pratsivnyky() {
        prizvyshche = new char[1];
        prizvyshche[0] = '\0';
        initsialy = new char[1];
        initsialy[0] = '\0';
        rikNarodzhennya = 0;
        oklad = 0.0;
    }

    Pratsivnyky(const char* pryzv, const char* inits, unsigned int rik, float okld) {
        prizvyshche = new char[strlen(pryzv) + 1];
        strcpy(prizvyshche, pryzv);

        initsialy = new char[strlen(inits) + 1];
        strcpy(initsialy, inits);

        rikNarodzhennya = rik;
        oklad = okld;
    }

    ~Pratsivnyky() {
        delete[] prizvyshche;
        delete[] initsialy;
    }

    void set(const char* pryzv, const char* inits, unsigned int rik, float okld) {
        delete[] prizvyshche;
        prizvyshche = new char[strlen(pryzv) + 1];
        strcpy(prizvyshche, pryzv);

        delete[] initsialy;
        initsialy = new char[strlen(inits) + 1];
        strcpy(initsialy, inits);

        rikNarodzhennya = rik;
        oklad = okld;
    }

    void input() {
        char pryzv[50];
        char inits[10];
        cout << "Vvedit informaciyu pro pratsivnyka (prizvyshche initsialy rik_narodzhennya oklad): ";
        cin >> setw(50) >> pryzv >> setw(10) >> inits >> rikNarodzhennya >> oklad;
        set(pryzv, inits, rikNarodzhennya, oklad);
    }

    void show() const {
        cout << "| " << setw(13) << left << prizvyshche
             << "| " << setw(9) << initsialy
             << "| " << setw(16) << rikNarodzhennya
             << "| " << setw(7) << fixed << setprecision(2) << oklad << " |\n";
    }
};

void showtable(const Pratsivnyky* pratsivnyky, int count) {
    cout << "|------------------------------------------------------|\n";
    cout << "|                   Viddil kadriv                      |\n";
    cout << "|------------------------------------------------------|\n";
    cout << "| Prizvyshche    | Initsialy | Rik narodzhennya| Oklad |\n";
    cout << "|----------------|-----------|-----------------|-------|\n";

    for (int i = 0; i < count; i++) {
        pratsivnyky[i].show();
    }
    cout << "|------------------------------------------------------|\n";
}

int Lab_10() {
    int count;
    cout << "Vvedit kilkist pratsivnykiv: ";
    cin >> count;

    Pratsivnyky *pratsivnyky = new Pratsivnyky[count];
    for (int i = 0; i < count; i++) {
        cout << "Vvedit danni dlya pratsivnyka " << i + 1 << ":\n";
        pratsivnyky[i].input();
    }

    showtable(pratsivnyky, count);

    delete[] pratsivnyky;
    return 0;
}