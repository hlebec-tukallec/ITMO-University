#include <iostream>
#include <vector>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int count = 0;
    int n;
    cin >> n;
    vector<long long>balls;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        balls.push_back(x);
    }

    int l = 0;
    int r = 0;
    int tmp = 0;

    vector<long long>nes;
    vector<long long>col;

    while (r < balls.size()) {
       //for (int i = 0; i < balls.size()-1; i++) {
         // if (balls[r] == balls[r+1]) {
           //    r++;
           //}
       // }
       while (r < balls.size() - 1 && balls[r] == balls[r + 1])
           r++;

       tmp = r - l + 1;

       if (l != 0 && col[col.size() - 1] == balls[l]) {
            tmp = tmp + nes[nes.size() - 1];
            if (tmp > 2) {
                nes.pop_back();
                col.pop_back();
                count = count + tmp;
                r++;
            } else {
                nes[nes.size() - 1] = nes[nes.size() - 1] + tmp;
                r++;
            }
        }

       else if (tmp >= 3){
            count = count + tmp;
           r++;
        }


       else if (tmp < 3) {
             nes.push_back(tmp);
             col.push_back(balls[l]);
           r++;
         }
       l = r;


    }
    cout << count;
    return 0;

}
