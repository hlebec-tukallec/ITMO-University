#include <iostream>
#include <string>
#include <vector>

using namespace std;
string n;

//vector<string>fin;
void generate(string ans) {
    int cnt_op = 0;
    int cnt_cl = 0;
    for (int i = ans.size()-1; i >= 0; i--) {
        if (ans[i] == '(') {
            cnt_op++;
            if (cnt_cl > cnt_op) {
                break;
            }
        } else {
            cnt_cl++;
        }
    }
    //cout << cnt_op;
   // cout << cnt_cl;
   // return;
   
  int tmp = ans.size();
  for (int i = tmp - cnt_op - cnt_cl; i < tmp; i++){
      ans.pop_back();
  }
     if (ans == "") {
         cout << '-';
     }
     else {
         ans = ans + ')';
         for (int j = 0; j < cnt_op; j++) {
             ans = ans + '(';
         }
         for (int j = 0; j < cnt_cl - 1; j++) {
             ans = ans + ')';
         }
        cout << ans;
     }


}

int main ()
{     freopen("nextbrackets.in","r", stdin);
      freopen("nextbrackets.out","w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cin >> n;
        generate(n);
        return 0;
}
