// https://codeforces.com/problemset/problem/327/A

#include <iostream>

using namespace std;

int main() {
    int n = 0;
    cin >> n;
    int sum = -999, cnt = 0, a[n], subArr[n];

    for (int i = 0; i < n; i++) {
        subArr[i] = 0;
        cin >> a[i];
        if (i == 0 && a[i] == 0)
            subArr[0] = 1;
        else if (i == 0 && a[i] == 1)
            subArr[0] = -1;
        if (a[i] == 1)
            cnt++;
    }

    for (int i = 1; i < n; i++) {
        if (a[i] == 1)
            subArr[i] = max(subArr[i - 1] - 1, -1);
        else if (a[i] == 0)
            subArr[i] = max(subArr[i - 1] + 1, 1);
    }
    
    for (int i = 0; i < n; i++)
        sum = max(sum, subArr[i]);
    
    sum += cnt;

    cout << sum << endl;

    return 0;
}