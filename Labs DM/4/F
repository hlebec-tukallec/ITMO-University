#include <iostream>
#include <string>
#include <vector>

using namespace std;
vector<vector<int>> a;
vector<vector<int>> b;
vector<bool> term_a;
vector<bool> term_b;
vector<bool> visited;

bool res = true;
void isom (int v1, int v2) {
    if (term_a[v1] != term_b[v2]) {
        res = false;
        return;
    }
    for (int i = 0; i < 26; i++) {
        if (a[v1][i] == -1 && b[v2][i] != -1) {
            res = false;
            return;
        }

        if (a[v1][i] != -1 && b[v2][i] != -1) {
            if (visited[v1] == true) {
                continue;
            }
            else {
                visited[v1] = true;
                isom(a[v1][i], b[v2][i]);
            }
        }
    }
}

int main() {
    freopen("isomorphism.in", "r", stdin);
    freopen("isomorphism.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie();

    int term_1, term_2;
    int n, m;
    cin >> n >> m >> term_1;

    a.resize(n);
    for (int i = 0; i < n; i++) {
        a[i].resize(26, -1);
    }

    term_a.resize(n, false);

    for (int i = 0; i < term_1; i++) {
        int x;
        cin >> x;
        term_a[x - 1] = true;
    }
    for (int i = 0; i < m; i++) {
        int x, y;
        char tmp;
        cin >> x >> y >> tmp;
        a[x - 1][tmp - 'a'] = y - 1;
    }

    cin >> n >> m >> term_2;

    b.resize(n);
    for (int i = 0; i < n; i++) {
        b[i].resize(26, -1);
    }

    term_b.resize(n, false);

    for (int i = 0; i < term_2; i++) {
        int x;
        cin >> x;
        term_b[x - 1] = true;
    }
    for (int i = 0; i < m; i++) {
        int x, y;
        char tmp;
        cin >> x >> y >> tmp;
        b[x - 1][tmp - 'a'] = y - 1;
    }

    if (term_1 != term_2) {
        cout << "NO";
        return 0;
    }
    visited.resize(n, false);

    isom(0, 0);

    if (res == true) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
    return 0;
}
