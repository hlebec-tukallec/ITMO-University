#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
   freopen("problem1.in", "r", stdin);
   freopen("problem1.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie();

    string s;
    cin >> s;
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> a(n, vector<int>(26, -1));

    vector<bool>term(n, false);
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        term[x - 1] = true;
    }
    for (int i = 0; i < m; i++) {
        int x, y;
        char tmp;
        cin >> x >> y >> tmp;
        a[x - 1][tmp - 'a'] = y - 1;
    }

    int vert = 0;
    for (int i = 0; i < s.size(); i++) {
        if (a[vert][s[i] - 'a'] != -1) {
            vert = a[vert][s[i] - 'a'];
        }
        else {
            cout << "Rejects";
            return 0;
        }
    }

    if (term[vert] == true) {
        cout << "Accepts";
    }
    else {
        cout << "Rejects";
    }

    return 0;
}
