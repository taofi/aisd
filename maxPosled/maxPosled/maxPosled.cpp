#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

void findLIS(vector<int> const& arr)
{

    int n = arr.size();

    if (n == 0) {
        return;
    }

    vector<vector<int>> LIS(n, vector<int>{});

    LIS[0].push_back(arr[0]);

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i] && LIS[j].size() > LIS[i].size())
            {
                LIS[i] = LIS[j];
            }
        }

        LIS[i].push_back(arr[i]);
    }
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (LIS[j].size() <= LIS[i].size()) {
            j = i;
        }
    }

    cout << LIS[j].size() << "\n";

    for (int i : LIS[j]) {
        cout << i << " ";
    }
}

int main()
{
    setlocale(LC_ALL, "rus");
    vector<int> arr;
    int count, num;
    cin >> count;
    for (int i = 0; i < count; i++) {
        cin >> num;
        arr.push_back(num);
    }


    findLIS(arr);

    cout << "\n\n";
    return 0;
}