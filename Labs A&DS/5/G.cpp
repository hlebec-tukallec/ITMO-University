#include <iostream>
#include <algorithm>

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

Node* insert(Node *v, int x, int ind) {
    pair<Node*, Node*> l = split(v, ind);
    Node *tmp = new Node(x, rand());
    Node *res = merge(merge(l.first, tmp), l.second);
    return res;
}

Node* move(Node *v, int l, int r) {
    pair<Node*, Node*> t2 = split(v, r);
    pair<Node*, Node*> t1 = split(t2.first, l);
    return merge(t1.second, merge(t1.first, t2.second));
}

void print(Node *v) {
    if (v->left) {
        print(v->left);
    }
    cout << v->x << " ";
    if (v->right) {
        print(v->right);
    }
}

signed main() {
   //freopen("crypto.in", "r", stdin);
   //freopen("crypto.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie();

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        root = insert(root, i + 1, i);
    }
   // print(root);
   // cout << endl;

    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        root = move(root, l - 1, r);
       // print(root);
       // cout << endl;
    }

    print(root);

    return 0;
}
