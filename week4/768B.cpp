// https://codeforces.com/problemset/problem/768/B

#include <iostream>

using namespace std;

long long solution(long long n, long long l, long long r) {
    long long num = n, length = 1;
    while (num > 1) {
        num /= 2;
        length = 2*length + 1;
    }

    if (l == 1 && r == length) {
        return n;
    } else if (l == r && l == (length/2 + 1)) {
        return n % 2;
    } else if (r < (length/2 + 1)) { // l r 중간
        return solution(n/2, l, r);
    } else if (r == (length/2 + 1)) { // l 중간(r)
        return solution(n/2, l, r - 1) + n % 2; 
    } else if (l < (length/2 + 1) && r > (length/2 + 1)) { // l 중간 r
        long long r_2 = length/2;
        long long l_2 = length/2 + 2;
        return solution(n/2, l, r_2) + solution(n/2, l_2 - (length/2 + 1), r - (length/2 + 1)) + n % 2;
    } else if (l == (length/2 + 1)) { // 중간(l) r
        return solution(n/2, l - (length/2 + 1) + 1, r - (length/2 + 1)) + n % 2;
    } else if (l > (length/2 + 1)) { // 중간 l r
        return solution(n/2, l - (length/2 + 1), r - (length/2 + 1));
    }
}

int main() {
    long long n = 0, l = 0, r = 0;

    cin >> n >> l >> r;
    cout << solution(n, l, r) << endl;

    return 0;
}