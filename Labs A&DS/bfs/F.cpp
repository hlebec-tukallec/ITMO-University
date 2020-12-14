#include <iostream>
#include <vector>
#include <set>

using namespace std;

const long long INF = 2'000'000'000'000'000'001;

vector<vector<pair<int, long>>> e;
vector<long long> d;

void dijkstra(int s) {

    d[s] = 0;
    set<pair<int, int>> q;
    q.insert({d[s], s});

    while (!q.empty()) {
        int t = q.begin()->second;
        q.erase(q.begin());

        for (int i = 0; i < e[t].size(); i++) {
            int to = e[t][i].first;
            int length = e[t][i].second;
            if (d[t] + length < d[to]) {
                q.erase({d[to], to});
                d[to] = d[t] + length;
                q.insert({d[to], to});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie();

    int n, m;
    cin >> n >> m;
    e.resize(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        long long time;
        cin >> time;
        e[a - 1].push_back({b - 1, time});
        e[b - 1].push_back({a - 1, time});
    }
    d.resize(n, INF);
    int a, b, c;
    cin >> a >> b >> c;

    dijkstra(a - 1);

    long long a_b = d[b - 1];
    long long a_c = d[c - 1];

    for (int i = 0; i < d.size(); i++) {
        d[i] = INF;
    }

    dijkstra(b - 1);
    long long b_c = d[c - 1];

    long long ans = min(min(a_b + a_c, a_b + b_c), a_c + b_c);
    if (ans >= INF) {
        cout << -1;
    } else {
        cout << ans;
    }
}
