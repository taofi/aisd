#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    srand(time(0));
    int n, a[10000], k =1;
   // cin >> k;
    cin >> n;
    if (k == 0) {
        for (int i = 0; i < n; i++)
        {
            a[i] = rand() % 100;
        }
    }
    else{
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
    }
    
    int maxi;
    for (int i = 0; i < n; i++)
    {
        maxi = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] > a[maxi])
                maxi = j;
        if (i != maxi)
            swap(a[i], a[maxi]);
    }
    if (n <= 1000) for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    cout << endl;
    int countWin = 0;
    int d = 0;
    int i = 0;
    if (n <= 3)
        countWin = n;
    else
    {
        while (d != 3 && i < n - 1) {
            if (a[i] != a[i + 1])
                d++;
            if (d != 4)
                countWin++;
            i++;
        }
        if (countWin + 1 == n && a[n - 1] == a[n - 2])
        {
            countWin++;
        }
        else
        {
            if (a[n - 1] != a[n - 2] && d != 3)
            {
                countWin++;
            }
        }
        
    }
    cout << countWin << endl;
}
