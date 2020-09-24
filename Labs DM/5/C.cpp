#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;
vector<vector <string>> table;
vector<int> checker(26, -1);

int main() {
    freopen("useless.in", "r", stdin);
    freopen("useless.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie();
    int n;
    table.resize(30);
    string start_term;
    getline(cin, start_term, ' ');
    n = stoi(start_term);
    getline(cin, start_term);
    checker[start_term[0] - 'A'] = 0;

    for (int i = 0; i < n; i++) {
        string tmp;
        getline(cin, tmp);
        char c = tmp[0];
        string symb;
        if (tmp[tmp.size() - 1] == '>') {
            symb = "eps";
        } else {
            int help = 0;
            for (int j = 0; j < tmp.size(); j++) {
                if (tmp[j] == '>') {
                    help = j;
                    break;
                }
            }
            help = help + 2;
            symb = tmp.substr(help);
        }
        table[c - 'A'].push_back(symb);
        checker[c - 'A'] = 0;
        if (symb != "eps") {
            for (char k : symb) {
                if (k <= 'Z') {
                    checker[k - 'A'] = 0;
                }
            }
        }
    }

    set<char>born;
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < table[i].size(); j++) {
            if (table[i][j] == "eps") {
                born.insert(i + 'A');
            }

            else {
                string cur = table[i][j];
                bool flag = true;
                for (char k : cur) {
                    if (k <= 'Z') {
                        flag = false;
                    }
                }
                if (flag) {
                    born.insert(i + 'A');
                }
            }
        }
    }

    bool flag;
    bool check;
    do {
        flag = false;
        for (int i = 0; i < 26; i++) {
            for (const auto& j : table[i]) {
                check = true;
                for (char k : j) {
                    if (k > 'Z') {
                        continue;
                    }
                    check = check & (born.find(k) != born.end());
                }
                if (check) {
                    int cur = born.size();
                    born.insert(i + 'A');
                    if (born.size() > cur) {
                        flag = true;
                    }
                }
            }
        }
        if (!flag) {
            break;
        }
    } while (true);

    if (born.find(start_term[0]) == born.end()) {
      born.clear();
    }

    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < table[i].size(); j++) {
            if (table[i][j] != "eps")  {
                for (char k : table[i][j]) {
                    if (k <= 'Z' && born.find(k) == born.end()) {
                        table[i].erase(table[i].cbegin() + j, table[i].cbegin() + j + 1);
                        break;
                    }
                }
            }
        }
    }

    set<char>reach;
    reach.insert(start_term[0]);

    do {
        flag = false;
        for (auto i : reach) {
            for (auto tmp : table[i - 'A']) {
                if (tmp != "eps") {
                    for (char & k : tmp) {
                        if (k <= 'Z') {
                            int cur = reach.size();
                            reach.insert(k);
                            if (reach.size() > cur) {
                                flag = true;
                            }
                        }
                    }
                }
            }
        }
        if (!flag) {
            break;
        }
    } while (true);


    for (int i = 0; i < 26; i++) {
        if (checker[i] == 0 && ((born.find(char(i + 'A')) == born.end())
        || (reach.find(char(i + 'A')) == reach.end()))) {
            cout << char(i + 'A') << " ";
        }
    }

    return 0;
    cout << '\n';

    for (auto i : born) {
        cout << i << " ";
    }
    cout << '\n';

    for (auto i : reach) {
        cout << i << " ";
    }

    return 0;
}
