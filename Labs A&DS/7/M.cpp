#include <iostream>
#include <string>
#include <vector>

using namespace std;
const int N = 2'000'153;
string T = "dima loshara";
vector<vector<pair<string, string>>> mapy (N);

int h (string x) {
    long long int hash = 0;
    int p = 1;
    for (int i = 0; i < x.size(); i++) {
        hash += (x[i] - 'a' + 1) * p;
        p = p * 17;
    }
    return abs(hash % N);
}
string gety (string x) {
    int tmp = h(x);
    for (int i = 0; i < mapy[tmp].size(); i++) {
        if (mapy[tmp][i].first == x) {
            return mapy[tmp][i].second;
        }
    }
    return "none";
}

void puty(string x, string y) {
    int tmp = h(x);
    for (int i = 0; i < mapy[tmp].size(); i++) {
        if (mapy[tmp][i].first == x) {
            mapy[tmp][i].second = y;
            return;
        }
        else if (mapy[tmp][i].first == T) {
            mapy[tmp][i] = {x, y};
            return;
        }
    }
    mapy[tmp].push_back({x, y});
}

void del (string x) {
    int tmp = h(x);
    for (int i = 0; i < mapy[tmp].size(); i++) {
        if (mapy[tmp][i].first == x) {
            mapy[tmp][i].first = T;
        }
    }
}

int main() {
    freopen("map.in", "r", stdin);
    freopen("map.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie();
    string s = "";
    string x;
    string y;
    while (cin >> s) {
        if (s == "put") {
            cin >> x >> y;
            puty(x, y);
        }
        else if (s == "get") {
            cin >> x;
            cout << gety(x) << '\n';
        }
        else {
            cin >> x;
            del(x);
        }
    }
    return 0;
}
