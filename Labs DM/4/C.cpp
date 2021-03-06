#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> a;
vector<vector<int>> b;
vector<bool>term;
vector<bool>visited;
vector<int>cycles;
int count = 0;
bool flag = false;

void do_term(int v) {
    if (visited[v]) {
        return;
    }
    visited[v] = true;
    for (int i = 0; i < 26; i++) {
        if (b[v][i] != -1) {
            do_term(b[v][i]);
        }
    }
}

void check_cycles(int v) {
    if (cycles[v] == 1) {
        return;
    }
    if (cycles[v] == -1) {
        if (visited[v]) {
            flag = true;
            cout << -1;
            exit(0);
            return;
        }
        else {
            for (int i = 0; i < 26; i++) {
                a[v][i] = -1;
            }
            return;
        }

    }

    cycles[v] = -1;
    for (int i = 0; i < 26; i++) {
        if (a[v][i] != -1) {
            check_cycles(a[v][i]);
        }
    }
    cycles[v] = 1;
}

void result(int v) {
    if (term[v]) {
        count = (count + 1) % 1000000007;
    }

    for (int i = 0; i < 26; i++) {
        if (a[v][i] != -1) {
            result(a[v][i]);
        }
    }
}

int main() {
    freopen("problem3.in", "r", stdin);
    freopen("problem3.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie();

    int n, m, k;
    cin >> n >> m >> k;

    a.resize(n, vector<int>(26, -1));
    b.resize(n, vector<int>(26, -1));

    term.resize(n, false);
    visited.resize(n, false);

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
        b[y - 1][tmp - 'a'] = x - 1;
    }
    for (int i = 0; i < n; i++) {
        if (term[i]) {
            do_term(i);
        }
    }

    cycles.resize(n, 0);
    check_cycles(0);
    if (flag) {
        return 0;
    }
    else {
        result(0);
        cout << count;
        return 0;
    }
}
