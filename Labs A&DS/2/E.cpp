#include <iostream>
#include <vector>
using namespace std;
vector<int>a;
int main() {
    string x;
    //int n;
   // cin >> n;
    //for (int i = 0; i < n; i ++) {
    while(cin >> x) {
       // cin >> x;
        if (x == "+") {
            a[a.size()-2] = a[a.size()-2] + a[a.size()-1];
            a.pop_back();
        }
        else if (x == "-") {
            a[a.size()-2] = a[a.size()-2] - a[a.size()-1];
            a.pop_back();
        }
        else if (x == "*") {
            a[a.size()-2] = a[a.size()-2] * a[a.size()-1];
            a.pop_back();
        }
        else a.push_back(stoi(x));

    }
    cout << a[0];
    return 0;
}
