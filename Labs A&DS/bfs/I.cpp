#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> e;
vector<bool> used;
vector<int> ch;
vector<int> neigh;

void find_the_last() {
    for (int i = 0; i < neigh.size(); i++) {
        if (neigh[i] == 0) {
            ch[i] = -1;
        }
    }
}

void dfs (int v) {
    used[v] = true;
    for (int i = 0; i < e[v].size(); i++) {
        if (ch[e[v][i]] == 0) {
            if (ch[v] == -1) {
                ch[e[v][i]] = 1;
                dfs(e[v][i]);
            } else {
                neigh[e[v][i]]--;
                if (neigh[e[v][i]] == 0) {
                    ch[e[v][i]] = -1;
                    dfs(e[v][i]);
                }
            }
        }
    }
}

void count() {
    find_the_last();

    for (int i = 0; i < e.size(); i++) {
        if (ch[i]!= 0 && !used[i]) {
            dfs(i);
        }
    }

    for (int i : ch) {
        if (i == 1) {
            cout << "FIRST";
        } else if (i == -1) {
            cout << "SECOND";
        } else {
            cout << "DRAW";
        }
        cout << endl;
    }
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        e.assign(n, vector<int>());
        ch.assign(n, 0);
        used.assign(n, false);
        neigh.assign(n, 0);

        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            neigh[a - 1]++;
            e[b - 1].push_back(a - 1);
        }
        count();
    }

    return 0;
}
