#include <iostream>

using namespace std;

int main() {
    long long n = 0, cnt = 0, cnt_one = 0, one_third = 0, two_thirds = 0;
    cin >> n;

    long long arr[n+1];
    long long prefix_sum[n+1];
    prefix_sum[0] = 0;
    
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    for (int i = 1; i <= n; i++)
        prefix_sum[i] = prefix_sum[i-1] + arr[i];

    if (prefix_sum[n] % 3 != 0)
        cnt = 0;
    else {
        one_third = prefix_sum[n] / 3;
        two_thirds = one_third * 2;

        for (int i = 1; i < n; i++) {
            if (prefix_sum[i] == two_thirds)
                cnt += cnt_one;
            if (prefix_sum[i] == one_third)
                cnt_one += 1;
        }
    }

    cout << cnt << endl;

    return 0;
}