#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, pair<int, int>>> edges;
vector<int> tree;

int dsu(int v) {
    if (v == tree[v]) {
        return v;
    }
    return tree[v] = dsu(tree[v]);
}

void dsu_unite(int a, int b) {
    a = dsu(a);
    b = dsu(b);
    if (rand() & 1) {
        swap(a, b);
    }
    if (a != b) {
        tree[a] = b;
    }

}

int main() {
    int n, m;
    cin >> n >> m;
    edges.resize(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].second.first >> edges[i].second.second;
        cin >> edges[i].first;
    }
    sort(edges.begin(), edges.end());
    long long int ans = 0;
    tree.resize(n + 1);

    for (int i = 1; i <= n; i++) {
        tree[i] = i;
    }
    for (int i = 0; i < m; i++) {
        int a = edges[i].second.first;
        int b = edges[i].second.second;
        int length = edges[i].first;
        if (dsu(a) != dsu(b)) {
            ans += length;
            dsu_unite(a, b);
        }
    }
    cout << ans;
    return 0;
}
