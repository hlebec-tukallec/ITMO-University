#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    freopen("huffman.in","r",stdin);
    freopen("huffman.out", "w", stdout);

    vector<long long>value;
    //vector<int>haff;
    long long n;
    cin >> n;
    long long x;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> x;
        value.push_back(x);
    }

    while (value.size() > 1) {
        sort(value.begin(), value.end());
        value[0] = value[0] + value[1];
       ans = ans + value[0];
        value.erase(value.begin() + 1);
    }

    cout << ans;
    return 0;
}
