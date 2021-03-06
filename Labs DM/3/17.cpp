#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;
int n;
signed long long int k;
vector<char> br;
signed long long int diny[41][41];

void din() {
    for (int i = 0; i < 2*n; i++) {
        for (int j = 0; j < 2*n; j++){
            if (i == 0 && j != 0) {
                diny[i][j] = 0;
            }
            else if (i == 0 && j == 0) {
                diny[0][0] = 1;
            }
            else if (j == 2*n-1) {
                diny[i][j] = diny[i-1][j-1];
            }
            else {
                diny[i][j] = diny[i - 1][j - 1] + diny[i - 1][j + 1];
            }
        }
    }
}

void generate() {
    int depth = 0;
    string ans = "";
    for (int i = 0; i < 2 * n; i++) {
        if(diny[2 * n - (i + 1)][depth + 1] > k) {
            ans.push_back('(');
            depth = depth + 1;
        }
        else {
            k = k - diny[2 * n - (i + 1)][depth + 1];
            ans.push_back(')');
            depth = depth - 1;
        }
    }
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];
    }

}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  freopen("num2brackets.in","r", stdin);
  freopen("num2brackets.out","w", stdout);
    cin >> n;
    cin >> k;

    din();
    generate();
    return 0;
}
