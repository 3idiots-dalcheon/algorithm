#include<iostream>
#include<algorithm>

using namespace std;

int n;
int arr[201];
int dp[201];
int result=1;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> n;

    for(int i=1;i<=n;i++) {
        cin >> arr[i];
        dp[i] = 1;
    }

    for(int i=2;i<=n;i++){
        for(int j=i-1;j>0;j--){
            if(arr[i] > arr[j]){
                dp[i] = max(dp[i],dp[j]+1);
                result = max(result,dp[i]);
            }
        }
    }

    cout << n - result;
}
