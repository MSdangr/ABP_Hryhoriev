#include <iostream>

using namespace std;

int Lab_2_1() {

    double x, y;

    cout << "Vvedit koordynaty tochky:" << endl;
    cout << "x = ";
    cin >> x;
    cout << "y = ";
    cin >> y;

    cout << "x = " << x << endl;
    cout << "y = " << y << endl;

    if ( x*x + y == 1 || (x >= 1 && y >= 1) ) {
        cout << "Tochka ne popadaye v oblast";
    } else {
        cout << "Tochka popadaye v oblast" << endl;
    }

    return 0;
}