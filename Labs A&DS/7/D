#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    freopen("sequence.in", "r", stdin);
    freopen("sequence.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie();
    int n;
    cin >> n;
    vector<pair<int, int>> seq;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        seq.push_back({x, i});
    }
    int sum_1 = 0;
    int sum_2 = 0;
    vector<pair<int, int>> first;
    vector<pair<int, int>> second;
    sort(seq.begin(), seq.end());
    for (int i = seq.size() - 1; i >= 0; i--) {
        if (sum_1 < sum_2) {
            first.push_back(seq[i]);
            sum_1 += seq[i].first;
        }
        else {
            second.push_back(seq[i]);
            sum_2 += seq[i].first;
        }
    }
    if (sum_2 != sum_1) {
        cout << -1;
        return 0;
    }

    cout << second.size() << '\n';
    for (int i = 0; i < second.size(); i++) {
        cout << second[i].second + 1 << " ";
    }
    return 0;
}
