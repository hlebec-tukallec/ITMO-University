#include <iostream>
#include <vector>
#include <string>
using namespace std;
int n;
int k;
vector<int>ch1;
vector<int>ch2;
int minim;
int maxim;

void generate_next() {
    for (int i = n - 2; i >= 0; i--) {
        if (ch1[i] < ch1[i + 1]) {
            minim = i + 1;
            for (int j = i + 1; j < n; j++) {
                if ((ch1[j] < ch1[minim]) && (ch1[j] > ch1[i])) {
                    minim = j;
                }
            }
            swap(ch1[i], ch1[minim]);
            for (int j = 0; j < i + 1; j++) {
                cout << ch1[j] << " ";
            }

            for (int j = n - 1; j >= i + 1; j--) {
                cout << ch1[j] << " ";
            }
            return;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << 0 << " ";
    }
    return;
}

void generate_prev() {
    for (int i = n - 2; i >= 0; i--) {
        if (ch2[i] > ch2[i + 1]) {
            maxim = i + 1;
            for (int j = i + 1; j < n; j++) {
                if ((ch2[j] > ch2[maxim]) && (ch2[j] < ch2[i])) {
                    maxim = j;
                }
            }
            swap(ch2[i], ch2[maxim]);
            for (int j = 0; j < i + 1; j++) {
               cout << ch2[j] << " ";
           }
            for (int j = n - 1; j >= i + 1; j--) {
                cout << ch2[j] << " ";
            }
           cout << endl;
           return;
        }

    }
    for (int i = 0; i < n; i++) {
        cout << 0 << " ";
    }
    cout << endl;
    return;

}


int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
    freopen("nextperm.in","r", stdin);
    freopen("nextperm.out","w", stdout);
    cin >> n;
    int a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        ch1.push_back(a);
        ch2.push_back(a);

    }
    generate_prev();
    generate_next();
    return 0;

}
