#include<iostream>
#include<iomanip>
using namespace std;

void Create(int* a, const int size, const int Low, const int High) {
    for (int i = 0; i < size; i++) {
        a[i] = Low + rand() % (High - Low + 1);
    }
}

void Print(int* a, const int size) {
    for (int i = 0; i < size; i++) {
        cout << setw(4) << a[i];
    }
    cout << "  ]" << endl;
}

int Find(int* a, const int size) {
    int max = a[0];
    int maxindex = 0;
    for (int i = 1; i < size; i++) {
        if (a[i] > max) {
            max = a[i];
            maxindex = i;
        }
    }
    return maxindex;
}

int Calculate(int* a, int size) {
    int first = -1;
    int product = 1;
    for (int i = 0; i < size; i++) {
        if (a[i] == 0) {
            if (first == -1) {
                first = i;
            }
            else {
                int second = i;
                if (first != second - 1) {
                    for (int j = first + 1; j < second; j++) {
                        product *= a[j];
                    }
                }
                else if (first == second - 1) {
                    product = 0;
                }
            }
        }
    }
    return product;
}

void ModifyMas(int* a, const int size) {
    int* result = new int[size];
    int evenIndex = 0;
    int oddIndex = size / 2;

    for (int i = 0; i < size; i++) {
        if (i % 2 != 0) {
            result[evenIndex] = a[i];
            evenIndex++;
        }
        else {
            result[oddIndex] = a[i];
            oddIndex++;
        }
    }

    for (int i = 0; i < size; i++) {
        a[i] = result[i];
    }

    delete[] result;
}

int main() {
    srand(static_cast<unsigned>(time(NULL)));
    int n1;
    cout << "n = "; cin >> n1;
    const int n = n1;
    int* a = new int[n];    // виділення пам'яті для масиву
    int Low = 0;
    int High = 7;

    Create(a, n, Low, High);
    cout << "mas =          ["; Print(a, n);
    cout << "Index of the max: [" << Find(a, n) << "]" << endl;
    cout << "0 .... 0 = " << Calculate(a, n) << endl;
    ModifyMas(a, n);
    cout << "modifyed mas = ["; Print(a, n);
    delete[] a; // Звільнення виділеної пам'яті після використання масиву

    return 0;
}
