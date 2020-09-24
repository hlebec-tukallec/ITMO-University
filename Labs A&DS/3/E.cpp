#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    string s1;
    s1 = " ";
    string a1;
    cin >> a1;
    s1 = s1 + a1;
    string s2;
    s2 = " ";
    string a2;
    cin >> a2;
    s2 = s2 + a2;
   // int n = s1.size();
  //  int m = s2.size();
    int dp[1010][1010];
    dp[0][0] = 0;
    for (int i = 1; i < s2.size() + 1; i++) {
        dp[0][i] = dp[0][i - 1] + 1;
    }
    for (int i = 1; i < s1.size() + 1; i++) {
        dp[i][0] = dp[i - 1][0] + 1;
        for (int j = 1; j < s2.size() + 1; j++) {
            if (s1[i] != s2[j]) {
                int tmp;
                tmp = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1);
                dp[i][j] = min(tmp, dp[i - 1][j - 1] + 1);
            }
            else {
                dp[i][j] = dp[i - 1][j - 1];
            }
        }
    }
    cout << dp[s1.size()-1][s2.size()-1];
    return 0;
}
