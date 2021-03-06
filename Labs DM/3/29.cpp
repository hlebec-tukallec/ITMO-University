#include <iostream>
#include <vector>
#include <string>
#include <deque>

using namespace std;
vector<int>a;
vector<int>ans;
//vector<char>tmp;
void generate() {
    if (a.size() == 1) {
        cout << "No solution";
    }
    else {
        a[a.size() - 1] = a[a.size() - 1] - 1;
        a[a.size() - 2] = a[a.size() - 2] + 1;
        if (a[a.size() - 2] > a[a.size() - 1]) {
            a[a.size() - 2] += a[a.size() - 1];
            a.pop_back();
        } else {
            while (a[a.size() - 2] * 2 <= a[a.size() - 1]) {
                a.push_back(a[a.size() - 1] - a[a.size() - 2]);
                a[a.size() - 2] = a[a.size() - 3];
            }
        }
        cout << ans[0] << "=";
        for (int i = 0; i < a.size(); i++) {
            if (i == a.size() - 1) {
                cout << a[i];
            } else {
                cout << a[i] << "+";
            }
        }
    }
}



int main() {
   freopen("nextpartition.in","r", stdin);
   freopen("nextpartition.out","w", stdout);

    string s;
    cin >> s;
    string tmp = "";
    int check = 0;
    string h = "";

    for (int i = 0; i < s.size(); i++) {
        if( s[i] == '=') {
            check++;
        }
        else if(check == 0) {
           tmp = tmp + s[i];
        }
        else if ((check == 1) && (s[i] != '+')) {
            if ((i == s.size() - 1) || (s[i + 1] == '+')) {
                h = h + s[i];
                a.push_back(stoi(h));
                h = "";
            }
            else if (i != s.size() - 1){
                if (s[i + 1] != '+') {
                    h = h + s[i];
                }
            }
        }
    }

    ans.push_back(stoi(tmp));
    generate();
    return 0;
}
