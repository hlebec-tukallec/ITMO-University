#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<pair<int, int>>> edges;
vector<bool> visited;
vector<int> ans;
vector<int> in;
vector<int> up;
int timer;

void print_matr() {
    for (int i = 0; i < edges.size(); i++) {
        cout << i + 1 << " ";
        for (int j = 0; j < edges[i].size(); j++) {
            cout << " " << edges[i][j].first + 1 << " ";
        }
        cout << endl;
    }
}

void dfs(int v, int parent = -1) {
    visited[v] = true;
    in[v] = up[v] = timer++;
    for (int i = 0; i < edges[v].size(); i++) {
        int tmp = edges[v][i].first;
        if (tmp == parent) {
            continue;
        }
        if (visited[tmp]) {
            up[v] = min(up[v], in[tmp]);
        } else {
            dfs(tmp, v);
            up[v] = min(up[v], up[tmp]);
            if (up[tmp] > in[v]) {
                ans.push_back(edges[v][i].second);
            }
        }
    }
}

void bridges(int n) {
    timer = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    edges.resize(n);
    in.resize(n);
    up.resize(n);
    visited.resize(n, false);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        edges[a - 1].push_back({b - 1, i + 1});
        edges[b - 1].push_back({a - 1, i + 1});
    }

    bridges(n);

   // print_matr();
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (int an : ans) {
        cout << an << " ";
    }
}
