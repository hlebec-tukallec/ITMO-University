#include <iostream>
#include <vector>

using namespace std;

struct edge {
    long long from, to, cost;
};

vector<edge> e;
const long long INF = 2'000'000'000'000'000'001;

int main() {
    int n, m, s;
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++) {
        long long a, b, cost;
        cin >> a >> b >> cost;
        e.push_back({a - 1, b - 1, cost});
    }

    vector<pair<long long, bool>> d;
    d.resize(n);
    for (auto &i : d) {
        i.first = INF;
        i.second = false;
    }

    vector<int> par(n, -1);

    d[s - 1].first = 0;

    for (int i = 0; i < n; i++) {
        for (auto &j : e) {
            if (d[j.from].first < INF) {
                if (d[j.to].first > d[j.from].first + j.cost) {
                    d[j.to].first = d[j.from].first + j.cost;
                    par[j.to] = j.from;
                }
            }
        }
    }

    for (auto &j : e) {
        if (d[j.from].first < INF) {
            if (d[j.to].first > d[j.from].first + j.cost) {
                long long v = j.to;
                for (int i = 0; i < n; i++) {
                    v = par[v];
                }
                long long y = v;
                while (y != par[v]) {
                    v = par[v];
                    d[v].second = true;
                }
                d[y].second = true;
            }
        }
    }

    for (int i = 0; i < e.size(); i++) {
        if (d[e[i].from].second) {
            if (d[e[i].to].second) {
                continue;
            } else {
                d[e[i].to].second = true;
                i = -1;
            }
        }
    }

    for (auto &i : d) {
        if (i.second) {
            cout << "-" << endl;
        } else if (i.first == INF) {
            cout << "*" << endl;
        } else {
            cout << i.first << endl;
        }
    }

    return 0;
}

