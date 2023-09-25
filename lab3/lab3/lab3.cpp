#include <iostream>
#define N 9

using namespace std;

int minDistance(int dist[], bool sptSet[])
{
    int min = INT_MAX, min_index;
    for (int i = 0; i < N; i++)
        if (sptSet[i] == false && dist[i] <= min)
        {
            min = dist[i];
            min_index = i;
        }
    return min_index;
}

void print(int dist[])
{
    char str[9] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I' };
    for (int i = 0; i < N; i++)
        cout << str[i] << " " << dist[i] << endl;
}

void dejkstra(int graph[][N], int src)
{
    int dist[N]; 
    bool sptSet[N]; 
    for (int i = 0; i < N; i++)
    {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }
    dist[src] = 0;
    for (int count = 0; count < N - 1; count++)
    {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;

        for (int i = 0; i < N; i++)
            if (!sptSet[i] && graph[u][i] && dist[u] != INT_MAX && dist[u] + graph[u][i] < dist[i])
                dist[i] = dist[u] + graph[u][i];
    }
    print(dist);
}
int main()
{
    setlocale(LC_ALL, "rus");
    // A - 0, B - 1, C - 2, D - 3,
    // E - 4, F - 5, G - 6, H - 7, I - 8
    int graph[N][N] =
    {
        // A  B  C   D  E  F  G  H  I
          {0, 7, 10, 0, 0, 0, 0, 0, 0},
          {7, 0, 0, 0, 0, 9, 27, 0, 0},
          {10, 0, 0, 0, 31, 8, 0, 0, 0},
          {0, 0, 0, 0, 32, 0, 0, 17, 21},
          {0, 0, 31, 32, 0, 0, 0, 0, 0},
          {0, 9, 8, 0, 0, 0, 0, 11, 0},
          {0, 27, 0, 0, 0, 0, 0, 0, 15},
          {0, 0, 0, 17, 0, 11, 0, 0, 15},
          {0, 0, 0, 21, 0, 0, 15, 15, 0},
    };
    int st;
    cout << "A - 0, B - 1, C - 2, D - 3, E - 4, F - 5, G - 6, H - 7, I - 8" << endl;
    cin >> st;
    dejkstra(graph, st);
	return 0;
}
