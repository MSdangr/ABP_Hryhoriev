#include <iostream>
using namespace std;

void fill(int* matrix, int size) {
    srand(time(0));


    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i * size + j] = rand() % 201 - 100;
        }
    }


    cout << "Matrytsya:" << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << matrix[i * size + j] << "\t";
        }
        cout << endl;
    }


    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i; j++) {

            swap(matrix[i * size + j], matrix[(size - j - 1) * size + (size - i - 1)]);
        }
    }


    cout << "Symetrychna matrytsya:" << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << matrix[i * size + j] << "\t";
        }
        cout << endl;
    }
}





int Lab_6() {
    int *Ar;
    int S;
    int size;


    cout << "Vvedit rozmir matrytsi: ";
    cin >> S;


    if (S <= 0) {
        cout << "Rozmir matrytsi povynen buty > 0" << endl;
        return 1;
    }


    size = S * S;


    Ar = new int[size];


    for (int i = 0; i < size; i++) {
        Ar[i] = 0;
    }


    fill(Ar, S);


     cout << "Matrix is displaying... " << endl;
    fill(Ar, S);


    delete[] Ar;

    return 0;
    }

