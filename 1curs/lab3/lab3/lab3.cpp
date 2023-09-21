#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void quicksort(int* mas, int first, int last);

int main()
{
    setlocale(LC_ALL, "rus");
    srand(time(0));
    int n;
    cin >> n;
    int *a = new int[n], *b = new int[n], *c = new int[n], *d = new int[n], *e = new int[n];
    unsigned int startTime;
    unsigned int endTime;
    double sec;
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 1000;
        b[i] = c[i] = d[i] = e[i] = a[i];
    }
    cout << "Пузырьковая сортировка\n";
    startTime = clock();
    for (int i = 1; i < n; i++)
        for (int j = 0; j < n - i; j++)
            if (b[j] > b[j + 1])
                swap(b[j], b[j + 1]);
    endTime = clock(); 
    if (n <= 1000) for (int i = 0; i < n; i++) {
        printf("%d ", b[i]);
    }
    cout << "\nвремя выполнения " << endTime - startTime <<"ms\n\n\n";
    cout << "Cортировка вставкой\n";
    startTime = clock();
    for (int i = 1; i < n; i++)
        for (int j = i; j > 0 && c[j - 1] > c[j]; j--)
                swap(c[j], c[j - 1]);
    endTime = clock();
    if (n <= 1000) for (int i = 0; i < n; i++) {
        printf("%d ", c[i]);
    }
    cout << "\nвремя выполнения " << endTime - startTime << "ms\n\n\n";

    cout << "Cортировка выбора\n";
    startTime = clock();
    int mini;
    for (int i = 0; i < n; i++)
    {
        mini = i;
        for (int j = i + 1; j < n; j++)
            if (d[j] < d[mini])
                mini = j;
        if (i != mini)
            swap(d[i], d[mini]);
    }
    endTime = clock();
    if (n <= 1000) for (int i = 0; i < n; i++) {
        printf("%d ", d[i]);
    }
    cout << "\nвремя выполнения " << endTime - startTime << "ms\n\n\n";

    cout << "Быстрая сортировка\n";
    startTime = clock();
    quicksort(e, 0, n - 1);
    endTime = clock();
    if(n <= 1000)
    for (int i = 0; i < n; i++) {
        printf("%d ", e[i]);
    }
    cout << "\nвремя выполнения " << endTime - startTime << "ms\n\n\n";

        delete []a;
        delete []b;
        delete []c;
        delete []d;
        delete []e;
}

void quicksort(int* mas, int first, int last) {
    int half;
    int f = first, l = last;
    half = mas[(f + l) / 2];
    do {
        while (mas[f] < half) 
            f++;
        while (mas[l] > half)
            l--;
        if (f <= l)
        {
            swap(mas[f], mas[l]);
            f++;
            l--;
        }
    } while (f < l);
    if (first < l)quicksort(mas, first, l);
    if (f < last)quicksort(mas, f, last);
}