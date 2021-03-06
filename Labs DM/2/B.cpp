#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


int main() {
    freopen("bwt.in", "r", stdin);
    freopen("bwt.out", "w", stdout);

    string s;
    cin >> s;
    vector<string>words(s.size());
    string tmp = s;
    words[0] = s;

    for (int i = 1; i < s.size(); i++) {
        string str1 = tmp.substr(tmp.size()-1, 1);
        tmp.pop_back();
        tmp = str1 + tmp;
        words[i] = tmp;
 
    }
    sort(words.begin(),words.end());
    for (int i = 0; i < words.size(); i ++) {
        cout << words[i][words.size()- 1];
    }

    return 0;
}
