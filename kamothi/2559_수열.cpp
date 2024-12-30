#include<iostream>

using namespace std;

int arr[100000];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,k,sum=0,result = -1e9;
    cin >> n >> k;

    for(int i=1;i<=n;i++) cin >> arr[i];

    int l=1,r=k;
    for(int i=1;i<k;i++) sum += arr[i];
    while(r<=n){
        sum += arr[r];
        sum -= arr[l-1];
        if(result < sum) result = sum;

        r++,l++;
    }

    cout << result;
}
