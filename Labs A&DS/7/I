#include <iostream>
#include <vector>
#include <string>

using namespace std;
vector<vector<int>> matr(4, vector<int>(4));

vector<vector<int>> operator&(vector<vector<int>> a, vector<vector<int>> b) {
    vector<vector<int>> c(4, vector<int>(4));
    c[0][0] = (a[0][0] * b[0][0] + a[1][0] * b[0][1] + a[2][0] * b[0][2] + a[3][0] * b[0][3]) % 2;
    c[0][1] = (a[0][1] * b[0][0] + a[1][1] * b[0][1] + a[2][1] * b[0][2] + a[3][1] * b[0][3]) % 2;
    c[0][2] = (a[0][2] * b[0][0] + a[1][2] * b[0][1] + a[2][2] * b[0][2] + a[3][2] * b[0][3]) % 2;
    c[0][3] = (a[0][3] * b[0][0] + a[1][3] * b[0][1] + a[2][3] * b[0][2] + a[3][3] * b[0][3]) % 2;

    c[1][0] = (a[0][0] * b[1][0] + a[1][0] * b[1][1] + a[2][0] * b[1][2] + a[3][0] * b[1][3]) % 2;
    c[1][1] = (a[0][1] * b[1][0] + a[1][1] * b[1][1] + a[2][1] * b[1][2] + a[3][1] * b[1][3]) % 2;
    c[1][2] = (a[0][2] * b[1][0] + a[1][2] * b[1][1] + a[2][2] * b[1][2] + a[3][2] * b[1][3]) % 2;
    c[1][3] = (a[0][3] * b[1][0] + a[1][3] * b[1][1] + a[2][3] * b[1][2] + a[3][3] * b[1][3]) % 2;

    c[2][0] = (a[0][0] * b[2][0] + a[1][0] * b[2][1] + a[2][0] * b[2][2] + a[3][0] * b[2][3]) % 2;
    c[2][1] = (a[0][1] * b[2][0] + a[1][1] * b[2][1] + a[2][1] * b[2][2] + a[3][1] * b[2][3]) % 2;
    c[2][2] = (a[0][2] * b[2][0] + a[1][2] * b[2][1] + a[2][2] * b[2][2] + a[3][2] * b[2][3]) % 2;
    c[2][3] = (a[0][3] * b[2][0] + a[1][3] * b[2][1] + a[2][3] * b[2][2] + a[3][3] * b[2][3]) % 2;

    c[3][0] = (a[0][0] * b[3][0] + a[1][0] * b[3][1] + a[2][0] * b[3][2] + a[3][0] * b[3][3]) % 2;
    c[3][1] = (a[0][1] * b[3][0] + a[1][1] * b[3][1] + a[2][1] * b[3][2] + a[3][1] * b[3][3]) % 2;
    c[3][2] = (a[0][2] * b[3][0] + a[1][2] * b[3][1] + a[2][2] * b[3][2] + a[3][2] * b[3][3]) % 2;
    c[3][3] = (a[0][3] * b[3][0] + a[1][3] * b[3][1] + a[2][3] * b[3][2] + a[3][3] * b[3][3]) % 2;

    return c;
}

void county(vector<vector<int>> &a, int symb, int row, int col) {
    a[row][col] = symb;
    col++;
    if (col > 3) {
        col = 0;
        row++;
    }
    if (row > 3) {
        vector<vector<int>> tmp(4, vector<int>(4));
        tmp = a & a;
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                if (tmp[i][j] != matr[i][j])
                    return;
        for (auto &i : a) {
            for (int j : i)
                cout << j << ' ';
            cout << '\n';
        }
        exit(0);
    }
    county(a, 0, row, col);
    county(a, 1, row, col);
}

int main() {
    freopen("sqroot.in", "r", stdin);
    freopen("sqroot.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for (auto &i : matr)
        for (int &j : i)
            cin >> j;
    vector<vector<int>> s(4, vector<int>(4));
    county(s, 0, 0, 0);
    county(s, 1, 0, 0);

    cout << "NO SOLUTION";

    return 0;
}
