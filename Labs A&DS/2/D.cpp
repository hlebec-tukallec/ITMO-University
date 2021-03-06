#include <iostream>
#include <deque>
using namespace std;

deque<int>part1;
deque<int>part2;

void insert(int x) {
    part2.push_back(x);
    if (part2.size() > part1.size()) {
        while (part2.size() > 0 && part1.size() < part2.size()) {
            part1.push_back(part2.front());
            part2.pop_front();
        }
    }


}

void byefirst() {
    cout << part1.front() << "\n";
    part1.pop_front();
    if (part2.size() > part1.size()) {
        while (part2.size() > 0 && part1.size() < part2.size()) {
            part1.push_back(part2.front());
            part2.pop_front();
        }
    }

}

void himid(int x) {
    //part1.push_back(x);
    part2.push_front(x);
    if (part2.size() > part1.size()) {
        while (part2.size() > 0 && part1.size() < part2.size()) {
            part1.push_back(part2.front());
            part2.pop_front();
        }
    }
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
        else if (y == '-') {
            byefirst();
        }
        else if (y == '*') {
            cin >> x;
            himid(x);
        }
    }
    return 0;
}
