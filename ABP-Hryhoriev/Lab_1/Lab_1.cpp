#include <iostream>
#include <iomanip>

using namespace std;

int Lab_1()
{

     //Масиви
     char name1[20], name2[20], name3[20];  // Масив прізвищ
     char in1[3], in2[3], in3[3];           // Масив ініціалів
     char rn1[5], rn2[5], rn3[5];           // Масив року народження
     double ok1, ok2, ok3;                  // Оклад

     // Введення даних
     cout << "1. Vvedit: prizvyshche, initsialy, rik narodzhennya, oklad > ";
     cin >> name1 >> in1 >> rn1 >> ok1;
     cout << "2. Vvedit: prizvyshche, initsialy, rik narodzhennya, oklad > ";
     cin >> name2 >> in2 >> rn2 >> ok2;
     cout << "3. Vvedit: prizvyshche, initsialy, rik narodzhennya, oklad > ";
     cin >> name3 >> in3 >> rn3 >> ok3;

     // Вивід таблиці
     cout << "  +------------------------------------------------------------+" << endl;
     cout << "  |                        Viddil kadriv                       |" << endl;
     cout << "  +------------------------------------------------------------+" << endl;
     cout << "  | Prizvyshche    | Initsialy | Rik narodzhennya | Oklad      |" << endl;
     cout << "  +----------------+-----------+------------------+------------+" << endl;

     // Вивід Данних
     cout << "  | " << setw(16) << left << name1 << " | " << setw(9) << left << in1
        << " | " << setw(14) << left << rn1 << " | " << setw(14) << fixed << setprecision(2) << ok1 << " |" << endl;
     cout << "  | " << setw(16) << left << name2 << " | " << setw(9) << left << in2
          << " | " << setw(14) << left << rn2 << " | " << setw(14) << fixed << setprecision(2) << ok2 << " |" << endl;
     cout << "  | " << setw(16) << left << name3 << " | " << setw(9) << left << in3
          << " | " << setw(14) << left << rn3 << " | " << setw(14) << fixed << setprecision(2) << ok3 << " |" << endl;

     return 0;
}