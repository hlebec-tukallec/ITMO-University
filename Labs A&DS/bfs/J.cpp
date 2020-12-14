#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

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
   /* for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;*/

    vector<int> grandy(n);

    grandy[ans[0]] = 0;
    for (int i = 1; i < ans.size(); i++) {
        set<int> number;
        for (int j = 0; j < edges[ans[i]].size(); j++) {
           number.insert(grandy[edges[ans[i]][j]]);
        }
        int ch = 0;

        for (auto k : number) {
            if (k == ch) {
                ch++;
            }
            else break;
        }

        grandy[ans[i]] = ch;
    }

    for (int i = 0; i < ans.size(); i++) {
        cout << grandy[i] << endl;
    }
}
