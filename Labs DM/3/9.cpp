#include <iostream>
#include <string>

using namespace std;
int n;

void generate(int s, int cnt_op, int cnt_cl, string ans) {
    if (cnt_op + cnt_cl == s * 2) {
        cout << ans;
        cout << endl;
    } else {
        if (cnt_op < s) {
            generate(s, cnt_op + 1, cnt_cl, ans + '(');
        }

        if (cnt_op > cnt_cl) {
            generate(s, cnt_op, cnt_cl+1, ans + ')');
        }
    }
}

int main ()
{
    freopen("brackets.in","r", stdin);
    freopen("brackets.out","w", stdout);
    cin >> n;


    generate (n, 0, 0, "");

    return 0;
}
