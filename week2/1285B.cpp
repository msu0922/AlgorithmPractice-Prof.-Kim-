// https://codeforces.com/problemset/problem/1285/B

#include <iostream>

using namespace std;

int main() {
    long long input[100005];
    int cases = 0;
    cin >> cases;
    int ans[cases]; // -1 : NO

    for (int i = 0; i < cases; i++) {
        int n;
        cin >> n; 

        long long prefix_sum[100005];
        long long MAX[100005];
        prefix_sum[0] = 0;

        for (int j = 1; j <= n; j++) {
            cin >> input[j];
            prefix_sum[j] = prefix_sum[j-1] + input[j];
        }
        long long total = prefix_sum[n];
        long long prefix_min = prefix_sum[0];

        for (int j = 1; j < n; j++) {
            MAX[j] = prefix_sum[j] - prefix_min;
            prefix_min = min(prefix_min, prefix_sum[j]);
            if (total <= MAX[j])
                ans[i] = -1;
        }

        for (int j = 1; j <= n; j++)
            // prefix_sum[j] -= prefix_sum[1];
            prefix_sum[j] -= input[1];
            
        prefix_min = prefix_sum[0];

        for (int j = 2; j <= n; j++) {
            MAX[j] = prefix_sum[j] - prefix_min;
            prefix_min = min(prefix_min, prefix_sum[j]);
            if (total <= MAX[j])
                ans[i] = -1;
        }
    }

    for (int i = 0; i < cases; i++) {
        if (ans[i] == -1)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }

    return 0;
}