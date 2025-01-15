#include<iostream>
#include<algorithm>

using namespace std;

// 같은 원소가 K개 이하로 들어 있는 최장 연속 부분 수열의 길이
int arr[200000];
int check[100001];
int result=1;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    for(int i=0;i<n;i++) cin >> arr[i];
    int l =0;
    check[arr[0]]++;
    for(int i=1;i<n;i++){
        check[arr[i]]++;
        if(check[arr[i]]>k){

            for(int j=l;j<i;j++) {
                check[arr[j]]--;
                if (arr[i] == arr[j]) {
                    l = j + 1;
                    break;
                }
            }
        }

        result = max(result,i-l+1);
    }
    cout << result;
}
