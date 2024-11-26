#include <iostream>
#include <cstring>
using namespace std;

class Student {
protected:
    char* imia;
    int vik;
    char* universytet;

public:
    Student() : vik(0) {
        imia = new char[1];
        imia[0] = '\0';
        universytet = new char[1];
        universytet[0] = '\0';
    }


    Student(const char* studentImia, int studentVik, const char* univ) : vik(studentVik) {
        imia = new char[strlen(studentImia) + 1];
        strcpy(imia, studentImia);
        universytet = new char[strlen(univ) + 1];
        strcpy(universytet, univ);
    }


    Student(const Student& other) : vik(other.vik) {
        imia = new char[strlen(other.imia) + 1];
        strcpy(imia, other.imia);
        universytet = new char[strlen(other.universytet) + 1];
        strcpy(universytet, other.universytet);
    }


    ~Student() {
        delete[] imia;
        delete[] universytet;
    }

    // Metody ustanovky
    void setUniversytet(const char* univ) {
        delete[] universytet;
        universytet = new char[strlen(univ) + 1];
        strcpy(universytet, univ);
    }

    void setImia(const char* studentImia) {
        delete[] imia;
        imia = new char[strlen(studentImia) + 1];
        strcpy(imia, studentImia);
    }

    void setVik(int studentVik) {
        vik = studentVik;
    }

    virtual void pokazatyInfo() const {
        cout << "Im'ia: " << imia << endl;
        cout << "Vik: " << vik << endl;
        cout << "Universytet: " << universytet << endl;
    }
};

class AkademichnyZvit : public Student {
private:
    int* otsinky;
    int kilkistotsinok;

public:

    AkademichnyZvit() : Student(), otsinky(nullptr), kilkistotsinok(0) {}


    AkademichnyZvit(const char* studentImia, int studentVik, const char* univ, const int* studentOtsinky, int kilkist)
        : Student(studentImia, studentVik, univ), kilkistotsinok(kilkist) {
        otsinky = new int[kilkistotsinok];
        for (int i = 0; i < kilkistotsinok; ++i) {
            otsinky[i] = studentOtsinky[i];
        }
    }


    AkademichnyZvit(const AkademichnyZvit& other) : Student(other), kilkistotsinok(other.kilkistotsinok) {
        otsinky = new int[kilkistotsinok];
        for (int i = 0; i < kilkistotsinok; ++i) {
            otsinky[i] = other.otsinky[i];
        }
    }

    // Destruktor
    ~AkademichnyZvit() {
        delete[] otsinky;
    }

    void vvestyOtsinky(int kilkist) {
        kilkistotsinok = kilkist;
        delete[] otsinky;
        otsinky = new int[kilkistotsinok];
        cout << "Vvedit " << kilkistotsinok << " otsinok: ";
        for (int i = 0; i < kilkistotsinok; ++i) {
            cin >> otsinky[i];
        }
    }

    void pokazatyInfo() const override {
        Student::pokazatyInfo();
        cout << "Otsinky: ";
        for (int i = 0; i < kilkistotsinok; ++i) {
            cout << otsinky[i] << " ";
        }
        cout << endl;
    }
};

int Lab_11() {
    int kilkistotsynok;
    char imia[100];
    int vik;
    char universytet[100];

    cout << "Vvedit informatsiyu pro studenta #1:\n";
    cout << "Im'ia: ";
    cin.ignore();
    cin.getline(imia, 100);
    cout << "Vik: ";
    cin >> vik;
    cout << "Universytet: ";
    cin.ignore();
    cin.getline(universytet, 100);
    cout << "Kilkist otsinok: ";
    cin >> kilkistotsynok;

    AkademichnyZvit student1(imia, vik, universytet, nullptr, 0);
    student1.vvestyOtsinky(kilkistotsynok);

    cout << "\nVvedit informatsiyu pro studenta #2:\n";
    cout << "Im'ia: ";
    cin.ignore();
    cin.getline(imia, 100);
    cout << "Vik: ";
    cin >> vik;
    cout << "Universytet: ";
    cin.ignore();
    cin.getline(universytet, 100);
    cout << "Kilkist otsinok: ";
    cin >> kilkistotsynok;

    AkademichnyZvit student2(imia, vik, universytet, nullptr, 0);
    student2.vvestyOtsinky(kilkistotsynok);

    cout << "\nInformatsiia pro studenta #1 z akademichnym zvitom:" << endl;
    student1.pokazatyInfo();

    cout << "\nInformatsiia pro studenta #2 z akademichnym zvitom:" << endl;
    student2.pokazatyInfo();

    return 0;
}

