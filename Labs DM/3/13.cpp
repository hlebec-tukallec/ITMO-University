#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;
int n;
vector<bool>used;

signed long long int factor(long long int val) {
    signed long long int ans = 1;
    while (val > 1) {
        ans = val * ans;
        val--;
    }
    return ans;
}

void generate(signed long long int x) {
   signed long long int ansy;
   signed long long int curFree;
   signed long long int alreadyWas;
   signed long long int tmp;
    for (int i = 1; i <= n; i++) {
        tmp = factor(n - i);
        alreadyWas = x / tmp;
        x = x % tmp;
        curFree = 0;
        for (int j = 1; j <= n; j++) {
            if (used[j] == false) {
                curFree++;
                if (curFree == alreadyWas + 1) {
                    used[j] = true;
                    ansy = j;
                }
            }
        }
    cout << ansy << " ";
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  freopen("num2perm.in","r", stdin);
  freopen("num2perm.out","w", stdout);
    cin >> n;
    signed long long int k;
    cin >> k;
    used.resize(n + 1, false);
    generate(k);
    return 0;
}
