#include <iostream>
#include <algorithm>

using namespace std;

#define int int64_t

struct Node {
    int x;
    int y;
    int sumy;
    Node *right;
    Node *left;
    Node (int key, int k) {
        x = key;
        y = k;
        sumy = x;
        left = right = nullptr;
    }
};

Node *root = nullptr;

int get_sumy(Node *v) {
    return !v ? 0 : v->sumy;
}

void fun(Node *v) {
    v->sumy = get_sumy(v->right) + get_sumy(v->left) + v->x;
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
        fun(a);
        return a;
    }
    else {
        b->left = merge(a, b->left);
        fun(b);
        return b;
    }
}

pair <Node*, Node*> split (Node *a, int key) {
    if (!a) {
        return {nullptr, nullptr};
    }
    else if (key > a->x) {
        pair <Node*, Node*> tmp;
        tmp = split(a->right, key);
        a->right = tmp.first;
        fun(a);
        return pair<Node*, Node*>(a, tmp.second);
    }
    else {
        pair <Node*, Node*> tmp;
        tmp = split(a->left, key);
        a->left = tmp.second;
        fun(a);
        return pair <Node*, Node*>(tmp.first, a);
    }
}

bool exists(Node *v, int key) {
    if (!v) {
        return false;
    }
    else if (v->x == key) {
        return true;
    }
    else if(v->x < key) {
        return exists(v->right, key);
    }
    else {
        return exists(v->left, key);
    }
}
       
Node* insert(Node *v, int x) {
    if (!exists(v, x)) {
        pair<Node *, Node *> l = split(v, x);
        Node *tmp = new Node(x, rand());
        Node *res = merge(merge(l.first, tmp), l.second);
        return res;
    }
    return root;
}


int sum(Node *v, int l, int r) {
    pair<Node*, Node*> left = split(v, l);
    pair<Node*, Node*> right = split(left.second, r + 1);
    int res = get_sumy(right.first);
    root = merge(left.first, merge(right.first, right.second));
    return res;
}

void print(Node *v) {
    if (v == nullptr) {
        return;
    }
    print(v->left);
    cout << v->x << endl;
    print(v->right);
}

const int mod = 1'000'000'000;

signed main() {
   //freopen("crypto.in", "r", stdin);
   //freopen("crypto.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie();

    int n;
    cin >> n;
    char x;
    int safe_op = 0, safe_last = 0;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x == '+') {
            int y;
            cin >> y;
            if (safe_op == 1) {
                y = (safe_last + y) % mod;
            }
            root = insert(root, y);
            safe_op = 0;
            safe_last = 0;
        }
        else {
            int l, r;
            cin >> l >> r;
            int tmp = sum(root, l, r);
            cout << tmp << '\n';
            safe_op = 1;
            safe_last = tmp;
        }
    }
    return 0;
}
