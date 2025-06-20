#include<iostream>

using namespace std;

int arr[1000];
int dp[1000];
int n,result;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    dp[0] = 1;
    result = dp[0];
    for (int i = 1; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (arr[i] < arr[j]) dp[i] = max(1 + dp[j], dp[i]);
        }
        result = max(result, dp[i]);
    }

    cout << result;
}
