#include<iostream>
using namespace std;

int split(int *a, int l, int r, int x) {
    int i = l;
    int j = r - 1;
    while (i <= j) {
        while (a[i] <= x) {
            i++;
        }
        while (a[j] > x) {
            j--;
        }
        if (i >= j) {
            break;
        }
        swap (a[i], a[j]);
        i++;
        j--;
    }
    return j;
}


void qsort(int *a, int l, int r) {
    int i = l;
    int j = r;
    int q = a[(i + j) / 2];
    while (i < j) {
    while (a[i] < q) {
        i++;
    }
    while (a[j] > q) {
        j--;
    }
    if (i <= j) {
        int m = a[i];
        a[i] = a[j];
        a[j] = m;
        i++;
        j--;
    }
}
    if (l < j) {
        qsort(a, l, j);
    }
    if (i < r)
    {qsort(a, i, r);
}
}


int main () {
 int n;
 cin >> n;
 int a[n];
 for (int i = 0; i < n; i ++) {
     cin >> a[i];
 }
 int l = 0;
 int r = n - 1 ;
// int x = a[rand() % n];
qsort(a, l, r);
for (int i = 0; i < n; i ++) {
    cout << a[i] << " ";
}
return 0;
}
