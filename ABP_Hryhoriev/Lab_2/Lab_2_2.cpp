#include <iostream>
#include <cmath>

using namespace std;

double calculate_an(int n) {

    double result = pow(-1, n) * (1 - (2.0 * n - 1) / (2.0 * (n + 1)));
    return result;
}

int Lab_2_2() {
    int n;


    cout << "Vvedit znachennya n: ";
    cin >> n;


    double a_n = calculate_an(n);


    cout << "Znachennya a_" << n << " = " << a_n << endl;

    return 0;
}