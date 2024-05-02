// https://codeforces.com/problemset/problem/839/C

#include <iostream>
#include <vector>

using namespace std;

class Node {
    public:
        int parent;
        int childCnt;
        vector<int> child;
        int prob;
        int depth;
};

Node N[100001];

int main() {
    int n = 0;
    cin >> n;

    int x, y = 0;

    N[1].depth = 1;
    N[1].prob = 1;
   
    for (int i = 1; i <= n; i++) {
        N[i].childCnt = 0;
    }

    for (int i = 1; i < n; i++) {
        cin >> x >> y;
        N[x].child.push_back(y);
        N[x].childCnt++;
        N[y].parent = x;
        N[y].depth = N[N[y].parent].depth + 1;
    }

    for (int i = 2; i <= n; i++)
        N[i].prob = N[N[i].parent].prob * N[N[i].parent].childCnt;

    long double ans = 0;

    for (int i = 1; i <= n; i++)
        if (N[i].childCnt == 0) {
            ans += (1.0 / N[i].prob) * (N[i].depth - 1);
        }

    printf("%.15f\n", (double)ans);

    return 0;
}