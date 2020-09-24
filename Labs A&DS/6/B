#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;
vector<int>depth;
int n;
vector<vector<int>>dp;

int lca (int l, int r) {
    if (depth[l] > depth[r]) {
        swap(l, r);
    }
    for (int i = log2(n); i >= 0; i--) {
        if (depth[dp[r][i]] - depth[l] >= 0) {
            r = dp[r][i];
        }
    }
    if (r == l) {
        return r;
    }
    for (int i = log2(n); i >= 0; i--) {
        if (dp[l][i] != dp[r][i]) {
            r = dp[r][i];
            l = dp[l][i];
        }
    }
    return dp[l][0];
}

int main() {
  
    ios::sync_with_stdio(false);
    cin.tie();
    cin >> n;
    int x;

    dp.resize(n + 1, vector<int> (20, 0));
    depth.resize(n + 1, 0);

    dp[1][0] = 1;
    for (int i = 2; i <= n; i++) {
       cin >> x;
       dp[i][0] = x;
       depth[i] = depth[x] + 1;
   }
   for (int j = 1; j <= log2(n); j++) {
       for (int i = 1; i <= n; i++) {
           dp[i][j] = dp[dp[i][j - 1]][j - 1];
       }
   }

   int m, f, y;
   cin >> m;

   for (int i = 0; i < m; i++) {
       cin >> f >> y;
       cout << lca (f, y) << '\n';
   }

    return 0;
}
