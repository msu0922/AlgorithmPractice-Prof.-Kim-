// https://codeforces.com/problemset/problem/160/A

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n = 0, sum = 0, my = 0, cnt = 0;
    cin >> n;

    int val[n];

    for (int i = 0; i < n; i++) {
        cin >> val[i];
        sum += val[i];
    }

    sort(val, val + n, greater<int>());

    int k = 0;

    while (my <= sum / 2) {
        my += val[k];
        k++;
        cnt++;
    }

    cout << cnt << endl;

    return 0;
}