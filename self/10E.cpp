// https://codeforces.com/problemset/problem/13/A

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int A = 0;
    cin >> A;
    
    int base[A+1];

    for (int i = 2; i < A; i++) {
        int base10 = A;
        int sum = 0;

        while (base10 >= i) {
            sum += base10 % i;
            base10 /= i;
        }
        sum += base10;
        base[i] = sum;
    }

    // 분수 출력
    int total = 0;
    
    for (int i = 2; i < A; i++)
        total += base[i];

    int gcd = __gcd(total, A-2);

    cout << total/gcd << "/" << (A-2)/gcd << endl;

    return 0;
}