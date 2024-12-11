#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int c,n;
int dp[1101];
pair<int,int> arr[20];

bool cmp(pair<int,int> a , pair<int,int> b){
    return a.second < b.second;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> c >> n;
    fill(dp, dp+1101, 1000000000);

    for(int i=0;i<n;i++) {
        cin >> arr[i].first >> arr[i].second;
        dp[arr[i].second] = min(dp[arr[i].second],arr[i].first);
    }

    sort(arr,arr+n,cmp);

    for(int i=1;i<=1100;i++){
        for(int j=0;j<n;j++){
            if((i-arr[j].second) >=0) {
                dp[i] = min(dp[i],dp[i-arr[j].second] + arr[j].first);
            }
        }
    }
    int result = 1000000000;
    for(int i=c;i<=1100;i++){
        result = min(result,dp[i]);
    }

    cout << result;
}
