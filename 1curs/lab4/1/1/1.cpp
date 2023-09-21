#include <iostream>
#include <cstdlib>
#include <ctime>


using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    srand(time(0));
    int n, a[10000];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 100;
    }
    
    int mini;
    for (int i = 0; i < n; i++)
    {
        mini = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[mini])
                mini = j;
        if (i != mini)
            swap(a[i], a[mini]);
    }
    if (n <= 1000) for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    cout << endl;

    int *pbg = &a[0];
    int *pend = &a[n - 1];
    int sum = 0;

    while (pbg < pend)
    {
        sum+=* pend;
        cout << *pend << " " << *pbg << " ";
        pbg++;
        pend--;
    }
    if (n % 2 != 0) {
        cout << *pend;
        sum += *pend;
    }

    
    cout << endl << sum << endl;
    return 0;
}