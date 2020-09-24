#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, k;
    cin >> n >> k;

    vector<int>dp(n + 1);
    vector<int>coins(n + 1);
    vector<int>steps;

    coins[0] = coins[1] = coins[n] = 0;
    for (int i = 2; i < coins.size() - 1; i++) {
        cin >> coins[i];
    }

    dp[0] = dp[1] = 0;
    int tmp = 0;

    for (int i = 2; i <= n; i++) {
        dp[i] = coins[i];
        int tmp = dp[i - 1] + dp[i];
        for (int j = 2; j <= k; j++) {
            if ((i - j) > 0) {
                if (dp[i] + dp[i - j] >= tmp) {
                    tmp = dp[i] + dp[i - j];
                }
            }
        }
        dp[i] = tmp;
    }

    steps.push_back(n);
    int i = n;
    while (i >= 2) {
        int par = dp[i - 1];
        int ind = i - 1;
        for (int j = 2; j <= k; j++) {
            if ((i - j) > 0) {
                if (dp[i - j] >= par) {
                    ind = i - j;
                    par = dp[i - j];
                }

            }
        }

        steps.push_back(ind);
        i = ind;
    }

    cout << dp[n] << endl;
    cout << steps.size() - 1 << endl;
    for (int i = steps.size() - 1; i >= 0; i--) {
        cout << steps[i] << " ";
    }

    return 0;
}
