#include <iostream>
#define N 6

using namespace std;

void buildOrderArr(int (&s)[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i == j)
                s[i][j] = 0;
            else
                s[i][j] = j + 1;
        }
    }
}

void printMtrx(int mtrx[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << mtrx[i][j] << " ";
        }
        cout << "\n";
    }
}

void buildFloydMtrx(int (&d)[N][N], int (&s)[N][N])
{
    for (int m = 0; m < N; m++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (i != j && i != m && j != m && d[i][m]!=INT_MAX && d[m][j] != INT_MAX && d[i][m] + d[m][j] < d[i][j] )
                {
                    d[i][j] = d[i][m] + d[m][j];
                    s[i][j] = m + 1;
                }
            }
        }
    }
}

int main()
{
    int graph[N][N] =
    {
          {0, 28, 21, 59, 12, 27},
          {7, 0, 24, INT_MAX, 21, 9},
          {9, 31, 0, 13, 11, INT_MAX},
          {8, INT_MAX, 5, 0, 16, INT_MAX},
          {14, 13, 15, 10, 0, 22},
          {15, 18, INT_MAX, INT_MAX, 6, 0},
    };
    int s[N][N];
    buildOrderArr(s);
    buildFloydMtrx(graph, s);
    cout << "d" << endl;
    printMtrx(graph);
    cout << "s" << endl;
    printMtrx(s);
}