#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<int>> edges;
vector<int> visited;
vector<int> ans;

void print_matr() {
    for (int i = 0; i < edges.size(); i++) {
        cout << i + 1 << " ";
        for (int j = 0; j < edges[i].size(); j++) {
            cout << " " << edges[i][j] + 1 << " ";
        }
        cout << endl;
    }
}

void dfs(int v) {
    if (visited[v] == 1) {
        cout << -1;
        exit(0);
    }
    visited[v] = 1;
    for (int i = 0; i < edges[v].size(); i++) {
        if (visited[edges[v][i]] != 2) {
            dfs(edges[v][i]);
        }

    }
    ans.push_back(v);
    visited[v] = 2;
}

void topo_sort(int n) {
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }
    ans.clear();
    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            dfs(i);
        }
    }
    reverse(ans.begin(), ans.end());
}

int main() {
    int n, m;
    cin >> n >> m;
    edges.resize(n);
    visited.resize(n, 0);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        edges[a - 1].push_back(b - 1);
    }

    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            dfs(i);
        }
    }

    topo_sort(n);
    for (int an : ans) {
        cout << an + 1 << " ";
    }


    //print_matr();
}
