#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> ans;
vector<int> final;
vector<string>table;
vector<int> tmp;
void triangle () {
    final.push_back(ans[0]);
    tmp.resize(ans.size()-1);
    if (ans.size() > 1) {
        for (int i = 0; i < ans.size()-1; i++) {
            if ((ans[i] == 1) && (ans[i + 1] == 1)) {
                tmp[i] = 0;
            }
            else {
                tmp[i] = ans[i] + ans[i + 1];
            }
            ans[i] = tmp[i];
        }
    }
}

int main() {
    int n;
    cin >> n;
    string a;
    int val;
    int c = pow(2,n);
    for (int i = 0; i < c; i ++) {
       cin >> a >> val;
       table.push_back(a);
       ans.push_back(val);
    }
    while (ans.size() > 0) {
        triangle();
        c--;
        ans.resize(c);
        tmp.clear();
    }

   // triangle();
    for (int i = 0; i < final.size(); i ++) {
        cout << table[i] << " " << final[i] << endl;
       //cout << final[i] << endl;
        }
    return 0;
    }


