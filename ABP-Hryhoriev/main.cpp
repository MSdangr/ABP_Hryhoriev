#include <iostream>
#include "Lab_1/Lab_1.cpp"
#include "Lab_2/Lab_2_1.cpp"
#include "Lab_2/Lab_2_2.cpp"
#include "Lab_3/Lab_3.cpp"
#include "Lab_4/Lab_4.cpp"
#include "Lab_5/Lab_5.cpp"
#include "Lab_6/Lab_6.cpp"

using namespace std;
int main() {

    int numberLab;
    cout << "Vvedit nomer laborotornoi" << endl;
    cin >> numberLab;

    switch (numberLab) {
    case 1:
        Lab_1();
        break;
    case 21:
        Lab_2_1();
        break;
    case 22:
        Lab_2_2();
        break;
    case 3:
        Lab_3();
        break;
    case 4:
        Lab_4();
        break;
    case 5:
        Lab_5();
        break;
    case 6:
        Lab_6();
        break;

    default:
        cout << "Wrong number" << endl;
    }



return 0;
}

