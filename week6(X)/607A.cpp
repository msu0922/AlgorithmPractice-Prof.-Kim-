// https://codeforces.com/problemset/problem/607/A

#include <iostream>

using namespace std;

int main() {
    int n = 0;
    cin >> n; // num of beacons

    int powers[1000001] = {0};
    int ans[1000001] = {0};
    int maxPos = 0;
    int minPos = 1000001;

    for (int i = 0; i < n; i++) {
        int idx = 0;
        cin >> idx;
        maxPos = max(maxPos, idx);
        minPos = min(minPos, idx);
        cin >> powers[idx];
    }

    for (int i = 1; i <= maxPos; i++) {
        int cnt = 1, temp = 0;
        if (powers[i] != 0) { // 비콘이 존재한다면
            for (int j = 1; j <= i - powers[i] - 1; j++) {
                if (ans[j] != 0)
                    temp = ans[j];
            }
            cnt += temp;
        } else {
            ans[i] = 0;
            continue;
        }
        ans[i] = cnt;
    }

    int maxAns = 0;
    int idx = 0;
    for (int i = 1; i <= maxPos; i++) {
        int temp = maxAns;
        maxAns = max(maxAns, ans[i]);
        if (maxAns != temp)
            idx = i;
    }
    
    cout << maxPos - idx << endl;

    return 0;
}