#include <iostream>
#include <ctime>

using namespace std;

int main()
{
    int n;
    unsigned long long int f0 = 0, f1 = 1, fn;
    cin >> n;
    setlocale(LC_ALL, "rus");
    clock_t start = clock();
    if (n < 2) 
    {
        cout << n << endl;
    }
    for (int i = 1; i < n; i++)
    {
        fn = f1 + f0;
        f0 = f1;
        f1 = fn;
    }
    cout << f1 << endl;
    clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Расчетное время циклом: %d минут %d секунд %d мс\n", int(seconds / 60), int(seconds - int(seconds / 60) * 60), int(seconds * 1000));
}