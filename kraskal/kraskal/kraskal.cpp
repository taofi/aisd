#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> parent;
vector <int> rank1;

void make_set(int v) {
    parent[v] = v;
    rank1[v] = 0;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rank1[a] < rank1[b])
            swap(a, b);
        parent[b] = a;
        if (rank1[a] == rank1[b])
            rank1[a]++;
    }
}

struct Edge {
    int u, v, weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
    Edge(int U, int V, int W)
    {
        u = U;
        v = V;
        weight = W;
    }
};


int main()
{
    int n = 8;
    vector<Edge> edges;
    int graph[8][8] =
    {
          {0, 2, 0,  8, 2, 0, 0, 0},
          {0, 0, 3, 10, 5, 0, 0, 0},
          {0, 0, 0, 0, 12, 0, 0, 7},
          {0, 0, 0, 0, 14, 3, 1, 0},
          {0, 0, 0, 0, 0, 11, 4, 8},
          {0, 0, 0, 0, 0, 0, 6, 0},
          {0, 0, 0, 0, 0, 0, 0, 9},
          {0, 0, 0, 0, 0, 0, 0, 0},
    };
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
           if(graph[i][j] != 0) edges.push_back(Edge(i, j, graph[i][j]));
    }
    int cost = 0;
    vector<Edge> result;
    parent.resize(n);
    rank1.resize(n);
    for (int i = 0; i < n; i++)
        make_set(i);

    sort(edges.begin(), edges.end());

    for (Edge e : edges) {
        if (find_set(e.u) != find_set(e.v)) {
            cost += e.weight;
            result.push_back(e);
            union_sets(e.u, e.v);
        }
    }
    for (Edge e : result) {
        cout << e.u + 1 << " -> " << e.v + 1 << endl;
    }
    cout << cost << endl;
    return 0;
}