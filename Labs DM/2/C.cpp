#include <iostream>
#include <string>

using namespace std;

int main() {
    freopen("mtf.in", "r", stdin);
    freopen("mtf.out", "w", stdout);

    string s;
    cin >> s;
    string alphabet = "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < s.size(); i++) {

        cout << alphabet.find(s[i])+1 << " ";

        int tmp = alphabet.find(s[i]);

        for (int j = tmp; j > 0; j--) {
            alphabet[j] = alphabet[j - 1];
        }

        alphabet[0] = s[i];
    }
    return 0;
}
