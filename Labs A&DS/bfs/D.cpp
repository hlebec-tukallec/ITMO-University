#include <iostream>
#include <vector>

using namespace std;

const int INF = 1000000000;

vector<vector<pair<int, int>>> g;
vector<vector<int>> d;

int main() {
    int n, m;
    cin >> n >> m;
    int k, st;
    cin >> k >> st;
    st = st - 1;

    g.resize(n);
    d.resize(n, vector<int>(k + 1, INF));
    d[st][0] = 0;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        int w;
        cin >> w;
        g[a - 1].push_back({b - 1, w});
    }

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            for (int l = 0; l < g[j].size(); l++) {
                if (d[j][i] != INF) {
                    d[g[j][l].first][i + 1] = min(d[j][i] + g[j][l].second, d[g[j][l].first][i + 1]);
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (d[i][k] == INF) {
            cout << -1 << endl;
        }
        else {
            cout << d[i][k] << endl;
        }
    }



}
