#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 2'000'000'005;
vector<pair<int,int>> money;

void county (int sum, int n, int &result) {
    int minim = INF;
    int tmp;
    for (int i = 0; i < 7; i++) {
        int cur = 1;
        if (n % money[i].second == 0) {
            cur = 0;
        }
        tmp = n/money[i].second + cur;
        minim = min(minim, tmp * money[i].first);
    }
    result = min(result, minim + sum);
}

void check (int sum, int n, int &result) {
    if (n <= 0) {
        result = min(result, sum);
        return;
    }
    int tmp;
    for (int i = 0; i < 7; i++) {
        tmp = n / money[i].second * money[i].first;
        if (tmp > 0) {
            int cur = n - (n/money[i].second) * money[i].second;
            county(sum + tmp, cur, result);
            check(sum + tmp, cur, result);
        }
    }
    county(sum, n, result);
}


int main() {
    freopen("printing.in", "r", stdin);
    freopen("printing.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie();
    int n;
    cin >> n;
    money.resize(7);

    int j = 1;
    for (int i = 0; i < 7; i++) {
        cin >> money[i].first;
        money[i].second = j;
        j *= 10;
    }
    
    int result = INF;
    check(0, n, result);

    cout << result;
    return 0;
}
