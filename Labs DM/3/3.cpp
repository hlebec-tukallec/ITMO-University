#include <iostream>
#include <string>

using namespace std;
int n;
int cnt = 0;

void antigr(string x) {
    for (int i = 0; i < n; i++) {
        if (x[i] == '2') {
            x[i] = '0';
        }
         else {
             x[i]++;
         }
    }
    cnt++;
    cout << x << endl;
    if (cnt == 1) {
       antigr(x);
    }
    else{
        cnt = 0;
    }

}

void generate(string x){
    if (x.size() == n) {
       cout << x << endl;
       antigr(x);
    }
    else {
        generate(x + "0" );
        generate(x + "1");
        generate(x + "2");
    }
}

int
main ()
{
    freopen("antigray.in","r", stdin);
    freopen("antigray.out","w", stdout);
    cin >> n;

    generate ("0");

    return 0;
}
