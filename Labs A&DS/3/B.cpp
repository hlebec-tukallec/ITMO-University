#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n,m;
    cin >> n >> m;
    vector<vector<int>> coins(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> coins[i][j];
        }
    }
    vector<vector<int>> dp(n, vector<int>(m, 0));
    vector<string> steps;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if ((i-1) >= 0 && (j-1)>=0) {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
            else if (i - 1 >= 0) {
                dp[i][j] = dp[i-1][j];
            }
            else if (j-1 >= 0){
                dp[i][j] = dp[i][j-1];
            }
            dp[i][j] += coins[i][j];
        }
    }
    int i = n - 1;
    int j = m - 1;
    while ((i > 0)||(j > 0)) {
            if ((i-1) >= 0 && (j-1)>=0) {
                //dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                if (dp[i - 1][j] > dp[i][j - 1]) {
                    i = i - 1;
                    steps.push_back("D");

                }
                else {
                    j = j - 1;
                    steps.push_back("R");
                }

            }
            else if (i - 1 >= 0) {
               // dp[i][j] = dp[i-1][j];
                i = i - 1;
                steps.push_back("D");
            }
            else if (j-1 >= 0){
               // dp[i][j] = dp[i][j-1];
                j = j - 1;
                steps.push_back("R");
            }

    }

    cout << dp[n-1][m-1] << endl;
    for (int i = steps.size()-1; i >= 0; i--) {
        cout << steps[i];
    }
    return 0;
}
