// https://codeforces.com/problemset/problem/602/B

#include <iostream>

using namespace std;

int main() {
    int n = 0;
    cin >> n;

    int sequence[n + 1];
    sequence[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> sequence[i];
    }

    int mn[n], mx[n], cnt[n], len[n];
    mn[0] = 999999, mx[0] = 0, cnt[0] = 0, len[0] = 0;
    for (int i = 1; i <= n; i++) {
        mn[i] = 0, mx[i] = 0, cnt[i] = 0, len[i] = 0;
    }
    
    for (int i = 1; i <= n; i++) {
        mn[i] = min(mn[i - 1], sequence[i]);
        mx[i] = max(mx[i - 1], sequence[i]);

        if (mx[i] - mn[i] <= 1) {
            cnt[i] = cnt[i - 1] + 1;
            len[i] = len[i - 1] + 1;
        } else {
            mn[i] = sequence[i];
            mx[i] = sequence[i];
            cnt[i] = 1;
            len[i] = 1;
        }
    }

    cout << len[n] << endl;

    return 0;
}