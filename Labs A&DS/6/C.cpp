#include <iostream>
#include <string>
#include <vector>
#include <cmath>
 
using namespace std;
vector<int>depth;
int n;
vector<vector<int>>dp;
vector<vector<int>>price;
 
 
int lca (int l, int r) {
    int res = 1e9;
    if (depth[l] > depth[r]) {
        swap(l, r);
    }
    for (int i = log2(n); i >= 0; i--) {
        if (depth[dp[r][i]] - depth[l] >= 0) {
            res = min(price[r][i], res);
            r = dp[r][i];
        }
    }
    if (r == l) {
        return res;
    }
    for (int i = log2(n); i >= 0; i--) {
        if (dp[l][i] != dp[r][i]) {
            res = min(res, min(price[r][i], price[l][i]));
            r = dp[r][i];
            l = dp[l][i];
        }
    }
    return min(res, min(price[l][0], price[r][0]));
}
 
int main() {
    freopen("minonpath.in", "r", stdin);
    freopen("minonpath.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie();
    cin >> n;
    int x;
 
    dp.resize(n + 2, vector<int> (20, 0));
    depth.resize(n + 2, 0);
    price.resize(n + 2, vector<int> (20, 1e9));
 
    dp[1][0] = 1;
  //  price[1][0] = 1e9;
    for (int i = 2; i <= n; i++) {
       cin >> x;
       dp[i][0] = x;
       depth[i] = depth[x] + 1;
       int y;
       cin >> y;
       price[i][0] = y;
   }
   for (int j = 1; j <= log2(n); j++) {
       for (int i = 1; i <= n + 1; i++) {
           dp[i][j] = dp[dp[i][j - 1]][j - 1];
           price[i][j] = min(price[i][j - 1], price[dp[i][j - 1]][j - 1]);
       }
   }
 
   int m, f, y;
   cin >> m;
 
   for (int i = 0; i < m; i++) {
       cin >> f >> y;
       cout << lca(f, y)  << '\n';
   }
 
    return 0;
}
