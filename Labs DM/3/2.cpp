#include <iostream>
#include <string>
using namespace std;
int n;
void generate(string x, int s){
    if (x.size() == n) {
        cout << x << endl;
    }
    else  {
        if (s%2 == 1) {
            generate(x + "1", s + 1);
            generate(x + "0", s);
        }
        else {
            generate(x + "0", s);
            generate(x + "1", s + 1);
        }
    }
}

int main() {
    freopen("gray.in","r", stdin);
    freopen("gray.out","w", stdout);
    cin >> n;
    generate("", 0);
    return 0;
}
