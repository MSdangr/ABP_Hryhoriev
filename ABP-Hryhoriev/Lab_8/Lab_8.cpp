#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Pratsivnyk {
    string surname;    // Прізвище
    string initials;   // Ініціали
    int birthYear;     // Рік народження
    double salary;     // Оклад
    Pratsivnyk* next;  // Вказівник на наступний елемент стека
};

// Додавання нового елемента в стек
bool push(Pratsivnyk*& top) {
    Pratsivnyk* newElement = new Pratsivnyk;

    cout << "Vvedit: prizvyshche, initsialy, rik narodzhennya, oklad > ";
    cin >> newElement->surname;

    if (newElement->surname == "***") {
        delete newElement;  // Вивільняємо пам'ять, якщо введено завершення
        return false;       // Повертаємо false для завершення циклу
    }

    cin >> newElement->initials >> newElement->birthYear >> newElement->salary;
    newElement->next = top;
    top = newElement;
    return true;            // Повертаємо true, якщо введення успішне
}

// Виведення та сортування даних стека
void displayAndSortStack(Pratsivnyk* top) {
    for (Pratsivnyk* i = top; i != nullptr; i = i->next) {
        Pratsivnyk* minNode = i;
        for (Pratsivnyk* j = i->next; j != nullptr; j = j->next) {
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

    Pratsivnyk* current = top;
    while (current != nullptr) {
        cout << setw(13) << current->surname << " | "
             << current->initials << " | "
             << setw(16) << current->birthYear << " | "
             << setw(19) << fixed << setprecision(2) << current->salary << " |" << endl;
        current = current->next;
    }

    cout << "|----------------------------------------------------|\n";
    cout << "| Prymitka: Oklad stanom na 1 sichnya 2000 roku.     |\n";
    cout << "|----------------------------------------------------|\n";
}

// Основна функція
int Lab_8() {
    Pratsivnyk* top = nullptr;
    const int maxEmployees = 10;
    int count = 0;

    while (count < maxEmployees) {
        cout << count + 1 << ". ";
        if (!push(top)) {  // Якщо введено "***", вихід з циклу
            break;
        }
        count++;
    }

    if (top) {
        displayAndSortStack(top);
    } else {
        cout << "Spysok porozhniy.\n";
    }

    return 0;
}
