#include <iostream>
#include <vector>
#include <map>

using namespace std;
 
int main() {
    int n;
    cin >> n;

    vector<int> vec(n, 0);
    for (int i = 0; i < n; ++i)
        cin >> vec[i];
 
    map<int, int> h, l;
    
    int cnt = 0, ans = 0;
    
    for (int i = 0; i < n; i++) {
        int minV = vec[i] - 2;
        int maxV = vec[i] + 2;
        if (h.find(maxV) != h.end()) {
            cnt = i - h[maxV] - 1;
            h.erase(maxV);
        }
        if (l.find(minV) != l.end()) {
            cnt = min(cnt, i - l[minV] - 1);
            l.erase(minV);
        }
 
        h[vec[i]] = i;
        l[vec[i]] = i;
        cnt += 1;
        ans = max(ans, cnt);
    }
 
    cout << ans << endl;
 
    return 0;
}