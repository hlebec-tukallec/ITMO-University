#include <iostream>
#include <vector>
using namespace std;

vector<int>val;
vector<int>din;
vector<int>ans;
int main() {
    int n;
    int a;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        val.push_back(a);
    }
    din.resize(val.size());
    ans.resize(val.size());
    for (int i = 0; i < din.size(); i++){
        din[i] = 1;
        ans[i] = -1;
    }

    for (int i = 0; i < din.size(); i++){
        for (int j = 0; j < i; j++) {
            if ((val[j] < val[i]) && (din[j] + 1 > din[i])) {
                din[i] = din[j] + 1;

                ans[i] = j;
            }
        }
    }
    int maxim = din[0];
    int ind = 0;
    for (int i = 0; i < din.size(); i++) {
        if (din[i] > maxim) {
            ind = i;
            maxim = din[i];
        }
    }
    cout << maxim << endl;

    din.clear();
    while (ind != -1) {
        din.push_back(val[ind]);
        ind = ans[ind];
    }
    for (int i = din.size() - 1; i >= 0; i--) {
        cout << din[i] << " ";
    }
    return 0;
}
