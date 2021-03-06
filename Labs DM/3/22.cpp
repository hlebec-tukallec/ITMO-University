#include <iostream>
#include <vector>

using namespace std;
int n;
vector<int>val;
long long int dp[1000][100002];

void help() {
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = n; j >= 1; j--) {
            if (i < j) {
               dp[i][j] = 0;
            }
            else if (i == j) {
                dp[i][j] = 1;
            }
            else if (j == n - 1) {
                dp[i][j] = dp[i - j][j];
            }
            else {
                dp[i][j] = dp[i][j + 1] + dp[i - j][j];
            }
        }
    }

}


void generate() {
   long long int number = 0;
   long long int s = 0;
   int last = 0;
    for (int i = 0; i < val.size(); i++) {
        for (int j = last; j < val[i]; j++) {
            number = number + dp[n - s - j][j];
        }
        s = s + val[i];
        last = val[i];
    }
    cout << number;
}

int main() {

    freopen("part2num.in", "r", stdin);
    freopen("part2num.out", "w", stdout);
    string s;
    cin >> s;
    n = 0;
    string h = "";
    //val.push_back(0);
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != '+') {
            if ((i == s.size() - 1) || (s[i + 1] == '+')) {
                h = h + s[i];
                val.push_back(stoi(h));
                h = "";
            }
            else if (i != s.size() - 1){
                if (s[i + 1] != '+') {
                    h = h + s[i];
                }
            }
        }
    }

    for (int i = 0; i < val.size(); i++) {
        n = n + val[i];
    }

    help();
    generate();
    return 0;
}
