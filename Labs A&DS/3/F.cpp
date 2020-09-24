#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
vector<int>a;
vector<int>precalc;
long long opt[3];
vector<vector<long long>>st;
int n;

void precalcy() {
    precalc[1] = 1;
    for (int i = 2; i <= n; i++) {
        precalc[i] = precalc[i - 1];
        if ((1 << (precalc[i]+1)) <= i) {
            precalc[i]++;
        }
    }
}

void prep() {
    for (int i = 0; i < n; i++) {
        st[i][0] = a[i];
    }
   for (int j = 0; (1 << j) <= n; j++) {
       for (int i = 0; i + (1 << j) < n; i++) {
           st[i][j] = min (st[i][j - 1], st[i + (1 << (j-1))][j-1]);
       }
   }
}

long long func (long long l, long long r) {
    int j = precalc[r - l + 1];
    return min(st[l][j], st[r - (1 << j) + 1][j]);
}


int main() {
     freopen("crypto.in", "r", stdin);
     freopen("crypto.out", "w", stdout);
     ios::sync_with_stdio(false);
     cin.tie();

     int m;
     cin >> n >> m;
     a.resize(n);
     precalc.resize(n);
     cin >> a[0];
     for (int i = 1; i < n; i++) {
         a[i] =  ((long long) 23 * (long long) a[i - 1] + (long long) 21563) % 16714589;
     }
    precalcy();
     vector<long long>tmp(precalc[n]);
     st.resize(n, tmp);
     prep();


     cin >> opt[0] >> opt[1];

     opt[2] = func(opt[0], opt[1]);

     for (int i = 1; i < m; i++) {
         opt[0] = (( 17 * (long long) opt[0] + (long long) 751 + (long long) opt[2] +  2 * (i - 1)) % n) + 1;
         opt[1] = (( 13 * (long long) opt[1] + (long long) 593 + (long long) opt[2] +  5 * (i - 1)) % n) + 1;
         opt[2] = func(opt[0], opt[1]);
     }
     cout << opt[0] << " " << opt[1] << " " << opt[2];

    return 0;
}
