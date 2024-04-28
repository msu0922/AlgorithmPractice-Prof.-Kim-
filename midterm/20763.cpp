// https://swexpertacademy.com/main/code/userProblem/userProblemDetail.do?contestProbId=AY8Qlj36PdkDFAS1&categoryId=AY8Qlj36PdkDFAS1&categoryType=CODE

#include <iostream>

using namespace std;

int main() {
    int N = 0;
    cin >> N;

    int capacity[N + 1];
    int original[N + 1];
    for (int k = 1; k <= N; k++)
        capacity[k] = 0;

    for (int k = 1; k <= N; k++) { // 물 용량 입력
        cin >> capacity[k];
        original[k] = capacity[k];
    }

    int i = 0, j = 0, X = 0, Y = 0, temp = 0;
    cin >> i >> X; // i번째 그릇에 X만큼
    cin >> j >> Y; // j번째 그릇에 Y만큼

    // for (int k = 1; k <= N; k++) { // temp
    //     cout << k << "번째 그릇 용량 : " << original[k] << endl;
    // }
    // cout << endl;

    int left_X = X;
    while (left_X > 0) {
        int in = min(capacity[i], left_X);
        capacity[i] -= in;
        left_X -= in;
        i += 1;
    }

    // for (int k = 1; k <= N; k++) { // temp
    //     cout << k << "번째 그릇 용량 : " << capacity[k] << endl;
    // }
    // cout << endl;

    int left_Y = Y;
    while (left_Y > 0) {
        int in = min(capacity[j], left_Y);
        capacity[j] -= in;
        left_Y -= in;
        j += 1;
    }

    // for (int k = 1; k <= N; k++) { // temp
    //     cout << k << "번째 그릇 용량 : " << capacity[k] << endl;
    // }

    int ans = 0;
    for (int k = temp; k <= N; k++) {
        // cout << "k : " << k << endl; // temp

        if(capacity[k] != original[k]) {
            // cout << "기존 용량: " << original[k] << endl;
            // cout << "현재 용량: " << capacity[k] << endl;
            ans = original[k] - capacity[k];
            // cout << "물의 양: " << ans << endl;
        }
    }
    cout << ans << endl;

    return 0;
}