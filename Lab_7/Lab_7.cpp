#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct lab7 {
    string surname;
    string initials;
    int birthYear;
    double salary;
};


void Sort(lab7 pratsivnyky[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (pratsivnyky[j].surname < pratsivnyky[minIndex].surname) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            lab7 temp = pratsivnyky[i];
            pratsivnyky[i] = pratsivnyky[minIndex];
            pratsivnyky[minIndex] = temp;
        }
    }
}

int Lab_7() {
    lab7 pratsivnyky[10];
    int n = 0;
    const int maxpratsivnyky = 10;


    while (n < maxpratsivnyky) {
        cout << n + 1 << ". Vvedit: prizvyshche, initsialy, rik narodzhennya, oklad > ";

        cin >> pratsivnyky[n].surname;
        if (pratsivnyky[n].surname == "***") {
            break;
        }


        cin >> pratsivnyky[n].initials;
        cin >> pratsivnyky[n].birthYear;
        cin >> pratsivnyky[n].salary;

        n++;
    }


    Sort(pratsivnyky, n);


    cout << "|----------------------------------------------------|\n";
    cout << "| Viddil kadriv                                      |\n";
    cout << "|----------------------------------------------------|\n";
    cout << "|Prizvyshe    |Initsialy  |Rik narodzhennya  |Oklad  |\n";
    cout << "|-------------|-----------|------------------|-------|\n";


    for (int i = 0; i < n; i++) {
        cout << setw(13) << pratsivnyky[i].surname << " | "
             << pratsivnyky[i].initials << " | "
             << setw(16) << pratsivnyky[i].birthYear << " | "
             << setw(19) << fixed << setprecision(2) << pratsivnyky[i].salary << " |" << endl;
    }

    cout << "|----------------------------------------------------|\n";
    cout << "| Prymitka: Oklad stanom na 1 sichnya 2000 roku. |\n";
    cout << "|----------------------------------------------------|\n";

    return 0;
}