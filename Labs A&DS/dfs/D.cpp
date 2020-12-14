#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector<vector<pair<int, int>>> edges;
vector<bool> visited;
vector<bool> br;
vector<int> in;
vector<int> up;
vector<int> color;
int maxColor;
int timer;

void dfs(int v, int ind = -1) {
    visited[v] = true;
    in[v] = up[v] = timer++;
    for (int i = 0; i < edges[v].size(); i++) {
        int tmp_ed = edges[v][i].second;
        int tmp_v = edges[v][i].first;
        if (tmp_ed == ind) {
            continue;
        }
        if (visited[tmp_v]) {
            up[v] = min(up[v], in[tmp_v]);
        } else {
            dfs(tmp_v, tmp_ed);
            up[v] = min(up[v], up[tmp_v]);
            if (up[tmp_v] > in[v]) {
                br[edges[v][i].second] = true;
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

void paint(int v, int c) {
    color[v] = c;
    for (int i = 0; i < edges[v].size(); i++) {
        int tmp = edges[v][i].first;
        if (color[tmp] == 0) {
            if (br[edges[v][i].second]) {
                maxColor++;
                paint(tmp, maxColor);
            } else {
                paint(tmp, c);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    edges.resize(n);
    in.resize(n);
    up.resize(n);
    br.resize(m, false);
    color.resize(n, 0);
    visited.resize(n, false);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        edges[a - 1].push_back({b - 1, i });
        edges[b - 1].push_back({a - 1, i });
    }

    bridges(n);
    maxColor = 0;
    for (int i = 0; i < n; i++) {
        if (color[i] == 0) {
            maxColor++;
            paint(i, maxColor);
        }
    }

    cout << maxColor << endl;
    for (int i : color) {
        cout << i << " ";
    }
}
