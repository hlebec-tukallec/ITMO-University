#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


vector<pair<int, int>> coord;
const int INF = 100000000;

double count_edges(int p1, int p2) {
   double ans = sqrt((coord[p2].first - coord[p1].first)*(coord[p2].first - coord[p1].first)
           + ((coord[p2].second - coord[p1].second)*(coord[p2].second - coord[p1].second)));
    return ans;

}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        coord.emplace_back(x, y);
    }


    vector<bool> used(n, false);
    vector<double> min_ed (n, INF);
    vector<int> end_ed (n, -1);
    long double cost = 0;

    min_ed[0] = 0;
    for (int i = 0; i < n; i++) {
        int v = -1;
        for (int j = 0; j < n; j++) {
            if (!used[j] && (v == -1 || min_ed[j] < min_ed[v])) {
                v = j;
            }
        }
        if (min_ed[v] == INF) {
            cout << '0';
            exit(0);
        }
        used[v] = true;
        if (end_ed[v] != -1) {
            cost+=count_edges(v, end_ed[v]);
        }
        for (int to = 0; to < n; to++) {
            if (count_edges(v, to) < min_ed[to]) {
                min_ed[to] = count_edges(v, to);
                end_ed[to] = v;
            }
        }
    }

    cout.precision(11);
    cout << cost;

    return 0;
}
