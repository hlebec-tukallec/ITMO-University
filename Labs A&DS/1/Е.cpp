#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<int> k;
void qsort(vector<int> &a, int l, int r) {
    int i = l;
    int j = r;
    int q = a[(i + j) / 2];
    while (i < j) {
        while (a[i] < q) {
            i++;
        }
        while (a[j] > q) {
            j--;
        }
        if (i <= j) {
            int m = a[i];
            a[i] = a[j];
            a[j] = m;
            i++;
            j--;
        }
    }
    if (l < j) {
        qsort(a, l, j);
    }
    if (i < r)
    {qsort(a, i, r);
    }
}


int find_l(int x) {
    int l = -1;
    int r = k.size();
    int m;
    while (l < r - 1) {
        m = (l + r) / 2;
        if (k[m] < x) l = m;
        else r = m;
    }
    return l;
}


int find_r(int x) {
    int l = -1;
    int r = k.size();
    int m;
    while (l < r - 1 ) {
        m = (l + r) / 2;
        if (x < k[m]) r = m;
        else l = m;
    }
    return r;
}

int main() {
    int n, m, l, r;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        k.push_back(x);
    }
    cin >> m;
    qsort(k, 0, k.size() - 1);
    vector<int> sorted;
    for (int i = 0; i < m; i++) {
        cin >> l >> r;
        l = find_l(l);
        r = find_r(r);
        sorted.push_back(r - l - 1);
    }
    for (int i = 0; i < sorted.size(); i++) {
        cout << sorted[i] << " ";
    }
    return 0;
}
