// https://codeforces.com/problemset/problem/448/C

#include <iostream>

using namespace std;

int solution(int fence[], int start, int end) {

    int shortest = 100000001, cnt = 0;

    for (int i = start; i <= end; i++)
        shortest = min(shortest, fence[i]);

    for (int i = start; i <= end; i++)
        fence[i] -= shortest;
    
    cnt += shortest;

    for (int i = start; i <= end;) {
        if (fence[i] == 0) {
            i++;
        } else {
            int sub_start = i;
            int sub_end = sub_start;
            while (sub_end <= end && fence[sub_end] > 0)
                sub_end++;
            cnt += solution(fence, sub_start, sub_end - 1);
            i = sub_end;
        }
    }

    return min(end - start + 1, cnt);
}

int main() {
    int n = 0;
    cin >> n;
    int fence[n];

    for (int i = 0; i < n; i++) {
        cin >> fence[i];
    }

    cout << solution(fence, 0, n - 1) << endl;

    return 0;
}