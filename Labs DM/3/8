#include <iostream>
#include <string>

using namespace std;
int n;
int k;

void
generate(string x, int size)
{
    if (size == k) {
            cout << x;
            cout << endl;
    }
    else {
        for (int i = 1; i <= n; i++) {
            if (x.size() == 0) {
                generate(x + " " + to_string(i), size + 1);
            } else   {
                int a = x[x.size() - 1] - 48;
                if (!(x[x.size() - 2] == ' ')) {
                    a += (x[x.size() - 2] - 48) * 10;
                }

                if (i > a)
                    generate(x + " " + to_string(i), size + 1);
            }
        }
    }

}

int
main ()
{
    freopen("choose.in","r", stdin);
    freopen("choose.out","w", stdout);
    cin >> n;
    cin >> k;

    generate ("", 0);

    return 0;
}
