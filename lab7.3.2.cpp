#include <iostream>
#include <Windows.h>
#include <time.h>
#include <iomanip>

using namespace std;
void Create(int** a, const int row, const int col, int low, int high);
void Print(int** a, const int row, const int col);
int Number(int** a, const int row, const int col, int k);
void Max(int** a, const int row, const int col);
int Null(int** a, const int row, const int col);
int main()
{
    srand((unsigned)time(NULL));

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int row;
    int col;
    int low;
    int high;

    cout << "Кількість рядків = "; cin >> row;
    cout << "Кількість стовпців = "; cin >> col;
    cout << "Діапазон значень" << endl;
    cout << "Найменше = "; cin >> low;
    cout << "Найбільше = "; cin >> high;
    int** a = new int* [row];
    for (int i = 0; i < row; i++)
        a[i] = new int[col];


    Create(a, row, col, low, high);
    Print(a, row, col); cout << endl;
    cout << "Кількість рядків, що не містять жодного нульового елементу:  " << Null(a, row, col) << endl;
    cout << "Максимальне число, що зустрічається більше, ніж раз:  " << endl;
    Max(a, row, col); cout << endl;
    for (int i = 0; i < row; i++)
        delete[] a[i];
    delete[] a;
    return 0;
}
void Create(int** a, const int row, const int col, const int low, const int high)
{
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            a[i][j] = low + rand() % (high - low + 1);
}
void Print(int** a, const int row, const int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
}
void Max(int** a, const int row, const int col)
{
    bool repfound;
    int valmax = 0;
    bool maxfound = false;
    int* b = new int[row * col];
    int pozb = 0;
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++) {
            repfound = false;
            for (int k = 0; k < pozb; k++) {
                if (a[i][j] == b[k]) {
                    repfound = true;
                    if (!maxfound) {
                        maxfound = true;
                        valmax = a[i][j];
                    }
                    else {
                        if (valmax < a[i][j])
                            valmax = a[i][j];
                    }
                    break;
                }
            }
            if (!repfound) {
                b[pozb] = a[i][j];
                pozb++;
            }
        }

    cout << valmax;

}
int Null(int** a, const int row, const int col)
{
    int count = 0;
    for (int i = 0; i < row; i++)
    {
        int s = 0;
        for (int j = 0; j < col; j++)
        {
            if (a[i][j] == 0) s++;
        }
        if (s == 0) count++;
    }
    return count;
}
