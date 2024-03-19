// https://codeforces.com/problemset/problem/734/B

#include <iostream>

using namespace std;

int main() {
    long long k2, k3, k5, k6, sum;
    k2 = k3 = k5 = k6 = sum = 0;

    cin >> k2 >> k3 >> k5 >> k6;
    
    long long fiftysix = min(k5, k6); // ()56 짝 만들기
    long long twofiftysix = min(k2, fiftysix); // (2)56의 개수
    sum += 256 * twofiftysix;

    if (k2 > fiftysix) { // 2가 남았다면
        sum += 32 * min(k2 - twofiftysix, k3);
    }

    cout << sum << endl;

    return 0;
}