#include <iostream>

using namespace std;

long long int dp[1000001];
int main() {
    long long int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        long long int pos,val;
        cin >> pos >> val;
        dp[pos]=val;
    }

    long long int ans=0;
    
    for(int i = 0;i <= 1000000; i++) {
        if (dp[i] != 0) {
            if (i - dp[i] < 0)
                dp[i]=1;
            else
                dp[i] = 1 + dp[i - dp[i] - 1];
        } else
            dp[i] = dp[i - 1];
        
        ans = max(ans, dp[i]);
    }
    cout << n - ans << endl;
}