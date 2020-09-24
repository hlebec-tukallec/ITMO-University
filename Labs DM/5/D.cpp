#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
  freopen("nfc.in", "r", stdin);
  freopen("nfc.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie();
    int n;
    char start_term;
    vector<pair<char, string>> all;
    vector<pair<char, string>> term;
    
    cin >> n >> start_term;

    for (int i = 0; i < n; i++) {
        char tmp;
        string nenado, s;
        cin >> tmp >> nenado >> s;
        
        if (s.size() == 2) {
            term.emplace_back(tmp, s);
        }
        all.emplace_back(tmp, s);
    }

    string w;
    cin >> w;
    vector<vector<vector<long long int>>> dp (100, vector<vector<long long int>>(100, vector<long long int>( 100, 0)));
    for (int i = 0; i < w.size(); i++) {
        for (auto j : all) {
            if (j.second.size() == 1 && j.second[0] == w[i]) {
                dp[j.first][i][i] = 1;
            }
        }
    }
    for (int i = 1; i < w.size(); i++) {
        for (int j = 0; j < w.size(); j++) {
            if (i + j < w.size()) {
                for (int k = j; k < i + j; k++) {
                    for (auto l : term) {
                        char a = l.first;
                        char b = l.second[0];
                        char c = l.second[1];
                        dp[a][j][i + j] = (dp[a][j][i + j] + dp[b][j][k] * dp[c][k + 1][i + j]) % 1000000007;
                    }
                }
            }
        }
    }

    cout << dp[start_term][0][w.size() - 1];
    return 0;
}
