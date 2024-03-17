// https://codeforces.com/problemset/problem/71/A

#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    string output[n];

    for(int i = 0; i < n; i++) {
        char input[200];
        cin >> input;
        if (strlen(input) <= 10)
            output[i] = input;
        else
            output[i] = input[0] + to_string(strlen(input)-2) + input[strlen(input)-1];
    }

    for(int i = 0; i < n; i++) {
        cout << output[i] << endl;
    }

    return 0;
}