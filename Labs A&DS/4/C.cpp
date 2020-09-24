#include <iostream>
#include <vector>

using namespace std;
typedef long long int ll;

vector<ll>a;
vector<ll>t;
vector<ll>upd;
vector<ll>datal;
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
        t[k - 1 + i] = a[i];
    }
    for (ll i = n; i < k; i++) {
        t[k - 1 + i] = 100000000;
    }
    for (ll i = k - 2; i >= 0; i--) {
        t[i] = min(t[2 * i + 1],t[2 * i + 2]);
    }

    for (int i = 0; i < t.size(); i++) {
        upd.push_back(t[i]);
        datal.push_back(t[i]);
    }
}

void push (ll v, ll l, ll r) {
    if (r - l == 1) {
        return;
    }
    if (upd[v] == t[v]) {
        return;
    }
    upd[2 * v + 1] = upd[v];
    datal[2 * v + 1] = upd[v];
    upd[2 * v + 2] = upd[v];
    datal[2 * v + 2] = upd[v];
    upd[v] = t[v];
}

void set (ll v, ll l, ll r, ll x, ll y, ll z) {
    push(v, l, r);
    if ((y <= l) || (x >= r)) {
        return;
    }
    if (l >= x && r <= y) {
        upd[v] = z;
        datal[v] = z;
        return;
    }
    set(2*v + 1, l, (l+r)/2, x, y, z);
    set(2*v + 2, (l+r)/2, r, x, y, z);
    datal[v] = min(datal[2*v + 1], datal[2*v + 2]);
}

void add (ll v, ll l, ll r, ll x, ll y, ll z) {
    push(v, l, r);
    if ((y <= l) || (x >= r)) {
        return;
    }
    if (l >= x && r <= y) {
        upd[v] += z;
        datal[v] += z;
        return;
    }
    add(2*v + 1, l, (l+r)/2, x, y, z);
    add(2*v + 2, (l+r)/2, r, x, y, z);
    datal[v] = min(datal[2*v + 1], datal[2*v + 2]);
}

ll minim (ll v, ll l, ll r, ll x, ll y) {
    push(v, l, r);
    if (y <= l || x >= r) {
        return 100000008;
    }
    if (l >= x && r <= y) {
        return datal[v];
    }
    return min(minim(2*v + 1, l, (l+r)/2 , x, y), minim(2*v+2, (l+r)/2, r, x, y));
}

int main() {
    cin >> n;
    ll x;
    for (ll i = 0; i < n; i++) {
        cin >> x;
        a.push_back(x);
    }
    treebuild();
    string tmp = "";
    for (int i = 0; i < 10; i ++) {
        cin >> tmp;
        // while(cin >> tmp) {
        ll x, y, z;
        if (tmp == "set") {
            cin >> x >> y >> z;
            set(0, 0, k, x - 1, y - 1, z);
        }

        else if (tmp == "add") {
            cin >> x >> y >> z;
            add(0, 0, k, x - 1, y - 1, z);
        }

        else {
            cin >> x >> y;
            cout << minim(0, 0, k, x - 1, y - 1) << endl;
        }
    }
    return 0;
}#include <iostream>
#include <vector>

using namespace std;
typedef long long int ll;

vector<ll>a;
vector<ll>t;
vector<ll>upd;
vector<ll>datal;
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
        t[k - 1 + i] = a[i];
    }
    for (ll i = n; i < k; i++) {
        t[k - 1 + i] = 100000000;
    }
    for (ll i = k - 2; i >= 0; i--) {
        t[i] = min(t[2 * i + 1],t[2 * i + 2]);
    }

    for (int i = 0; i < t.size(); i++) {
        upd.push_back(t[i]);
        datal.push_back(t[i]);
    }
}

void push (ll v, ll l, ll r) {
    if (r - l == 1) {
        return;
    }
    if (upd[v] == t[v]) {
        return;
    }
    upd[2 * v + 1] = upd[v];
    datal[2 * v + 1] = upd[v];
    upd[2 * v + 2] = upd[v];
    datal[2 * v + 2] = upd[v];
    upd[v] = t[v];
}

void set (ll v, ll l, ll r, ll x, ll y, ll z) {
    push(v, l, r);
    if ((y <= l) || (x >= r)) {
        return;
    }
    if (l >= x && r <= y) {
        upd[v] = z;
        datal[v] = z;
        return;
    }
    set(2*v + 1, l, (l+r)/2, x, y, z);
    set(2*v + 2, (l+r)/2, r, x, y, z);
    datal[v] = min(datal[2*v + 1], datal[2*v + 2]);
}

void add (ll v, ll l, ll r, ll x, ll y, ll z) {
    push(v, l, r);
    if ((y <= l) || (x >= r)) {
        return;
    }
    if (l >= x && r <= y) {
        upd[v] += z;
        datal[v] += z;
        return;
    }
    add(2*v + 1, l, (l+r)/2, x, y, z);
    add(2*v + 2, (l+r)/2, r, x, y, z);
    datal[v] = min(datal[2*v + 1], datal[2*v + 2]);
}

ll minim (ll v, ll l, ll r, ll x, ll y) {
    push(v, l, r);
    if (y <= l || x >= r) {
        return 100000008;
    }
    if (l >= x && r <= y) {
        return datal[v];
    }
    return min(minim(2*v + 1, l, (l+r)/2 , x, y), minim(2*v+2, (l+r)/2, r, x, y));
}

int main() {
    cin >> n;
    ll x;
    for (ll i = 0; i < n; i++) {
        cin >> x;
        a.push_back(x);
    }
    treebuild();
    string tmp = "";
    for (int i = 0; i < 10; i ++) {
        cin >> tmp;
        // while(cin >> tmp) {
        ll x, y, z;
        if (tmp == "set") {
            cin >> x >> y >> z;
            set(0, 0, k, x - 1, y - 1, z);
        }

        else if (tmp == "add") {
            cin >> x >> y >> z;
            add(0, 0, k, x - 1, y - 1, z);
        }

        else {
            cin >> x >> y;
            cout << minim(0, 0, k, x - 1, y - 1) << endl;
        }
    }
    return 0;
}
