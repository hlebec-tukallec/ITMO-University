#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;
vector<vector <string>> table;

int main() {
  freopen("epsilon.in", "r", stdin);
  freopen("epsilon.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie();
    int n;
    table.resize(30);
    string start_term;
    getline(cin, start_term, ' ');
    n = stoi(start_term);
    getline(cin, start_term);

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
    }

    set <char> to_eps;
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < table[i].size(); j++) {
            if (table[i][j] == "eps") {
                to_eps.insert(i + 'A');
            }
        }
    }

    bool flag;
    bool check;
    do {
        flag = false;
        for (int i = 0; i < 26; i++) {
            for (auto j : table[i]) {
                check = true;
                for (char k : j) {
                    check = check & (to_eps.find(k) != to_eps.end());
                }
                if (check == true) {
                    int cur = to_eps.size();
                    to_eps.insert(i + 'A');
                    if (to_eps.size() > cur) {
                        flag = true;
                    }
                }

            }
        }
        if (flag == false) {
            break;
        }
    } while (true);

    for (auto i : to_eps) {
        cout << i << " ";
    }

    return 0;
}
