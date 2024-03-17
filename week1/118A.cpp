// https://codeforces.com/problemset/problem/118/A

#include <iostream>

using namespace std;

int main() {
    char input[200], output[400];
    int n = 0;
    cin >> input;

    for(int i = 0; i < strlen(input); i++) {
        if(input[i] == 'A' || input[i] == 'O' || input[i] == 'Y' || input[i] == 'E' || input[i] == 'U' || input[i] == 'I')
            continue;
        else if(input[i] == 'a' || input[i] == 'o' || input[i] == 'y' || input[i] == 'e' || input[i] == 'u' || input[i] == 'i')
            continue;
        else if(input[i] >= 'A' && input[i] <= 'Z') {
            output[n++] = '.';
            output[n++] = input[i] + ('a' - 'A');
        } else {
            output[n++] = '.';
            output[n++] = input[i];
        }
    }

    output[n] = '\0';

    cout << output << endl;

    return 0;
}