#include <iostream>
#include <vector>

using namespace std;
vector<int>a;
vector<int>sort;
vector<string>ans;

int main() {
    int n;
    int x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (i > 0) {
            for (int j = a.size() - 1; j >= 0; j--) {
                if (a[j] < x) {
                    ans.push_back("pop");
                    sort.push_back(a[j]);
                    a.pop_back();
                }
                else {
                    break;
                }
            }
        }
        a.push_back(x);
        ans.push_back("push");
    }
    while (a.size() > 0) {
        sort.push_back(a[a.size()-1]);
        a.pop_back();
        ans.push_back("pop");
    }

for (int i = 0; i < sort.size()-1; i++) {
    if (sort[i] > sort[i + 1]) {
        cout << "impossible";
        return 0;
    }
}

for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << endl;
}
    return 0;
}

