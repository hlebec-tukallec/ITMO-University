#include <iostream>
#include <vector>

using namespace std;
vector<int>a;
int c;
int n;
void generate(int p, int sum) {
    if (sum == 0) {
        for (int i = 1; i < a.size(); i++) {
            cout << a[i];
            if (i != a.size()-1) {
                cout << "+";
            }
            else {
                cout << endl;
            }
        }
    }
    else {
         c = min(a[p-1], sum);
         for (int i = c; i >= 1; i--) {
            a.push_back(c);
             generate(p + 1, sum - i);
         }
    }

}

int main() {
   // freopen("partition.in", "r", stdin);
    //freopen("partition.out", "w", stdout);
    cin >> n;
    a.push_back(1);
    generate(1, n);

    return 0;
}
