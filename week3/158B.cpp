// https://codeforces.com/problemset/problem/158/B

#include <iostream>

using namespace std;

int main() {
    int n, cnt;
    cin >> n;

    int groups[5];

    // 4
    for (int i = 0; i < n; i++) {
        cin >> groups[i];
        if (groups[i] == 4)
            cnt += 1;
    }

    // 3 & 1
    int threes, ones;

    for (int i = 0; i < n; i++) {
        if (groups[i] == 3)
            threes += 1;
        else if (groups[i] == 1)
            ones += 1;
    }

    if (threes / ones > 0) { // 3의 개수 > 1의 개수
        cnt += threes;
        ones -= threes; // 3+1 맞추고 남은 1의 개수

        // 2
        int twos;

        for (int i = 0; i < n; i++) {
            if (groups[i] == 2)
                twos += 1;
        }
    } else { // 3의 개수 < 1의 개수
        cnt += ones;
        threes -= ones; // 3+1 맞추고 남은 3의 개수


    }

    
    // 2
    int twos;

    for (int i = 0; i < n; i++) {
        if (groups[i] == 2)
            twos += 1;
    }

    return 0;
}
