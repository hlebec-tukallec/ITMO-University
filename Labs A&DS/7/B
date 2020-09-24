#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<pair<int, int>>times;

bool comp (pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int main() {
    freopen("request.in", "r", stdin);
    freopen("request.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie();
    int n;
    cin >> n;
    int x, y;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        times.emplace_back(x, y);
    }
    times.emplace_back(1441, 1441);
    sort(times.begin(), times.end(), comp);
   int now = 0;
   int count = 0;
   int i = 0;
   while (now < 1440) {
       if (times[i].first == 1441) {
           break;
       }
       else if (times[i].first >= now) {
           now = times[i].second;
           count++;
           i++;
       } else {
           i++;
       }
   }

   cout << count;
   return 0;
}
