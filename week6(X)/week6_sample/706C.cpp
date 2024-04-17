#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
long long INF = 10000000000000007;
int main() {
    int n;
    cin >> n;
    vector<int> c(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }

    vector<long long> dp_norm(n + 1, INF);
    vector<long long> dp_per(n + 1, INF);
    dp_norm[1] = 0;
    dp_per[1] = c[1];
    vector<string> s(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> s[i];
    }

    bool f = true;

    for (int i = 2; i <= n; i++) {
        if(s[i] >= s[i - 1]) {
            dp_norm[i] = dp_norm[i - 1];
        }
        string l = s[i];
        string m = s[i - 1];
        reverse(l.begin(), l.end());
        reverse(m.begin(), m.end());
        if (s[i] >= m) {
            dp_norm[i] = min(dp_norm[i], dp_per[i - 1]);
        }
        if (l >= s[i - 1]) {
            dp_per[i] = dp_norm[i - 1] + c[i];
        }
        if (l >= m) {
            dp_per[i] = min(dp_per[i], dp_per[i - 1] + c[i]);
        }
        if (dp_norm[i] >= INF && dp_per[i] >= INF) {
            f = false;
            break;
        }
    }
    if(f) {
        cout << min(dp_norm[n], dp_per[n]) << endl;
    } else {
        cout << -1 << endl;
    }
}