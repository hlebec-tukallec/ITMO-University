#include <iostream>
#include <vector>
using namespace std;

vector<int> val;

void func(int n)  {
    int a;
    vector<int> tmp;
    for (int i = 0; i < n; i ++) {
        cin >> a;
        if (a == 0) {
            a = 1;
            tmp.push_back(a);
        }
        else if (a == 1) {
            a = 0;
            tmp.push_back(a);
        }
        //else if (a == -1)

    }
    int c = 0;
     for (int j = 0; j < tmp.size(); j++) {
         if (tmp[j] == 1) {
             c = 1;
             break;
         }
     }
    val.push_back(c);
}


int main () {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        func(n);
    }
    int check = 1;
    for (int j = 0; j < val.size(); j++) {
        if (val[j] == 0) {
            check = 0;
            break;
        }
    }
    if (check == 0) {
        cout << "YES";
    }
    else
        cout << "NO";

return 0;
}