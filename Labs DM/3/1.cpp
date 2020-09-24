#include <iostream>
#include <string>
using namespace std;
int n;
void generate(string x){
    if (x.size() == n) {
        cout << x << endl;
    }
    else {
        generate(x + "0");
        generate(x + "1");
    }
}

int main() {
    freopen("allvectors.in","r", stdin);
    freopen("allvectors.out","w", stdout);
    cin >> n;

    generate("");
    return 0;
}
