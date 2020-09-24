#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

struct matrix {
    int a, b, c, d;
};
vector<matrix> mas;
vector<matrix> tree;
matrix net;
int n, r;

matrix operator & (matrix a, matrix b) {
    matrix c;
    c.a = ((a.a * b.a) % r + (a.b * b.c) % r) % r;
    c.b = ((a.a * b.b) % r + (a.b * b.d) % r) % r;
    c.c = ((a.c * b.a) % r + (a.d * b.c) % r) % r;
    c.d = ((a.c * b.b) % r + (a.d * b.d) % r) % r;
    return c;
}

void tree_build(int v, int tl, int tr) {
    if (tr - tl == 1) {
        tree[v] = mas[tl];
    }
    else {
        int mid = (tl+tr)/2;
        tree_build(2*v + 1, tl, mid);
        tree_build(2*v + 2, mid, tr);
        tree[v] = tree[2*v+1] & tree[2*v+2];
    }
}

matrix count(int v, int tl, int tr, int le, int ri) {
    if (le <= tl && ri >= tr) {
        return tree[v];
    }
    if (le >= tr || ri <= tl) {
        return net;
    }
    else {
        matrix a = count(2*v + 1, tl, (tl+tr)/2, le, ri);
        matrix b = count(2*v + 2, (tl+tr)/2, tr, le, ri);
        return a & b;
    }
}

int main() {
     freopen("crypto.in", "r", stdin);
     freopen("crypto.out", "w", stdout);
     ios::sync_with_stdio(false);
     cin.tie();
     int m;
     cin >> r >> n >> m;
     net.a = 1;
     net.b = 0;
     net.c = 0;
     net.d = 1;
     mas.resize(n);
     tree.resize(4 * n);
     for (int i = 0; i < n; i++) {
         cin >> mas[i].a >> mas[i].b >> mas[i].c >> mas[i].d;
     }
     tree_build(0, 0, n);

     for (int i = 0; i < m; i++) {
         int l, r;
         cin >> l >> r;
         matrix tmp = count(0, 0, n, l-1, r);
         cout << tmp.a << " " << tmp.b << "\n" << tmp.c << " " << tmp.d << "\n\n";
     }

    return 0;
}
