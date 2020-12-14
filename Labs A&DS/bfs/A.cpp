#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> edges;

int main() {
    int n;
    cin >> n;
    edges.resize(n, vector<int> (n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> edges[i][j];
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                edges[i][j] = min(edges[i][j], edges[i][k] + edges[k][j]);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << edges[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
