#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct lab8 {
    string surname;
    string initials;
    int birthYear;
    double salary;
    lab8* next;
};


lab8* top = nullptr;


void StvorytyStek() {
    lab8* newElement;
    int count = 0;
    const int maxEmployees = 10;

    while (count < maxEmployees) {
        newElement = new lab8;
        cout << "Vvedit: prizvyshche, initsialy, rik narodzhennya, oklad > ";
        cin >> newElement->surname;


        if (newElement->surname == "***") {
            delete newElement;
            break;
        }

        cin >> newElement->initials >> newElement->birthYear >> newElement->salary;
        newElement->next = top;
        top = newElement;
        count++;
    }
}


void vyluchenniazsteku() {

    for (lab8* i = top; i != nullptr; i = i->next) {
        lab8* minNode = i;
        for (lab8* j = i->next; j != nullptr; j = j->next) {
            if (j->surname < minNode->surname) {
                minNode = j;
            }
        }
        if (minNode != i) {
            swap(i->surname, minNode->surname);
            swap(i->initials, minNode->initials);
            swap(i->birthYear, minNode->birthYear);
            swap(i->salary, minNode->salary);
        }
    }


    cout << "|----------------------------------------------------|\n";
    cout << "| Viddil kadriv                                      |\n";
    cout << "|----------------------------------------------------|\n";
    cout << "|Prizvyshe    |Initsialy  |Rik narodzhennya  |Oklad  |\n";
    cout << "|-------------|-----------|------------------|-------|\n";

    lab8* current = top;
    while (current != nullptr) {
        cout << setw(13) << current->surname << " | "
             << current->initials << " | "
             << setw(16) << current->birthYear << " | "
             << setw(13) << fixed << setprecision(2) << current->salary << " |" << endl;
        current = current->next;
    }

    cout << "|----------------------------------------------------|\n";
    cout << "| Prymitka: Oklad stanom na 1 sichnya 2000 roku.     |\n";
    cout << "|----------------------------------------------------|\n";
}


int Lab_8() {
    StvorytyStek();

    if (top != nullptr) {
        vyluchenniazsteku();
    } else {
        cout << "Spysok porozhniy.\n";
    }

    return 0;
}
