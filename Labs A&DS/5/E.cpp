#include <iostream>
#include <algorithm>

using namespace std;

struct Node {
    int x;
    int y;
    int w;
    Node *right;
    Node *left;
    Node (int key, int k) {
        x = key;
        y = k;
        w = 1;
        left = right = nullptr;
    }
};

Node *root = nullptr;

int get_size(Node *v) {
    if (!v) {
        return 0;
    }
    else {
        return v->w;
    }
}

Node* children(Node *v) {
    v->w = get_size(v->right) + get_size(v->left) + 1;
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
    else if (key > a->x) {
        pair <Node*, Node*> tmp;
        tmp = split(a->right, key);
        a->right = tmp.first;
        children(a);
        return pair<Node*, Node*>(a, tmp.second);
    }
    else {
        pair <Node*, Node*> tmp;
        tmp = split(a->left, key);
        a->left = tmp.second;
        children(a);
        return pair <Node*, Node*>(tmp.first, a);
    }
}

int findy_max(Node *v, int k) {
    if (k - get_size(v->right) == 1) {
        return v->x;
    } else if (k > get_size(v->right)) {
        return findy_max(v->left, k - get_size(v->right) - 1);
    } else {
        return findy_max(v->right, k);
    }

}

void print(Node *v) {
    if (v) {
        if (v->left) {
            print(v->left);
        }
        cout << v->x << '\n';
        if (v->right) {
            print(v->right);
        }
    }
    else {
        cout << "Masha loshara";
    }
}
       
Node* insert(Node *v, int x) {
    pair<Node*, Node*> l = split(v, x);
    Node *tmp = new Node(x, rand());
    Node *res = merge(merge(l.first, tmp), l.second);
    return res;
}

Node* del(Node *v, int x) {
    if (!v) {
        return nullptr;
    }
    pair<Node*, Node*> l = split(v, x);
    pair<Node*, Node*> r = split(l.second, x + 1);
    Node *res = merge(l.first, r.second);
    return res;
}

int main() {
   // freopen("crypto.in", "r", stdin);
   // freopen("crypto.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie();

    int n;
    cin >> n;
    int x, y;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        if (x == -1) {
           root = del(root, y);
        }

       else if (x == 0) {
           cout << findy_max(root, y) << '\n';
        }

        else {
            root = insert(root, y);
        }
        //else {
        //    print(root);
        //}
    }
    return 0;
}
