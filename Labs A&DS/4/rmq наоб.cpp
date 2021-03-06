#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;
#define int long long
vector<int> check;
vector<int> t;
int k, n;

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
        t[k - 1 + i] = INT32_MIN;
    }
    for (int i = n; i < k; i++) {
        t[k - 1 + i] = INT32_MIN;
    }

    for (int i = k - 2; i >= 0; i--) {
        t[i] = min(t[2 * i + 1], t[2 * i + 2]);
    }
}

void push(int v, int l, int r) {
    if (r - l > 1) {
        t[2 * v + 1] = max(t[2 * v + 1], t[v]);
        t[2 * v + 2] = max(t[2 * v + 2], t[v]);
    }
}

int rmq (int v, int l, int r, int a, int b) {
    push(v, l, r);
    if (l >= b || r <= a) {
        return INT32_MAX;
    }

    if (l >= a && r <= b) {
        return t[v];
    }
    return min(rmq(2 * v + 1, l, (r + l) / 2, a, b), rmq(2 * v + 2, (r + l) / 2, r, a, b));
}

void build(int v, int l, int r, int a, int b, int inc) {
    push(v, l, r);
    if (b <= l || r <= a) {
        return;
    }
    if (l >= a && r <= b) {
        if (t[v] < inc) {
            t[v] = inc;
            push(v, l, r);
        }
        return;
    }
    build(2 * v + 1, l, (r + l) / 2, a, b, inc);
    build(2 * v + 2, (r + l) / 2, r, a, b, inc);
    t[v] = min(t[2 * v + 1], t[2 * v + 2]);
}

signed main() {
    freopen("crypto.in", "r", stdin);
    freopen("crypto.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie();

    int m;
    cin >> n >> m;
    treebuild();

    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        check.push_back(x - 1);
        check.push_back(y);
        check.push_back(z);
        build(0, 0, k, x - 1, y, z);
    }

    for (int i = 0; i < 3 * m; i = i + 3) {
        int a = rmq(0, 0, k, check[i], check[i + 1]);
        if (a != check[i + 2]) {
            cout << "inconsistent";
            return 0;
        }
    }
    cout << "consistent" << endl;
    int j = 0;
    for (int i = 0; i < n; i++) {
        //cout << t[i] << " ";
        cout << rmq(0, 0, k, i, i + 1) << " ";
    }
    return 0;
}
