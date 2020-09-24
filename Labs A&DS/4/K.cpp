#include <cstdio>
#include <iostream>
#include <set>

using namespace std;
set<int>park;

int main() {
    freopen("parking.in", "r", stdin);
    freopen("parking.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie();

    int n, m;
    cin >> n >> m;
    string tmp = " ";
    for (int i = 0; i < n; i++) {
        park.insert(i + 1);
    }
    for (int i = 0; i < m; i++) {
        cin >> tmp;
        if (tmp == "enter") {
            int x;
            cin >> x;
            if (park.lower_bound(x) == park.end())  {
               cout << *park.lower_bound(1) << endl;
               park.erase(*park.lower_bound(1));
            }
            else {
                cout << *park.lower_bound(x) << endl;
                park.erase(*park.lower_bound(x));
            }
        }
        else {
            int x;
            cin >> x;
            park.insert(x);
        }
    }
    return 0;
}
