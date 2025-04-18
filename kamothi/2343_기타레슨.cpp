#include<iostream>
#include<algorithm>
using namespace std;

long long arr[100000];

// 이진 탐색으로 구하고자 하는 값은? -> 블루레이의 크기

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;
    cin >> n >> m;

    long long Lsum = 0;
    long long Max = 0;


    for(int i=0;i<n;i++){
        cin >> arr[i];
        Lsum += arr[i];
        Max = max(Max, arr[i]);
    }

    long long right = Lsum;
    long long left = Max;
    long long mid = 0;

    while(left <= right){
        int cnt = 0;
        int sum = 0;

        mid = (left+right)/2;
        for(int i=0; i<n; i++){
            sum += arr[i];
            if(sum > mid){
                sum = arr[i];
                cnt++;
            }
        }

        if(sum > 0){
            cnt++;
        }

        if(cnt > m){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }

    cout << left;

}
