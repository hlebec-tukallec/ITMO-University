#include <iostream>
#include <vector>
using namespace std;
int n;
int count = 0;
vector<vector<int>> safe;

void generate(vector<int> a, int symb) {
    a.push_back(symb);
    if (a.size() > 1 && a[a.size() - 1] == 1 && a[a.size() - 2] == 1) {
        return;
    }
    if (a.size() == n) {
        count++;
        safe.push_back(a);
        return;
    }
    generate(a, 0);
    generate(a, 1);

}

int main() {
    freopen("vectors2.in", "r", stdin);
    freopen("vectors2.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie();
    cin >> n;
    vector<int> s;
    generate(s, 0);
    generate(s, 1);
    cout << count << '\n';

    for (int i = 0; i < safe.size(); i++) {
        for (int j = 0; j < n; j++) {
            cout << safe[i][j];
        }
        cout << '\n';
    }

    return 0;
}
