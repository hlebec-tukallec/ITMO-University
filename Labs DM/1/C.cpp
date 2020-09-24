#include<iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

vector<int>full(5,1);

void zero(string a) {
    if (a[0] != '0') {
        full[0] = 0;
    }
}

void one(string a) {
    if (a[a.size()-1] != '1') {
        full[1] = 0;
    }
}

void dual(string a) {
    if (a.size()==1) {
    full[2] = 0;
    return;
    }
    int i = 0;
    int j = a.size() - 1;
    while (i < j) {
        if(a[i] == a[j]) {
            full[2] = 0;
            return;
        }
        i++;
        j--;
    }
}

void  monoton(string a) {
   string str1 = a.substr(0, a.size()/2);
   string str2 = a.substr(a.size()/2, a.size()/2);
    if (str1 > str2) {
    full[3] = 0;
    return;
    }
   // while (str1.size() > 1 && str2.size() > 1) {
   if (str1.size() > 1) {
       monoton(str1);
   }
   if (str2.size() > 1) {
       monoton(str2);
   }
}


vector<int>zhig;
vector<int>tmp;
vector<int>ans;


void triangle () {
    zhig.push_back(ans[0]);
    if (ans.size() > 1) {
    tmp.resize(ans.size()-1);
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

vector<int>bini;

void bin(int a) {
    while (a > 0) {
        int tm = a % 2;
        bini.push_back(tm);
        a = a / 2;
    }
}

void lin() {
    for (int i = 0; i < zhig.size(); i++) {
        int count = 0;
        if (zhig[i] == 1) {
          bin(i);
           for (int j = 0; j < bini.size(); j++) {
              if (bini[j] == 1) {
                  count++;
              }
           }
         bini.clear();
        }

        if (count > 1) {
            full[4] = 0;
            return;
        }
    }
}


int main() {
    int n;
    cin >> n;
    int s;
    string t;
    for (int i = 0; i < n; i++) {
        cin >> s;
        int c = pow(2, s);
        cin >> t;
        if (full[0] != 0)
        zero (t);
        if (full[1] != 0)
        one (t);
        if (full[2] != 0)
        dual (t);
        if (full[3] != 0)
        monoton (t);
        if (full[4] != 0) {
            for (int j = 0; j < t.size(); j++) {
                ans.push_back((int) (t[j] - 48));
            }
            while (ans.size() > 0) {
                triangle();
                c--;
                ans.resize(c);
                tmp.clear();
            }
            lin();
            ans.clear();
            tmp.clear();
            zhig.clear();
        }
        t.clear();

    }
  if (full[0] == 0 && full[1] == 0 && full[2] == 0 && full[3] == 0 && full[4] == 0) {
     cout << "YES";
  }

   else {
      cout << "NO";
  }
      //for (int i = 0; i < 5; i++) {
       //  cout << full[i];
     // }
      return 0;
}

