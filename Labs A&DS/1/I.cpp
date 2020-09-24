#include<iostream>
#include <cmath>
using namespace std;

int main () {
    float c;
    cin >> c;
   float l = 0;
   float m;
   float  r = c;
    for (int i = 0; i < 50; i++) {
        m = (r + l)/2;

      if (m * m + sqrt(m) < c) {
          l = m;
      }
      else {
          r = m;
      }

   }

    cout << fixed;

    cout.precision(6);

    cout << r;
   return 0;
}
