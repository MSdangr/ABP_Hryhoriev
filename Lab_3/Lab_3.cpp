#include <iostream>

using namespace std;

int Lab_3() {

    const int size = 100;
    int Ar[size];
    int nn = 0;
    int av = 0;
    int ib = 0;
    int count_sequences = 0;


    srand(time(0));


    for (int i = 0; i < size; ++i) {
        Ar[i] = rand() % 101;
    }


    cout << "Pochatkovyi Masyv: " << endl;
    for (int i = 0; i < size; ++i) {
        cout << Ar[i] << " ";
    }
    cout << endl;


    ib = 0;
    for (int i = 1; i < size; ++i) {
        if (Ar[i] >= Ar[i - 1]) {

            nn++;
        } else {

            if (nn > 0) {
                count_sequences++;
            }
            nn = 0;
            ib = i;
        }
    }

    if (nn > 0) {
        count_sequences++;
    }


    cout << "Kilkist nepadauchyh poslidovnostey: " << count_sequences << endl;

    return 0;
}


