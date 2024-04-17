// https://codeforces.com/problemset/problem/706/C

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
    int numOfStr = 0;
    cin >> numOfStr; // n

    long long cost[numOfStr + 1];
    for (int i = 0; i < numOfStr; i++)
        cin >> cost[i]; // c_i

    string str[numOfStr + 1];
    for (int i = 0; i < numOfStr; i++) {
        cin >> str[i]; // string
    }
    long long originalCost[numOfStr + 1];
    originalCost[0] = 0;

    string reversed[numOfStr + 1];
    for (int i = 0; i < numOfStr; i++) {
        reversed[i] = str[i];
        reverse(reversed[i].begin(), reversed[i].end());
    }
    long long reversedCost[numOfStr + 1];
    reversedCost[0] = cost[0];

    for (int i = 1; i <= numOfStr; i++) {
        cout << endl; // temp
        cout << "i : " << i << endl; // temp
        originalCost[i] = 0;
        cout << "originalCost[" << i - 1 << "] : " << originalCost[i-1] << endl; // temp
        cout << "originalCost[" << i << "] : " << originalCost[i] << endl; // temp
        // str2 도착
        if (str[i - 1] <= str[i] || reversed[i - 1] <= str[i]) {
            if (originalCost[i - 1] == -1) {
                originalCost[i] = -1;
                continue;
            }
            if (str[i - 1] <= str[i]) { // str1 -> str2
                cout << "str1 -> str2" << endl; // temp
                originalCost[i] = originalCost[i - 1];
            }
            if (reversed[i - 1] <= str[i]) { // rev1 -> str2
                cout << "rev1 -> str2" << endl; // temp
                originalCost[i] = reversedCost[i - 1];
            }
        } else
            originalCost[i] = -1;

        cout << "originalCost[" << i << "] : " << originalCost[i] << endl << endl; // temp
        reversedCost[i] = 0;
        cout << "reversedCost[" << i - 1 << "] : " << reversedCost[i-1] << endl; // temp
        cout << "reversedCost[" << i << "] : " << reversedCost[i] << endl; // temp
        // rev2 도착
        if (str[i - 1] <= reversed[i] || reversed[i - 1] <= reversed[i]) {
            if (reversedCost[i - 1] == -1) {
                reversedCost[i] = -1;
                continue;
            }
            if (str[i - 1] <= reversed[i]) { // str1 -> rev2
                cout << "str1 -> rev2" << endl; // temp
                reversedCost[i] = originalCost[i - 1] + cost[i];
                cout << "reversedCost[" << i << "] : " << reversedCost[i] << endl; // temp
            }
            if (reversed[i - 1] <= reversed[i]) { // rev1 -> rev2
                cout << "rev1 -> rev2" << endl; // temp
                reversedCost[i] = reversedCost[i - 1] + cost[i];
                cout << "reversedCost[" << i << "] : " << reversedCost[i] << endl; // temp
            }
            continue;
        } else
            reversedCost[i] = -1;
        
        cout << "reversedCost[" << i << "] : " << reversedCost[i] << endl; // temp
    }
    
    if (originalCost[numOfStr] == -1 && reversedCost[numOfStr] == -1) {
        cout << originalCost[numOfStr] << endl;
        cout << "cout << originalCost[numOfStr] << endl;" << endl; // temp
    } else if (originalCost[numOfStr] != -1 && reversedCost[numOfStr] != -1) {
        cout << min(originalCost[numOfStr], reversedCost[numOfStr]) << endl;
        cout << "cout << min(originalCost[numOfStr], reversedCost[numOfStr]) << endl;" << endl; // temp
    } else if (originalCost[numOfStr] != -1 && reversedCost[numOfStr] == -1) {
        cout << originalCost[numOfStr] << endl;
        cout << "cout << originalCost[numOfStr] << endl;" << endl; // temp
    } else if (originalCost[numOfStr] == -1 && reversedCost[numOfStr] != -1) {
        cout << reversedCost[numOfStr] << endl;
        cout << "cout << reversedCost[numOfStr] << endl;" << endl; // temp
    }

    return 0;
}