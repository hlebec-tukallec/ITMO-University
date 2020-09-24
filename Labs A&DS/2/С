#include <iostream>
#include <vector>
using namespace std;

vector<int>queue;
//int start = 0;
//int last = 0;

void insert(int y) {
  //  start++;
   // queue[start] = y;
   queue.push_back(y);
}

void firstbye() {
    //queue[start-1] = -1;
    //start--;
    queue.erase(queue.begin());
}

void lastbye() {
    //queue[last] = -1;
    //last++;
    queue.pop_back();
}

void countpeople(int y) {
   int count = 0;
    for (int i = 0; i <= queue.size(); i++) {
        if (y == queue[i]) {
            break;
        }
       // if (queue[i] != -1) {
       count++;
       // }
    }
    cout << count << endl;
}

void whoisthefirst() {
   // cout << queue[start - 1];
   cout << queue[0] << endl;
}

int main() {
    int n;
    int x;
    int y;
    cin >> n;
   // queue.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x == 1){
            cin >> y;
            insert(y);
        }
        if (x == 2) {
            firstbye();
        }
        if (x == 3) {
            lastbye();
        }
        if (x == 4){
            cin >> y;
            countpeople(y);
        }
        if (x == 5) {
            whoisthefirst();
        }

    }
    return 0;
}
