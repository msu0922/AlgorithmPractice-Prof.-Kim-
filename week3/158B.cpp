// https://codeforces.com/problemset/problem/158/B

#include <iostream>

using namespace std;

int main() {
    int n = 0, cnt = 0;
    cin >> n;

    int tmp = 0, ones = 0, twos = 0, threes = 0;

    for (int i = 0; i < n; i++) {
        cin >> tmp;

        if (tmp == 4) // 4 그룹 추가
            cnt += 1;
        else if (tmp == 1)
            ones += 1;
        else if (tmp == 2)
            twos += 1;
        else if (tmp == 3)
            threes += 1;
    }

    if (threes > ones) { // 3의 개수 > 1의 개수
        cnt += threes; // 3, 3+1 그룹 추가
        if (twos % 2 == 0)
            cnt += (twos / 2); // 2+2 그룹 추가
        else
            cnt += (twos / 2 + 1); // 2+2 그룹, 2 그룹 추가
    } else { // 1의 개수 > 3의 개수
        cnt += threes; // 1+3 그룹 추가
        ones -= threes; // 남은 1
        if (twos % 2 == 0) {
            cnt += twos / 2; // 2+2 그룹 추가
            cnt += ones / 4;
            if (ones % 4 != 0)
                cnt += 1;
        } else {
            cnt += twos / 2; // 2 + 1; 2+2, 2 그룹 추가
            if (ones < 3) {
                cnt += 1;
            } else {
                cnt += 1;
                ones -= 2;
                cnt += ones / 4;
                if (ones % 4 != 0)
                    cnt += 1;
            }
        }
    }

    cout << cnt << endl;

    return 0;
}
