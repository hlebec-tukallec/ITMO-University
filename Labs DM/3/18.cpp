#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;
int n;
int k;
vector<char> br;
signed long long int diny[41][41];

void din() {
   // diny[0][0] = 1;
    for (int i = 0; i < 2*n; i++) {
        for (int j = 0; j < 2*n; j++){
            if (i == 0 && j != 0) {
                diny[i][j] = 0;
            }
            else if (i == 0 && j == 0) {
                diny[0][0] = 1;
            }
            else if (j == 2*n-1) {
                diny[i][j] = diny[i-1][j-1];
            }
            else {
                diny[i][j] = diny[i - 1][j - 1] + diny[i - 1][j + 1];
            }
        }
    }
}


void generate() {
    signed long long int number = 0;
    int depth = 0;
    for (int i = 0; i <= 2 * n; i++) {
        if (br[i] == '(') {
            depth++;
        }
        else {
            number = number + diny[2 * n - i - 1][depth + 1];
            depth--;
        }
    }
    cout << number;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  freopen("brackets2num.in","r", stdin);
  freopen("brackets2num.out","w", stdout);
    char a;
    while (cin >> a) {
      br.push_back(a);
   }
  // for (int i = 0; i < 8; i ++) {
    // cin >> a;
     //br.push_back(a);
   //}
    n = br.size()/2;
    din();
    generate();
    return 0;
}
