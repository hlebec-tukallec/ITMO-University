#include <iostream>
#include <vector>
#include <string>

using namespace std;
vector<string>alp;

int findy(string x) {
    for (int i = 0; i < alp.size(); i ++) {
        if (alp[i] == x) {
            return i;
        }
    }
    return -1;

}

int main() {
    freopen("lzw.in","r",stdin);
    freopen("lzw.out","w",stdout);

    string si;
    cin >> si;
    vector<string>s(si.size());
    for (int i = 0; i < si.size();i++) {
        s[i] = si[i];
    }
    vector<string>table;

    alp.push_back("a");
    alp.push_back("b");
    alp.push_back("c");
    alp.push_back("d");
    alp.push_back("e");
    alp.push_back("f");
    alp.push_back("g");
    alp.push_back("h");
    alp.push_back("i");
    alp.push_back("j");
    alp.push_back("k");
    alp.push_back("l");
    alp.push_back("m");
    alp.push_back("n");
    alp.push_back("o");
    alp.push_back("p");
    alp.push_back("q");
    alp.push_back("r");
    alp.push_back("s");
    alp.push_back("t");
    alp.push_back("u");
    alp.push_back("v");
    alp.push_back("w");
    alp.push_back("x");
    alp.push_back("y");
    alp.push_back("z");
    int r = 1;
    int i = 0;
    while (i < s.size()) {
        string tmp = s[i];
        string w;
        //cout << tmp;

        while (findy(tmp) != -1) {
            if (findy(tmp) != -1){
                w = tmp;
                if (tmp.size() > 1){
                    i++;
                }
            }
            if (r < s.size()) {
                tmp = tmp + s[r];
                r++;
            }
            else {
                break;
            }


        }

       // tmp.pop_back();

        cout << findy(w) << " ";

      //  r = 1;
        // tmp = s[i];
        //while (findy(tmp) != -1) {
          //  tmp = tmp + s[r];
            //r++;
        //}
        if (findy(tmp) == -1)
        alp.push_back(tmp);
        i++;
       // for (int k = 0; k < alp.size(); k++) {
         //cout << alp[k] << " ";
        //}
    }
return 0;

}
