#include <iostream>
#include <Lab_1/Lab_1.cpp>
#include <Lab_2/Lab_2_1.cpp>
#include <Lab_2/Lab_2_2.cpp>

using namespace std;
int main() {
    int numberLab;
    cout << "Vvedit nomer laborotornoi" << endl;
    cin >> numberLab;

    switch (numberLab) {
    case 1:
        Lab_1();
        break;
    case 2_1:
        Lab_2_1();
        break;
    case 2_2:
        Lab_2_2();
        break;

    default:
        cout << "Wrong number" << endl;
    }



return 0;
}

