// https://codeforces.com/problemset/problem/455/A

#include <iostream>

using namespace std;

int main() {
    int n = 0, a[n], point = 0, temp = 0, mx = 0;
    long long sum[100001] = {0}, A[100001] = {0}, B[100001] = {0};

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        sum[temp] += temp;
        mx = max(mx, temp);
    }

    A[1] = sum[1];
    B[1] = 0;

    for (int i = 2; i <= mx + 1; i++) {
        B[i] = max(A[i - 1], B[i - 1]);
        A[i] = B[i - 1] + sum[i];
    }

    cout << max(A[mx + 1], B[mx + 1]) << endl;

    return 0;
}