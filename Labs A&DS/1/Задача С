#include <iostream>
#include <vector>

using namespace std;
long long int count = 0;

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
            count = count + (a.size() - i);
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

int main(){
    vector<int> a;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }
    vector<int> outA(msort(a));
    cout << count;

    return 0;
}
