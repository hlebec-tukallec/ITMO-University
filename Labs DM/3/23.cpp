#include <iostream>
#include <string>
using namespace std;


void generate_prev(string x){
    int s;
    s = x.size();
    while ((s >= 0) && (x[s-1] != '1')) {
        x[s-1] = '1';
        s--;
    }
    if (s < 0) {
        cout << "-" << endl;
        return;
    }
    x[s-1] = '0';
    //сделать проверку на первый 0 чтоб его убирать
    cout << x << endl;
}

void generate_next(string x) {
    int s;
    s = x.size();
    while ((s >= 0) && (x[s-1] != '0')) {
        x[s-1] = '0';
        s--;
    }
    if (s < 0) {
        cout << "-";
        return;
    }
    x[s-1] = '1';
    cout << x;
}



int main() {
    freopen("nextvector.in","r", stdin);
    freopen("nextvector.out","w", stdout);
    string n;
    cin >> n;
    generate_prev(n);
    generate_next(n);
    return 0;
}
