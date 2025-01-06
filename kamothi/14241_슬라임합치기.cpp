#include<iostream>
#include<algorithm>

using namespace std;

int n,result;
int arr[100];

int main(){
    cin >> n;
    for(int i=0;i<n;i++) cin >> arr[i];
    
    sort(arr,arr+n);
    
    int now = arr[0] + arr[1];
    result += arr[0]*arr[1];
    
    for(int i=2;i<n;i++){
        result += now*arr[i];
        
        now = now + arr[i];
    }
    
    cout << result;

}
