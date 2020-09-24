#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;
vector<string>ans;
int n;
string tmp;
map<string,int>ch;

int findy(string x) {
    for (int i = 0; i < ans.size(); i++) {
        if (ans[i] == x) {
            return 1;
        }
    }
    return -1;
}

void generate(string x) {
    string pref;
   // int mapy = 1;
    for (int i = 1; i < pow(2, n); i++) {
        x.erase(x.begin());
        pref = x;

        if (ch.find(pref + '1') == ch.end()) {
            x = pref + '1';
            ch.insert(pair<string,int>(x, 1));
            ans.push_back(x);
           // mapy++;
        }

        else if(ch.find(pref + '0') == ch.end()) {
            x = pref + '0';
            ch.insert(pair<string,int>(x, 1));
            ans.push_back(x);
            //mapy++;
        }

        else {
            return;
        }
    }
}


int main() {
    freopen("chaincode.in", "r", stdin);
    freopen("chaincode.out", "w", stdout);
   // int n;
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
    cin >> n;
    tmp = "";
    for (int i = 0; i < n; i++) {
        tmp.push_back('0');
    }
   // cout << tmp << endl;
    ans.push_back(tmp);
    ch.insert(pair<string,int>(tmp, 1));

    generate(tmp);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
    return 0;
}
