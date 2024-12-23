#include<iostream>
#include<algorithm>

using namespace std;

int arr[1000000];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;
    int result;
    cin >> n >> m;

    for(int i=0;i<n;i++) cin >> arr[i];
    long long left=0,right=2000000001;
    while(left <= right){
        int mid = (left+right)/2;
        long long tmp=0;
        for(int i=0;i<n;i++){
            if(arr[i] > mid) tmp += arr[i] - mid;
        }

        if(tmp >= m) {
            result = mid;
            left = mid+1;
        }
        else{
            right = mid-1;
        }
    }

    cout << result;
}
