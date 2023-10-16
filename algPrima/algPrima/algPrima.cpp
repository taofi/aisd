#include <iostream>
#include <set>
#define N 8

using namespace std;

int** prima(int mtrx[N][N])
{
    int n = 0;
    int** newMtrx = new int* [N];
    for (int i = 0; i < N; i++)
    {
        newMtrx[i] = new int[N];
        for (int j = 0; j < N; j++)
            newMtrx[i][j] = 0;
    }
    bool markedPoint[N];
    int marked[N];
    for (int i = 0; i < N; i++)
        markedPoint[i] = false;

    int minI, minJ, minCh = INT_MAX, lastMin;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (minCh > mtrx[i][j] && mtrx[i][j] != 0)
            {
                minI = i;
                minJ = j;
                minCh = mtrx[i][j];
            }
        }
    }
    marked[0] = minI;
    marked[1] = minJ;
    n += 2;
    for (int i = 0; i < N; i++)
    {
        mtrx[minI][i] = 0;
        mtrx[minJ][i] = 0;
    }
    newMtrx[minI][minJ] = minCh;

    int m;
    while (n < N)
    {
        minCh = INT_MAX;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (minCh > mtrx[i][marked[j]] && mtrx[i][marked[j]] != 0)
                {
                    minI = i;
                    minJ = marked[j];
                    minCh = mtrx[i][marked[j]];
                }
            }
        }
        if (markedPoint[minI])
            m = minJ;
        else
            m = minI;
        for (int i = 0; i < N; i++)
            mtrx[m][i] = 0;
        newMtrx[minI][minJ] = minCh;
        markedPoint[m] = true;
        marked[n] = m;
        n++;
    }

    return newMtrx;
}


int main()
{
    int graph[N][N] =
    {
          {0, 2, 0,  8, 2, 0, 0, 0},
          {2, 0, 3, 10, 5, 0, 0, 0},
          {0, 3, 0, 0, 12, 0, 0, 7},
          {8, 10, 0, 0, 14, 3, 1, 0},
          {1, 5, 12, 14, 0, 11, 4, 8},
          {0, 0, 0, 3, 11, 0, 6, 0},
          {0, 0, 0, 1, 4, 6, 0, 9},
          {0, 0, 7, 0, 8, 0, 9, 0},
         
    };
    int cost = 0;
    int** mtrx = prima(graph);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << mtrx[i][j] << ' ';
            if (mtrx[i][j] != 0)
                cost += mtrx[i][j];
        }
        cout << endl;
    }
    cout << cost << endl;
    for (int i = 0; i < N; ++i) {
        delete[] mtrx[i]; 
    }
    delete[] mtrx;
}