#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;
int n;
int k;
signed long long int m;
vector<int> choose;

signed long long int factor(signed long long int val) {
    signed long long int ans = 1;
    while (val > 1) {
        ans = val * ans;
        val--;
    }
    return ans;
}

signed long long int count_choose (int x, int y) {
    //signed long long int ans = factor(x)/factor(x - y) * factor(y);
    signed long long int ans = 1;
    for (int i = 1; i <= y; i++) {
        ans = ans * (x - i + 1);
        ans = ans / i;
    }
    return ans;
}


void generate () {
    int next = 1;
    while (k > 0) {
        if (m < count_choose(n-1, k-1)) {
            choose.push_back(next);
            k = k -1;
        }
        else {
            m = m - count_choose(n-1, k-1);
        }
        n = n - 1;
        next = next + 1;
    }
    for (int i = 0; i < choose.size(); i++) {
        cout << choose[i] << " ";
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   freopen("num2choose.in","r", stdin);
   freopen("num2choose.out","w", stdout);
    cin >> n;
    cin >> k;
    cin >> m;
    generate();
    return 0;
}
