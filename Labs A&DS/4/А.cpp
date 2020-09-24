#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef signed long long int ll;
ll sum = 0;
vector<ll>preff;
vector<int>a;
int n;

void prep() {
    preff[0] = a[0];
    for (int i = 1; i < n; i++) {
        preff[i] = preff[i-1] + a[i];
    }
}

ll count(int l, int r) {
    if (l > 0) {
        return (preff[r] - preff[l-1]);
    }
    else {
        return preff[r];
    }
}

int main() {
    cin >> n;
    a.resize(n);
    int x, y;
    cin >> x >> y >> a[0];
    for (int i = 1; i < n; i++) {
        a[i] = ((long long) x * a[i - 1] + y) % 65536;
    }
    int m;
    cin >> m;
    if (m == 0) {
        cout << 0 << endl;
    } else {
        vector<int> b(m * 2);
        int z, t;
        cin >> z >> t >> b[0];
        for (int i = 1; i < m * 2; i++) {
            b[i] = ((long long) z * b[i - 1] + t + 1073741824) % 1073741824;
        }

        for (int i = 0; i < b.size(); i++) {
            b[i] = b[i] % n;
        }
        preff.resize(a.size());
        prep();

        for (int i = 0; i < m; i++) {
            int l = min(b[2 * i], b[2 * i + 1]);
            int r = max(b[2 * i], b[2 * i + 1]);
            sum += count(l, r);
        }
        cout << sum;
    }
    return 0;
}
