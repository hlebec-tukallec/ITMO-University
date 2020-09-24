#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
vector<int>shoes;

int main() {
    freopen("cobbler.in", "r", stdin);
    freopen("cobbler.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie();
    int k, n;
    cin >> k >> n;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        shoes.push_back(x);
    }
    sort(shoes.begin(), shoes.end());
    int i = 0;
    int count = 0;
    while (k > 0) {
        if (shoes[i] <= k) {
            count++;
            k = k - shoes[i];
            i++;
        }
        else {
            break;
        }
    }
    cout << count;
    return 0;
}
