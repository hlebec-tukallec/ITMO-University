#include <iostream>
#include <vector>

using namespace std;
typedef long long int ll;
vector<ll>mas;
vector<ll>t;
ll n;
ll k;

ll nextpow(ll x) {
    ll pow = 1;
    while (pow < x) {
        pow = pow * 2;
    }
    return pow;
}

void treebuild () {
    k = nextpow(n);
    t.resize(2 * k - 1);
    for (ll i = 0; i < n; i++) {
        t[k - 1 + i] = mas[i];
    }
    for (ll i = n; i < k; i++) {
        t[k - 1 + i] = 0;
    }
    for (ll i = k - 2; i >= 0; i--) {
        t[i] = t[2 * i + 1] + t[2 * i + 2];
    }
}

void update(ll i, ll x) {
    t[k - 1 + i] = x;
    ll j = k - 1 + i;
    while (j > 0) {
        j = (j-1)/2;
        t[j] = t[2*j + 1] + t[2*j + 2];
    }
}

ll rsq(ll v, ll l, ll r, ll a, ll b) {
    if ((l >= a) && (r <= b)) {
        return t[v];
    }
    if ((l >= b)||(r <= a)) {
        return 0;
    }
    return (rsq(2*v + 1, l, (l+r)/2, a, min(b, (l+r)/2)) + rsq(2*v + 2, (l+r)/2, r, max(a,(l+r)/2), b));
}


 int main() {
     ll a;
     cin >> n;
     for (ll i = 0; i < n; i++) {
         cin >> a;
         mas.push_back(a);
     }
     treebuild();
     string tmp = "";
     while (cin >> tmp) {
         ll x, y;
         cin >> x >> y;
         if (tmp == "sum") {
             cout << rsq(0, 0, k, x-1, y) << endl;
         }
         else {
            update(x-1, y);
         }
     }
     return 0;
 }



