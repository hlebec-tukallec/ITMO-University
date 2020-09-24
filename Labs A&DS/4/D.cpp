#include <iostream>
#include <vector>

using namespace std;
typedef long long int ll;
ll k;
ll count = 0;
vector<ll>t;
vector<ll>upd;
vector<ll>datal;

void treebuild () {
    k = 1000000;
    t.resize(2 * k - 1, 0);
    upd.resize(2*k - 1, 0);
    datal.resize(2*k - 1,0);
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
       // if (z == 1) {
         //   if (datal[v - 1] == 1 && datal[v + 1] == 1 && count > 0) {
           //     count--;
            //} else if (datal[v - 1] != 1 && datal[v + 1] != 1 && count >= 0) {
              //  count++;
            //}
       // }
        return;
    }
    set(2*v + 1, l, (l+r)/2, x, y, z);
    set(2*v + 2, (l+r)/2, r, x, y, z);
    datal[v] = datal[2 * v + 1] +  datal[2 * v + 2];
}

ll rsq(ll v, ll l, ll r, ll a, ll b) {
    if ((l >= a) && (r <= b)) {
        return datal[v];
    }
    if ((l >= b)||(r <= a)) {
        return 0;
    }
    return (rsq(2*v + 1, l, (l+r)/2, a, min(b, (l+r)/2)) + rsq(2*v + 2, (l+r)/2, r, max(a,(l+r)/2), b));
}

void white(int x, int y){
    set(0, 0, k, x + 500000, x + 500000 + y, 0);
    //количество черных отрезков
    cout << count << " ";
    //суммарная длина
    cout << datal[0] << endl;
}

void black (int x, int y) {
    set(0, 0, k, x + 500000, x + 500000 + y, 1);
    //количество черных отрезков
    cout << count << " ";
    //суммарная длина
    cout << datal[0] << endl;
}

int main() {
    ll  n;
    cin >> n;
    ll x, y;
    treebuild();
    for (ll i = 0; i < n; i++) {
        string tmp = "";
        cin >> tmp;
        if (tmp == "W") {
            cin >> x >> y;
            white(x, y);
        }
        else {
            cin >> x >> y;
            black(x, y);
        }
    }
    return 0;
}
