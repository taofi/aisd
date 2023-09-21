#include <iostream>

using namespace std;

unsigned long long int fib(unsigned long long int n)
{
    if (n < 2) {
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
    }
    return fib(n - 2) + fib(n - 1);
}

int main()
{
    setlocale(LC_ALL, "rus");
    unsigned long long int n;
    cin >> n;
    clock_t start = clock();
    cout << fib(n) << endl;
    clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Расчетное время рекурсией: %d минут %d секунд %d мс\n", int(seconds / 60), int(seconds), int ((seconds - int(seconds)) * 1000));
}