// https://codeforces.com/problemset/problem/282/A

#include <iostream>

using namespace std;

int main() {
    int n = 0;
    int cnt = 0;

    cin >> n;

    string input[n];
    for(int i = 0; i < n; i++)
        cin >> input[i];

    for (int i = 0; i < n; i++) {
        if (input[i] == "X++" || input[i] == "++X")
            cnt++;
        else if (input[i] == "X--" || input[i] == "--X")
            cnt--;
    }
    cout << cnt << endl;

    return 0;
}