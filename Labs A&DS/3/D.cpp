#include <iostream>
#include <vector>

using namespace std;

vector<signed long long int>num1(10);
vector<signed long long int>num2(10);

void count() {
    num1[0] = num2[4] + num2[6];
    num1[1] = num2[6] + num2[8];
    num1[2] = num2[7] + num2[9];
    num1[3] = num2[4] + num2[8];
    num1[4] = num2[0] + num2[3] + num2[9];
    num1[5] = 0;
    num1[6] = num2[0] + num2[1] + num2[7];
    num1[7] = num2[2] + num2[6];
    num1[8] = num2[1] + num2[3];
    num1[9] = num2[2] + num2[4];
}


int main() {
    int n;
    cin >> n;
    num1[0] = 0;
    for (int i = 1; i < 10; i++) {
        if (i == 8) {
            num1[i] = 0;
        }
        else {
            num1[i] = 1;
        }
    }
    signed long long int ans = 0;
    if (n == 1) {
        cout << 8;
        return 0;
    }
    else {
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < 10; j++) {
                num2[j] = num1[j] % 1000000000;
            }
            count();
        }

        for (int i = 0; i < 10; i++) {
            ans = ans + (num1[i] % 1000000000);
        }
    }
    ans = ans % 1000000000;
    cout << ans;
    return 0;
}
