#include <iostream>
using namespace std;
int main(){
    int n;
    int w, h;
    cin >> w >> h >> n;
   unsigned long long int m;
   unsigned long long int r = 1000000000000000000;
   unsigned long long int l = 0;
        while (l < r - 1) {
            m = (r + l) / 2;
            if ((m / w) * (m / h) < n) {
                l = m;
            } else {
                r = m;
            }
        }

            cout << r;
    return 0;
}
