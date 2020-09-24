#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie();
    int n;
    cin >> n;
    int x;
   vector<vector<int>>dp (n + 1, vector<int> (20, 0));

   for (int i = 1; i <= n; i++) {
       cin >> x;
       dp[i][0] = x;
   }
   for (int j = 1; j <= log2(n); j++) {
       for (int i = 1; i <= n; i++) {
           dp[i][j] = dp[dp[i][j - 1]][j - 1];
       }
   }

   for (int i = 1; i <= n; i++) {
       cout << i << ":" << " ";
       for (int j = 0; j < log2(n); j++) {
           if (dp[i][j] == 0) {
                break;
           }
           cout << dp[i][j] << " ";
       }
       cout << '\n';
   }

    return 0;
}
