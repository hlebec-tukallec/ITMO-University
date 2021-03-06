#include <iostream>
#include <vector>
using namespace std;

int tmp, index;

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> a(k);
    vector<int> c(k);
    for (int i = 0; i < k; i++) {
        a[i].resize(n);
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            if (a[i][j] != -1) {
                c[i]++;
            }
        }
    }while (true){
        int i = 0;
        while ( i != k && c[i] != 1) {
            i++;
        }
        if (i == k) {
            cout << "NO";
            return 0;
        }
        for (int j = 0; j < n; j++) {
            if (a[i][j] != -1) {
                c[i]--;
                tmp = a[i][j];
                index = j;
                a[i][j] = -1;
            }
        }
        for (int j = 0; j < k; j++) {
            if (a[j][index] == tmp) {
                c[j] = 0;
            } else if (a[j][index] != -1 && a[j][index] != tmp) {
                if (c[j] == 1) {
                    cout << "YES";
                    return 0;
                } else {
                    a[j][index] = -1;
                    c[j]--;
                }
            }
        }
   }
}
