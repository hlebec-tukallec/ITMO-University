#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

struct Node {
    int key;
    int height;
    Node *left;
    Node *right;
    Node(int k) {
        key = k;
        left = right = nullptr;
        height = 1;
    }
};

Node *root = nullptr;

int height (Node *v) {
    if (v) {
        return v->height;
    }
    else {
        return 0;
    }
}

int justify (Node *v) {
    return (height(v->right) - height(v->left));
}

void fixy(Node *v) {
    int hl = height(v->left);
    int hr = height(v->right);
    if (hl > hr) {
        v->height = hl + 1;
    }
    else {
        v->height = hr + 1;
    }
}

Node* rotate_right(Node *v) {
    Node *tmp = v->left;
    v->left = tmp->right;
    tmp->right = v;
    fixy(v);
    fixy(tmp);
    return tmp;
}

Node* rotate_left(Node *v) {
    Node *tmp = v->right;
    v->right = tmp->left;
    tmp->left = v;
    fixy(v);
    fixy(tmp);
    return tmp;
}

Node* balance(Node *v) {
    fixy(v);
    if (justify(v) == 2) {
        if (justify(v->right) < 0) {
            v->right = rotate_right(v->right);
        }
        return rotate_left(v);
    }
    else if (justify(v) == -2) {
        if (justify(v->left) > 0) {
            v->left = rotate_left(v->left);
        }
        return rotate_right(v);
    }
    else {
        return v;
    }
}

Node* insert (Node* v, int x) {
    if (!v) {
        return new Node(x);
    }
    else if (x < v->key) {
        v->left = insert(v->left, x);
    }
    else {
        v->right = insert(v->right, x);
    }
    return balance(v);
}

Node* minim(Node *v) {
    if (v->left) {
        return minim(v->left);
    }
    else {
        return v;
    }
}

Node* delmin(Node *v) {
    if (v->left == nullptr) {
        return v->right;
    }
    else {
        v->left = delmin(v->left);
        return balance(v);
    }
}

Node* del (Node *v, int x) {
    if (!v) {
        return nullptr;
    }
    else if (x < v->key) {
        v->left = del(v->left, x);
    }
    else if (x > v->key) {
        v->right = del(v->right, x);
    }
    else {
        Node *tmpl = v->left;
        Node *tmpr = v->right;
        delete v;
        if (!tmpr) {
            return tmpl;
        }
        Node *min = minim(tmpr);
        min->right = delmin(tmpr);
        min->left = tmpl;
        return balance(min);
    }
    return balance(v);
}

bool exist(Node *v, int x) {
    if (!v) {
        return false;
    }
    if (v->key == x) {
        return true;
    }
    else if (x < v->key) {
        return exist(v->left, x);
    }
    else {
        return exist(v->right, x);
    }
}

Node* nexty (Node *v, int x) {
    if (!v) {
        return nullptr;
    }
    Node *cur = root;
    Node *kid = nullptr;
    while (cur != nullptr) {
        if (cur->key > x) {
            kid = cur;
            cur = cur->left;
        }
        else {
            cur = cur->right;
        }
    }
    return kid;
}

Node* prevy (Node *v, int x) {
    if (!v) {
        return nullptr;
    }
    Node *cur = root;
    Node *kid = nullptr;
    while (cur != nullptr) {
        if (cur->key < x) {
            kid = cur;
            cur = cur->right;
        }
        else {
            cur = cur->left;

        }
    }
    return kid;
}

int main() {

   //freopen("crypto.in", "r", stdin);
   //freopen("crypto.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie();

    string str;
    int x;
    while (cin >> str){
        if (str == "insert") {
            cin >> x;
            if (!exist(root, x)) {
               root = insert(root, x);
            }
        } else if (str == "delete") {
            cin >> x;
            if (exist(root, x)) {
               root = del(root, x);
            }
        } else if (str == "exists") {
            cin >> x;
            if (exist(root, x)) {
                cout << "true" << '\n';
            }
            else {
                cout << "false" << '\n';
            }

        } else if (str == "next") {
            cin >> x;
            if (nexty(root, x) == nullptr) {
                cout << "none" << '\n';
            }
            else {
                cout << nexty(root, x)->key << '\n';
            }

        } else {
            cin >> x;
            if (prevy(root, x) == nullptr) {
                cout << "none" << '\n';
            }
            else {
                cout << prevy(root, x)->key << '\n';
            }
        }
   }
    return 0;
}
