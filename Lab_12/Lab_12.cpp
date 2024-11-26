#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

class Pratsivnyk {
    char *prizvyshche;
    char *initsialy;
    unsigned int rikNarodzhennya;
    float oklad;

public:
    Pratsivnyk() {
        prizvyshche = new char[1];
        prizvyshche[0] = '\0';
        initsialy = new char[1];
        initsialy[0] = '\0';
        rikNarodzhennya = 0;
        oklad = 0.0;
    }

    Pratsivnyk(const char* pryzv, const char* inits, unsigned int rik, float okld) {
        prizvyshche = new char[strlen(pryzv) + 1];
        strcpy(prizvyshche, pryzv);

        initsialy = new char[strlen(inits) + 1];
        strcpy(initsialy, inits);

        rikNarodzhennya = rik;
        oklad = okld;
    }

    ~Pratsivnyk() {
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

    Pratsivnyk operator+(const Pratsivnyk& other) const {
        size_t newLength = strlen(prizvyshche) + strlen(other.prizvyshche) + 1;
        char* newPrizvyshche = new char[newLength];
        strcpy(newPrizvyshche, prizvyshche);
        strcat(newPrizvyshche, other.prizvyshche);

        Pratsivnyk result(newPrizvyshche, initsialy, rikNarodzhennya, oklad + other.oklad);
        delete[] newPrizvyshche;

        return result;
    }

    bool operator==(const Pratsivnyk& other) const {
        return (strcmp(prizvyshche, other.prizvyshche) == 0 && strcmp(initsialy, other.initsialy) == 0);
    }

    void input() {
        char pryzv[50];
        char inits[10];
        cout << "Vvedit prizvyshche, initsialy, rik narodzhennya, oklad > ";
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

void showtable(const Pratsivnyk* pratsivnyky, int count) {
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

int Lab_12() {
    int count;
    cout << "Vvedit kilkist pratsivnykiv: ";
    cin >> count;

    Pratsivnyk *pratsivnyky = new Pratsivnyk[count];
    for (int i = 0; i < count; i++) {
        cout << "Vvedit danni dlya pratsivnyka " << i + 1 << ":\n";
        pratsivnyky[i].input();
    }

    showtable(pratsivnyky, count);
    delete[] pratsivnyky;
    return 0;
}