#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Employee {
    string surname;   // Прізвище
    string initials;  // Ініціали
    int birthYear;    // Рік народження
    double salary;    // Оклад
};

// Функція сортування (методом вибору за прізвищем)
void selectionSort(Employee employees[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (employees[j].surname < employees[minIndex].surname) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            Employee temp = employees[i];
            employees[i] = employees[minIndex];
            employees[minIndex] = temp;
        }
    }
}

int Lab_7() {
    Employee employees[10]; // Масив для 10 співробітників
    int n = 0; // Кількість введених співробітників
    const int maxEmployees = 10;

    // Цикл введення даних
    while (n < maxEmployees) {
        cout << n + 1 << ". Vvedit: prizvyshche, initsialy, rik narodzhennya, oklad > ";

        // Введення прізвища
        cin >> employees[n].surname;

        // Перевірка на закінчення введення
        if (employees[n].surname == "***") {
            break; // Вихід з циклу, якщо введено "***"
        }

        // Введення ініціалів
        cin >> employees[n].initials;

        // Введення року народження
        cin >> employees[n].birthYear;

        // Введення окладу
        cin >> employees[n].salary;

        n++; // Збільшення лічильника співробітників
    }

    // Сортування співробітників за прізвищем
    selectionSort(employees, n);

    // Виведення заголовка таблиці
    cout << "|----------------------------------------------------|\n";
    cout << "| Viddil kadriv                                      |\n";
    cout << "|----------------------------------------------------|\n";
    cout << "|Prizvyshe    |Initsialy  |Rik narodzhennya  |Oklad  |\n";
    cout << "|-------------|-----------|------------------|-------|\n";

    // Виведення даних співробітників
    for (int i = 0; i < n; i++) {
        cout << setw(13) << employees[i].surname << " | "
             << employees[i].initials << " | "
             << setw(16) << employees[i].birthYear << " | "
             << setw(19) << fixed << setprecision(2) << employees[i].salary << " |" << endl;
    }

    cout << "|----------------------------------------------------|\n";
    cout << "| Prymitka: Oklad stanom na 1 sichnya 2000 roku. |\n";
    cout << "|----------------------------------------------------|\n";

    return 0;
}
