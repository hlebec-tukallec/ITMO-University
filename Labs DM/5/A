#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<pair<char, char>>> table;
bool flag = false;

void check (int now, char st, string word) {
    if (st == '0' && now == word.size()) {
        flag = true;
        return;
    }
    if (st == '0' || now >= word.size()) {
        return;
    }

    char tmp = word[now];
    for (int i = 0; i < table[st - 'A'].size(); i++) {
        if (tmp == table[st - 'A'][i].second) {
            check(now + 1, table[st - 'A'][i].first, word);
        }
    }
}


int main() {
    freopen("automaton.in", "r", stdin);
    freopen("automaton.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie();
    int n;
    char start_term;
    cin >> n >> start_term;
    table.resize(26);
    for (int i = 0; i < n; i++) {
        char tmp;
        string nenado, s;
        cin >> tmp >> nenado >> s;
        pair<char, char> help;
        if (s.size() == 1) {
            help = {'0', s[0]};
        }
        else {
            help = {s[1], s[0]};
        }
        table[tmp - 'A'].push_back(help);
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        flag = false;
        string s;
        cin >> s;
        check(0, start_term, s);
        if (!flag) {
            cout << "no" << '\n';
        }
        else {
            cout << "yes" << '\n';
        }
    }
    return 0;
}
