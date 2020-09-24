#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int>perm;
vector<int>values;
int n;
int r;
int j = 0;
int county = 0;

void value() {
    for (int i = 1; i < n; i++) {
        values[j] = (values[j] + perm[i - 1] * perm[i]) % r;
    }
    j++;
}

void check() {
    int del = 0;
    for (int i = 1; (i * i) <= values[j]; i++) {
        if ((i * i) == values[j]) {
            del++;
        }
        else if (values[j] % i == 0) {
            del += 2;
        }
    }
    if (del % 3 == 0 || del == 0) {
        county = county + 1;
    }
    j++;
}

int main() {
    freopen("beautiful.in", "r", stdin);
    freopen("beautiful.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie();
    cin >> n >> r;
    for (int i = 1; i <= n; i++) {
        perm.push_back(i);
    }

    do {
        values.push_back(0);
        value();
    } while (next_permutation(perm.begin(), perm.end()));

    j = 0;
    for (int i = 0; i < values.size(); i++) {
        check();
    }
    cout << county;

    return 0;
}
