#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<pair<int, int>> cards;
long long int cnt = 0;

vector<int> merge(const vector<int> &a, const vector<int> &b){
    vector<int> c;
    int i = 0, j = 0;
    while (i < a.size() && j < b.size()){
        if (a[i] <= b[j]){
            c.push_back(a[i]);
            i++;
        }
        else {
            c.push_back(b[j]);
            j++;
            cnt = cnt + (a.size() - i);
        }
    }
    if (i == a.size()){
        for (int k = j; k < b.size(); k++){
            c.push_back(b[k]);
        }
    }
    else {
        for (int k = i; k < a.size(); k++){
            c.push_back(a[k]);
        }
    }
    return c;
}

vector<int> msort(const vector<int> &d){
    if (d.size() < 2){
        return d;
    }
    int m = d.size() / 2;
    vector<int> mass1;
    vector<int> mass2;
    for (int i = 0; i < m; i++){
        mass1.push_back(d[i]);
    }
    for (int i = m; i < d.size(); i++){
        mass2.push_back(d[i]);
    }
    return merge(msort(mass1), msort(mass2));
}


int main() {
    freopen("john.in", "r", stdin);
    freopen("john.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie();
    int n;
    cin >> n;
    int x, y;
    vector<int>help;
    cards.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        cards[i].first = x;
        cards[i].second = y;
    }
    sort(cards.begin(), cards.end());
    for (int i = 0; i < cards.size(); i++) {
        help.push_back(cards[i].second);
    }
    vector<int>res(msort(help));
    cout << cnt;
    return 0;
}
