#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool comp (pair<pair<int, int>,int> a, pair<pair<int, int>,int> b) {
    return a.first.second < b.first.second;
}

int main() {
    freopen("apples.in", "r", stdin);
    freopen("apples.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie();
    int n, height;
    cin >> n >> height;
    int x, y;
    vector<pair<pair<int, int>, int>> apples;
    vector<pair<pair<int, int>, int>> ap;
    vector<int>ans;

    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        if (x <= y) {
            apples.push_back({{x, y}, i});
            //apples[i].first.first = x;
            //apples[i].first.second = y;
            //apples[i].second = i;
        }
        else {
            ap.push_back({{y, x}, i});
          //  ap[i].first.first =  y;
           // ap[i].first.second = x;
            //ap[i].second = i;
        }
    }
    sort(apples.begin(), apples.end());
    sort(ap.begin(), ap.end());
   // reverse(ap.begin(), ap.end());

    for (int i = 0; i < apples.size(); i++) {
        int tmp = height - apples[i].first.first;
        height = tmp + apples[i].first.second;
        ans.push_back(apples[i].second);
    }

    for( int i = ap.size() - 1; i >= 0; i--) {
        int tmp = height - ap[i].first.second;
        if (tmp <= 0) {
            cout << -1;
            return 0;
        }
        height = tmp + ap[i].first.first;
        ans.push_back(ap[i].second);
    }
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] + 1 << " ";
    }

    return 0;
}
