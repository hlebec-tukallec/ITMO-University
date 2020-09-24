#include <iostream>
#include <string>
#include <vector>

using namespace std;
const int N = 2'000'153;
const int T = 1000000007;
vector<vector<int>> sety (N, vector<int>(0));

int h (int x) {
    return abs(x % N);
}
bool ex (int x) {
    int tmp = h(x);
    for (int i = 0; i < sety[tmp].size(); i++) {
        if (sety[tmp][i] == x) {
            return true;
        }
    }
    return false;
}

void in (int x) {
    if (!ex(x)) {
        int tmp = h(x);
        for (int i = 0; i < sety[tmp].size(); i++) {
            if (sety[tmp][i] == T) {
                sety[tmp][i] = x;
                return;
            }
        }
        sety[tmp].push_back(x);
    }
}

void del (int x) {
    if (ex(x)) {
        int tmp = h(x);
        for (int i = 0; i < sety[tmp].size(); i++) {
            if (sety[tmp][i] == x) {
                sety[tmp][i] = T;
            }
        }
    }
}

int main() {
    freopen("set.in", "r", stdin);
    freopen("set.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie();
    string s = "";
    int x;
    while (cin >> s) {
     //for (int i = 0; i < 10; i++) {
        //cin >> s;
        if (s == "insert") {
            cin >> x;
            in(x);
        }
        else if (s == "exists") {
            cin >> x;
            if (ex(x)) {
                cout << "true" << '\n';
            }
            else {
                cout << "false" << '\n';
            }
        }
        else {
            cin >> x;
            del(x);
        }
    }
    return 0;
}
