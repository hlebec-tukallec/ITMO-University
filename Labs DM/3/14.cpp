#include <iostream>
#include <string>
#include <vector>
using namespace std;
int n;
vector<int>perm;
vector<bool>used;

signed long long int factor(int val) {
    signed long long int ans = 1;
    while (val > 1) {
        ans = val * ans;
        val--;
    }
   // cout << ans;
    return ans;
}

void generate(vector<int>x) {
    signed long long int ans = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j < x[i]; j++) {
            if (used[j] == false) {
                ans = ans + factor(n-i);
            }
        }
        used[x[i]] = true;
    }
    cout << ans;
}
int main() {
   freopen("perm2num.in","r", stdin);
   freopen("perm2num.out","w", stdout);

    int a;
    cin >> n;
    perm.push_back(0);
    for (int i = 0; i < n; i++) {
        cin >> a;
        perm.push_back(a);
    }
    used.resize(n + 1);
    for (int i = 1; i < used.size() + 1; i++) {
        used[i] = false;
    }
    generate(perm);

    return 0;
}
