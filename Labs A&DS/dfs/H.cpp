#include <iostream>
#include <vector>

using namespace std;

vector<bool> visited;

vector<int> order;
vector<int> colors;

vector<vector<int>> map;
vector<vector<int>> tr_map;

int color = 0;
int n;

void dfs(int v, int w) {
    visited[v] = true;
    for (int i = 0; i < map[v].size(); i++) {
        if ((!visited[i]) && (map[v][i] <= w)) {
            dfs(i, w);
        }
    }
    order.push_back(v);
}

void dfsy(int v, int w) {
    visited[v] = true;
    colors[v] = color;
    for (int i = 0; i < tr_map[v].size(); i++) {
        if ((!visited[i]) && (tr_map[v][i] <= w)) {
            dfsy(i, w);
        }
    }
}


bool check(int w) {
    order.clear();
    visited.assign(n, false);
    color = 0;
    colors.assign(n, 0);

    for (int i = 0; i < map.size(); i++) {
        if (!visited[i]) {
            dfs(i, w);
        }
    }

    visited.assign(n, false);
    for (int i = 0; i < n; i++) {
        int tmp = order[n - 1 - i];
        if (!visited[tmp]) {
            color++;
            dfsy(tmp, w);
        }
    }

    if (color == 1) {
        return true;
    }

    return false;
}

int main() {
    //freopen("avia.in", "r", stdin);
    //freopen("avia.out", "w", stdout);

    cin >> n;

    map.assign(n, vector<int>(n, 0));
    tr_map.assign(n, vector<int>(n, 0));
    colors.assign(n, 0);
    visited.assign(n, false);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int a;
            cin >> a;
            map[i][j] = a;
            tr_map[j][i] = map[i][j];
        }
    }

    int l = 0;
    int r = 1000000000;
    int mid;
    while (l < r - 1) {
        mid = (l + r) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << r;
    return 0;
}
