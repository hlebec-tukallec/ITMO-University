#include <iostream>
#include <string>
#include <vector>
#include <queue>
 
using namespace std;
 
vector<vector<int>> a;
vector<vector<int>> b;
vector<bool> term_a;
vector<bool> term_b;
vector<vector<bool>> visited;
queue<pair<int, int>> q;
 
bool res = true;
void equals () {
    q.push({1, 1});
 
    while (!q.empty()) {
        pair<int, int> tmp = q.front();
        q.pop();
        if (term_a[tmp.first] != term_b[tmp.second]) {
            res = false;
            return;
        }
        visited[tmp.first][tmp.second] = true;
        for (int i = 0; i < 26; i++) {
            if (visited[a[tmp.first][i]][b[tmp.second][i]] == false) {
                q.push({a[tmp.first][i], b[tmp.second][i]});
            }
        }
    }
}
 
 
int main() {
    freopen("equivalence.in", "r", stdin);
    freopen("equivalence.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie();
 
    int term_1, term_2;
    int n1, m;
    cin >> n1 >> m >> term_1;
 
    a.resize(n1 + 1);
    for (int i = 0; i <= n1; i++) {
        a[i].resize(26, 0);
    }
 
    term_a.resize(n1 + 1, false);
 
    for (int i = 0; i < term_1; i++) {
        int x;
        cin >> x;
        term_a[x] = true;
    }
    for (int i = 0; i < m; i++) {
        int x, y;
        char tmp;
        cin >> x >> y >> tmp;
        a[x][tmp - 'a'] = y;
    }
 
    int n2;
    cin >> n2 >> m >> term_2;
 
    b.resize(n2 + 1);
    for (int i = 0; i <= n2; i++) {
        b[i].resize(26, 0);
    }
 
    term_b.resize(n2 + 1, false);
 
    for (int i = 0; i < term_2; i++) {
        int x;
        cin >> x;
        term_b[x] = true;
    }
    for (int i = 0; i < m; i++) {
        int x, y;
        char tmp;
        cin >> x >> y >> tmp;
        b[x][tmp - 'a'] = y;
    }
 
    visited.resize(n1 + 1, vector<bool> (n2 + 1, false));
 
    equals();
 
    if (res) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
    return 0;
}
