// https://codeforces.com/problemset/problem/189/A

#include <iostream>

using namespace std;

int main() {
    int n = 0, a = 0, b = 0, c = 0, num = 0;

    cin >> n >> a >> b >> c;

    for (int i = 0; i <= 4000; i++) { // num of pieces with length a
        for (int j = 0; j <= 4000; j++) { // num of pieces with length b
            int remain = n - a * i - b * j;
            if (remain >= 0) {
                if (remain % c == 0)
                    num = max(num, i + j + remain/c);
            }
        }
    }

    cout << num << endl;

    return 0;
}