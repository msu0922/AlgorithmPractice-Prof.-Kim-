// https://codeforces.com/problemset/problem/231/A
 
#include <iostream>
 
using namespace std;
 
int main() {
    int n = 0, solved[3], cnt = 0;
 
    cin >> n; // number of problems
    for (int i = 0; i < n; i++) {
        cin >> solved[0] >> solved[1] >> solved[2];
 
        int temp = 0;
 
        for (int j = 0; j < 3; j++) {
            if (solved[j] == 1)
                temp++;
        }
 
        if (temp >= 2)
            cnt++;
    }
    cout << cnt << endl;
 
    return 0;
}