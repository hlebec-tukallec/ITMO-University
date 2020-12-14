#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<vector<int>> edges;
vector<bool> visited;
set<int> ans;
vector<int> in;
vector<int> up;
int timer;

void dfs(int v, int parent = -1) {
    int kids = 0;
    visited[v] = true;
    in[v] = up[v] = timer++;
    for (int i = 0; i < edges[v].size(); i++) {
        int tmp = edges[v][i];
        if (tmp == parent) {
            continue;
        }
        if (visited[tmp]) {
            up[v] = min(up[v], in[tmp]);
        } else {
            dfs(tmp, v);
            kids++;
            up[v] = min(up[v], up[tmp]);
            if (up[tmp] >= in[v] && parent != -1) {
                ans.insert(v);
            }
        }
    }
    if (parent == -1 && kids > 1) {
        ans.insert(v);
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
        edges[a - 1].push_back(b - 1);
        edges[b - 1].push_back(a - 1);
    }

    timer = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    cout << ans.size() << endl;
    for (auto i: ans) {
        cout << i + 1 << " ";
    }
}
