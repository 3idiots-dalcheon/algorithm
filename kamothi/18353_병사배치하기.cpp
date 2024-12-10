#include<iostream>
#include<algorithm>

using  namespace std;

int arr[2000];
int dp[2001];
int result = 1;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> arr[i];
        dp[i] = 1;
    }

    for(int i=n-2;i>=0;i--){
        for(int j=i+1;j<n;j++){
            if(arr[i] > arr[j]) dp[i] = max(dp[i],dp[j]+1);
        }
        result = max(result,dp[i]);
    }

    cout << n-result;

}
