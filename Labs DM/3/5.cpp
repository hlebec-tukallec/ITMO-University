#include <iostream>
#include <string>
using namespace std;
int n;
int k;
void generate(string x, int s) {
    if (x.size() == n) {
        cout << x << endl;
    } else {
        if (s%2 == 0){
          // ++s;
            for (int i = 0; i < k; i++) {
                generate(to_string(i) + x, s+i%2);
            }
        }
        else {
         // s++;
            for (int i = k-1; i >= 0; i--) {
                generate(to_string(i) + x, s+i%2);
            }
        }
    }

}

int main() {
    freopen("telemetry.in","r", stdin);
    freopen("telemetry.out","w", stdout);
    cin >> n;
    cin >> k;
    generate("", 0);
    return 0;
}
