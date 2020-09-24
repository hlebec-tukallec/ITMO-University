#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;
vector<vector<vector<int>>>t;
int n;

int count (int x, int y, int z) {
    int res = 0;
    for (int i = x; i >= 0; i = (i & (i + 1)) - 1) {
        for (int j = y; j >= 0; j = (j & (j + 1)) - 1) {
            for (int k = z; k >= 0; k = (k & (k + 1)) - 1) {
                res += t[i][j][k];
            }
        }
    }

    return res;
}

void upd (int x, int y, int z, int val) {
    for (int i = x; i < n; i = (i | (i + 1))) {
        for (int j = y; j < n; j = (j | (j + 1))) {
            for (int k = z; k < n; k = (k | (k + 1))) {
                t[i][j][k] += val;
            }
        }
    }
}

int main() {
    //freopen("crypto.in", "r", stdin);
   // freopen("crypto.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie();

    cin >> n;

    t.resize(n);
    for (int i = 0; i < n; i++) {
        t[i].resize(n);
        for (int j = 0; j < n; j++) {
            t[i][j].resize(n);
        }
    }

    int m;
    while(true) {
        cin >> m;
        if (m == 1) {
            int x, y, z, k;
            cin >> x >> y >> z >> k;
            upd(x, y, z, k);
        }

        else if (m == 2) {
            int x1, y1, z1, x2, y2, z2;
            cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
            cout << count(x2, y2, z2) - count(x1 - 1, y2, z2) - count(x2, y1 - 1, z2) - count(x2, y2, z1 - 1) + count(x1 - 1, y1 - 1, z2) + count(x2, y1 - 1, z1 - 1) + count(x1 - 1, y2 , z1 - 1) - count(x1 - 1, y1 - 1, z1 - 1) << endl;
        }

        else {
            break;
        }
    }

    return 0;
}
