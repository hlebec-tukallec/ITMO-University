#include <iostream>
#include <vector>
using namespace std;
int n;
vector<int>minim;
vector<int>count;
vector<int>parents;
vector<int>rang;
vector<int>maxim;

int findy (int x) {
    if (parents[x] != x) {
        parents[x] = findy(parents[x]);
    }
    return parents[x];
}

void uniony(int x, int y) {
    x = findy(x);
    y = findy(y);
    if (x == y) {
        return;
    }
    if (x > y) {
        swap(x, y);
    }
    if (rang[x] < rang[y]) {
        if (minim[x] < minim[y]) {
            minim[y] = minim[x];
        }
        else {
            minim[x] = minim[y];
        }
        if (maxim[x] > maxim[y]) {
            maxim[y] = maxim[x];
        }
        else {
            maxim[x] = maxim[y];
        }

        parents[x] = y;
        count[x] = count[x] + count[y];
        count[y] = count[x];
    }
}


int get(int x) {
    x = findy(x);
    cout << minim[x] << " ";
    cout << maxim[x] << " ";
    cout << count[x] << endl;
}


int main() {
    cin >> n;
    minim.resize(n+1);
    parents.resize(n+1);
    rang.resize(n+1);
    maxim.resize(n+1);
    count.resize(n+1, 1);
    for (int i = 1; i <= n; i++) {
        parents[i] = i;
        minim[i] = i;
        rang[i] = i;
        maxim[i] = i;
    }
    string s;
    int k;
    int w;

    while (cin >> s) {
        if (s[0] == 'u') {
            cin >> k >> w;
            uniony(k, w);
        }
        else {
            cin >> k;
            get(k);
        }
    }
}
