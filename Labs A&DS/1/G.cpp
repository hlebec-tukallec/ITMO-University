#include <iostream>

using namespace std;

int main(){
    int n, x, y;
    cin >> n >> x >> y;
    n--;
    int l = 0;
    int maxi = max(x, y);
    int mini = min(x, y);
    int r = n * maxi;
    int m;
    while (l < r) {
        m = (r + l) / 2;
        if ((m / x + m / y) < n) {
            l = m + 1;
        }
        else  {
            r = m;
        }
    }
    cout << r + mini;
    return 0;
}
