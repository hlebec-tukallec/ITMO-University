#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;
int n;
int k;
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
    signed long long int ans = 1;
    for (int i = 1; i <= y; i++) {
        ans = ans * (x - i + 1);
        ans = ans / i;
    }
    return ans;
}


void generate () {
    int number = 0;
    for (int i = 1; i <= k; i++) {
        for (int j = choose[i - 1] + 1; j <= choose[i] - 1; j++) {
            number = number + count_choose(n - j, k - i);
        }
    }
    cout << number;

}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  freopen("choose2num.in","r", stdin);
  freopen("choose2num.out","w", stdout);
    cin >> n;
    cin >> k;
    int a;
    choose.push_back(0);
    for (int i = 0; i < k; i++) {
        cin >> a;
        choose.push_back(a);
    }

    generate();
    return 0;
}
