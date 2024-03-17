// https://codeforces.com/problemset/problem/4/A

#include <iostream>

using namespace std;

int main() {
    int w;
    cin >> w;

    if(w < 1 or w > 100)
        cout << "NO" << endl;

    if(w < 4)
        cout << "NO" << endl;
    else if(w % 2 == 0)
        cout  << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}