#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<int>> edges;
vector<int> visited;
vector<int> ans;

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
}

int main() {
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    int n, m, s;
    cin >> n >> m >> s;
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
   /* for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;*/

    vector<bool> game(n, false);
    game[ans[0]] = false;
    for (int i = 1; i < ans.size(); i++) {
        for (int j = 0; j < edges[ans[i]].size(); j++) {
            if (!game[edges[ans[i]][j]]) {
                game[ans[i]] = true;
                break;
            }
        }
    }

    if (game[s - 1]) {
        cout << "First player wins";
    }
    else {
        cout << "Second player wins";
    }
   // cout << game[s - 1];
}
