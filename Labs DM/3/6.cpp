#include <iostream>
#include <vector>
#include <string>

using namespace std;
int n;
vector<string>ans;
void generate(string x){
    if (x.size() == n) {
      ans.push_back(x);
    }
    else {
        //   ans.push_back(x);
        generate(x + "0");

        if (x[x.size()-1] != '1') {
            generate(x + "1");
        }


    }
}

int main() {
    freopen("vectors.in","r", stdin);
    freopen("vectors.out","w", stdout);
    cin >> n;
    generate("");
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
    return 0;
}
