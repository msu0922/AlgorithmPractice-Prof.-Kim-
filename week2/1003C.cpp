// https://codeforces.com/problemset/problem/1003/C

#include <iostream>

using namespace std;

int main() {
    int prefix_sum[5005];
    int n = 0, k = 0;
    double max_avg = 0.0;

    cin >> n >> k;
    int temperatures[n+1];

    for (int i = 1; i <= n; i++)
        cin >> temperatures[i];

    prefix_sum[0] = 0;
    for (int i = 1; i <= n; i++) {
        prefix_sum[i] = prefix_sum[i-1] + temperatures[i];
    }

    for (int i = k; i <= n; i++) {
        for (int j = 1; j <= n-i+1; j++) {
            max_avg = max(max_avg, double(prefix_sum[i+j-1] - prefix_sum[j-1])/double(i));
        }
    }

    printf("%lf\n", max_avg);

    // cout << max_avg << endl;

    return 0;
}