#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#define N 10

using namespace std;

void DFS(int start, int graph[][10])
{
    stack <int> s; 
    bool visited[N];
    bool inqueue[N];
    int view_cell;
    for (int i = 0; i < N; i++)
    {
        visited[i] = inqueue[i] = false;
    }
    s.push(start); 
    visited[start] = inqueue[start] = true; 
    while (!s.empty())
    {
        view_cell = s.top(); 
        cout << view_cell + 1 << " ";

        visited[view_cell] = true;
        s.pop();
        for (int i = 0; i < N; i++)
        {
            if (!inqueue[i] && graph[view_cell][i])
            {
                s.push(i);
                inqueue[i] = true;
            }
        }
    }
}

void BFS(int start, int graph[][10])
{
    queue <int> q; 
    bool visited[N];
    bool inqueue[N];
    int view_cell; 
    for (int i = 0; i < N; i++)
    {
        visited[i] = inqueue[i] = false;
    }
    q.push(start);
    visited[start] = inqueue[start] = true; 
    while (!q.empty())
    {
        view_cell = q.front(); 
        cout << view_cell + 1 << " ";
        visited[view_cell] = true;
        q.pop();
        for (int i = 0; i < N; i++)
        {
            if (!inqueue[i] && graph[view_cell][i])
            {
                q.push(i);
                inqueue[i] = true;
            }
        }
    }
}

struct Edge
{
    int start;
    int finish;
};


int main()
{
    int grafM[10][10] = {
        {0,1,0,0,1,0,0,0,0,0},
        {1,0,0,0,0,0,1,1,0,0},
        {0,0,0,0,0,0,0,1,0,0},
        {0,0,0,0,0,1,0,0,1,0},
        {1,0,0,0,0,1,0,0,0,0},
        {0,0,0,1,1,0,0,0,1,0},
        {0,1,0,0,0,0,0,1,0,0},
        {0,1,1,0,0,0,1,0,0,0},
        {0,0,0,1,0,1,0,0,0,1},
        {0,0,0,0,0,0,0,0,1,0}
    };
    vector<Edge> edges =
    {
      {1, 2}, {2, 1}, {1, 5}, {5, 1},
      {2, 7}, {7, 2}, {2, 8}, {8, 2},
      {7, 8}, {8, 7}, {8, 3}, {3, 8},
      {5, 6}, {6, 5}, {4, 6}, {6, 4},
      {4, 9}, {9, 4}, {6, 9}, {9, 6},
      {9, 10}, {10, 9}
    };// список ребер
    int n = 11;
    vector<vector<int>> adjList; // список смежности
    adjList.resize(n);
    for (auto& edge : edges)
    {
        adjList[edge.start].push_back(edge.finish);
    }
    int startCell = 1;
    cin >> startCell;
    if (startCell >= 1 && startCell <= 10)
    {
        cout << "BFS" << endl;
        BFS(startCell - 1, grafM);// O(V+E) V - количество вершин E - Количество ребер
        cout << "\nDFS" << endl;
        DFS(startCell - 1, grafM); // O(V+E) V - количество вершин E - Количество ребер
    }
   
}