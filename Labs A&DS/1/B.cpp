#include <iostream>
#include <vector>

using namespace std;

void Count(vector<int>&a, int n){
    int max = -1;
    int  min = 100000;
    for (int i = 0; i < n; i++) {
        if (a[i] > max)
            max = a[i];
        if (a[i] < min)
            min = a[i];
    }
    int *c = new int[max + 1 - min];
    for (int i = 0; i < max + 1 - min; i++) {
        c[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        c[a[i] - min] = c[a[i] - min] + 1;
    }
    int i = 0;
    for (int j = min; j < max + 1; j++) {
        while (c[j-min] != 0) {
            a[i] = j;
            c[j-min]--;
            i++;
        }
    }
    return;
}

int main() {
    vector <int> a;
    int x;
    while(cin >> x) {
        a.push_back(x);
    }
    Count(a, a.size());
    for (int i = 0; i < a.size(); i ++) {
        cout << a[i] << " ";
    }
    return 0;

}
