// https://codeforces.com/problemset/problem/158/B

#include <iostream>

using namespace std;

int main() {
    int n, cnt;
    cin >> n;

    int groups[n], ones, twos, threes;

    // 4
    for (int i = 0; i < n; i++) {
        cin >> groups[i];

        if (groups[i] == 4) // 4인 그룹 추가
            cnt += 1;
        else if (groups[i] == 1)
            ones++;
        else if (groups[i] == 2)
            twos++;
        else if (groups[i] == 3)
            threes++;
    }
    

    cout << cnt << endl;

    return 0;
}
