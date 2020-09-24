#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
vector<pair<int, int>>t;
int n;
int k;

int nextpow(int x) {
    int pow = 1;
    while (pow < x) {
        pow = pow * 2;
    }
    return pow;
}

void treebuild() {
    k = nextpow(n);
    t.resize(2 * k - 1);
    for (int i = 0; i < n; i++) {
        t[k - 1 + i].first = 0;
        t[k - 1 + i].second = i;
    }
    for (int i = n; i < k; i++) {
        t[k - 1 + i].first = 10e9;
        t[k - 1 + i].second = 10e9;
    }
    for (int i = k - 2; i >= 0; i--) {
        t[i] = min(t[2 * i + 1],t[2 * i + 2]);
    }
}

void push(int v, int l, int r) {
    if (r - l > 1) {
        t[2 * v + 1].first = max(t[2 * v + 1].first, t[v].first);
        t[2 * v + 2].first = max(t[2 * v + 2].first, t[v].first);
    }
}

pair<int, int> attack(int v, int l, int r, int a, int b) {
    push(v, l, r);
    if (l >= b || r <= a) {
        pair<int, int> res;
        res.first = 10e9;
        res.second = 10e9;
        return res;    //neutral pair
    }
    if (l >= a && r <= b) {
        return t[v];
    }
    pair<int, int> pr = attack(2 * v + 1, l, (r + l) / 2, a, b);
    return min(pr, attack(2 * v + 2, (r + l) / 2, r, a, b));
}

void defend(int v, int l, int r, int a, int b, int inc) {
    push(v, l, r);
    if (b <= l || r <= a) {
        return;
    }
    if (l >= a && r <= b) {
        if (t[v].first < inc) {
            t[v].first = inc;
        }
        return;
    }
    defend(2 * v + 1, l, (r + l) / 2, a, b, inc);
    defend(2 * v + 2, (r + l) / 2, r, a, b, inc);
    t[v] = min(t[2 * v + 1], t[2 * v + 2]);
}


int main() {
    freopen("crypto.in", "r", stdin);
    freopen("crypto.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie();

    int m;
    cin >> n >> m;
    treebuild();
    string tmp = " ";
    for (int i = 0; i < m; i++) {
        cin >> tmp;
        if (tmp == "defend") {
            int a, b, c;
            cin >> a >> b >> c;
            defend(0, 0, k, a - 1, b, c);
        }
        else {
            int d, e;
            cin >> d >> e;
            cout << attack(0, 0, k, d - 1, e).first << " " << attack(0, 0, k, d - 1, e).second + 1 << endl;
        }
    }
    return 0;
}
