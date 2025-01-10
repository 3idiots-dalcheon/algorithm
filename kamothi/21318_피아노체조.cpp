#include<iostream>

using namespace std;

int n,q;
int arr[100001];
int sum[100001];

// 마지막으로 연주하는 y번 악보에선 절대 실수하지 않는다

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
        if(arr[i] < arr[i-1]) sum[i] = sum[i-1] + 1;
        else sum[i] = sum[i-1];
    }

    cin >> q;
    while(q--){
        int x,y;
        cin >> x >> y;

        cout << sum[y] - sum[x] << "\n";
    }

}
