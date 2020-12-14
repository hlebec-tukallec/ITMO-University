#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<vector<int>> edges;
vector<vector<int>> tr_edges;
vector<vector<int>> edges_safe;
vector<bool> visited;
vector<bool> used;
vector<int> order;
vector<int> components;
set<pair<int, int>> doubles;
vector<int> colors_comp;
int color = 0;
int cnt = 0;

void dfs(int v) {
    visited[v] = true;
    for (int i = 0; i < edges[v].size(); i++) {
        if (!visited[edges[v][i]]) {
            dfs(edges[v][i]);
        }
    }
    order.push_back(v);
}

void dfsy(int v) {
    used[v] = true;
    components.push_back(v);
    for (int i = 0; i < tr_edges[v].size(); i++) {
        if (!used[tr_edges[v][i]]) {
            dfsy(tr_edges[v][i]);
        }
    }
}

bool inside_comp(int v) {
    for (int i = 0; i < components.size(); i++) {
        if (components[i] == v) {
            return true;
        }
    }
    return false;
}

void cleaning_comp() {
    for (int i = 0; i < components.size(); i++) {
        colors_comp[components[i]] = color;
        for (int j = 0; j < edges[components[i]].size(); j++) {
            if (inside_comp(edges[components[i]][j])) {
                edges_safe[components[i]][j] = -1;
            }
        }
    }
}

void count_edges() {
    for (int i = 0; i < edges_safe.size(); i++) {
        for (int j = 0; j < edges_safe[i].size(); j++) {
            if (edges_safe[i][j] != -1) {
                doubles.insert({colors_comp[i], colors_comp[edges_safe[i][j]]});
            }
        }
    }
    cnt += doubles.size();
}

int main() {
    int n, m;
    cin >> n >> m;
    visited.resize(n, false);
    edges.resize(n);
    edges_safe.resize(n);
    tr_edges.resize(n);
    used.resize(n, false);
    colors_comp.resize(n);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        edges[a - 1].push_back(b - 1);
        edges_safe[a - 1].push_back(b - 1);
        tr_edges[b - 1].push_back(a - 1);
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    for (int i = 0; i < n; i++) {
        int v = order[n - 1 - i];
        if (!used[v]) {
            dfsy(v);
            color++;
            cleaning_comp();
            components.clear();
        }
    }

    count_edges();

    cout << cnt;
    return 0;
}
