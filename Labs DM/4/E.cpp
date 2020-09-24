#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;

int main() {
    freopen("problem5.in", "r", stdin);
    freopen("problem5.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie();

    int n, m, k;
    cin >> n >> m >> k;
    int l;
    cin >> l;

    vector<vector<vector<int>>> a(n, vector<vector<int>> (26));
    queue<set<int>> q;
    q.push({0});

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

    map<set<int>, int> table;
    table[{0}] = 0;

    int count = 0;
    vector<vector<int>>dka(1, vector<int>(26, -1));
    vector<bool> termy({term[0]});
    while (!q.empty()) {
        auto tmp = q.front();
        q.pop();
        for (auto i : tmp) {
            if (term[i]) {
                termy[table[tmp]] = true;
            }
        }
        // for (auto i : tmp) {
        //     cout << ' ' << i;
        // }
        // cout << endl << endl;
        for (int i = 0; i < 26; i++) {
            set<int> emp;
            for (auto j: tmp) {
               for (int w = 0; w < a[j][i].size(); w++) {
                   emp.insert(a[j][i][w]);
               }
            }
            if (table.find(emp) == table.end()) {
                count++;
                dka.emplace_back(26, -1);
                termy.emplace_back(false);
                table[emp] = count;
                q.push(emp);
            }
            // cout << table[tmp] << ' ' << table[emp] << ' ' << char('a' + i) << endl;
            dka[table[tmp]][i] = table[emp];
        }
    }

    vector<vector<int>> cnt(dka.size(), vector<int>(l + 1, 0));
    for (int i = 0; i < dka.size(); i++) {
        cnt[i][0] = termy[i];
    }

    for (int i = 0; i < l; i++) {
        for (int j = 0; j < dka.size(); j++) {
            for (int k = 0; k < 26; k++) {
                if (dka[j][k] != -1) {
                    cnt[j][i + 1] += cnt[dka[j][k]][i];
                    cnt[j][i + 1] %= 1000000007;
                }
            }
        }
    }

    cout << cnt[0][l];
    return 0;
}
