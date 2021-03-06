#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int main() {
    freopen("problem2.in", "r", stdin);
    freopen("problem2.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie();

    string s;
    cin >> s;
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<vector<int>>> a(n, vector<vector<int>>(26));
    queue<pair<int, int>> q;
    q.push(pair<int, int>(0, 0));

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
        a[x - 1][tmp - 'a'].push_back(y - 1);
    }
    vector<vector<int>> table(n, vector<int>(s.size() + 1, -1));

    while (!q.empty()) {
        pair<int, int> tmp = q.front();
        q.pop();
        if (tmp.second == s.size()) {
            if (term[tmp.first] == true) {
                cout << "Accepts";
                return 0;
            }
            else {
                continue;
            }
        }

        for (int i = 0; i < a[tmp.first][s[tmp.second] - 'a'].size(); i++) {
            if (table[a[tmp.first][s[tmp.second] - 'a'][i]][tmp.second + 1] == -1) {
                q.push(pair<int, int>(a[tmp.first][s[tmp.second] - 'a'][i], tmp.second + 1));
                table[a[tmp.first][s[tmp.second] - 'a'][i]][tmp.second + 1] = 0;
            }
        }
    }
    cout << "Rejects";
    return 0;
}
