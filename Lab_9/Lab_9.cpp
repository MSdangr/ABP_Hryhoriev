#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>

using namespace std;

struct workers {
    char surname[10];
    char initials[5];
    int birthYear;
    double salary;
} mm[30], temp;

int n;

void reset_file_position(fstream &file) {
    file.clear();
    file.seekg(0, ios::beg);
}

void initf(fstream &file, const char *filename) {
    file.open(filename, ios::in | ios::out | ios::binary | ios::trunc);
    if (!file) {
        cout << "Error" << endl;
    }
}

void commit(fstream &file) {
    file.close();
}

void f_add(fstream &file, const workers &signals) {
    file.clear();
    file.seekp(0, ios::end);
    file.write(reinterpret_cast<const char *>(&signals), sizeof(signals));
    file.flush();
}

int fcheck_number(fstream &file, int record_number) {
    file.seekg(record_number * sizeof(workers), ios::beg);
    workers temp;
    return file.read(reinterpret_cast<char *>(&temp), sizeof(workers)) ? 0 : -1;
}

void fshow_1(fstream &file, int record_number) {
    reset_file_position(file);
    file.seekg(record_number * sizeof(workers), ios::beg);
    workers temp;
    if (file.read(reinterpret_cast<char *>(&temp), sizeof(workers))) {
        cout << " Name : " << temp.surname
                << ", Initials: " << temp.initials

                << ", birthyear: " << temp.birthYear <<
                ", Salary: " << temp.salary
                << endl;
    } else {
        cout << "Ne znaideno" << endl;
    }
}

void fshow_all(fstream &file) {
    reset_file_position(file);
    file.seekg(0, ios::beg);
    workers temp;
    cout << "|-------------------------------------------------------|\n";
    cout << "|                   Viddil kadriv                       |\n";
    cout << "|-------------------------------------------------------|\n";
    cout << "| Prizvyshe     | Initsialy | Rik narodzhennya | Oklad  |\n";
    cout << "|---------------|-----------|------------------|--------|\n";
    while (file.read(reinterpret_cast<char *>(&temp), sizeof(workers))) {
        cout << "| " << setw(11) << temp.surname << " | "
                << setw(5) << temp.initials << " | "
                << setw(6) << temp.birthYear << " | "
                << setw(9) << temp.salary << " |" << endl;
    }
    cout << "|----------------------------------------------------|\n";
    cout << "| Prymitka: Oklad stanom na 1 sichnya 2000 roku.     |\n";
    cout << "|----------------------------------------------------|\n";
}

void fdel_item(fstream &file, const char *filename, int record_number) {
    fstream temp_file("temp.bin", ios::out | ios::binary);
    file.clear();
    file.seekg(0, ios::beg);
    workers temp;
    int current_record = 0;
    while (file.read(reinterpret_cast<char *>(&temp), sizeof(workers))) {
        if (current_record++ != record_number) {
            temp_file.write(reinterpret_cast<char *>(&temp), sizeof(workers));
        }
    }
    file.close();
    temp_file.close();
    remove(filename);
    rename("temp.bin", filename);
    file.open(filename, ios::in | ios::out | ios::binary);
    file.clear();  // Очищаємо стан потоку
}

int Lab_9() {
    fstream file;
    const char *filename = "lab9.txt";
    initf(file, filename);

    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Add row\n";
        cout << "2. Show row by number\n";
        cout << "3. Show all rows\n";
        cout << "4. Delete row by number\n";
        cout << "0. Exit\n";
        cout << "Your choise: ";
        cin >> choice;
        if (choice == 1) {
            workers new_signals;
            cout << "Enter surname: ";
            cin >> new_signals.surname;
            cout << "Enter initials: ";
            cin >> new_signals.initials;
            cout << "Enter birthyear: ";
            cin >> new_signals.birthYear;
            cout << "Enter salary: ";
            cin >> new_signals.salary;
            f_add(file, new_signals);
        } else if (choice == 2) {
            int record_number;
            cout << "Enter record number: ";
            cin >> record_number;
            fshow_1(file, record_number - 1);
        } else if (choice == 3) {
            fshow_all(file);
        } else if (choice == 4) {
            int record_number;
            cout << "Enter record number for delete: ";
            cin >> record_number;
            fdel_item(file, "lab9.txt", record_number - 1);
        }
    } while (choice != 0);
    file.close();
    return 0;
}