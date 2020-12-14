#include <iostream>
#include <vector>

using namespace std;

vector<vector<pair<int, int>>> edges;
vector<bool> visited;
vector<bool> ans;
vector<int> in;
vector<int> up;
vector<int> colors;
vector<vector<int>> doubles;

int timer = 0;
int maxColor = 0;

void dfs(int v, int parent = -1) {
    int kids = 0;
    visited[v] = true;
    in[v] = up[v] = timer++;
    for (int i = 0; i < edges[v].size(); i++) {
        int tmp = edges[v][i].first;
        if (tmp == parent) {
            continue;
        }
        if (visited[tmp]) {
            up[v] = min(up[v], in[tmp]);
        } else {
            dfs(tmp, v);
            kids++;
            up[v] = min(up[v], up[tmp]);
            if (up[tmp] >= in[v] && parent != -1) {
                ans[v] = true;
            }
        }
    }
    if (parent == -1 && kids > 1) {
        ans[v] = true;
    }
}

void painty (int u, int v, int color) {
    for (int i = 0; i < edges[v].size(); i++) {
        if (edges[v][i].first == u) {
            colors[edges[v][i].second] = color;
        }
    }
}

void paint(int v, int color, int parent) {
    visited[v] = true;
    for (int i = 0; i < edges[v].size(); i++) {
        if (edges[v][i].first == parent) {
            continue;
        }
        if (!visited[edges[v][i].first]) {
            if (up[edges[v][i].first] >= in[v]) {
                int newColor = ++maxColor;
                painty(edges[v][i].first, v, newColor);
                //colors[edges[v][i].second] = newColor;
                paint(edges[v][i].first, newColor, v);
            } else {
               // colors[edges[v][i].second] = color;
               painty(edges[v][i].first, v, color);
                paint(edges[v][i].first, color, v);
            }
        } else if (in[edges[v][i].first] < in[v]) {
            painty(edges[v][i].first, v, color);
            //colors[edges[v][i].second] = color;
        }
    }
}

void checkDouble(int a, int b, int ind) {
    for (int i = 0; i < edges[a - 1].size(); i++) {
        if (edges[a - 1][i].first == b - 1) {
            doubles[edges[a - 1][i].second].push_back(ind);
        }
    }
}

void doDouble() {
    for (int i = 0; i < doubles.size(); i++) {
        for (int j = 0; j < doubles[i].size(); j++) {
            colors[doubles[i][j]] = colors[i];
        }
    }
}


int main() {
    int n, m;
    cin >> n >> m;
    edges.resize(n);
    in.resize(n);
    up.resize(n);
    colors.resize(m, 0);
    visited.resize(n, false);
    ans.resize(n, false);
    doubles.resize(m);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        if (a > b) {
            swap(a, b);
        }
        //checkDouble(a, b, i);
        edges[a - 1].push_back({b - 1, i});
        edges[b - 1].push_back({a - 1, i});
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    visited.assign(n, false);
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            paint(i, maxColor, -1);
        }
    }

    //doDouble();

    cout << maxColor << endl;
    for (int colory : colors) {
        cout << colory << " ";
    }
    /*cout << endl;

      // cout << ans.size() << endl;
      for (int i = 0; i < doubles.size(); i++) {
          for (int j = 0; j < doubles[i].size(); j++) {
              cout << i << " " << doubles[i][j] << " ";
          }
          cout << endl;
      }
      */

}
