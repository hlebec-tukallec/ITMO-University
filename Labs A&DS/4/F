#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

vector<int>a;
long long opt[3];
vector<vector<long long>>st;
int n;

const int log = 25;


int fl(int len) {
    if (len == 1) {
        return 0;
    }
    else {
        return fl(len/2) + 1;
    }
}


void prep() {
    for (int i = 0; i < n; i++) {
        st[i][0] = a[i];
    }
   for (int j = 1; (1 << j) <= n; j++) {
       for (int i = 0; i + (1 << j) <= n; i++) {
           st[i][j] = min(st[i][j - 1], st[i + (1 << (j-1))][j-1]);
       }
   }
}

long long func (int l, int r) {
    int j = fl(r - l + 1);
    return min(st[l][j], st[r - (1 << j) + 1][j]);
}

int main() {

     ios_base::sync_with_stdio(false);
     cin.tie();

     int m;
     cin >> n >> m;
     a.resize(n);
     cin >> a[0];
     for (int i = 1; i < n; i++) {
         a[i] =  (23 *  a[i - 1] + 21563) % 16714589;
     }

     st.resize(n);
     for (int i = 0; i < n; i++) {
         st[i].resize(log);
     }

     prep();
     cin >> opt[0] >> opt[1];

    opt[2] = func(min(opt[0], opt[1]) - 1, max(opt[0], opt[1]) - 1);

     for (int i = 1; i < m; i++) {
         opt[0] = (( 17 * opt[0] + 751 + opt[2] +  2 * i) % n) + 1;
         opt[1] = (( 13 * opt[1] + 593 + opt[2] +  5 * i) % n) + 1;
         opt[2] = func(min(opt[0], opt[1]) - 1, max(opt[0], opt[1]) - 1);
     }
     cout << opt[0] << " " << opt[1] << " " << opt[2];

    return 0;
}
