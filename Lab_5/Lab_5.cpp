#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int Lab_5() {
    int *Ar;
    int size;


    cout << "Vvedit rozmir masyvu: ";
    cin >> size;


    if (size <= 0) {
        cout << "Rozmir masyvu maye buty dodatnim chyslom" << endl;
        return 1;
    }


    Ar = new int[size];


    srand(static_cast<unsigned int>(time(0)));


    for (int i = 0; i < size; i++) {
        Ar[i] = rand() % 201 - 100;
        cout << Ar[i] << " ";
    }
    cout << endl;


    int *NewAr = new int[size];


    for (int i = 0; i < size; i++) {

        int sum = Ar[i];
        int count = 1;


        if (i > 0) {
            sum += Ar[i - 1];
            count++;
        }


        if (i < size - 1) {
            sum += Ar[i + 1];
            count++;
        }


        NewAr[i] = sum / count;
    }


    cout << "Masyv-resultat: " << endl;
    for (int i = 0; i < size; i++) {
        cout << NewAr[i] << " ";
    }
    cout << endl;


    delete[] Ar;
    delete[] NewAr;

    return 0;
}
