#include<iostream>
#include <vector>
using namespace std;
 
int binar(const vector<int> &a, int y) {
    int l = 0;
    int r = a.size() - 1;
    if (y > a[a.size() - 1])
        return a[r];
    if (y < a[0])
        return a[l];
 
    if (y == a[r])
        return a[r];
    if (y == a[l])
        return a[l];
 
    while (l < r) {
        int m = l + (r - l) / 2;
        if (a[m] > y)
            r = m;
        if (a[m] == y)
            return a[m];
        else if (a[m] < y)
            l = m + 1;
        //  if (a[m] == y) {
        //     return a[m];
        // }
    }
 
//if ((a[r] - y) <= (y - a[l]))
//  return a[l-1];
    if (y - a[l - 1] <= a[l] - y)
        return a[l - 1];
    else
        return a[l];
}
 
 
int main() {
    int n;
    int k;
    cin >> n >> k;
    vector<int> sorted;
    vector<int> a;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        sorted.push_back(x);
    }
    for (int i = 0; i < k; i ++) {
        int y;
        cin >> y;
        a.push_back(y);
        y = binar(sorted, y);
        cout << y << endl;
    }
    return 0;
 
}
