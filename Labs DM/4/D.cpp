#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int main() {
    freopen("problem4.in", "r", stdin);
    freopen("problem4.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie();

    int n, m, k;
    cin >> n >> m >> k;
    int l;
    cin >> l;

    if (l == 0) {
        cout << 1;
        return 0;
    }

    vector<vector<int>> a(n, vector<int>(26, -1));
    vector<vector<int>> cnt(n, vector<int>(l + 1, 0));

    vector<bool>term(n, false);
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        term[x - 1] = true;
        cnt[x - 1][0] = 1;

    }
    for (int i = 0; i < m; i++) {
        int x, y;
        char tmp;
        cin >> x >> y >> tmp;
        a[x - 1][tmp - 'a'] = y - 1;
    }

    for (int i = 0; i < l; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < 26; k++) {
                if (a[j][k] != -1) {
                    cnt[j][i + 1] += cnt[a[j][k]][i];
                    cnt[j][i + 1] %= 1000000007;
                }
            }
        }
    }

    cout << cnt[0][l];
    return 0;
}
