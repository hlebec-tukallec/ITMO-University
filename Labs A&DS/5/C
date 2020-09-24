#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

struct Node {
    int child;
    int x;
    int y;
    Node *right;
    Node *left;
    Node (int k, int key) {
        child = 1;
        x = k;
        y = key;
        left = right = nullptr;
    }
};

vector<int>fin;
set<int>safe;

Node *root = nullptr;

int get_kids(Node *v) {
    return !v ? 0 : v->child;
}

void children(Node *v) {
    v->child = get_kids(v->right) + get_kids(v->left) + 1;
}

Node* merge (Node *a, Node *b) {
    if (!a) {
        return b;
    }
    if (!b) {
        return a;
    }

    if (a->y > b->y) {
        a->right = merge(a->right, b);
        children(a);
        return a;
    }
    else {
        b->left = merge(a, b->left);
        children(b);
        return b;
    }
}

pair <Node*, Node*> split (Node *a, int key) {
    if (!a) {
        return {nullptr, nullptr};
    }
    if (key > get_kids(a->left)) {
        pair<Node *, Node *> tmp;
        tmp = split(a->right, key - get_kids(a->left) - 1);
        a->right = tmp.first;
        children(a);
        return pair<Node*, Node*>(a, tmp.second);
    } else {
        pair<Node *, Node *> tmp;
        tmp = split(a->left, key);
        a->left = tmp.second;
        children(a);
        return pair<Node*, Node*>(tmp.first, a);
    }
}

int zerro(int pos) {
    if (safe.lower_bound(pos) == safe.end()) {
        return -1;
    }
    else {
        int tmp = *(safe.lower_bound(pos));
        safe.erase(tmp);
        return tmp;
    }
}

Node* del(Node *v, int x) {
    pair<Node*, Node*> l = split(v, x - 1);
    pair<Node*, Node*> r = split(l.second, 1);
    Node *res = merge(l.first, r.second);
    return res;
}

Node* insert(Node *v, int x, int ind) {
    pair<Node *, Node *> l = split(v, ind - 1);
    Node *tmp = new Node(x, rand());
    Node *res = merge(merge(l.first, tmp), l.second);
    return res;
}

Node* inserty(Node *v, int x, int ind) {
    int tmpy = zerro(ind);
    if (tmpy != -1) {
        v = del(v, tmpy);
    }
    pair<Node *, Node *> l = split(v, ind - 1);
    Node *tmp = new Node(x, rand());
    Node *res = merge(merge(l.first, tmp), l.second);
    return res;
}

void printy(Node *v) {
    if (v->left) {
        printy(v->left);
    }
    cout << v->x << " ";
    if (v->right) {
        printy(v->right);
    }
}

void print(Node *v) {
    if (v->left) {
        print(v->left);
    }
    fin.push_back(v->x);
    if (v->right) {
        print(v->right);
    }
}

signed main() {
   freopen("crypto.in", "r", stdin);
   freopen("crypto.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie();

    srand(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        root = insert(root, 0, i + 1);
        safe.insert(i + 1);
    }
   //printy(root);
   //cout << '\n';

    int cnt = 1;
    int pos;
    for (int i = 0; i < n; i++) {
        cin >> pos;
        root = inserty(root, cnt, pos);
      //  printy(root);
      //  cout << '\n';
        cnt++;
    }
    print(root);

    int check = 0;
    for (int i = fin.size() - 1; i >= 0; i--) {
        if (fin[i] == 0) {
            fin.pop_back();
        }
        else {
            check = i + 1;
            break;
        }
    }

    cout << check << '\n';
    for (int i = 0; i < fin.size(); i++) {
        cout << fin[i] << " ";
    }

    return 0;
}
