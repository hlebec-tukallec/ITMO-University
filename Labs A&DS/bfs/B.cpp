#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int INF = INT32_MAX;
vector<vector<pair<int, int>>> edges;

int main() {
    int n, m;
    cin >> n >> m;
    edges.resize(n);
    for (int i = 0; i < m; i++) {
        int a, b, val;
        cin >> a >> b >> val;
        edges[a - 1].push_back({b - 1, val});
        edges[b - 1].push_back({a - 1, val});
    }
    vector<int> v(n, INF);
    v[0] = 0;
    set<pair<int, int>> q;
    q.insert({v[0], 0});

   while (!q.empty()) {
       int s = q.begin()->second;
       q.erase(q.begin());

       for (int i = 0; i < edges[s].size(); i++) {
           int to = edges[s][i].first;
           int length = edges[s][i].second;
           if (v[s] + length < v[to]) {
               q.erase({v[to], to});
               v[to] = v[s] + length;
               q.insert({v[to], to});
           }
       }
   }

    for (int i : v) {
        cout << i << " ";
    }
}
