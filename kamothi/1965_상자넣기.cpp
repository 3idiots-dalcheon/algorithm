#include<iostream>
#include<algorithm>
using namespace std;

int n,result;
int dp[1000];
int arr[1000];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i] > arr[j]){
                dp[i] = max(dp[j],dp[i]);
            }
        }
        dp[i]++;
        result = max(result,dp[i]);
    }

    cout << result;
}
