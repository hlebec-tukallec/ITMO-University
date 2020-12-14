#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int no_edge = 100000;

struct edge {
    int from, to, cost;
};

vector<edge> e;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int weight;
            cin >> weight;
            if (weight == no_edge) {
                continue;
            }
            e.push_back({i, j, weight});
        }
    }

    vector<int> d(n);
    vector<int> par(n, -1);

    d[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < e.size(); j++) {
            if (d[e[j].to] > d[e[j].from] + e[j].cost) {
                d[e[j].to] = d[e[j].from] + e[j].cost;
                par[e[j].to] = e[j].from;
            }
        }
    }


    vector<int> cycle;

    for (int j = 0; j < e.size(); j++) {
        if (d[e[j].to] > d[e[j].from] + e[j].cost) {
            int v = e[j].to;
            for (int i = 0; i < n; i++) {
                v = par[v];
            }
            int y = v;
            while (y != par[v]) {
                v = par[v];
                cycle.push_back(v);
            }
            cycle.push_back(y);

            reverse(cycle.begin(), cycle.end());

            cout << "YES" << endl;
            cout << cycle.size() << endl;
            for (int i = 0; i < cycle.size(); i++) {
                cout << cycle[i] + 1 << " ";
            }
            return 0;
        }
    }
    cout << "NO";
}
