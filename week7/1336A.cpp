// https://codeforces.com/problemset/problem/1336/A

#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int n = 0, k = 0;
 
class Node {
public:
    int parent;
    int nchild;
    int dr;
    int ndesc;
    vector<int> AD;
};
 
Node C[200005];
int P[200005];
 
void dfs1(int nd, int PT)
{
    int s = 0;
    C[nd].parent = PT;
    s = C[nd].AD.size();
    C[nd].nchild = 0;
    for (int i = 0; i < s; i++) {
        if (C[nd].AD[i] != C[nd].parent) {
            C[nd].nchild++;
            dfs1(C[nd].AD[i], nd);
        }
    }
}
 
int dfs2(int nd, int dr)
{
    int s = C[nd].AD.size();
    C[nd].dr = dr;
    C[nd].ndesc = 0;
    for (int i = 0; i < s; i++) {
        if (C[nd].AD[i] != C[nd].parent) {
            C[nd].ndesc += dfs2(C[nd].AD[i], dr + 1);
        }
    }
    return C[nd].ndesc + 1;
}
 
int main()
{
    int x, y;
    cin >> n >> k;

    for (int i = 1; i < n; i++) {
        cin >> x >> y;
        C[x].AD.push_back(y);
        C[y].AD.push_back(x);
    }

    dfs1(1, 0);
    dfs2(1, 0);
    
    for (int i = 1; i <= n; i++)
        P[i] = C[i].dr - C[i].ndesc;
    
    sort(P + 1, P + n + 1);
    
    long long ans = 0;

    for (int i = 0; i < k; i++)
        ans += P[n - i];

    cout << ans << endl;

    return 0;
}