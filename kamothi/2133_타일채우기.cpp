#include<iostream>

using namespace std;


// 3*n
int dp[31], arr[31];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    dp[0] = 1, dp[2] = 3;

    for(int i=4;i<=30;i=i+2){
       arr[i] = arr[i-2] + dp[i-4];
       dp[i] = 3*dp[i-2]+ 2*arr[i];
    }
    cout << dp[n] <<"\n";
}
