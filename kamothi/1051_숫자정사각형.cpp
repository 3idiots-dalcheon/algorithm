#include<iostream>
#include<algorithm>

using namespace std;

int n,m;
int arr[50][50];
int ans;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for(int i=0;i<n;i++){
        string input;
        cin >> input;
        for(int j=0;j<m;j++) {
            arr[i][j] = input[j];
        }
    }



    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int l = 0;
            while(i + l < n && j + l < m) {
                if(arr[i][j] == arr[i+l][j]
                   && arr[i][j] == arr[i][j+l]
                   && arr[i][j] == arr[i+l][j+l]) {
                    ans = max(ans, (l+1)*(l+1));
                }
                l++;
            }
        }
    }

    cout << ans;


}
