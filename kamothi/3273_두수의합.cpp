#include<iostream>
#include<algorithm>

using namespace std;

int n,x,answer;
int arr[100000];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=0;i<n;i++) cin >> arr[i];
    cin >> x;

    sort(arr,arr+n);

    int left = 0,right=n-1;

    while(left < right){
        if(arr[left] + arr[right] == x){
            answer++;
            right--;
        }
        else if(arr[left] + arr[right] > x){
            right--;
        }
        else{
            left++;
        }

    }


    cout << answer;


}
