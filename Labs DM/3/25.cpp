#include <iostream>
#include <vector>
#include <string>
using namespace std;
int n;
int k;
vector<int>ch;
vector<int>help;
void generate() {
    int tmp = k - 1;
    while ((tmp >= 0) && ((help[tmp + 1] - help[tmp]) < 2)) {
        tmp--;
    }
    if (tmp >= 0) {
        help[tmp] = help[tmp] + 1;
        for (int i = tmp + 1; i < k; i++) {
            help[i] = help[i - 1] + 1;
        }
        for (int j = 0; j < k; j++) {
            ch[j] = help[j];
        }
        for (int i = 0; i < ch.size(); i++) {
            cout << ch[i] << " ";
        }
    }
    else {
        cout << -1;
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("nextchoose.in","r", stdin);
    freopen("nextchoose.out","w", stdout);
    cin >> n;
    cin >> k;
    int a;
    for (int i = 0; i < k; i++) {
        cin >> a;
        ch.push_back(a);
        help.push_back(a);
    }
    help.push_back(n + 1);
    generate();
    return 0;

}
