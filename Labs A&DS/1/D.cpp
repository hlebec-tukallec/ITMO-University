#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;
int size = 0;

void SiftUp (int a) {
    int j = (a - 1)/2;
    while (arr[a] > arr[j])  {

      swap(arr[a],arr[j]);
       a = j;
       j = (a - 1)/2;
     }
}


void SiftDown (int a) {
  while ((2 * a) + 1 < size) {
  int leftch;
  int rightch;
  int k;
  leftch = (a * 2) + 1;
  k = leftch;
  rightch = (a * 2) + 2;
  if ((rightch < size) && (arr[rightch] > arr[leftch])) {
      k = rightch;
  }
  if (arr[a] >= arr[k]) {
      break;
  }
  swap(arr[a],arr[k]);
  a = k;
  }
}




int Extract () {
  int max = arr[0];
  size--;
  arr[0] = arr[size];
  arr.resize(size);
  SiftDown(0);
  return max;
}


void Insert (int a) {
    size++;
    arr.resize(size);
    arr[size - 1] = a;
    SiftUp(size - 1);
}



int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x != 1) {
            int num;
            cin >> num;
            Insert(num);
        }
        if (x == 1) {
            cout << Extract() << endl;
        }

    }
    return 0;
}
