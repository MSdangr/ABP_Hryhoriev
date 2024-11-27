#include <iostream>
using namespace std;

class DynamicArrayBase {
public:
    virtual void SetElement(int index, int value) = 0;
    virtual int GetElement(int index) const = 0;
    virtual void Print() const = 0;
    virtual int Find(int value) const = 0;
    virtual void Clear() = 0;
    virtual ~DynamicArrayBase() = default;
};

class DynamicArray : public DynamicArrayBase {
private:
    int* array;
    int size;

public:
    DynamicArray() : array(nullptr), size(0) {}

    DynamicArray(int size) : size(size) {
        array = new int[size];
        for (int i = 0; i < size; ++i) {
            array[i] = 0;
        }
    }

    DynamicArray(const DynamicArray& other) : size(other.size) {
        array = new int[size];
        for (int i = 0; i < size; ++i) {
            array[i] = other.array[i];
        }
    }

    ~DynamicArray() {
        delete[] array;
    }

    void SetElement(int index, int value) override {
        if (index < 0 || index >= size) {
            cout << "Indeks pozam mezhamy\n";
            return;
        }
        array[index] = value;
    }

    int GetElement(int index) const override {
        if (index < 0 || index >= size) {
            cout << "Indeks pozam mezhamy\n";
            return -1;
        }
        return array[index];
    }

    void Print() const override {
        for (int i = 0; i < size; ++i) {
            cout << array[i] << " ";
        }
        cout << endl;
    }

    int Find(int value) const override {
        for (int i = 0; i < size; ++i) {
            if (array[i] == value) {
                return i;
            }
        }
        return -1;
    }

    void Clear() override {
        delete[] array;
        array = nullptr;
        size = 0;
    }
};

int Lab_14() {
    cout << "dynamichnyi masyv:\n";

    DynamicArray arr(5);
    cout << "Masyv pislya stvorennya:\n";
    arr.Print();

    cout << "\nZadannya znachen elementiv masyvu:\n";
    for (int i = 0; i < 5; ++i) {
        arr.SetElement(i, i * 2);
    }
    arr.Print();

    cout << "\nOtrymannya elementa za indeksom 2:\n";
    cout << arr.GetElement(2) << endl;

    cout << "\nPoshuk elementa '6' u masyvi:\n";
    int index = arr.Find(6);
    if (index != -1) {
        cout << "Element znajdeno za indeksom: " << index << endl;
    } else {
        cout << "Element ne znajdeno\n";
    }

    cout << "\nOchyshchennya masyvu:\n";
    arr.Clear();
    arr.Print();

    cout << "\nStvorennya kopii masyvu:\n";
    DynamicArray arr2(3);
    arr2.SetElement(0, 10);
    arr2.SetElement(1, 20);
    arr2.SetElement(2, 30);
    DynamicArray arrCopy = arr2;
    cout << "Originalnyy masiv:\n";
    arr2.Print();
    cout << "Kopiya masyvu:\n";
    arrCopy.Print();

    return 0;
}
