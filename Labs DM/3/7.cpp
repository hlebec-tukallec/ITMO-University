#include <iostream>
#include <string>
#include <cmath>

using namespace std;
int n;
void generate(string x) {
    if (x.size() == n) {
        for (int i = 0; i < n; i++) {
            cout << x[i] << " ";
        }
        cout << endl;
    } else {
        for (int i = 1; i <= n; i++) {
            if (x.find(to_string(i)) > n - 1) {
                generate(x + to_string(i));
            }
        }

    }
}

int main() {
    freopen("permutations.in","r", stdin);
    freopen("permutations.out","w", stdout);
    cin >> n;
    generate("");
    return 0;
}
