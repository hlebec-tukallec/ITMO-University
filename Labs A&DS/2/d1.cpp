#include <iostream>
#include <vector>
#include <deque>
using namespace std;
deque<int>a;
deque<int>part1;
deque<int>part2;
int i = 0;

void insert(int x) {
    a.push_back(x);

    if (a.size() == 1) {
        part1.push_back(a.front());
    }
    else if (part2.size() >= part1.size()) {
        part1.push_back(part2.front());
        part2.pop_front();
        part2.push_front(x);
    }
    else if (part2.size() < part1.size()){
        part2.push_back(x);
    }

}

void byefirst() {
    cout << part1.front() << "\n";
    a.pop_front();
    part1.pop_front();
    if (part2.size() > 0) {
        part1.push_back(part2.front());
        part2.pop_front();
    }
}

void himid(int x) {
    part1.push_back(x);
    a.push_back(x);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    char y;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> y;
        if (y == '+'){
            cin >> x;
            insert(x);
        }
        if (y == '-') {
            byefirst();
        }
        if (y == '*') {
            cin >> x;
            himid(x);
        }
    }
    return 0;
}
