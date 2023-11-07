#include<iostream>
#include<iomanip>
#include<ctime>
#include<cstdlib>
#include<cmath>
using namespace std;

double* create(int n, const double Low, const double High)
{
    double* a = new double[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = Low + static_cast<double>(rand()) / RAND_MAX * (High - Low);
    }
    return a;
}

void print(double* a, int n)
{
    cout << "Array: ";
    for (int i = 0; i < n; i++)
    {
        if (i == n - 1) cout << setw(5) << a[i];
        else
            cout << a[i] << "," << setw(5);
    }
    cout << endl;
}

double Max(double* a, const int size)
{
    double max = a[0];
    for (int i = 1; i < size; i++)
    {
        if (a[i] > max)
            max = a[i];
    }
    return max;
}

double Sum(double* a, const int size)
{
    double S = 0;
    int last = -1; // Індекс останнього додатнього елементу

    for (int i = 0; i < size; i++)
    {
        if (a[i] > 0)
        {
            last = i;
        }
    }
    if (last == -1)
    {
        // Якщо немає додатніх елементів, повернути 0.
        return 0;
    }
    for (int i = 0; i < last; i++) {
        S += a[i];
    }

    return S;
}

void CompressArray(double* a, int n, double a_val, double b_val)
{
    int writeIndex = 0;
    for (int i = 0; i < n; i++) {
        if (abs(a[i]) < a_val || abs(a[i]) > b_val) {
            a[writeIndex] = a[i];
            writeIndex++;
        }
    }


    for (int i = writeIndex; i < n; i++) {
        a[i] = 0;
    }
}

int main()
{
    srand(static_cast<unsigned>(time(nullptr)));
    double Low = -20.0;
    double High = 30.0;

    double n;
    cout << "Enterthesize ";
    cin >> n;

    double* a = create(n, Low, High);
    cout << "InitialArray:" << endl;
    print(a, n);

    double a_val, b_val;
    cout << "Enter a: ";
    cin >> a_val;
    cout << "Enter b: ";
    cin >> b_val;

    CompressArray(a, n, a_val, b_val);

    cout << "ModifiedArray:" << endl;
    print(a, n);

    cout << "Max = " << Max(a, n) << endl;
    cout << "Sum = " << Sum(a, n) << endl;

    delete[] a;

    return 0;
}
