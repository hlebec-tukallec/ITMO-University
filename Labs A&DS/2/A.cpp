#include <iostream>
#include <vector>
using namespace std;


//int s = 0;
vector<long long>st;
vector<long long>minim;

//void insert(double y) {
 //s = s + 1;
 //st.resize(s);
 //st[s - 1] = y;
 //st.push_back(y);
//}

//void pop() {
  //  s = s - 1;
   // st.pop_back();
    //st.resize(s-1);
//}

//void minim(){
   // long long mini = 1000000000;
   // for (int i = 0; i < st.size(); i++) {
   //     if(st[i] < mini)
    //        mini = st[i];
    //}
   // cout << mini << "\n";
//}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    long long tmp = 10000000000;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        long long y;
        cin >> x;
        if (x == 1) {
            cin >> y;
            st.push_back(y);
            if (y <= tmp) {
                tmp = y;
                minim.push_back(tmp);
            }
            else {
                minim.push_back(tmp);
            }

        }
        if (x == 2) {
            st.pop_back();
            minim.pop_back();
            tmp = minim[minim.size()-1];
        }
        //s = s-1;
        if (x == 3)
            cout << minim[minim.size()-1] << "\n";

    }
    return 0;
}
